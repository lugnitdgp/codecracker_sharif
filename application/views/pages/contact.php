<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('selected' => 'contact_us')); ?>
<?php $now = shj_now(); ?>

<link rel='stylesheet' type='text/css' href='<?php echo base_url("assets/styles/contact.css") ?>'/>


<div id="main_container" class="scroll-wrapper">
    <div class="scroll-content">

        <div id="page_title">
            <img src="<?php echo base_url('assets/images/icons/submit.png') ?>"/>
            <span><?php echo $title ?></span>
        </div>
        <div id="contact_big">
            <h3>For updates, tune to our <a target="_blank" href="https://www.facebook.com/CodeCracker.Mukti">Facebook page</a>!</h3>
            <div id="contact">
                <a target="_blank" href="https://www.facebook.com/anuj.prajapati2" class="contactName"><b>Anuj Prajapati</b></a>
                <p><a target="_blank" href="mailto:anuj@mkti.in" class="contactEmail">&nbsp;&nbsp;anuj@mkti.in&nbsp;&nbsp;</a></p>
                <p>+91 8927 05 2427<p>
            </div>
            <div id="contact">
                <a target="_blank" href="https://www.facebook.com/sahashouvik" class="contactName"><b>Shouvik Saha</b></a>
                <p><a target="_blank" href="mailto:shouvik@mkti.in" class="contactEmail">&nbsp;&nbsp;shouvik@mkti.in&nbsp;&nbsp;</a></p>
                <p>+91 9038 4444 75 <p>
            </div>
        </div>
    </div>
