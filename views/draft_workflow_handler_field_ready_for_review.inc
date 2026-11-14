<?php
/**
 * @file
 * Definition of draft_workflow_handler_field_ready_for_review.
 */

/**
 * Field handler that shows "Ready for review" when the content has a draft,
 * newer than the current revision, that is marked ready for review.
 *
 * @ingroup views_field_handlers
 */
class draft_workflow_handler_field_ready_for_review extends views_handler_field {

  function query() {
    $formula = '(SELECT COUNT(*) FROM {draft_workflow_review} dwr WHERE dwr.nid = node.nid AND dwr.vid > node.vid)';
    $this->field_alias = $this->query->add_field(NULL, $formula, 'draft_workflow_ready_for_review');
  }

  function render($values) {
    return !empty($values->{$this->field_alias}) ? t('Ready for review') : '';
  }
}
