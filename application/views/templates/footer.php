<?php
/**
 * Sharif Judge online judge
 * @file footer.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
//date_default_timezone_set('Asia/Kolkata');
defined('BASEPATH') OR exit('No direct script access allowed');
?>
<script>
	shj.check_for_notifications = false; // Set to true if you want to enable checking for new notifications
	shj.notif_check_time = null;
	shj.notif_check_delay = 30; //checks for new notifications every 30 seconds
	shj.check_notifs = function(){
		if (shj.notif_check_time==null)
			shj.notif_check_time = moment().add('milliseconds',shj.offset-(shj.notif_check_delay*1000));
		$.post("<?php echo site_url('notifications/check') ?>",
			{
				time: shj.notif_check_time.format('YYYY-MM-DD HH:mm:ss'),
				<?php echo $this->security->get_csrf_token_name() ?>: '<?php echo $this->security->get_csrf_hash() ?>'
			},
			function (data) {
				if (data=="new_notification"){
					noty({
						text: 'New Notification',
						layout: 'bottomRight',
						type: 'information',
						closeWith: ['click','button'],
						animation: {
							open: {height: 'toggle'},
							close: {height: 'toggle'},
							easing: 'swing',
							speed: 300
						}
					});
					alert("New Notification");
				}
			}
		);
		shj.notif_check_time = moment().add('milliseconds',shj.offset);
	}
	$(document).ready(function(){
		$('.scroll-wrapper').nanoScroller({
			contentClass: 'scroll-content'
		});
		$('#main_content').resize(function(){
			// update the scrollbar
			$('.scroll-wrapper').nanoScroller();
		});
		$('.widget_contents_container').resize(function(){
			// update the scrollbar
			$('.scroll-wrapper').nanoScroller();
		});
		if ( shj.check_for_notifications )
			window.setInterval(shj.check_notifs,(shj.notif_check_delay*1000));
	});
</script>
</body>
</html>
