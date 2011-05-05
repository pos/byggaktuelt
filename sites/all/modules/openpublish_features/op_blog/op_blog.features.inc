<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_blog_content_default_fields() {
  module_load_include('inc', 'op_blog', 'op_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_blog_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_blog_ctools_plugin_api() {
  module_load_include('inc', 'op_blog', 'op_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_blog_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_noderelationships_default_settings().
 */
function op_blog_noderelationships_default_settings() {
  module_load_include('inc', 'op_blog', 'op_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_blog_noderelationships_default_settings', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_blog_strongarm() {
  module_load_include('inc', 'op_blog', 'op_blog.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_blog_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_blog_views_default_views() {
  module_load_include('inc', 'op_blog', 'op_blog.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_blog_views_default_views', $args);
}
