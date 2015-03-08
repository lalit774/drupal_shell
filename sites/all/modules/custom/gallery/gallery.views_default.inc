<?php
/**
 * Implements hook_views_default_views().
 */
function gallery_views_default_views() {
  $export = array();
  $path = drupal_get_path('module', 'gallery').'/views/'; 
  
  include_once($path. 'article_band.views.inc');
  $export[$article_band_view->name] = $article_band_view;
  
  include_once($path. 'article_feed.views.inc');
  $export[$article_feed_view->name] = $article_feed_view;  
  
  include_once($path. 'steve-paikin-blog.views.inc');
  $export[$view_steve_paikin_blog->name] = $view_steve_paikin_blog;
  
  include_once($path. 'documentaries_band.views.inc');
  $export[$ca_documentaries_view->name] = $ca_documentaries_view;
  
  return $export;
}
