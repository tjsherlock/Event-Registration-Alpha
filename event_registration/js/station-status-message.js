// $Id$

/*
// Only run if we are in a supported browser.
if (Drupal.jsEnabled) {
  // Run the following code when the DOM has been fully loaded.
  $(document).ready(function () {
    // Attach some code to the click event for the
    // link with class "plusone-link".
    $('a.event-registration-link').click(function () {
      // When clicked, first define an anonymous function
      // to the variable voteSaved.
      var countRefreshed = function (data) {
        // Update the status.
        $('div.station-status-' + data.status).html(data.status);
        // Update the message.
        $('div.station-status-message').html(data.message);
      }
      // Make the AJAX call; if successful the
      // anonymous function in voteSaved is run.
      $.ajax({
        type: 'POST',       // Use the POST method.
        url: this.href,
        dataType: 'json',
        success: countRefreshed, 
        data: 'js=1'        // Pass a key/value pair.
      });
      // Prevent the browser from handling the click.
      return false;
    });
  });
}
*/

// Below is the rewritten code using Drupal.behaviors.



//Drupal.fbconnect = Drupal.fbconnect || {};
//Drupal.fbconnect.init = function () {
//  Drupal.behaviors.fbconnect = function(context) {
//  }


var StationCensus = StationCensus || {};
StationCensus.statusMessage = null;

/*StationCensus.cense = function() {
    
    Drupal.behaviors.StationCensus = function(context){
        
        setInterval(Drupal.StationCensus.periodicRefresh, 7000);
    }
}*/


Drupal.behaviors.station = function(context){
    
    //StationCensus.statusMessage = $('#station-status-message-1857', context);
    var j = 0;
    do{
        //setInterval(, 7000);
        //setInterval(, 7000);
        
        //for(k=0; k<=3000; k++){}
        
        StationCensus.periodicRefresh(context);
        
    }while(j<5);
        
        //setInterval(StationCensus.periodicRefresh(context), 7000);
        
        //clearInterval
}


StationCensus.periodicRefresh = function(context){
    
   
  // Run the following code when the DOM has been fully loaded.
 
    // Attach some code to the click event for the
    // link with class "plusone-link".
    $('a.event-registration-link').click(function () {
      // When clicked, first define an anonymous function
      // to the variable voteSaved.
      var countRefreshed = function (data) {
        // Update the status.
        $('div.station-status-' + data.status).html(data.status);
        // Update the message.
        $('div.station-status-message').html(data.message);
      }
      // Make the AJAX call; if successful the
      // anonymous function in voteSaved is run.
      $.ajax({
        type: 'POST',       // Use the POST method.
        url: this.href,
        dataType: 'json',
        success: countRefreshed, 
        data: 'js=1'        // Pass a key/value pair.
      });
      // Prevent the browser from handling the click.
      return false;
    });
  

    
    
    
    
    
    
    
}







/**
* Callback function to change show a new sticky.
*/
StationCensus.periodicRefresh = function (context) {
    //var statusMessageRefreshed = StatusCensus.statusMessage;
   //var statusMessageRefreshed = $('#station-status-message-1857', context);
   
   var spotsLeft  = $('.spots-left', context);
   
   spotsLeft.each(function(index){
       
       //alert(index + ': ' + $(this).text());
       
       
       
       //var count = $(this).text();
       var count = $(this).text();


       var newCount = new Number(count);

       //var newCount = parseInt(count);
       
       
       newCount++;
       
       //alert($(this).text());
       //alert($(this).text() + ':  ' + ++$newCount);
       
       /*if(isNAN(parseInt($(this).innerHtml))){
           var newCount = 1;
       }else{
           var newCount = ++$(this).innerHTML;
       }*/
       
        //var newCount = ++$(this).innerHTML;
        /*if ( !typeof newCount === "number" ) {
                newCount = 0;
        }*/
       
       //newCount = count + 1
       //alert('new count:  ' + newCount);
        $(this).html(newCount);
        
        //this.innerHMTL++;
   });
   
   
   //$('#spots-left-1857', context).html(' ' + count + 1);
   
   //if(isNaN(parseInt(statusMessageRefreshed))){
   //    statusMessageRefreshed = 0;
   //}
        
    //$('#station-status-message-1857', context).html(' ' + statusMessageRefreshed + 1);
}

//$(document).ready(Drupal.StationCensus.init);

/*Drupal.behaviors.StationCensus.init = function(context){
    
    $('#station-status-message-1857', context).html('Six and three occillate');
    setInterval(StationCensus.periodicRefresh, 7000);
}*/

/*Drupal.behaviors.event_registration = function (context) {
  $('a.event-registration-link:not(.event-registration-processed)', context)
  //$('a.event-registration-link', context)  
  .click(function () {
    var countRefreshed = function (data) {
        // Update the status.
        $('div#station-status-' + data.id + '.station-status-' + data.status).html(data.status);
        // Update the message.
        $('div.station-status-message').html(data.message);
        //edit-event-stations-1857
*/        
        /*$('div#edit-event-stations-' + data.id).keydown(function() {
            alert('Handler for .keydown() called.');
        });*/
        /*$('div#station-status-' + data.id).keydown(function() {
            alert('Handler for .keydown() called.');
        });*/
/*    }
    $.ajax({
      type: 'POST',
      url: this.href,
      dataType: 'json',
      success: countRefreshed,
      data: 'js=1'
    });
    return false;
  })
*/
  //.removeClass('event-registration-processed');
  //.addClass('event-registration-processed');
  
  /*.keydown(function() {
  alert('Handler for .keydown() called.')//;
  .addClass('event-registration-processed');
})*/

    

//}
