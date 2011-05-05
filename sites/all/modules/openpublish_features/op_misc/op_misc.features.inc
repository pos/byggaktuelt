<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_misc_content_default_fields() {
  module_load_include('inc', 'op_misc', 'op_misc.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_misc_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_misc_ctools_plugin_api() {
  module_load_include('inc', 'op_misc', 'op_misc.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_misc_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_misc_node_info() {
  module_load_include('inc', 'op_misc', 'op_misc.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_misc_node_info', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_misc_strongarm() {
  module_load_include('inc', 'op_misc', 'op_misc.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_misc_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_misc_views_default_views() {
  module_load_include('inc', 'op_misc', 'op_misc.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_misc_views_default_views', $args);
}
