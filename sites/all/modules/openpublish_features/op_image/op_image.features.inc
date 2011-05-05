<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_image_content_default_fields() {
  module_load_include('inc', 'op_image', 'op_image.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_image_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_image_ctools_plugin_api() {
  module_load_include('inc', 'op_image', 'op_image.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_image_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_image_node_info() {
  module_load_include('inc', 'op_image', 'op_image.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_image_node_info', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_image_strongarm() {
  module_load_include('inc', 'op_image', 'op_image.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_image_strongarm', $args);
}
