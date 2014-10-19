<?php
/**
 * Sharif Judge online judge
 * @file login.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

-<marquee style="font-size: 20px"> Monthly Codecracker Round 3 scheduled for 9:00 PM, 8th April '14. Till then, stay tuned and register if you are not registered. Refer to our <a target="_blank" href="https://www.facebook.com/CodeCracker.Mukti/">Facebook page</a> for updates!</marquee>
<!--<marquee style="font-size: 20px"> The Contest is on</marquee>-->
<?php echo form_open('login') ?>
	<div class="box login">

		<div class="judge_logo">
			<a href="<?php echo site_url() ?>"><img src="<?php echo base_url("assets/images/lug_logo.png") ?>" width="80px" height="80px" style="float: left;"/><img src="<?php echo base_url("assets/images/cc_black.png") ?>" width="250px" height="90px" style="float: right;"/></a>
		</div>

		<div class="login_form">
			<div class="login1">
				<p>
					<label for="form_username">Username</label><br/>
					<input id="form_username" type="text" name="username" required="required" pattern="[0-9A-Za-z]{3,20}" title="The Username field must be between 3 and 20 characters in length, and contain only alpha-numeric characters" class="sharif_input" value="<?php echo set_value('username'); ?>" autofocus="autofocus"/>
					<?php echo form_error('username','<div class="shj_error">','</div>'); ?>
				</p>
				<p>
					<label for="form_password">Password</label><br/>
					<input id="form_password" type="password" name="password" required="required" pattern=".{6,200}" title="The Password field must be at least 6 characters in length" class="sharif_input"/>
					<?php echo form_error('password','<div class="shj_error">','</div>'); ?>
				</p>
				<?php if ($error): ?>
					<div class="shj_error">Incorrect username or password.</div>
				<?php endif ?>
			</div>
			<div class="login2">
				<p style="margin:0;">
					<?php if ($this->settings_model->get_setting('enable_registration')): ?>
					<?php echo anchor("register","Register") ?> |
					<?php endif ?>
					<?php echo anchor('login/lost','Reset Password') ?>
					<input type="submit" value="Login" id="sharif_submit"/>
				</p>
			</div>
		</div>
                <img src="<?php echo base_url("assets/images/sponsor_logo.png") ?>" width="220px" height="110px" style="float: right;"/>

	</div>
</form>
