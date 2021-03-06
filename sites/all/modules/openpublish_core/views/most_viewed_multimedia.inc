<?php

$view = new view;
$view->name = 'most_viewed_multimedia';
$view->description = 'Shows the most-viewed multimedia nodes. ';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'title' => array(
    'label' => '',
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'totalcount' => array(
    'id' => 'totalcount',
    'table' => 'node_counter',
    'field' => 'totalcount',
    'order' => 'DESC',
    'relationship' => 'none',
  ),
  'title' => array(
    'order' => 'ASC',
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'type' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'php',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '$arg0 = arg(0);
            if ($arg0 && !is_numeric($arg0) && $arg0 != \'topics\' && $arg0 != \'admin\')  {   
              return  rtrim($arg0, \'s\');
            }
            else return \'all\';',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'article' => 0,
      'event' => 0,
      'feed' => 0,
      'feeditem' => 0,
      'irakli' => 0,
      'multimedia' => 0,
      'page' => 0,
      'resource' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '42' => 0,
      '43' => 0,
      '44' => 0,
      '41' => 0,
      '45' => 0,
      '46' => 0,
      '47' => 0,
      '48' => 0,
      '49' => 0,
      '50' => 0,
      '51' => 0,
      '52' => 0,
      '53' => 0,
      '54' => 0,
      '55' => 0,
      '56' => 0,
      '57' => 0,
      '58' => 0,
      '59' => 0,
      '60' => 0,
      '61' => 0,
      '62' => 0,
      '63' => 0,
      '64' => 0,
      '65' => 0,
      '66' => 0,
      '67' => 0,
      '68' => 0,
      '69' => 0,
      '70' => 0,
      '71' => 0,
      '72' => 0,
      '73' => 0,
      '74' => 0,
      '75' => 0,
      '76' => 0,
      '77' => 0,
      '78' => 0,
      '79' => 0,
      '80' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
    'validate_argument_node_flag_name' => '*relationship*',
    'validate_argument_node_flag_test' => 'flaggable',
    'validate_argument_node_flag_id_type' => 'id',
    'validate_argument_user_flag_name' => '*relationship*',
    'validate_argument_user_flag_test' => 'flaggable',
    'validate_argument_user_flag_id_type' => 'id',
  ),
  'name' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'php',
    'default_argument' => '',
    'validate_type' => 'none',
    'validate_fail' => 'not found',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'none',
    'transform_dash' => 0,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '$arg0 = arg(0);
            $arg1 = arg(1);
            if ($arg0 == \'articles\' && $arg1)  { 
              return  $arg1;
            }
            else return \'all\';',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'article' => 0,
      'event' => 0,
      'feed' => 0,
      'feeditem' => 0,
      'irakli' => 0,
      'multimedia' => 0,
      'package' => 0,
      'page' => 0,
      'resource' => 0,
      'story' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '42' => 0,
      '43' => 0,
      '44' => 0,
      '41' => 0,
      '45' => 0,
      '46' => 0,
      '47' => 0,
      '48' => 0,
      '49' => 0,
      '50' => 0,
      '51' => 0,
      '52' => 0,
      '53' => 0,
      '54' => 0,
      '55' => 0,
      '56' => 0,
      '57' => 0,
      '58' => 0,
      '59' => 0,
      '60' => 0,
      '61' => 0,
      '62' => 0,
      '63' => 0,
      '64' => 0,
      '65' => 0,
      '66' => 0,
      '67' => 0,
      '68' => 0,
      '69' => 0,
      '70' => 0,
      '71' => 0,
      '72' => 0,
      '73' => 0,
      '74' => 0,
      '75' => 0,
      '76' => 0,
      '77' => 0,
      '78' => 0,
      '79' => 0,
      '80' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
    'validate_argument_node_flag_name' => '*relationship*',
    'validate_argument_node_flag_test' => 'flaggable',
    'validate_argument_node_flag_id_type' => 'id',
    'validate_argument_user_flag_name' => '*relationship*',
    'validate_argument_user_flag_test' => 'flaggable',
    'validate_argument_user_flag_id_type' => 'id',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'operator' => '=',
    'value' => '1',
    'group' => 0,
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
  ),
  'totalcount' => array(
    'id' => 'totalcount',
    'table' => 'node_counter',
    'field' => 'totalcount',
    'operator' => '>',
    'value' => array(
      'value' => '0',
      'min' => '',
      'max' => '',
    ),
    'group' => 0,
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'audio' => 'audio',
      'op_image' => 'op_image',
      'video' => 'video',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
  'role' => array(),
  'perm' => '',
));
$handler->override_option('title', 'Most Viewed Multimedia');
$handler->override_option('items_per_page', 5);
$handler->override_option('use_pager', '0');
$handler->override_option('use_more', 0);
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
));
$handler = $view->new_display('block', 'Most Viewed Multimedia', 'block');
$handler->override_option('fields', array(
  'title' => array(
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'label' => '',
    'link_to_node' => 1,
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array());
$handler->override_option('style_options', array(
  'type' => 'ul',
));
$handler->override_option('row_options', array(
  'inline' => array(
    'title' => 'title',
    'totalcount' => 'totalcount',
  ),
  'separator' => '',
));
$handler->override_option('block_description', 'Most Viewed Multimedia');
$handler->override_option('block_caching', -1);
