<?php
/**
 * Sharif Judge online judge
 * @file submit.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

<script>
    shj.p={};
<?php
foreach ($problems as $problem) {
    $languages = explode(',', $problem['allowed_languages']);
    $items = '';
    foreach ($languages as $language) {
        $items = $items . "'" . trim($language) . "',";
    }
    $items = substr($items, 0, strlen($items) - 1);
    echo "shj.p[{$problem['id']}]=[{$items}]; ";
}
?>
    $(document).ready(function(){
        $("select#problems").change(function(){
            var v = $(this).val();
            $('select#languages').empty();
            $('<option value="0" selected="selected">-- Select One --</option>').appendTo('select#languages');
            if (v==0)
                return;
            for (var i=0;i<shj.p[v].length;i++)
            $('<option value="'+shj.p[v][i]+'">'+shj.p[v][i]+'</option>').appendTo('select#languages');
        });
    });
</script>
<style type="text/css">
    #editor {
        position: relative;
        top: 0;
        right: 0;
        bottom: 0;
        left: 0;
        overflow: auto;
    }
</style>


<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('selected' => 'submit')); ?>
<?php $now = shj_now(); ?>

<div id="main_container" class="scroll-wrapper">
    <div class="scroll-content">

        <div id="page_title">
            <img src="<?php echo base_url('assets/images/icons/submit.png') ?>"/>
            <span><?php echo $title ?></span>
        </div>

        <div id="main_content">
            <?php if ($assignment['id'] == 0): ?>
                <p>Please select a round first.</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && !$assignment['open']): ?>
                <?php // if assignment is closed, non-student users (admin, instructors) still can submit ?>
                <p>Selected round is closed.</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && $now < strtotime($assignment['start_time'])): ?>
                <p>Selected round has not started.</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && $now > strtotime($assignment['finish_time']) + $assignment['extra_time']): // deadline = finish_time + extra_time?>
                <p>Selected round has finished.</p>
            <?php elseif (!$this->assignment_model->is_participant($assignment['participants'], $username)): ?>
                <p>You are not registered for submitting.</p>
            <?php else: ?>
                <p>Selected assignment: <?php echo $assignment['name'] ?></p>
                <p>Coefficient: <?php echo $coefficient ?>%</p>
                <?php echo form_open_multipart('submit') ?>
                <p class="input_p">
                    <label for="problems" class="tiny">Problem:</label>
                    <select id="problems" name ="problem" class="sharif_input">
                        <?php if ($single_problem == NULL) : ?>
                            <option value="0" selected="selected">-- Select One --</option>
                            <?php foreach ($problems as $problem): ?>
                                <option value="<?php echo $problem['id'] ?>"><?php echo $problem['name'] ?></option>
                            <?php endforeach ?>
                        <?php else : ?>
                            <option  value="<?php echo $single_problem['id'] ?>" selected="selected"><?php echo $single_problem['name'] ?></option>
                        <?php endif ?>
                    </select>

                    <?php echo form_error('problem', '<div class="shj_error">', '</div>') ?>
                </p>
                <p class="input_p">
                    <label for="languages" class="tiny">Language:</label>
                    <select id="languages" name="language" class="sharif_input">
                        <option value="0" selected="selected" id="language">-- Select One --</option>
                        <?php if ($single_problem !== NULL) : ?>
                            <?php  $languages = explode(',', $single_problem['allowed_languages']) ?>
                            <?php foreach ($languages as $language): ?>
                                <option value="<?php echo $language ?>"><?php echo $language ?></option>
                            <?php endforeach ?>
                        <?php endif ?>
                    </select>
                    <?php echo form_error('language', '<div class="shj_error">', '</div>') ?>
                </p>
                <p class="input_p">
                    <label for="code">Enter your code in the editor or upload a file:</label>
                        <textarea  name="code" id="code" style="visibility: hidden;"></textarea>
                    <div id="editor">
                    </div>
                </p>
                <p class="input_p">
                    <label for="file" class="tiny">File:</label>
                    <input type="file" id="file" class="sharif_input medium" name="userfile" />
                    <?php if ($upload_state === 'error'): ?>
                    <div class="shj_error">Error uploading file.</div>
                <?php elseif ($upload_state === 'ok'): ?>
                    <div class="shj_ok">File uploaded successfully. See the result in 'All Submissions'.</div>
                <?php endif ?>
                <?php echo $this->upload->display_errors('<div class="shj_error">', '</div>') ?>
                </p>
                <p class="input_p">
                    <input type="submit" value="Submit" id="submit" class="sharif_input"/>
                </p>
                </form>
            <?php endif ?>

        </div> <!-- main_content -->
    </div> <!-- scroll-content -->
</div> <!-- main_container -->

<script src='<?php echo base_url("assets/js/ace-builds/src-noconflict/ace.js") ?>' type="text/javascript" charset="utf-8"></script>
<script>
    var editor = ace.edit("editor");
    $('#editor').height('250');
    $('#editor').width('100%');
    editor.resize();
    editor.setTheme("ace/theme/monokai");
    var langg = {
        'C': 'c_cpp',
        'C++': 'c_cpp',
        'Python 3': 'python',
        'Python 2': 'python',
        'Java' : 'java'
    };
    editor.setValue("", 0);
    editor.setFontSize(15);
    $('#languages').change(function() {
        if(editor.getValue() == "") {
            var comment = "";
            if(this.value == 'Python 2' || this.value == 'Python 3') comment = "#";
            else comment = "//";
            comment += "write your code here";
            editor.setValue(comment, 0);
        }
        console.log(langg[this.value]);
        editor.getSession().setMode("ace/mode/"+langg[this.value]);
        console.log(editor.getSession().getMode());
    });
    $('#submit').click(function() {
        $('#code').text(editor.getValue());
    });
</script>   
