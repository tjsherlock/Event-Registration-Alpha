<?php
// $Id$

/*
 * @file
 * Administration page call backs for the annotate module.
 */

/**
 * Form builder.  Configure annotations.
 *
 * @ingroup forms
 * @see system_settings_form().
 */

function event_registration_admin_settings(){

// Set Registration Event with taxonomy term?

// Check for stations  (content_type==station)
// If present, list
    $stations = array();
    $stations = get_stations(get_registration_event());
    //$stations = move_values_from_table_to_table();
    $stations_as_text = '';
     if(!empty($stations)){

        $stations_as_text = '';

        foreach($stations as $station){

            //$stations_as_text .= ', ' . $station['name'];
            $stations_as_text .= ', ' . $station['title'];//tjs 2012June14
        }

        //$stations_as_text = implode(',', get_stations());
     }
     else{
        $stations_as_text = 'No station exists for the current Registration Event.  Please <a href="/">add a Station</a>';
     }



    $form['registration_info'] = array(
        '#type' => 'fieldset',
        '#title' => t('Registration Information'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        //'#description' => t($stations_as_text),
   );

    $form['registration_info']['registration_event'] = array(
        '#type' => 'textfield',
        '#title' => 'Registration Event',
        '#default_value' => variable_get('registration_event', ''),
        '#description' => t('Enter the name of the event, e.g., Halloween Social.'),
        '#weight' => -10,
    );

    $form['registration_info']['registration_year']= array(
        '#type' => 'select',
        '#title' => t('Year'),
        '#options' => array(date('Y')-1 => date('Y')-1, date('Y') => date('Y'), date('Y')+1 => date('Y')+1),
        '#default_value' => variable_get('registration_year', date('Y')),
    );

    $form['registration_info']['markup'] = array(
          '#prefix' => '<div class="station-list">',
          '#suffix' => '</div>',
          '#value' => t($stations_as_text),
        );


    /**$form['registration_info']['stations'] = array(
        '#type' => 'textfield',
        '#title' => 'Stations',
        '#description' => t($stations_as_text),
        '#default_value' => t($stations_as_text),

    );*/

// Set Photo Gallery
// Create photo gallery view
// Add registration event as argument or filter?
// Check for photos    (taxonomy term)
// if photos, link to gallery

// further develop and test view tjs 2011Jan25


//photos/gallery/Halloween-Social/2010
//photos/gallery/%s/2010

// create taxonomy term and add to event gallery view
// use taxonomy_save_term


// To display volunteers and associated list of stations
// use views_get_views_result('view', 'display')
//     views_get_view('view')

// views/includes/plugins.inc

//backup and download files from lincolnschoolta.net




    /**$form['event_registration_node_types'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Users may select these stations'),
        '#options' => $options,
        //'#default_value' => variable_get('event_registration_node_types', array('page')),
        '#description' => t('The user will be added to the selected stations.'),

    );*/

    return system_settings_form($form);
}



/**
* Validate the annotation configuration form.
*/
function event_registration_admin_settings_validate($form, $form_state) {

}


function event_registration__admin_form_submit($form, &$form_state) {

$values = $form_state;

//db_query("UPDATE {blocks} SET status = %d, weight = %d, region = '%s', throttle = %d WHERE module = '%s' AND delta = '%s' AND theme = '%s'", $block['status'], $block['weight'], $block['region'], isset($block['throttle']) ? $block['throttle'] : 0, $block['module'], $block['delta'], $block['theme']);


}


function get_stations($event){

    //SELECT * FROM `station` WHERE 1


        //$query = "SELECT nid, name, event, spots, weight FROM {station} WHERE event = '%s' ORDER BY weight ASC";
        //$query = "SELECT nid, name, event, spots, weight FROM {event_station} WHERE event = '%s' ORDER BY weight ASC";
        $query = "SELECT nid, title, event, spots, weight FROM {event_station} WHERE event = '%s' ORDER BY weight ASC";
	//$query = 'SELECT nid, field_station_name_value AS name, field_station_description AS description FROM {content_type_station} ORDER BY field_station_weight_value ASC';
	//field_station_weight_value ASC
	$result = db_query($query, $event);

        $stations = array();
	while ($row = db_fetch_object($result)) {

                $stations[] = array(
                    //'name' => $row->name,
                	'title' => $row->title,
                    'nid' =>  $row->nid,
                    'event' => $row->event,
                    'spots' => $row->spots,
                    'weight' => $row->weight
                );

        }//while

        return $stations;
}


/*function get_registration_event(){


    return variable_get('registration_event', 'PTA Event');




}*/

function set_registration_event($event){

  variable_set('registration_event', $event);

}





function move_values_from_table_to_table() {
        $stations = array();





        $query = 'SELECT ';
        $query .= 'vid, nid, field_station_event_value, field_station_weight_value, field_station_description_value, ';
        $query .= 'field_station_name_value, field_station_spots_value, field_station_event_2_value ';
        $query .= 'FROM {content_type_station}';

        //$query = 'SELECT nid AS reg_id, field_hb_assignee_uid AS assignee FROM {content_type_station_reg} WHERE field_hb_assignee_uid  = \'%d\'';
    	//$query = 'SELECT nid, name, event FROM {station} ORDER BY weight ASC';

        $result = db_query($query);

    	while ($row = db_fetch_object($result)) {

            //db_query("INSERT INTO {content_field_hb_stations} (vid, nid, delta, field_hb_stations_value) VALUES (%d, %d, %d, %d)", $reg_id, $reg_id, $delta, $station);

            //$insert_query = "INSERT INTO {station} (nid, vid, event, description, name, spots, weight) ";
            //$insert_query .= "VALUES (%d, %d, %s, %s, %s, %s, %d)";

            //$values = "$row->nid, $row->vid, $row->field_station_event_2_value,$row->field_station_description_value, ";
            //$values .= "$row->field_station_name_value, $row->field_station_spots_value, $row->field_station_weight_value";

            //$action = (empty($_POST['action'])) ? 'default' : $_POST['action'];

            $insert_query = "INSERT INTO {station} (nid, vid, event, description, name, spots, weight) ";
            $insert_query .= "VALUES (%d, %d, '%s', '%s', '%s', '%s', %d)";


            //nid	vid	event	description	name	spots	weight

            $result2 = db_query($insert_query,
                                ((empty($row->nid))? 0 : $row->nid),
                                ((empty($row->vid))? 0 : $row->vid),
                                ((empty($row->field_station_event_2_value))? 'default'  : $row->field_station_event_2_value),
                                ((empty($row->field_station_description_value))? NULL : $row->field_station_description_value),
                                ((empty($row->field_station_name_value))? NULL : $row->field_station_name_value),
                                ((empty($row->field_station_spots_value))? NULL : $row->field_station_spots_value),
                                ((empty($row->field_station_weight_value))? 0 : $row->field_station_weight_value)
                               );

            $stations[] = array(
                'nid' =>  $row->nid,
                'vid' =>  $row->vid,
                'event' => $row->field_station_event_2_value,
                'description' => $row->field_station_description_value,
                'name' => $row->field_station_name_value,
                'spots' => $row->field_station_spots_value,
                'weight' => $row->field_station_weight_value,
            );



	}//while

        return $stations;
}





/*
 *
 * Simple function for MYSQL INSERT and UPDATE in Drupal custom modules
 *
 *
 */

/*
* $tablename to get all fields from this tablename
*/
function get_fields_from_table($tablename){
  $qry = db_query("SHOW COLUMNS FROM $tablename");
  while ($row = db_fetch_object($qry)) {
    $fields[] = $row->Field;
  }
  return $fields;
}
/*
* $values It should be a array, it contains key as field name
* $tablename pass the table where you want to insert
*/
function save_to_table($values,$tablename){
  if(count($values)){
    $transaction_fields = get_fields_from_table($tablename);
    foreach ($transaction_fields as $key) {
      if (isset($values[$key])) {
        $k[] = db_escape_string($key);
        $v[] = $values[$key];
        $s[] = "'%s'";
      }
    }
    if(count($k)){
      db_query('INSERT INTO {' . $tablename . '} (' . implode(', ', $k) . ') VALUES(' . implode(', ', $s) . ')', $v);
    }
  }
}
/*
* $values It should be a array, it contains key as field name
* $tablename pass the table where you want to insert
* $where_field where condition field name
* $idval value of thet filed
*/
function update_to_table($values,$tablename,$where_field,$idval){
  if(count($values)){
    $transaction_fields = get_fields_from_table($tablename);
    foreach ($transaction_fields as $key) {
      if (isset($values[$key]) && !empty($values[$key])) {
        $q[] = db_escape_string($key) ." = '%s'";
        $v[] = $values[$key];
      }
    }
    if (is_array($q) && is_array($v)) {
      db_query('UPDATE {' . $tablename . '} SET ' . implode(', ', $q) . " WHERE $where_field = '$idval'", $v);
    }
  }
}
//Example
/*
$values['field1']='pass the value of field';
$values['field2']='pass the value of field';
$values['field3']='pass the value of field';
save_to_table($values,'tablename');*/
