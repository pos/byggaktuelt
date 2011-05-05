<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function op_contexts_context_default_contexts() {
  module_load_include('inc', 'op_contexts', 'op_contexts.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_contexts_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_contexts_ctools_plugin_api() {
  module_load_include('inc', 'op_contexts', 'op_contexts.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_contexts_ctools_plugin_api', $args);
}
