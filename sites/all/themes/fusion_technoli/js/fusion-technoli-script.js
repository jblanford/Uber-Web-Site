// $Id: fusion-technoli-script.js 7154 2010-04-24 16:42:29Z chris $

Drupal.behaviors.fusion_technoliFirstWord = function (context) {
  $('#site-name a').each(function(){
      var bt = $(this);
      bt.html( bt.text().replace(/(^\w+)/,'<span class="first-word">$1</span>') );
  });
  $('#comments .box h2.title').each(function(){
      var bt = $(this);
      bt.html( bt.text().replace(/(^\w+)/,'<span class="first-word">$1</span>') );
  });
};

Drupal.behaviors.fusion_technoliRoundedCorners = function (context) {
  $(".terms").corner("5px");
  $(".blockquote").corner("5px");

  // Header - Rounded corners - Top
  // This is called twice so the background color doesn't get overwritten (cc:#0F70B2)
  $("#header .rounded-corners-top .inner").corner("top 10px");
  $("#header .rounded-corners-right .inner").corner("tr br 10px");
  $("#header .rounded-corners-bottom .inner").corner("bottom 10px");
  $("#header .rounded-corners-left .inner").corner("tl bl 10px");
  $("#header .rounded-corners-all .inner").corner("10px");

  // Rounded corners
  $(".rounded-corners-all .inner").corner("10px");
  $(".rounded-corners-top .inner").corner("top 10px");
  $(".rounded-corners-right .inner").corner("tr br 10px");
  $(".rounded-corners-bottom .inner").corner("bottom 10px");
  $(".rounded-corners-left .inner").corner("tl bl 10px");

  // Header - Rounded corners - Bottom
  // This is called twice so the background color doesn't get overwritten (cc:#0F70B2)
  $("#header .rounded-corners-top .inner").corner("top 10px");
  $("#header .rounded-corners-right .inner").corner("tr br 10px");
  $("#header .rounded-corners-bottom .inner").corner("bottom 10px");
  $("#header .rounded-corners-left .inner").corner("tl bl 10px");
  $("#header .rounded-corners-all .inner").corner("10px");
};
