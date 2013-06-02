// $Id$


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
        
          //var spotsLeft  = $('.spots-left', context);
          //id="spots-left-1831"
          
          //var spotsLeft  = $('.spots-left #spots-left-' + data.id);
          var spotsLeft  = $('#spots-left-' + data.id);
          spotsLeft.html(data.message + ' refreshed');
          // Update the status.
          //$('div.station-status-' + data.status).html(data.status);
          // Update the message.
          //$('div.station-status-message').html(data.message);
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


// Below is the rewritten code using Drupal.behaviors.



