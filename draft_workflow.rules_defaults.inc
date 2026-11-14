<?php
/**
 * @file
 * Default Rules configurations for the Draft Workflow module.
 *
 * Rules is optional: this file is only loaded when Rules is enabled.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function draft_workflow_default_rules_configuration() {
  // A starting point for sites that prefer Rules to the built-in reviewer
  // emails. It is disabled by default: turn off the built-in "Email reviewers"
  // setting for the content type before enabling it, or reviewers get two
  // emails. Change the role to the site's reviewer role.
  $rule = rules_reaction_rule();
  $rule->label = 'Draft Workflow: email reviewers when a draft is ready for review';
  $rule->tags = array('Draft Workflow');
  $rule->active = FALSE;
  $rule->event('draft_workflow_review_requested')
    ->action('mail_to_users_of_role', array(
      'roles' => array('administrator'),
      'subject' => '[[site:name]] Draft ready for review: [node:title]',
      'message' => "[requester:name] has marked a draft of the [node:content-type:name] \"[node:title]\" as ready for review.\n\nView the draft: [site:url]node/[node:nid]/revisions/[node:vid]/view\n\nAll revisions: [site:url]node/[node:nid]/revisions",
    ));

  $configs['draft_workflow_email_reviewers'] = $rule;
  return $configs;
}
