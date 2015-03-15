<?php
/**
 * Implements hook_views_default_views().
 */
function rig_views_default_views() {
  $export = array();
  $path = drupal_get_path('module', 'rig').'/views/'; 
  
  include_once($path. 'rig.views.inc');
  if(isset($rig_view)){
    $export[$rig_view->name] = $rig_view;
  }
  
  return $export;
}
