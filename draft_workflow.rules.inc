<?php
/**
 * @file
 * Rules integration for the Draft Workflow module.
 *
 * Rules is optional: this file is only loaded when Rules is enabled.
 */

/**
 * Implements hook_rules_event_info().
 */
function draft_workflow_rules_event_info() {
  return array(
    'draft_workflow_review_requested' => array(
      'label' => t('A draft is marked ready for review'),
      'group' => t('Draft Workflow'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Draft revision'),
        ),
        'requester' => array(
          'type' => 'user',
          'label' => t('Person who marked the draft ready for review'),
        ),
      ),
    ),
  );
}
