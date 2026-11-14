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

  $data['node']['draft_workflow_latest_revision_log'] = array(
    'title' => t('Latest draft revision log'),
    'help' => t('The log message from the most recent draft revision (newer than the current active revision).'),
    'field' => array(
      'handler' => 'draft_workflow_handler_field_latest_revision_log',
      'label' => t('Latest draft note'),
    ),
  );

  $data['node']['draft_workflow_ready_for_review'] = array(
    'title' => t('Has a draft ready for review'),
    'help' => t('Whether the content has a draft revision, newer than the current revision, that is marked ready for review.'),
    'field' => array(
      'handler' => 'draft_workflow_handler_field_ready_for_review',
      'label' => t('Ready for review'),
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'draft_workflow_handler_filter_ready_for_review',
      'label' => t('Has a draft ready for review'),
      'type' => 'yes-no',
    ),
  );

  return $data;
}
