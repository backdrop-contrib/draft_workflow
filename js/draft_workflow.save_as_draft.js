/**
 * @file
 * Hides node-level settings while "Save as a draft" is checked.
 *
 * Publishing options, URL settings and authoring information belong to the
 * node, not to a draft, so they are hidden while the edit form will save a
 * draft. The server side
 * (draft_workflow_node_submit()) does not depend on this script.
 */
(function ($) {

  'use strict';

  Backdrop.behaviors.draftWorkflowSaveAsDraft = {
    attach: function (context) {
      $('input[name="save_as_draft"]', context).once('draft-workflow-save-as-draft').each(function () {
        var $checkbox = $(this);
        var $form = $checkbox.closest('form');

        var toggle = function () {
          var hide = $checkbox.is(':checked');
          // Hiding a tab moves focus to the first visible tab, so remember the
          // tab that holds the checkbox and return to it afterwards.
          var ownTab = $checkbox.closest('.vertical-tabs-pane').data('verticalTab');
          $form.find('#edit-options, #edit-path, #edit-author').each(function () {
            var $fieldset = $(this);
            var tab = $fieldset.data('verticalTab');
            if (tab) {
              if (hide) {
                tab.tabHide();
              }
              else {
                tab.tabShow();
              }
            }
            else {
              $fieldset.toggle(!hide);
            }
          });
          if (hide && ownTab) {
            ownTab.focus();
          }

          // A draft is always saved as a new revision, so show "Create new
          // revision" as checked (and locked) while "Save as a draft" is on.
          var $revision = $form.find('input[name="revision"]');
          if (hide) {
            $revision.data('draftWorkflowWasChecked', $revision.prop('checked'));
            $revision.prop('checked', true).prop('disabled', true);
          }
          else if ($revision.prop('disabled')) {
            $revision.prop('checked', $revision.data('draftWorkflowWasChecked')).prop('disabled', false);
          }
        };

        $checkbox.on('change', toggle);
        // When the form is shown with the box already checked (for example
        // after a validation error), hide the settings once vertical tabs have
        // been set up.
        if ($checkbox.is(':checked')) {
          setTimeout(toggle, 0);
        }
      });
    }
  };

})(jQuery);
