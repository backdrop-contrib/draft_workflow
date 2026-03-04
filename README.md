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

Using this module
-----------------

Once installed, navigate to the **Revisions** tab on any node to manage its revisions.
From there you can:

- **Publish or unpublish** the content using the buttons at the top of the page.
- **Copy the current revision** to create a new draft without affecting what is
  currently live.
- **View, edit, or copy any revision** using the action links in the revisions table.
- **Make any revision the current revision** — the version site visitors will see.

When editing or copying a non-current revision, the publishing options are hidden to
avoid confusion. Instead, a single "Make this the current revision" checkbox is
available in the Revision information section.

Configuration
-------------

### Make revision information more prominent

By default, revision information appears inside the sidebar tabs on the content
editing form. If your editorial workflow relies heavily on revisions, you can make
this section always visible by enabling a per-content-type setting:

1. Go to **Admin > Structure > Content Types**.
2. Click **Edit** for the content type you want to configure.
3. Open the **Revision** section.
4. Check **Display revision information prominently**.

When enabled, the revision information fieldset will appear above the sidebar tabs
on all editing forms for that content type, making it immediately visible without
requiring an extra click.

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.


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
