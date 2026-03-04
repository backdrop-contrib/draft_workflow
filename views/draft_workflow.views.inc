<?php
/**
 * @file
 * Views integration for the Draft Workflow module.
 */

/**
 * Implements hook_views_data().
 */
function draft_workflow_views_data() {
  $data = array();

  $data['node']['draft_workflow_forward_revisions'] = array(
    'title' => t('Has forward revisions'),
    'help' => t('Filter nodes based on whether they have revisions newer than the current active revision.'),
    'filter' => array(
      'handler' => 'draft_workflow_handler_filter_forward_revisions',
      'label' => t('Has forward revisions'),
      'type' => 'yes-no',
    ),
  );

  return $data;
}
