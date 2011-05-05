<?php

$view = new view;
$view->name = 'feed_items';
$view->description = 'Show a listing of all feed items for a feed';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'timestamp' => array(
    'id' => 'timestamp',
    'table' => 'feedapi_node_item',
    'field' => 'timestamp',
  ),
  'item_title_url' => array(
    'id' => 'item_title_url',
    'table' => 'feedapi_node_item',
    'field' => 'item_title_url',
  ),
));
$handler->override_option('sorts', array(
  'created' => array(
    'order' => 'DESC',
    'granularity' => 'second',
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'sortorder' => 'desc',
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'feed_nid' => array(
    'default_action' => 'not found',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '%1',
    'default_argument_type' => 'fixed',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'feed_nid',
    'table' => 'feedapi_node_item_feed',
    'field' => 'feed_nid',
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'panel' => 0,
      'article' => 0,
      'audio' => 0,
      'event' => 0,
      'feed' => 0,
      'feeditem' => 0,
      'op_image' => 0,
      'package' => 0,
      'page' => 0,
      'resource' => 0,
      'topichub' => 0,
      'twitter_item' => 0,
      'video' => 0,
    ),
    'validate_argument_node_access' => 1,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(),
    'validate_argument_type' => 'tid',
    'validate_argument_php' => '',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
      '3' => 0,
      '5' => 0,
      '4' => 0,
      '6' => 0,
    ),
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'feeditem' => 'feeditem',
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
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('title', 'Feed items');
$handler->override_option('header_format', '1');
$handler->override_option('footer_format', '1');
$handler->override_option('empty', 'No feed items found.');
$handler->override_option('empty_format', '1');
$handler->override_option('use_pager', '1');
$handler->override_option('row_plugin', 'node');
$handler->override_option('row_options', array(
  'teaser' => 1,
  'links' => 1,
));
$handler = $view->new_display('page', 'Page', 'page');
$handler->override_option('path', 'feed-item');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
$handler = $view->new_display('block', 'Block', 'block_1');
$handler->override_option('fields', array(
  'timestamp' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'date_format' => 'custom',
    'custom_date_format' => 'F j, Y',
    'exclude' => 0,
    'id' => 'timestamp',
    'table' => 'feedapi_node_item',
    'field' => 'timestamp',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'url' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'display_url' => 'title',
    'exclude' => 0,
    'id' => 'url',
    'table' => 'feedapi_node_item',
    'field' => 'url',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
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
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'feeditem' => 'feeditem',
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
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('items_per_page', 5);
$handler->override_option('use_pager', '0');
$handler->override_option('use_more', 0);
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(),
  'separator' => '',
));
$handler->override_option('block_description', 'Feed Items');
$handler->override_option('block_caching', -1);
