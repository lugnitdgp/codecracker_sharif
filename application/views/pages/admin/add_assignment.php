<?php
/**
 * Sharif Judge online judge
 * @file add_assignment.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

<script type="text/javascript" src="<?php echo base_url("assets/js/jquery-ui-timepicker-addon.js") ?>"></script>
<script type='text/javascript' src="<?php echo base_url("assets/tinymce/tinymce.min.js") ?>"></script>

<script>
    var numOfProblems=<?php echo count($problems); ?>;
    var row1='<tr>\
                <td>';
    function get_row2(num) {
                    var row2='</td>\
                <td><input type="text" name="name[]" class="sharif_input short" value="Problem "/></td>\
                <td>\
                    <p id="add_statement' + num + '">Add Statement</p>\
                    <div id="editor' + num + '">\
                        <textarea id="statement' + num + '" name="statement[]"></textarea>\
                    </div>\
                </td>\
                <td><input type="text" name="score[]" class="sharif_input tiny2" value="100"/></td>\
                <td><input type="text" name="c_time_limit[]" class="sharif_input tiny2" value="500"/></td>\
                <td><input type="text" name="python_time_limit[]" class="sharif_input tiny2" value="1500"/></td>\
                <td><input type="text" name="java_time_limit[]" class="sharif_input tiny2" value="2000"/></td>\
                <td><input type="text" name="memory_limit[]" class="sharif_input tiny" value="50000"/></td>\
                <td><input type="text" name="languages[]" class="sharif_input short2" value="C,C++,Python 2,Python 3,Java"/></td>\
                <td><input type="text" name="diff_cmd[]" class="sharif_input tiny" value="diff"/></td>\
                <td><input type="text" name="diff_arg[]" class="sharif_input tiny" value="-bB"/></td>\
                <td><input type="checkbox" name="is_upload_only[]" class="check" value="';
                return row2;
     }
                    var row3='"/><td><i class="splashy-gem_remove delete_problem pointer"></i></td></td>\
        </tr>';
                    $(document).ready(function(){

                        //editor_id = $('#statement' + numOfProblems).attr('id');
                        //tinymce.get(editor_id).hide();
                        //$('#statement' + numOfProblems).hide();
                        //$('#editor1').hide();

                        $('p').click(function(event){
                            button_id = event.target.id;
                            console.log("inside function");
                            if(button_id.substring(0, 13) == "add_statement") {
                                editor_id = "#editor"+button_id.substring(13, button_id.length);
                                console.log(editor_id);
                                //tinymce.get(editor_id).show();
                                $(editor_id).show();
                                $(this).hide();
                                //$('#statement' + numOfProblems).attr('id');
                            }
                        });

                        $("#add").click(function(){
                            numOfProblems++;
                            $('#problems_table>tbody').children().last().after(row1+(numOfProblems)+get_row2(numOfProblems)+(numOfProblems)+row3);
                            editor_init("statement" + numOfProblems);
                            $('#nop').attr('value',numOfProblems);
                            console.log(numOfProblems);
                            //$('#editor' + numOfProblems).hide();
                        });
                        
                        $(document).on('click','.delete_problem',function(){
                            if (numOfProblems==1) return;
                            var row = $(this).parents('tr');
                            var id = row.children(':first').html();
                            row.remove();
                            var i = 0;
                            $('#problems_table>tbody').children('tr').each(function(){
                                i++;
                                $(this).children(':first').html(i);
                                $(this).find('[type="checkbox"]').attr('value',i);
                            });
                            numOfProblems--;
                            $('#nop').attr('value',numOfProblems);
                        });
                        $('#start_time').datetimepicker();
                        $('#finish_time').datetimepicker();
                
                        for(i=1; i<=numOfProblems; i++) editor_init("statement"+i);

                        function editor_init(id) {
                            tinymce.init({
                                mode : "exact",
                                elements : id,
                                //selector: 'textarea.notif_text',
                                toolbar_items_size: 'small',
                                relative_urls: false,
                                width: 430,
                                height: 120,
                                resize: true,
                                plugins: 'directionality emoticons textcolor link code',
                                toolbar1: "undo redo | styleselect | bold italic | alignleft aligncenter alignright alignjustify | bullist numlist outdent indent",
                                toolbar2: "forecolor backcolor | emoticons | link unlink anchor image media code | removeformat"
                            });
                        }

                    });
</script>
<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('selected' => 'assignments')); ?>

<div id="main_container" class="scroll-wrapper">
    <div class="scroll-content">

        <div id="page_title">
            <img src="<?php echo base_url('assets/images/icons/add.png') ?>"/>
            <span><?php echo $title ?></span>
            <span class="title_menu_item">
                <a href="http://docs.sharifjudge.ir/add_assignment" target="_blank"><i class="splashy-help"></i> Help</a>
            </span>
        </div>

        <div id="main_content">

            <?php foreach ($success_messages as $success_message): ?>
                <p class="shj_ok"><?php echo $success_message ?></p>
            <?php endforeach ?>
            <?php foreach ($error_messages as $error_message): ?>
                <p class="shj_error"><?php echo $error_message ?></p>
            <?php endforeach ?>

            <?php if ($edit): ?>
                <p>
                    <i class="splashy-information"></i> If you don't want to change tests, just do not upload any file.
                </p>
            <?php endif ?>

            <?php echo form_open_multipart($edit ? 'assignments/edit/' . $edit_assignment['id'] : 'assignments/add') ?>
            <div class="panel_left">
                <input type="hidden" name="number_of_problems" id="nop" value="<?php echo $edit ? $edit_assignment['problems'] : count($problems); ?>"/>
                <p class="input_p">
                    <label for="form_a_name">Round Name</label>
                    <input id="form_a_name" type="text" name="assignment_name" class="sharif_input medium" value="<?php
            if ($edit)
                echo $edit_assignment['name'];
            else
                echo set_value('assignment_name');
            ?>"/>
                           <?php echo form_error('assignment_name', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p">
                    <label for="start_time">Start Time</label>
                    <input id="start_time" type="text" name="start_time" class="sharif_input medium" value="<?php
                           if ($edit)
                               echo date('m/d/Y H:i', strtotime($edit_assignment['start_time']));
                           else
                               echo set_value('start_time');
                           ?>" />
                           <?php echo form_error('start_time', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p">
                    <label for="finish_time">Finish Time</label>
                    <input id="finish_time" type="text" name="finish_time" class="sharif_input medium" value="<?php
                           if ($edit)
                               echo date('m/d/Y H:i', strtotime($edit_assignment['finish_time']));
                           else
                               echo set_value('finish_time');
                           ?>" />
                           <?php echo form_error('finish_time', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p clear">
                    <label for="form_extra_time">
                        Extra Time (minutes)<br>
                        <span class="form_comment">Extra time for late submissions.</span>
                    </label>
                    <input id="form_extra_time" type="text" name="extra_time" id="extra_time" class="sharif_input medium" value="<?php
                           if ($edit) {
                               $extra_time = floor($edit_assignment['extra_time'] / 60);
                               if ($extra_time % 60 == 0)
                                   echo ($extra_time / 60) . '*60';
                               else
                                   echo $extra_time;
                           }
                           else
                               echo set_value('extra_time');
                           ?>" />
                           <?php echo form_error('extra_time', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p clear">
                    <label for="form_participants">Participants<br>
                        <span class="form_comment">Enter username of participants here (comma separated).
                            Only these users are able to submit. You can use keyword "ALL".</span>
                    </label>
                    <textarea id="form_participants" name="participants" rows="5" class="sharif_input medium"><?php
                           if ($edit)
                               echo $edit_assignment['participants'];
                           else
                               echo set_value('participants', 'ALL');
                           ?></textarea>
                </p>
                <p class="input_p clear">
                    <label for="form_tests">Tests (zip file)<br>
                        <span class="form_comment">
                            <a href="http://docs.sharifjudge.ir/tests_structure" target="_blank">Use this structure</a>
                        </span>
                    </label>

                    <input id="form_tests" type="file" name="tests" class="sharif_input medium"/>
                    <?php
                    if (!$edit)
                        echo $this->upload->display_errors('<div class="shj_error">', '</div>');
                    ?>
                </p>
            </div>
            <div class="panel_right">
                <p class="input_p">
                    <input id="form_a_open" type="checkbox" name="open" value="1" <?php if ($edit) echo $edit_assignment['open'] ? 'checked' : ''; else echo set_checkbox('open', '1') ?> />
                    <label for="form_a_open" class="default">Open</label><br>
                    <span class="form_comment">Open or close this assignment.</span>
                    <?php echo form_error('open', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p">
                    <input id="form_a_scoreboard" type="checkbox" name="scoreboard" value="1" <?php if ($edit) echo $edit_assignment['scoreboard'] ? 'checked' : ''; else echo set_checkbox('scoreboard', '1') ?> />
                    <label for="form_a_scoreboard" class="default">Scoreboard</label><br>
                    <span class="form_comment">Check this to enable scoreboard.</span>
                    <?php echo form_error('scoreboard', '<div class="shj_error">', '</div>'); ?>
                </p>
                <p class="input_p">
                    <label for="form_late_rule">Coefficient rule (<a target="_blank" href="http://docs.sharifjudge.ir/add_assignment#coefficient_rule">?</a>)</label><br>
                    <span class="form_comment medium clear" style="display: block;">PHP script without &lt;?php ?&gt; tags</span>
                    <textarea id="form_late_rule" name="late_rule" rows="14" class="sharif_input add_text"><?php
                    if ($edit)
                        echo $edit_assignment['late_rule'];
                    else
                        echo set_value('late_rule', $this->settings_model->get_setting('default_late_rule'))
                        ?></textarea>
                    <?php echo form_error('late_rule', '<div class="shj_error">', '</div>'); ?>
                </p>
            </div>
            <p class="input_p" id="add_problems">Problems <i class="splashy-add pointer" id="add"></i>
            <div class="wrapper">
                <table id="problems_table">
                    <thead>
                        <tr>
                            <th rowspan="2"></th>
                            <th rowspan="2">Name</th>
                            <th rowspan="2">Statement</th>
                            <th rowspan="2">Score</th>
                            <th colspan="3" style="border-bottom: 1px solid #BDBDBD">Time Limit (ms)</th>
                            <th rowspan="2">Memory<br>Limit (kB)</th>
                            <th rowspan="2">Allowed<br>Languages (<a target="_blank" href="http://docs.sharifjudge.ir/add_assignment#allowed_languages">?</a>)</th>
                            <th rowspan="2">Diff<br>Command (<a target="_blank" href="http://docs.sharifjudge.ir/add_assignment#diff_command">?</a>)</th>
                            <th rowspan="2">Diff<br>Argument (<a target="_blank" href="http://docs.sharifjudge.ir/add_assignment#diff_arguments">?</a>)</th>
                            <th rowspan="2">Upload<br>Only (<a target="_blank" href="http://docs.sharifjudge.ir/add_assignment#upload_only">?</a>)</th>
                            <th rowspan="2"></th>
                        </tr>
                        <tr>
                            <th>C/C++</th><th>Python</th><th>Java</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php $i = 1 ?>
                        <?php foreach ($problems as $problem): ?>
                            <tr>
                                <td><?php echo $problem['id'] ?></td>
                                <td><input type="text" name="name[]" class="sharif_input short" value="<?php echo $problem['name'] ?>"/></td>
                                <td><!--<p id="add_statement1">Add Statement</p>-->
                                    <div id="editor1">
                                        <textarea id="statement<?php echo $i++ ?>" name="statement[]"><?php echo $problem['statement'] ?></textarea>
                                    </div>
                                </td>
                                <td><input type="text" name="score[]" class="sharif_input tiny2" value="<?php echo $problem['score'] ?>"/></td>
                                <td><input type="text" name="c_time_limit[]" class="sharif_input tiny2" value="<?php echo $problem['c_time_limit'] ?>"/></td>
                                <td><input type="text" name="python_time_limit[]" class="sharif_input tiny2" value="<?php echo $problem['python_time_limit'] ?>"/></td>
                                <td><input type="text" name="java_time_limit[]" class="sharif_input tiny2" value="<?php echo $problem['java_time_limit'] ?>"/></td>
                                <td><input type="text" name="memory_limit[]" class="sharif_input tiny" value="<?php echo $problem['memory_limit'] ?>"/></td>
                                <td><input type="text" name="languages[]" class="sharif_input short2" value="<?php echo $problem['allowed_languages'] ?>"/></td>
                                <td><input type="text" name="diff_cmd[]" class="sharif_input tiny" value="<?php echo $problem['diff_cmd'] ?>"/></td>
                                <td><input type="text" name="diff_arg[]" class="sharif_input tiny" value="<?php echo $problem['diff_arg'] ?>"/></td>
                                <td><input type="checkbox" name="is_upload_only[]" class="check" value="<?php echo $problem['id'] ?>" <?php if ($problem['is_upload_only']) echo "checked" ?>/></td>
                                <td><i class="splashy-gem_remove delete_problem pointer"></i></td>
                            </tr>
                        <?php endforeach ?>
                    </tbody>
                </table>
            </div>
            </p>
            <?php echo form_error('name[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('score[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('c_time_limit[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('python_time_limit[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('java_time_limit[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('memory_limit[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('languages[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('diff_cmd[]', '<div class="shj_error">', '</div>'); ?>
            <?php echo form_error('diff_arg[]', '<div class="shj_error">', '</div>'); ?>
            <p class="input_p">
                <input type="submit" value="<?php echo $edit ? 'Edit' : 'Add' ?> Assignment" class="sharif_input"/>
            </p>
            </form>

        </div> <!-- main_content -->
    </div> <!-- scroll-content -->
</div> <!-- main_container -->