Draft Workflow
========

This module expands on Backdrop's core revision handling to support a draft workflow —
the ability to create and manage unpublished draft versions of content that is already
published.

![image](https://github.com/user-attachments/assets/15faed0d-d8cd-4e0b-8404-444a61d773ed)

1) This "Current" revision is the version that site visitors will see when they visit your
website.

2) This version contains changes to the "Current" version that are not yet visible to
site visitors. When this revision is ready, you can make it or any other revision your
"Current" revision.

![image](https://github.com/user-attachments/assets/a832d7fd-0ac2-49b5-aaef-20bf52547524)

Getting started
---------------

The draft workflow is **off for every content type** until you turn it on. After
installing the module, turn it on for the content types that need it, either:

- on the settings page, **Admin > Configuration > Content authoring > Draft
  Workflow** (`admin/config/content/draft-workflow`), or
- on each content type: **Admin > Structure > Content Types**, **Edit**, the
  **Revision settings** tab, then check **Enable draft workflow**.

Then give your editors and publishers the module's permissions (see Permissions
below). Content types without the draft workflow keep core's normal revision
behaviour.

Sites that used an earlier version of the module keep the draft workflow on for
their existing content types when they run `update.php`.

Using this module
-----------------

### Creating a draft

There are two ways to start a draft:

- **From the Edit tab:** open the **Revision information** section, check **Save as a
  draft**, and save. Your changes are saved as a new draft revision, and the current
  revision stays as it is. While this box is checked, the publishing options, URL
  settings and authoring information are hidden, because they belong to the content
  as a whole, not to a draft.
  On published content, the Edit tab is only available to people with the _Publish
  and unpublish content_ permission (see Permissions below).
- **From the Revisions tab:** use **Copy current revision**, or **Copy this revision**
  on any revision. This works for everyone who can create drafts.

After saving a draft, you land on the draft itself, with a message saying it is not
yet the current revision.

### The Revisions tab

Navigate to the **Revisions** tab on any node to manage its revisions. From there you
can:

- **Publish or unpublish** the content using the buttons at the top of the page.
- **Copy the current revision** to create a new draft without affecting what is
  currently live.
- **View, edit, or copy any revision** using the action links in the revisions table.
- **Make any revision the current revision** — the version site visitors will see.

