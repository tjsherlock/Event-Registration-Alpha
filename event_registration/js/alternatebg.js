// $Id$
/**
* Hide blocks in sidebars, then make them visible at the click of a button.
*/
if (Drupal.jsEnabled) {
    $(document).ready(function() {
        // Get all div elements of class 'block' inside the left sidebar.
        // Add to that all div elements of class 'block' inside the
        // right sidebar.
        var blocks = $('div.stations div.form-item');

        //$('div.stations div.form-item')
       


        //blocks.removeClass("form-item");
        //blocks.addClass("form-item-even");
        //blocks.removeClass('form-item-odd');
        //blocks.addClass('form-item');


        $("div.stations div.form-item:even").css("background-color", "blanchedalmond");
        $("div.stations div.form-item:odd").css("background-color", "lemonchiffon");


        // Hide them.
        /*blocks.hide();
        // Add a button that, when clicked, will make them reappear.
        $('div.region-sidebar-first div.section').prepend('<div id="collapsibutton">Show Blocks</div>');
        $('#collapsibutton').css({
            'width': '90px',
            'border': 'solid',
            'border-width': '1px',
            'padding': '5px',
            'background-color': '#fff'
        });
        // Add a handler that runs once when the button is clicked.
        $('#collapsibutton').one('click', function() {
            // Button clicked! Get rid of the button.
            $('#collapsibutton').remove();
            // Display all our hidden blocks using an effect.
            blocks.slideDown("slow");
        });*/
    });
}


