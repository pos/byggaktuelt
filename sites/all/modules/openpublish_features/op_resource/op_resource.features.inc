<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_resource_content_default_fields() {
  module_load_include('inc', 'op_resource', 'op_resource.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_resource_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_resource_ctools_plugin_api() {
  module_load_include('inc', 'op_resource', 'op_resource.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_resource_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_resource_node_info() {
  module_load_include('inc', 'op_resource', 'op_resource.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_resource_node_info', $args);
}

/**
 * Implementation of hook_noderelationships_default_settings().
 */
function op_resource_noderelationships_default_settings() {
  module_load_include('inc', 'op_resource', 'op_resource.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_resource_noderelationships_default_settings', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_resource_strongarm() {
  module_load_include('inc', 'op_resource', 'op_resource.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_resource_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_resource_views_default_views() {
  module_load_include('inc', 'op_resource', 'op_resource.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_resource_views_default_views', $args);
}
