<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _op_resource_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'module' => 'features',
      'description' => t('Resources are links, files, documents and other items of interest to readers. This content type is intended to provide a flexible mechanism for providing content that doesn\'t fit other content types, and can be differentiated from others via flexible categorization.'),
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
