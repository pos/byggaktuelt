<?php

//$Id: openpublish_core.lib.inc,v 1.1.2.18 2010/07/28 19:19:37 tirdadc Exp $

/**
* @File a library of helper functions for openpublish_core/openpublish_theme
*/

/**
 * Sets the body-tag class attribute.
 *  
 * Adds 'sidebar-left', 'sidebar-right' or 'sidebars' classes depending on whether 
 * left column and/or right column content is empty. Allows designer to safely adjust
 * column widthes in each such case.
 *
 * @theme_function 
 *
 * @param $left
 *    The rendered content of the left region. Variable available in page-level templates
 * @param $right 
 *    The rendered content of the right region. Variable available in page-level templates 
 * @param $other_classes
 *    A string containing listing of other classes separated by a single space.
 */ 
function openpublish_body_classes($left, $right, $other_classes='') {
  
  if (!empty($left) && !empty($right)) {
    $class = 'sidebars';
  }
  else {
    if (!empty($left)) {
      $class = 'sidebar-left';
    }
    if (!empty($right)) {
      $class = 'sidebar-right';
    }
    if (empty($right) && empty($left)) {
      $class = 'no-sidebars';
    }    
  }
  
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $class .= ' node-view-page';
  }
  
  if (drupal_is_front_page()) {
    $class .= ' front-page';
  }
  
  // Please note: $class var can never be empty, so we don't have to check that condition.  
  $classes = (empty($other_classes)) ? $class : "$class $other_classes";

  return ' class="'. $classes .'"';

}

/**
 * Generates IE CSS link.
 */
function openpublish_get_ie_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/css/fix-ie.css" />';
  return $iecss;
}

/**
 * Generates IE 6-only CSS link.
 */
function openpublish_get_ie6_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/css/fix-ie6.css" />';
  return $iecss;
}

/**
* Render related terms links
*/
function openpublish_related_terms_links($taxonomy) {	
  if (empty($taxonomy) || !is_array($taxonomy)) {
    $taxonomy = array();
  }
  return theme('op_related_terms', $taxonomy);
}

/**
* AddThis widget
*/
function openpublish_addthis_widget($title='') {

  $addthis_link_title = $title;
  return theme('op_addthis_widget', $addthis_link_title);

}

/**
* template_preprocess_views_view_list Views hook implementation
*/
function openpublish_core_preprocess_views_view_list(&$vars) {
  openpublish_core_expose_display_title($vars);
}

/**
* template_preprocess_views_view_unformatted Views hook implementation
*/
function openpublish_core_preprocess_views_view_unformatted(&$vars) {
  openpublish_core_expose_display_title($vars);
}

/**
* Expose views display title and title_link as simple variables to row-level TPLs
*/
function openpublish_core_expose_display_title(&$vars) {
  $view = $vars['view'];
  
  openpublish_core_unset_view_titles_for_panel_views($vars);
    
  // If no title is set and this is a block display
  if (empty($vars['title']) && (strpos($view->current_display, 'block') !== FALSE)) {
    
    // Check for the overridden display title first
    $vars['title'] = $view->display[$view->current_display]->handler->options['title'];
    
    // If not there, use the default display title
    if (empty($vars['title'])) {
      $vars['title'] = $view->display['default']->display_options['title'];
    }
    
    // Determine which page this block links to and use it for the title
    $page_display_id = $view->display_handler->get_link_display();    
    if (!empty($page_display_id) && !empty($vars['title'])) {
      $vars['title_link'] = $view->display[$page_display_id]->display_options['path'];
      $vars['title'] = l($vars['title'], $vars['title_link']);
    }
  } 
   
}

