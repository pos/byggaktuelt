<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function op_imce_config_ctools_plugin_api() {
  module_load_include('inc', 'op_imce_config', 'op_imce_config.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_imce_config_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function op_imce_config_strongarm() {
  module_load_include('inc', 'op_imce_config', 'op_imce_config.defaults');
  $args = func_get_args();
  return call_user_func_array('_op_imce_config_strongarm', $args);
}

/**
 * Helper to implementation of hook_enable().
 */
function _op_imce_config_enable() {

}

/**
 * Helper to implementation of hook_disable().
 */
function _op_imce_config_disable() {

}
