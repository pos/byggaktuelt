<?php
// $Id: router.inc,v 1.1.2.5 2010/07/09 21:36:33 tirdadc Exp $


// Include RDFa utility functions
include_once('rdfa.lib.inc');

/**
 * Implementation of hook_preprocess.
 */
function openpublish_core_preprocess(&$vars, $hook) {  
  
  if ($hook == 'page' && _is_openpublish_theme()) {
    
    //-- copy into new array to avoid passing by reference.
    $pagevars = $vars;
    $vars['page_header'] = theme('page_header', $pagevars);
    $vars['page_footer'] = theme('page_footer', $pagevars);    
    return;
  }
  
  openpublish_core_suggest_preprocessor($vars, $hook);
}


/**
* Determines if a theme is an OP-"compatible" one. OpenPublish Theme itself and any sub-themes are all considered compatible.
*
* @param $tkey
*    theme_key of the theme being checked. Defaults to current theme.
*/
function _is_openpublish_theme($tkey = NULL) {
  global $theme_key;
  
  if (empty($tkey)) {
    $tkey = $theme_key;
  }
  
  if ($tkey == 'openpublish_theme') {
    return TRUE;
  }
  
  $theme_infos = list_themes();
  
  if (!empty($theme_infos[$tkey]->base_theme)) {
    return _is_openpublish_theme($theme_infos[$tkey]->base_theme);
  }
  else {
    return FALSE;
  }  
}

/**
 * Checks for preprocessor files based on node type and includes them if available.
 */
function openpublish_core_suggest_preprocessor(&$vars, $hook) {

  if ($hook == 'page_header' || $hook == 'page_footer') {
    unset($vars['page_vars']['template_files']);    
    if (is_array($vars['page_vars'])) {
      foreach ($vars['page_vars'] as $var_key => $var_value) {
        $vars[$var_key] = $var_value;
      }
    }
    return;    
  }
  
  
  
  if (!empty($vars['type']) && $hook == 'node') { 
    $inc_file = dirname(__FILE__) . '/node-' . $vars['type'] . '.tpl.inc';
    $func_name = 'openpublish_node_' . $vars['type'] . '_preprocess';
      
    if (file_exists($inc_file)) {
      require_once($inc_file);
      if (function_exists($func_name)) {
        $func_name($vars);
      }
    }
  }
    
}