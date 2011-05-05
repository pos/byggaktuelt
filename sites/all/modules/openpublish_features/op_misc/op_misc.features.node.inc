<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _op_misc_node_info() {
  $items = array(
    'feeditem' => array(
      'name' => t('Feed Item'),
      'module' => 'features',
      'description' => t('Feed Items are created automatically from Feeds.  Create a Feed and configure accordingly to import Feed Items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
