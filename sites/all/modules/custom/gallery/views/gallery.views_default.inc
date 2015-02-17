<?php
/**
 * Implements hook_views_default_views().
 */
function gallery_views_default_views() {
 
  $export[$view->name] = $view;
  return $export;
}
