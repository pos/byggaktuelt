<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_package_content_default_fields() {
  module_load_include('inc', 'op_package', 'op_package.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_package_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_package_ctools_plugin_api() {
  module_load_include('inc', 'op_package', 'op_package.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_package_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_package_node_info() {
  module_load_include('inc', 'op_package', 'op_package.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_package_node_info', $args);
}

/**
 * Implementation of hook_noderelationships_default_settings().
 */
function op_package_noderelationships_default_settings() {
  module_load_include('inc', 'op_package', 'op_package.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_package_noderelationships_default_settings', $args);
}