When editing or copying a non-current revision, the publishing options, URL settings
and authoring information are hidden, because they belong to the content as a whole,
not to a draft. Instead, a single "Make this the current revision" checkbox is
available in the Revision information section. The draft form has no button that
deletes the whole content: when editing a saved draft, **Delete this draft** deletes
only that revision (this needs core's _Delete revisions_ permission).

Good to know:

- **Published or not is a setting of the content, not of a revision.** Saving a draft
  never publishes or unpublishes the content.
- **The URL alias follows the current revision.** Changing a draft's title does not
  change the page's URL until the draft is made current.
- If you open the regular **Edit** tab while a newer draft exists, a message warns
  you, with a link to edit the latest draft instead.

### Ready for review

When a draft is finished, check **Ready for review** when saving it (on the draft
forms, or next to "Save as a draft" on the Edit tab). Drafts that are ready for review
are marked on the Revisions tab. The mark is removed when the box is unchecked, or
when the draft is made current.

Pending Review view
-------------------

The module provides a **Pending Review** view at `admin/content/drafts` (also
available as a tab alongside the main Content list). It shows all nodes that have
draft revisions newer than the currently published revision, along with the latest
draft note left by an editor, and a **Review** column for content with a draft that
is ready for review.

The view can also be filtered by **Has a draft ready for review**. On sites that
installed the module before this column was added, the view is not changed
automatically: add the "Ready for review" field in the Views UI if you want it.

A **Pending Review block** is also available. Add it to a dashboard or admin layout
to show a quick count of content awaiting review, with a link to the full list.

Configuration
-------------

### Settings page

Go to **Admin > Configuration > Content authoring > Draft Workflow**
(`admin/config/content/draft-workflow`) to:

- Turn the draft workflow on or off for each content type.
- Turn on **Prominent revision info** for each content type (see below).
- See which content types email reviewers (set on each content type; see below).
- Set the module's permissions for each role.

The page requires the _Administer content types_ permission. The permissions table is
only shown to people who also have _Administer permissions_. All of these settings are
also available on each content type's edit page and on the main Permissions page.

### Permissions

The module defines four permissions that allow you to separate editorial roles:

| Permission | Description |
|---|---|
| **Create draft revisions** | Create new draft revisions and edit existing draft revisions. |
| **Activate draft revisions** | Make a draft revision current on an **unpublished** node. |
| **Publish and unpublish content** | Publish and unpublish nodes; also required to activate revisions on already-published nodes, since doing so changes what is publicly visible. |
| **View pending draft revisions** | Access the Pending Review view and dashboard block. |

Core's _Administer content_ permission allows all of these actions, whatever these
permissions are set to. The settings page names the roles that have it. Give it only
to roles that should be able to publish.

A typical two-role setup might look like:

- **Editor**: Grant _Create draft revisions_ and _View pending draft revisions_.
- **Publisher**: Grant all four permissions.

New content created by people without _Publish and unpublish content_ is always saved
unpublished, even when the content type is published by default. A publisher can then
publish it from the Revisions tab.

> **Important:** Saving the regular edit form makes your changes the current, live
> version, so people without _Publish and unpublish content_ cannot open the Edit tab
> of published content. They work from the **Revisions** tab instead: copy or edit a
> draft revision, mark it ready for review, and leave it for a publisher to make
> current.

### Make revision information more prominent

By default, revision information appears inside the sidebar tabs on the content
editing form. If your editorial workflow relies heavily on revisions, you can make
this section always visible by enabling a per-content-type setting:

1. Go to **Admin > Structure > Content Types**.
2. Click **Edit** for the content type you want to configure.
3. Open the **Revision settings** tab.
4. Check **Display revision information prominently**.

When enabled, the revision information fieldset will appear above the sidebar tabs
on all editing forms for that content type, making it immediately visible without
requiring an extra click.

This setting also works for content types that don't use the draft workflow. It is
shown when **Enable option to create revisions** is checked.

### Email reviewers

The module can email reviewers when a draft is marked ready for review. This is set
for each content type that uses the draft workflow (the setting is shown when
**Enable draft workflow** is checked):

1. Go to **Admin > Structure > Content Types** and click **Edit** for the content type.
2. Open the **Revision settings** tab.
3. Check **Email reviewers when a draft is ready for review**.
4. Choose one or more **Reviewer roles**. Only roles with the _Activate draft
   revisions_ or _Administer content_ permission are listed.

Each active person in those roles gets an email with links to the draft and to the
Revisions tab. The person who marked the draft ready for review is not emailed, and
saving the draft again while it stays marked does not send another email. To open the
draft from the email, reviewers also need core's _View content revisions_ permission.

Related Modules
---------------

### Diff

Install the [Diff module](https://backdropcms.org/project/diff) to enable
side-by-side comparisons between revisions. When Diff is active, a **Diff**
link appears in the revisions table, letting editors and reviewers quickly see
exactly what changed between a draft and the current live version.

### Rules

The [Rules module](https://backdropcms.org/project/rules) is optional. When it is
enabled, this module provides:

- An event, **A draft is marked ready for review**, with the draft revision and the
  person who marked it, for sites that want their own notifications or other actions.
- A default rule, **Draft Workflow: email reviewers when a draft is ready for review**.
  It is **disabled** by default and emails the Administrator role. Enable it and
  change the role in the Rules UI. Note that, unlike the built-in email, Rules' "Send
  mail to all users of a role" action also emails blocked accounts and the person who
  marked the draft.

If a rule reacts to this event while a content type also has **Email reviewers**
turned on, a warning appears on the content type form and the settings page, because
reviewers may get two emails. Turn off one or the other.

For developers
--------------

`hook_draft_workflow_review_requested($node, $account)` is invoked once when a draft
is marked ready for review. See `draft_workflow.api.php`.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.
- Turn on the draft workflow for your content types (see Getting started above).


Issues
------

Bugs and Feature Requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/draft_workflow/issues.


Current Maintainers
-------------------

- [Joseph Flatt](https://github.com/hosef)
- Tim Erickson ([@stpaultim](https://github.com/stpaultim)).


License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
