<?php



function event_gallery_views_default_views() {

    $view = new view;
    $view->name = get_machine_name();//'Halloween_Social_2010';
    $view->description = 'Slide show for the ' . get_gallery_name();
    $view->tag = 'slide show';
    $view->base_table = 'node';
    $view->api_version = '2';
    $view->disabled = TRUE; //FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Defaults', 'default');
    $handler->display->display_options['use_ajax'] = TRUE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      2 => 2,
    );
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['distinct'] = TRUE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['style_plugin'] = 'slideshow';
    $handler->display->display_options['style_options']['grouping'] = 'field_photo_fid';
    $handler->display->display_options['style_options']['singleframe']['timeout'] = '5000';
    $handler->display->display_options['style_options']['singleframe']['speed'] = '700';
    $handler->display->display_options['style_options']['thumbnailhover']['timeout'] = '5000';
    $handler->display->display_options['style_options']['thumbnailhover']['speed'] = '300';
    $handler->display->display_options['style_options']['thumbnailhover']['teasers_last'] = 1;
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Field: Node: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
    $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['title']['alter']['html'] = 0;
    $handler->display->display_options['fields']['title']['hide_empty'] = 1;
    $handler->display->display_options['fields']['title']['empty_zero'] = 0;
    $handler->display->display_options['fields']['title']['link_to_node'] = 0;
    /* Field: Content: Photo (field_photo) */
    $handler->display->display_options['fields']['field_photo_fid']['id'] = 'field_photo_fid';
    $handler->display->display_options['fields']['field_photo_fid']['table'] = 'node_data_field_photo';
    $handler->display->display_options['fields']['field_photo_fid']['field'] = 'field_photo_fid';
    $handler->display->display_options['fields']['field_photo_fid']['alter']['alter_text'] = 1;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['text'] = '<span align="center">[field_photo_fid]</span>';
    $handler->display->display_options['fields']['field_photo_fid']['alter']['make_link'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['alter']['html'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['hide_empty'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['empty_zero'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['link_to_node'] = 0;
    $handler->display->display_options['fields']['field_photo_fid']['label_type'] = 'none';
    $handler->display->display_options['fields']['field_photo_fid']['format'] = '720-wide_linked';
    /* Filter: Node: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = '1';
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter: Node: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'photo' => 'photo',
    );
    $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
    /* Filter: Taxonomy: Term */
    $handler->display->display_options['filters']['tid']['id'] = 'tid';
    $handler->display->display_options['filters']['tid']['table'] = 'term_node';
    $handler->display->display_options['filters']['tid']['field'] = 'tid';

    //Needs to be dynamic tjs 2011Jan25
    $handler->display->display_options['filters']['tid']['value'] = array(
      //0 => '478',
      //1 => '479',
      0 => get_term_id(get_gallery_name()),
    );
    $handler->display->display_options['filters']['tid']['expose']['operator'] = FALSE;
    $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
    $handler->display->display_options['filters']['tid']['vid'] = TAGS;

    /* Display: Halloween Social 2010 */
    $handler = $view->new_display('page', get_gallery_name(), 'page_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'The ' . get_gallery_name();
    $handler->display->display_options['defaults']['items_per_page'] = FALSE;
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      2 => 2,
      19 => 19,
    );
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'slideshow';
    $handler->display->display_options['style_options']['singleframe']['timeout'] = '5000';
    $handler->display->display_options['style_options']['singleframe']['speed'] = '700';
    $handler->display->display_options['style_options']['thumbnailhover']['timeout'] = '5000';
    $handler->display->display_options['style_options']['thumbnailhover']['speed'] = '300';
    $handler->display->display_options['style_options']['thumbnailhover']['teasers_last'] = 1;
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['path'] = get_gallery_path();
    $handler->display->display_options['menu']['type'] = 'normal';
    $handler->display->display_options['menu']['title'] = get_gallery_name();
    $handler->display->display_options['menu']['weight'] = '0';
    $handler->display->display_options['menu']['name'] = 'menu-special-links';

    /* Display: Block */
    $handler = $view->new_display('block', 'Block', 'block_1');
    $handler->display->display_options['block_description'] = 'Slideshow of ' . get_gallery_name();

    /* Display: Attachment */
    $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'role';
    $handler->display->display_options['access']['role'] = array(
      22 => 22,
    );// role should be selected on admin page.  tjs 2011Jan26
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = 1;
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Global: Custom text */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="add-button">Add photo</div>';
    $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 1;
    $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/photo';
    $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
    $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
    $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
    $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
    $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
    $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
    $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    $handler->display->display_options['render_pager'] = TRUE;
    $handler->display->display_options['displays'] = array(
      'page_1' => 'page_1',
      'default' => 0,
      'block_1' => 0,
    );
    $translatables[get_machine_name()] = array(
      t('Defaults'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort By'),
      t('Asc'),
      t('Desc'),
      t('Items per page'),
      t('Offset'),
      t('<span align="center">[field_photo_fid]</span>'),
      t(get_gallery_name()),
      t('The ' . get_gallery_name()),
      t('Block'),
      t('Slideshow of Murals'),
      t('Attachment'),
      t('<div class="add-button">Add photo</div>'),
      t('node/add/photo'),
    );

    $views[$view->name] = $view;
    return $views;
}


//function get_event_gallery_name(){


/**function get_gallery_name(){

    $space = ' ';
     $event = variable_get('registration_event', 'PTA Event Photo Gallery');
     $year = variable_get("event_year", date('Y'));

     $gallery_name = $event . $space . $year;

     return $gallery_name;

}*/




