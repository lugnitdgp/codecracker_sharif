<?php
/**
 * Sharif Judge online judge
 * @file register.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');
?>

<?php echo form_open('login/register') ?>
<div class="box register">

	<div class="judge_logo">
	    <a href="<?php echo site_url() ?>"><img src="<?php echo base_url("assets/images/lug_logo.png") ?>" width="80px" height="80px" style="float: left;"/><img src="<?php echo base_url("assets/images/cc_black.png") ?>" width="250px" height="90px" style="float: right;"/></a>
	</div>

	<div class="login_form">
		<div class="login1">
			<?php if ($registration_code_required): ?>
			<p>
				<label for="form_reg_code">Registration Code</label><br/>
				<input id="form_reg_code" type="text" name="registration_code" required="required" autofocus="autofocus" class="sharif_input" value="<?php echo set_value('registration_code'); ?>"/>
				<?php echo form_error('registration_code','<div class="shj_error">','</div>'); ?>
			</p>
			<?php endif ?>
			<p>
				<label for="form_username">Username</label><br/>
				<input id="form_username" type="text" name="username" required="required" pattern="[0-9A-Za-z]{3,20}" title="The Username field must be between 3 and 20 characters in length, and contain only alpha-numeric characters" class="sharif_input" value="<?php echo set_value('username'); ?>"/>
				<?php echo form_error('username','<div class="shj_error">','</div>'); ?>
			</p>
			<p>
				<label for="form_email">Email</label><br/>
				<input id="form_email" type="email" autocomplete="off" name="email" required="required" class="sharif_input" value="<?php echo set_value('email'); ?>"/>
				<?php echo form_error('email','<div class="shj_error">','</div>'); ?>
			</p>
			<p>
				<label for="form_password">Password</label><br/>
				<input id="form_password" type="password" name="password" required="required" pattern=".{6,200}" title="The Password field must be at least 6 characters in length" class="sharif_input"/>
				<?php echo form_error('password','<div class="shj_error">','</div>'); ?>
			</p>
			<p>
				<label for="form_password_2">Password, Again</label><br/>
				<input id="form_password_2" type="password" name="password_again" required="required" pattern=".{6,200}" title="The Password Confirmation field must be at least 6 characters in length" class="sharif_input"/>
				<?php echo form_error('password_again','<div class="shj_error">','</div>'); ?>
			</p>
		</div>
		<div class="login2">
			<p style="margin:0;">
				<?php echo anchor("login","Login") ?>
				<input type="submit" value="Register" id="sharif_submit"/>
			</p>
		</div>
	</div>

</div>
</form>
