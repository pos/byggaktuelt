<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_event_content_default_fields() {
  module_load_include('inc', 'op_event', 'op_event.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_event_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_event_node_info() {
  module_load_include('inc', 'op_event', 'op_event.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_event_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_event_views_default_views() {
  module_load_include('inc', 'op_event', 'op_event.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_event_views_default_views', $args);
}
