<?php

/**
 * Implementation of hook_content_default_fields().
 */
function op_article_content_default_fields() {
  module_load_include('inc', 'op_article', 'op_article.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_article_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_article_ctools_plugin_api() {
  module_load_include('inc', 'op_article', 'op_article.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_article_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function op_article_node_info() {
  module_load_include('inc', 'op_article', 'op_article.features.node');
  $args = func_get_args();
  return call_user_func_array('_op_article_node_info', $args);
}

/**
 * Implementation of hook_noderelationships_default_settings().
 */
function op_article_noderelationships_default_settings() {
  module_load_include('inc', 'op_article', 'op_article.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_article_noderelationships_default_settings', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_article_strongarm() {
  module_load_include('inc', 'op_article', 'op_article.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_article_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function op_article_views_default_views() {
  module_load_include('inc', 'op_article', 'op_article.features.views');
  $args = func_get_args();
  return call_user_func_array('_op_article_views_default_views', $args);
}
