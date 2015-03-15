<?php

function _install_rig_content_type() {
  field_cache_clear();
  node_types_rebuild(TRUE);
  
  _rig_content_type_create_rig_content_type();
   
  $instance = _rig_content_type_field_default_field_instances(); 
  if(!empty($instance)){
   foreach ($instance as $instance_field){
     field_create_instance($instance_field);
   }
  }
  
  // Set default settings.
  variable_set('node_options_rig' , array('status'));
  
}

function _rig_content_type_create_rig_content_type() {
  $rig_content_info = array(
      'type' => 'rig',
      'name' => t('Rig'),
      'base' => 'node_content',
      'description' => t('Rig content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
  );
  $rig_content_type = node_type_set_defaults($rig_content_info);
  node_type_save($rig_content_type); 
}


function _delete_rig_content_type($type){
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
function _rig_content_type_field_default_field_instances() {
  $field_instances = array();

 // Exported field_instance: 'node-rig-body'
  $field_instances['node-rig-body'] = array(
    'bundle' => 'rig',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-rig-field_depths_diameters_drilled'
  $field_instances['node-rig-field_depths_diameters_drilled'] = array(
    'bundle' => 'rig',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_depths_diameters_drilled',
    'label' => 'Depths & Diameters Drilled',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-rig-field_quantity'
  $field_instances['node-rig-field_quantity'] = array(
    'bundle' => 'rig',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_quantity',
    'label' => 'Quantity',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-rig-field_rig_category'
  $field_instances['node-rig-field_rig_category'] = array(
    'bundle' => 'rig',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_rig_category',
    'label' => 'Rig Category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Depths & Diameters Drilled');
  t('Description');
  t('Quantity');
  t('Rig Category');

  
  return $field_instances;
}