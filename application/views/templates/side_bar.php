<?php
/**
 * Sharif Judge online judge
 * @file side_bar.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

<script>
	// difference of server and browser time:
	shj.offset = moment('<?php echo date("Y-m-d H:i:s", shj_now()); ?>').diff(moment());

	shj.sync_server_time = function() {
		$.post('<?php echo site_url('server_time') ?>',
			{<?php echo $this->security->get_csrf_token_name(); ?>: '<?php echo $this->security->get_csrf_hash(); ?>'},
			function(data) {
				shj.offset = moment(data).diff(moment());
			}
		);
	}
</script>

<script type= "text/javascript">
	$(document).ready(function() {
		if (shj.supports_local_storage())
			shj.sidebar = localStorage.shj_sidebar;
		else
			shj.sidebar = $.cookie('shj_sidebar');

		if (shj.sidebar!='open' && shj.sidebar!='close'){
			shj.sidebar='open';
			if (shj.supports_local_storage())
				localStorage.shj_sidebar = 'open';
			else
				$.cookie('shj_sidebar','open',{path:'/', expires: 365});
		}
		if (shj.sidebar=="open")
			shj.sidebar_open(0);
		else
			shj.sidebar_close(0);

		$("#shj_collapse").click(shj.toggle_collapse);

		shj.time = moment();
		shj.finish_time = moment("<?php echo $assignment['finish_time'] ?>");
		shj.extra_time = moment.duration(<?php echo $assignment['extra_time'] ?>, 'seconds');
		shj.update_clock();
		window.setInterval(shj.update_clock,1000);
	});
</script>

<div id="side_bar" class="sidebar_open">
	<ul>

		<li <?php echo ($selected=='dashboard'?'class="selected"':'') ?>><a href="<?php echo site_url('dashboard') ?>"><i class="splashy-home_green"></i><span class="sidebar_text">Dashboard</span></a></li>

		<?php if ($user_level==3): ?>
		<li <?php echo ($selected=='settings'?'class="selected"':'') ?>><a href="<?php echo site_url('settings') ?>"><i class="splashy-sprocket_light"></i><span class="sidebar_text">Settings</span></a></li>
		<?php endif ?>

		<?php if ($user_level==3): ?>
		<li <?php echo ($selected=='users'?'class="selected"':'') ?>><a href="<?php echo site_url('users') ?>"><i class="splashy-group_blue"></i><span class="sidebar_text">Users</span></a></li>
		<?php endif ?>

		<li <?php echo ($selected=='notifications'?'class="selected"':'') ?>><a href="<?php echo site_url('notifications') ?>"><i class="splashy-comment_reply"></i><span class="sidebar_text">Notifications</span></a></li>

		<li <?php echo ($selected=='assignments'?'class="selected"':'') ?>><a href="<?php echo site_url('assignments') ?>"><i class="splashy-quanitity_capsule_1"></i><span class="sidebar_text">Rounds</span></a></li>

                <li <?php echo ($selected=='problems'?'class="selected"':'') ?>><a href="<?php echo site_url('problems') ?>" Title="Display problems of current round"><i class="splashy-folder_modernist_opened_stuffed"></i><span class="sidebar_text">Problems</span></a></li>

		<li <?php echo ($selected=='submit'?'class="selected"':'') ?>><a href="<?php echo site_url('submit') ?>"><i class="splashy-arrow_large_up"></i><span class="sidebar_text">Submit</span></a></li>

		<li <?php echo ($selected=='final_submissions'?'class="selected"':'') ?>><a href="<?php echo site_url('submissions/final') ?>"><i class="splashy-marker_rounded_violet"></i><span class="sidebar_text">Final Submissions</span></a></li>

		<li <?php echo ($selected=='all_submissions'?'class="selected"':'') ?>><a href="<?php echo site_url('submissions/all') ?>"><i class="splashy-view_list_with_thumbnail"></i><span class="sidebar_text">All Submissions</span></a></li>

		<li <?php echo ($selected=='scoreboard'?'class="selected"':'') ?>><a href="<?php echo site_url('scoreboard') ?>"><i class="splashy-star_boxed_full"></i><span class="sidebar_text">Scoreboard</span></a></li>

		<li <?php echo ($selected=='contact_us'?'class="selected"':'') ?>><a href="<?php echo site_url('contact_us') ?>"><i class="splashy-contact_blue"></i><span class="sidebar_text">Contact Us</span></a></li>
	</ul>
	<div id="sidebar_bottom">
       		<!--<a target="_blank" href="http://mkti.in">
			<img src="<?php echo base_url('assets/images/mukti_logo.png'); ?>" width="100%" height="80%"/>
		</a>-->
       		<a target="_blank" href="http://letsintern.com">
			<img src="<?php echo base_url('assets/images/sponsor_logo.png'); ?>" width="100%"/>
		</a>

		<p>
			<a href="http://sharifjudge.ir" target="_blank">&copy; Sharif Judge <?php echo SHJ_VERSION ?></a>
		</p>
		<p class="timer"></p>
		<div id="shj_collapse" class="pointer">
			<i id="collapse" class="splashy-pagination_1_previous"></i><span class="sidebar_text">Collapse Menu</span>
		</div>
	</div>
</div>

