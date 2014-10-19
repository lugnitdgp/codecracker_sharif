<?php
/**
 * Sharif Judge online judge
 * @file all _problems.php
 * @author Anuj Kumar <anujkumar.nitdgp@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('selected' => 'problems')); ?>
<?php $now = shj_now(); ?>

<script>
    $(document).ready(function(){
        $('table tr').click(function(){
            window.location = $(this).attr('href');
            return false;
        });
    });
</script>
<div id="main_container" class="scroll-wrapper">
    <div class="scroll-content">

        <div id="page_title">
            <img src="<?php echo base_url('assets/images/icons/problems.png') ?>"/>
            <span><?php echo $title ?></span>
        </div>
        <div id="main_content">
            <?php //print_r($assignment);//echo $now-strtotime ($assignment['start_time']); ?>
            <?php if ($assignment == NULL): ?>
                <p>No round selected. Please go to rounds and check the <b><?php $last_assignment = end($all_assignments); echo $last_assignment['name'] ?></b> and come back to view the problems!</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && !$assignment['open']): ?>
                <?php // if assignment is closed, non-student users (admin, instructors) still can submit ?>
                <p>Selected round is closed.</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && $now < strtotime($assignment['start_time'])): ?>
                <p>Selected round has not started.</p>
            <?php elseif ($this->user_model->get_user_level($username) == 0 && !$this->assignment_model->is_participant($assignment['participants'], $username)): ?>
                <p>You are not registered for submitting.</p>
            <?php else: ?>
                <?php $i = 1 ?>
                <table class="sharif_table">
                    <tr>
                        <th>Serial No.</th>
                        <th>Problem Name</th>
                        <th>No. of Final Submissions</th>
                        <th>Max. Points</th>
                    </tr>
                    <?php foreach ($problems as $problem) : ?>
                        <tr href="<?php echo base_url('/index.php/problems/view/' . $problem['id']) ?>" Title="click to view the problem">
                            <td><?php echo $i++ ?></td>
                            <td> <?php echo $problem['name'] ?></td>
                            <td><?php echo $problem['numOfSubmissions'] ?></td>
                            <td><?php echo $problem['score'] ?></td>
                        </tr>
                    <?php endforeach; ?>
                </table>
            <?php endif ?>

        </div>
    </div>
</div>
