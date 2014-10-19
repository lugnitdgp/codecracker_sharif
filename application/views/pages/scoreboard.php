<?php
/**
 * Codecracker powered by Sharif Judge
 * @file scoreboard_2.php
 * @author Anuj Kumar <anujkumar.nitdgp@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>
<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('notification_count' => $notification_count, 'selected' => 'scoreboard')); ?>

<div id="main_container" class="scroll-wrapper">
    <div class="scroll-content">

        <div id="page_title">
            <img src="<?php echo base_url('assets/images/icons/scoreboard.png') ?>"/>
            <span><?php echo $title ?></span>
        </div>

        <div id="main_content">
            <table class="sharif_table">
                <thead>
                    <tr>
                        <th>#</th><th>Username</th><th>Name</th>
                        <?php foreach ($problems as $problem): ?>
                            <th>Problem <?php echo $problem['id'] ?><br>(<?php echo $problem['name'] ?>)</th>
                        <?php endforeach ?>
                        <th>Total Score in this Round</th>
                        <th>Score from Previous Round</th>
                        <th>Cumulative Score</th>
                    </tr>
                </thead>
                <?php
                $i = 1;
                foreach ($total_scores as $user => $score_cumulative):
                    ?>
                    <tr>
                        <td><?php echo $i++ ?></td>
                        <td><?php echo $user ?></td>
                        <td><?php echo $this->user_model->get_user($user)->display_name ?></td>

                        <?php foreach ($problems as $problem): ?>
                            <td>
                                <?php if (isset($scoreboard_1[$user]['problems'][$problem['id']]['score'])): ?>
                                    <?php echo $scoreboard_1[$user]['problems'][$problem['id']]['score'] ?>
                                    <br>
                                    <span class="scoreboard_hours" title="time"><?php echo floor($scoreboard_1[$user]['problems'][$problem['id']]['time'] / 6) / 10 ?> minutes</span>
                                <?php else: ?>
                                    -
                                <?php endif ?>
                            </td>
                        <?php endforeach ?>

                        <td>
                            <?php if (isset($scoreboard_1[$user]['total_score'])): ?>
                                <?php echo $scoreboard_1[$user]['total_score'] ?>
                                <br>
                                <span class="scoreboard_hours" title="time"><?php echo floor($scoreboard_1[$user]['total_time'] / 6) / 10 ?> minutes</span>
                            <?php else: ?>
                                -
                            <?php endif ?>
                        </td>
                        <td>
                            <?php if (isset($scoreboard_2[$user]['total_score'])): ?>
                                <?php echo $scoreboard_2[$user]['total_score'] ?>
                                <br>
                                <span class="scoreboard_hours" title="time"><?php echo floor($scoreboard_2[$user]['total_time'] / 6) / 10 ?> minutes</span>
                            <?php else: ?>
                                -
                            <?php endif ?>
                        </td>

                        <td><?php echo $score_cumulative['score'] ?> 
                            <br>
                            <span class="scoreboard_hours" title="time"><?php echo floor($score_cumulative['total_time'] / 6) / 10 ?> minutes</span></td>
                    </tr>
                <?php endforeach ?>
            </table>
        </div>
    </div>
</div>
