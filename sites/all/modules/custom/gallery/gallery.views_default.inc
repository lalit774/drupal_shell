<?php
/**
 * Implements hook_views_default_views().
 */
function gallery_views_default_views() {
  $export = array();
  $path = drupal_get_path('module', 'gallery').'/views/'; 
  
  include_once($path. 'gallery.views.inc');
  if(isset($gallery_view)){
    $export[$gallery_view->name] = $gallery_view;
  }
  
  return $export;
}
