/**
 * Sharif Judge
 * @file shj_functions.js
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */

// shj is Sharif Judge's namespace for js variable names
var shj = {};

// These words are used in countdown timer
shj.time_words = ['day', 'days', 'hour', 'hours', 'minute', 'minutes', 'second' , 'seconds'];

// selectText is used for "Select All" when viewing a submitted code
jQuery.fn.selectText = function(){
	var doc = document
		, element = this[0]
		, range, selection
		;
	if (doc.body.createTextRange) {
		range = document.body.createTextRange();
		range.moveToElementText(element);
		range.select();
	} else if (window.getSelection) {
		selection = window.getSelection();
		range = document.createRange();
		range.selectNodeContents(element);
		selection.removeAllRanges();
		selection.addRange(range);
	}
};

shj.supports_local_storage = function() {
	try {
		return 'localStorage' in window && window['localStorage'] !== null;
	} catch(e){
		return false;
	}
}

shj.update_clock = function(){
	if (Math.abs(moment().diff(shj.time))>3500){
		//console.log('moment: '+moment()+' time: '+time+' diff: '+Math.abs(moment().diff(time)));
		shj.sync_server_time();
	}
	shj.time = moment();
	var now = moment().add('milliseconds', shj.offset);
	$('.timer').html('Server Time: '+now.format('MMM DD - HH:mm:ss'));
	var countdown = shj.finish_time.diff(now);
	if (countdown<=0 && countdown + shj.extra_time.asMilliseconds()>=0){
		countdown = countdown + shj.extra_time.asMilliseconds();
		$("div#extra_time").css("display","block");
	}
	else
		$("div#extra_time").css("display","none");
	if (countdown<=0){
		countdown=0;
	}

	countdown = Math.floor(moment.duration(countdown).asSeconds());
	var seconds = countdown%60; countdown=(countdown-seconds)/60;
	var minutes = countdown%60; countdown=(countdown-minutes)/60;
	var hours = countdown%24; countdown=(countdown-hours)/24;
	var days = countdown;
	$("#time_days").html(days);
	$("#time_hours").html(hours);
	$("#time_minutes").html(minutes);
	$("#time_seconds").html(seconds);
	if(days==1)
		$("#days_label").html(shj.time_words[0]);
	else
		$("#days_label").html(shj.time_words[1]);
	if(hours==1)
		$("#hours_label").html(shj.time_words[2]);
	else
		$("#hours_label").html(shj.time_words[3])
	if(minutes==1)
		$("#minutes_label").html(shj.time_words[4]);
	else
		$("#minutes_label").html(shj.time_words[5]);
	if(seconds==1)
		$("#seconds_label").html(shj.time_words[6]);
	else
		$("#seconds_label").html(shj.time_words[7]);
}

shj.sidebar_open = function(time){
	if (time==0){
		$(".sidebar_text").css('display','inline-block');
		$("#sidebar_bottom p").css('display','block');
		$("#side_bar").css('width', '165px');
		$("#main_container").css('left','165px');
	}
	else{
		$("#side_bar").animate({width: '165px'},time,function(){$(".sidebar_text").css('display','inline-block');$("#sidebar_bottom p").css('display','block');});
		$("#main_container").animate({'left':'165px'},time*1.7);
	}
	$("i#collapse").removeClass("splashy-pagination_1_next");
	$("i#collapse").addClass("splashy-pagination_1_previous");
}

shj.sidebar_close = function(time){
	if (time==0){
		$(".sidebar_text").css('display','none');
		$("#sidebar_bottom p").css('display','none');
		$("#side_bar").css('width', '37px');
		$("#main_container").css('left','37px');
	}
	else{
		$("#side_bar").animate({width: '37px'},time,function(){$(".sidebar_text").css('display','none');$("#sidebar_bottom p").css('display','none');});
		$("#main_container").animate({'left':'37px'},time*1.7);
	}
	$("i#collapse").removeClass("splashy-pagination_1_previous");
	$("i#collapse").addClass("splashy-pagination_1_next");
}

shj.toggle_collapse = function(){
	if (shj.sidebar == "open"){
		shj.sidebar = "close";
		shj.sidebar_close(200);
		if (shj.supports_local_storage())
			localStorage.shj_sidebar = 'close';
		else
			$.cookie('shj_sidebar','close',{path:'/', expires: 365});
	}
	else if (shj.sidebar == "close"){
		shj.sidebar = "open";
		shj.sidebar_open(200);
		if (shj.supports_local_storage())
			localStorage.shj_sidebar = 'open';
		else
			$.cookie('shj_sidebar','open',{path:'/', expires: 365});
	}
}