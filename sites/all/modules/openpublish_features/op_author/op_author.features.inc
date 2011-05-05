<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_author_content_default_fields() {
  module_load_include('inc', 'op_author', 'op_author.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_author_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_author_ctools_plugin_api() {
  module_load_include('inc', 'op_author', 'op_author.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_author_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function op_author_imagecache_default_presets() {
  module_load_include('inc', 'op_author', 'op_author.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_author_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_author_node_info() {
  module_load_include('inc', 'op_author', 'op_author.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_author_node_info', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_author_strongarm() {
  module_load_include('inc', 'op_author', 'op_author.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_author_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_author_views_default_views() {
  module_load_include('inc', 'op_author', 'op_author.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_author_views_default_views', $args);
}
