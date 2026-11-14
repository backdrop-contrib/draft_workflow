<?php
/**
 * @file
 * Definition of draft_workflow_handler_filter_ready_for_review.
 */

/**
 * Filter to nodes that have (or do not have) a draft, newer than the current
 * revision, that is marked ready for review.
 *
 * @ingroup views_filter_handlers
 */
class draft_workflow_handler_filter_ready_for_review extends views_handler_filter_boolean_operator {

  function construct() {
    parent::construct();
    $this->value_value = t('Has a draft ready for review');
  }

  function get_value_options() {
    $this->value_options = array(
      1 => t('Yes'),
      0 => t('No'),
    );
  }

  function query() {
    $subquery = 'EXISTS (SELECT 1 FROM {draft_workflow_review} dwr WHERE dwr.nid = node.nid AND dwr.vid > node.vid)';
    $this->query->add_where_expression(
      $this->options['group'],
      empty($this->value) ? 'NOT ' . $subquery : $subquery
    );
  }
}
