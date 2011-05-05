<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_defaults_ctools_plugin_api() {
  module_load_include('inc', 'op_defaults', 'op_defaults.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_defaults_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function op_defaults_imagecache_default_presets() {
  module_load_include('inc', 'op_defaults', 'op_defaults.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_defaults_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function op_defaults_user_default_permissions() {
  module_load_include('inc', 'op_defaults', 'op_defaults.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_defaults_user_default_permissions', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_defaults_strongarm() {
  module_load_include('inc', 'op_defaults', 'op_defaults.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_defaults_strongarm', $args);
}
