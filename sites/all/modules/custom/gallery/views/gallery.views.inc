<?php

$gallery_view = new view();
$gallery_view->name = 'gallery';
$gallery_view->description = '';
$gallery_view->tag = 'default';
$gallery_view->base_table = 'node';
$gallery_view->human_name = 'Gallery';
$gallery_view->core = 7;
$gallery_view->api_version = '3.0';
$gallery_view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$gallery_view_handler = $gallery_view->new_display('default', 'Master', 'default');
$gallery_view_handler->display->display_options['title'] = 'Gallery';
$gallery_view_handler->display->display_options['use_more_always'] = FALSE;
$gallery_view_handler->display->display_options['access']['type'] = 'perm';
$gallery_view_handler->display->display_options['cache']['type'] = 'none';
$gallery_view_handler->display->display_options['query']['type'] = 'views_query';
$gallery_view_handler->display->display_options['exposed_form']['type'] = 'basic';
$gallery_view_handler->display->display_options['pager']['type'] = 'some';
$gallery_view_handler->display->display_options['pager']['options']['items_per_page'] = '0';
$gallery_view_handler->display->display_options['pager']['options']['offset'] = '0';
$gallery_view_handler->display->display_options['style_plugin'] = 'flexslider';
$gallery_view_handler->display->display_options['style_options']['optionset'] = 'thumbnails';
$gallery_view_handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Title */
$gallery_view_handler->display->display_options['fields']['title']['id'] = 'title';
$gallery_view_handler->display->display_options['fields']['title']['table'] = 'node';
$gallery_view_handler->display->display_options['fields']['title']['field'] = 'title';
$gallery_view_handler->display->display_options['fields']['title']['label'] = '';
$gallery_view_handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$gallery_view_handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Image */
$gallery_view_handler->display->display_options['fields']['field_image']['id'] = 'field_image';
$gallery_view_handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
$gallery_view_handler->display->display_options['fields']['field_image']['field'] = 'field_image';
$gallery_view_handler->display->display_options['fields']['field_image']['label'] = '';
$gallery_view_handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
$gallery_view_handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
$gallery_view_handler->display->display_options['fields']['field_image']['settings'] = array(
  'image_style' => 'flexslider_full',
  'image_link' => 'content',
);
/* Sort criterion: Content: Post date */
$gallery_view_handler->display->display_options['sorts']['created']['id'] = 'created';
$gallery_view_handler->display->display_options['sorts']['created']['table'] = 'node';
$gallery_view_handler->display->display_options['sorts']['created']['field'] = 'created';
$gallery_view_handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$gallery_view_handler->display->display_options['filters']['status']['id'] = 'status';
$gallery_view_handler->display->display_options['filters']['status']['table'] = 'node';
$gallery_view_handler->display->display_options['filters']['status']['field'] = 'status';
$gallery_view_handler->display->display_options['filters']['status']['value'] = 1;
$gallery_view_handler->display->display_options['filters']['status']['group'] = 1;
$gallery_view_handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$gallery_view_handler->display->display_options['filters']['type']['id'] = 'type';
$gallery_view_handler->display->display_options['filters']['type']['table'] = 'node';
$gallery_view_handler->display->display_options['filters']['type']['field'] = 'type';
$gallery_view_handler->display->display_options['filters']['type']['value'] = array(
  'gallery' => 'gallery',
);

/* Display: Gallery */
$gallery_view_handler = $gallery_view->new_display('block', 'Gallery', 'gallery');
$gallery_view_handler->display->display_options['defaults']['style_plugin'] = FALSE;
$gallery_view_handler->display->display_options['style_plugin'] = 'flexslider';
$gallery_view_handler->display->display_options['style_options']['optionset'] = 'gallery';
$gallery_view_handler->display->display_options['defaults']['style_options'] = FALSE;
$gallery_view_handler->display->display_options['defaults']['row_plugin'] = FALSE;
$gallery_view_handler->display->display_options['row_plugin'] = 'fields';
$gallery_view_handler->display->display_options['defaults']['row_options'] = FALSE;
$gallery_view_handler->display->display_options['block_description'] = 'gallery';