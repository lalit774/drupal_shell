<?php
/**
 * Implements hook_views_default_views().
 */
function gallery_views_default_views() {
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
    $handler = $gallery_view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Gallery';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '0';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'flexslider';
    $handler->display->display_options['style_options']['optionset'] = 'thumbnails';
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
    $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
    /* Field: Content: Image */
    $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
    $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
    $handler->display->display_options['fields']['field_image']['label'] = '';
    $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_image']['settings'] = array(
      'image_style' => 'flexslider_full',
      'image_link' => 'content',
    );
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
      'gallery' => 'gallery',
    );

    /* Display: Gallery */
    $handler = $gallery_view->new_display('block', 'Gallery', 'gallery');
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'flexslider';
    $handler->display->display_options['style_options']['optionset'] = 'gallery';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['block_description'] = 'gallery';

    $export[$gallery_view->name] = $gallery_view;
    return $export;
}
