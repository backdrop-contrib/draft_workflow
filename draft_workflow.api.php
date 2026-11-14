<?php
/**
 * @file
 * Hooks provided by the Draft Workflow module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Respond to a draft revision being marked ready for review.
 *
 * Invoked once, when a draft that was not yet marked is saved with "Ready for
 * review" checked. Saving it again while it stays marked does not invoke this
 * hook again.
 *
 * @param Node $node
 *   The node, loaded at the draft revision that was marked ready for review.
 * @param object $account
 *   The person who marked the draft ready for review.
 */
function hook_draft_workflow_review_requested(Node $node, $account) {
  watchdog('mymodule', '@name asked for a review of %title.', array(
    '@name' => user_format_name($account),
    '%title' => $node->title,
  ));
}

/**
 * @} End of "addtogroup hooks".
 */
