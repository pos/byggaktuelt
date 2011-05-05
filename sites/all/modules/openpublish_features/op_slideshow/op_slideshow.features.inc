<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_slideshow_content_default_fields() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_slideshow_ctools_plugin_api() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function op_slideshow_imagecache_default_presets() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_slideshow_node_info() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_node_info', $args);
}

/**
 * Implementation of hook_noderelationships_default_settings().
 */
function op_slideshow_noderelationships_default_settings() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_noderelationships_default_settings', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_slideshow_strongarm() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_slideshow_views_default_views() {
  module_load_include('inc', 'op_slideshow', 'op_slideshow.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_slideshow_views_default_views', $args);
}
