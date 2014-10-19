<!--
To change this template, choose Tools | Templates
and open the template in the editor.
-->
<!DOCTYPE html>
<script type='text/javascript'>
    $(document).ready(function() {
        console.log("HEllo");
        var data = {
            'submit_id': <?php echo $submit_id ?>,
            'problem_id': <?php echo $problem ?>,
            'username': '<?php echo $username ?>',
            <?php echo $this->security->get_csrf_token_name(); ?>: '<?php echo $this->security->get_csrf_hash(); ?>'
        };
        $('result').html("<img src=\"<?php echo base_url('assets/images/loading.gif') ?>\"/>");
        worker();
        function worker() {
            //console.log(data);
            $.ajax({
                type: "POST",
                url: '<?php echo site_url('submissions/status') ?>',
                data: data,
                success: function(data) {
                    data = JSON.parse(data);
                    if(data.status == "SCORE") {
                        $('#result').children().find('p').html('Your submission got ' + data.score + ' points. Go to all submissions for details.');
                        $('#result').children().find('img').remove();
                        $('#result').children().append('<div class="'+data.style_class+'" code="0">'+data.score+'</div>');
                    }
                    else if(data.status == "pending"){
                        console.log(data);
                        setTimeout(worker, 2000);
                        $('#result').children().find('p').html('<div class="'+data.style_class+'" code="0">'+data.status+'</div>');
                    }
                    else {
                        $('#result').children().html(' Go to all submissions for details.<br><div class="'+data.style_class+'"" code="0">'+data.status+'</div>');
                    }
                    if(data.status != "pending") {
                        setTimeout(function() {
                            window.location = "<?php echo site_url('submissions/all') ?>";
                        }, 3000);
                    }
                }
            });
        }
    });
</script>

<?php $this->view('templates/top_bar'); ?>
<?php $this->view('templates/side_bar', array('selected' => 'submit')); ?>

<div id="main-container">
    <div id="scroll-content">
        <div id="main-content">
            <div id="result">
                  <div style="text-align: center; margin-top: 100px">
                      <p>Running</p>
                      <br>
                      <img src="<?php echo base_url('assets/images/loading.gif') ?>"/>
                  </div>
            </div>
        </div>
    </div>
</div>
</head>