/**
* Views blocks on Panel pages (e.g. topichubs) already have titles (coming from Panel panes)
* so we need to unset view titles to avoid duplicates or having to theme each and every view
* used in Panels.
*/
function openpublish_core_unset_view_titles_for_panel_views(&$vars) {

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    
    $openpublish_panel_that_zero_view_titles = variable_get('op_panel_pages_to_null_views_titles_on', array('author', 'topichub'));
    $openpublish_excl_views_names = variable_get('op_views_names_to_keep_views_titles_on_panels', array()); 
    
    if (in_array($node->type, $openpublish_panel_that_zero_view_titles) && 
        !in_array($vars['view']->name, $openpublish_excl_views_names)) {
      if (!empty($vars['view']->display[$view->current_display]->handler->options['title'])) {
        unset($vars['view']->display[$view->current_display]->handler->options['title']);        
      }
      else {
        unset($vars['view']->display['default']->display_options['title']);
      }
    }
  }
  
}

/**
 * Implementation of module_preprocess_views_view_fields
 */
function openpublish_core_preprocess_views_view_fields(&$variables) {
  $view = $variables['view'];
  
  $op_views = variable_get('openpublish_core_views', array('articles', 'blogs', 'events', 'multimedia', 'resources'));
  
  if (!in_array($view->name, $op_views)) return;
  
  // Image handling
  $image = $variables['fields']['field_thumbnail_image_fid'];
  if (!empty($image->content)) {
    // Use thumbnail
    $variables['fields'] = array('image' => $image) + $variables['fields'];
  }
  else {
    // Check if there's a main image we can use
    $image = $variables['fields']['field_main_image_fid'];
    if (!empty($image->content)) {
      
      $variables['fields'] = array('image' => $image) + $variables['fields'];
    }
    
  }
  // remove these to avoid duplicate images
  unset($variables['fields']['field_main_image_fid']);
  unset($variables['fields']['field_thumbnail_image_fid']);
  
  // Fixing some content types having "op_" prefix.
  if (!empty($variables['fields']['type']) && is_object($variables['fields']['type'])) {
    $variables['fields']['type']->content = t(str_ireplace("OP_" , "", $variables['fields']['type']->content));
    $variables['fields']['type']->raw = str_ireplace("OP_" , "", $variables['fields']['type']->raw);  
  }
  
  // Teaser handling  
  $teaser = $variables['fields']['field_teaser_value'];
  
  // strip_tags is used in case even left-over markup is still there after FCKeditor use
  $raw = strip_tags($teaser->raw);
  
  // If custom teaser field is filled use it, if not use Drupal's teaser thing;
  if (empty($raw)) {
    $variables['fields']['field_teaser_value']->content = $variables['fields']['teaser']->content;
  }
  unset($variables['fields']['teaser']);
}

/**
 * Implementation of hook_form_alter().
 */
function openpublish_core_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id != 'system_theme_settings') {
    return;  
  }
  
  $form['logo']['custom_logo_imagecache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Resize the custom logo with imagecache'),
    '#default_value' => 0,
    '#value' => variable_get('custom_logo_imagecache', 0),
    '#tree' => FALSE,
    '#description' => t('Check here if you want the custom logo to be resized
      using the <strong>custom_logo_upload</strong> imagecache preset'),
  );
  $form['#submit'][] = 'openpublish_core_theme_settings';
}

function openpublish_core_theme_settings($form, &$form_state) {
  
  $values = $form_state['values'];
  // Update checkbox value
  variable_set('custom_logo_imagecache', $values['custom_logo_imagecache']);
      
  // Use the Imagecache preset for custom uploads
  if ($values['custom_logo_imagecache'] && $values['logo_path']) {
    
    if (strpos($values['logo_path'], '/files/imagecache/') == FALSE) {
      // Flip the logo path in this theme's settings
      $new_logo_path = str_replace('/files/', '/files/imagecache/custom_logo_upload/', $values['logo_path']);
      $theme_settings = variable_get($values['var'], array());
      $theme_settings['logo_path'] = $new_logo_path;
      variable_set($values['var'], $theme_settings);
    }
    // Flush Imagecache preset
    imagecache_preset_flush(array('presetname' => 'custom_logo_upload'));
  }
}