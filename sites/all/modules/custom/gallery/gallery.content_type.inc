<?php

function _install_gallery_content_type() {
  field_cache_clear();
  node_types_rebuild(TRUE);
  
  _gallery_content_type_gallery_content_type();
   
  $instance = _gallery_content_type_field_default_field_instances(); 
  if(!empty($instance)){
   foreach ($instance as $instance_field){
     field_create_instance($instance_field);
   }
  }
  
  // Set default settings.
  variable_set('node_options_gallery' , array('status'));
  
}

function _gallery_content_type_create_gallery_content_type() {
  $gallery_content_info = array(
      'type' => 'gallery',
      'name' => t('Gallery'),
      'base' => 'node_content',
      'description' => t('Gallery content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
  );
  $gallery_content_type = node_type_set_defaults($gallery_content_info);
  node_type_save($gallery_content_type); 
}


function _delete_gallery_content_type($type){
  $results = db_select('node', 'n')
            ->fields('n', array('nid'))
            ->condition('type', $type, '=')
            ->execute();
  foreach ($results as $result) {
    $nids[] = $result->nid;
  }
  if (!empty($nids)) {
    node_delete_multiple($nids);
  }
  
  $types = node_type_get_types();
  if(isset($types[$type])){
    $instances = field_info_instances('node', $type);
    foreach ($instances as $instance_name => $instance) {
      field_delete_instance($instance);
    }
    node_type_delete($type);
    field_purge_batch(1000);
    node_types_rebuild(TRUE);
    menu_rebuild();
  }
}

/**
 * Implements hook_field_default_field_instances().
 */
function _gallery_content_type_field_default_field_instances() {
  $field_instances = array();

 // Exported field_instance: 'node-gallery-field_image'
  $field_instances['node-gallery-field_image'] = array(
    'bundle' => 'gallery',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => -4,
    ),
  );
  
  // Exported field_instance: 'node-gallery-field_display_area'
  $field_instances['node-gallery-field_display_area'] = array(
    'bundle' => 'gallery',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_display_area',
    'label' => 'Display Area',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );


  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Display Area');
  
  return $field_instances;
}