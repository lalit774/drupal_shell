<?php
/**
 * Implements hook_flexslider_default_presets().
 */
function flexslider_custom_presets_flexslider_default_presets() {
    $export = array();

    $gallery_preset = new stdClass();
    $gallery_preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
    $gallery_preset->api_version = 1;
    $gallery_preset->name = 'gallery';
    $gallery_preset->title = 'Gallery';
    $gallery_preset->theme = 'classic';
    $gallery_preset->imagestyle_normal = 'flexslider_full';
    $gallery_preset->imagestyle_thumbnail = 'flexslider_thumbnail';
    $gallery_preset->options = array(
      'namespace' => 'flex-',
      'selector' => '.slides > li',
      'easing' => 'swing',
      'direction' => 'horizontal',
      'reverse' => 0,
      'smoothHeight' => 0,
      'startAt' => '0',
      'animationSpeed' => '600',
      'initDelay' => '0',
      'useCSS' => 1,
      'touch' => 1,
      'video' => 0,
      'keyboard' => 1,
      'multipleKeyboard' => 0,
      'mousewheel' => 0,
      'controlsContainer' => '.flex-control-nav-container',
      'sync' => '#flexslider-2',
      'asNavFor' => '',
      'itemWidth' => '0',
      'itemMargin' => '0',
      'minItems' => '0',
      'maxItems' => '0',
      'move' => '0',
      'animation' => 'fade',
      'slideshow' => 1,
      'slideshowSpeed' => '7000',
      'directionNav' => 1,
      'controlNav' => '1',
      'prevText' => 'Previous',
      'nextText' => 'Next',
      'pausePlay' => 0,
      'pauseText' => 'Pause',
      'playText' => 'Play',
      'randomize' => 0,
      'thumbCaptions' => 0,
      'thumbCaptionsBoth' => 0,
      'animationLoop' => 1,
      'pauseOnAction' => 1,
      'pauseOnHover' => 0,
      'manualControls' => '',
    );

    $export['gallery'] = $gallery_preset; 
    
    $thumbnails_preset = new stdClass();
    $thumbnails_preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
    $thumbnails_preset->api_version = 1;
    $thumbnails_preset->name = 'thumbnails';
    $thumbnails_preset->title = 'Thumbnails';
    $thumbnails_preset->theme = 'classic';
    $thumbnails_preset->imagestyle_normal = 'flexslider_full';
    $thumbnails_preset->imagestyle_thumbnail = 'flexslider_thumbnail';
    $thumbnails_preset->options = array(
      'namespace' => 'flex-',
      'selector' => '.slides > li',
      'easing' => 'swing',
      'direction' => 'horizontal',
      'reverse' => 0,
      'smoothHeight' => 0,
      'startAt' => '0',
      'animationSpeed' => '600',
      'initDelay' => '0',
      'useCSS' => 1,
      'touch' => 1,
      'video' => 0,
      'keyboard' => 1,
      'multipleKeyboard' => 0,
      'mousewheel' => 0,
      'controlsContainer' => '.flex-control-nav-container',
      'sync' => '',
      'asNavFor' => '',
      'itemWidth' => '250',
      'itemMargin' => '10',
      'minItems' => '4',
      'maxItems' => '4',
      'move' => '0',
      'animation' => 'fade',
      'slideshow' => 1,
      'slideshowSpeed' => '7000',
      'directionNav' => 1,
      'controlNav' => 'thumbnails',
      'prevText' => 'Previous',
      'nextText' => 'Next',
      'pausePlay' => 0,
      'pauseText' => 'Pause',
      'playText' => 'Play',
      'randomize' => 0,
      'thumbCaptions' => 0,
      'thumbCaptionsBoth' => 0,
      'animationLoop' => 1,
      'pauseOnAction' => 1,
      'pauseOnHover' => 0,
      'manualControls' => '',
    );
    $export['thumbnails'] = $thumbnails_preset;

    return $export;
}
