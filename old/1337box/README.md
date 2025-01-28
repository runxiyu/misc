% 1337box, an insanely optimized CSS-only, no-JS lightbox implementation
% Leah Rowe
% 19 December 2021 (updated on 24 December 2021)

Introduction
============

1337box is a simple, insanely optimized Lightbox replacement in pure CSS.\
[Demos are available](https://vimuser.org/demo.1337box_default.html)

With 1337box, you can click an image on a page and a full sized zoomed in
version of it appears, filling the width/height of your browser window.

Download
--------

You can download it from a Git repository:

    git clone https://codeberg.org/1337box/1337box

Direct links to the latest file, each with varying levels of optimization:

* <https://codeberg.org/1337box/1337box/raw/master/1337box_default.css> (136 bytes)([demo](https://vimuser.org/demo.1337box_default.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_default_nocursor.css> (116 bytes)([demo](https://vimuser.org/demo.1337box_default_nocursor.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_shadow.css> (235 bytes)([demo](https://vimuser.org/demo.1337box_shadow.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_shadow_cursed.css> (188 bytes)([demo](https://vimuser.org/demo.1337box_shadow_cursed.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_shadow_supercursed.css> (173 bytes)([demo](https://vimuser.org/demo.1337box_shadow_supercursed.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_cursed.css> (107 bytes)([demo](https://vimuser.org/demo.1337box_cursed.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_cursed_nocenter.css> (77 bytes)([demo](https://vimuser.org/demo.1337box_cursed_nocenter.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_supercursed.css> (93 bytes)([demo](https://vimuser.org/demo.1337box_supercursed.html))
* <https://codeberg.org/1337box/1337box/raw/master/1337box_supercursed_nocenter.css> (63 bytes)([demo](https://vimuser.org/demo.1337box_supercursed_nocenter.html))

Features
--------

It makes image galleries more user-friendly, on otherwise static HTML pages,
and works fully, even if the user has JavaScript disabled in their browser!

Benefits over other Lightbox implementations include:

* Insane optimizations.
* Minified by default, but still easy to read.
* No shadows or fade-in effects in the default files, because that is *bloat*.
* Special versions available *with* the shadow effect, behind enlarged images.
  This makes it look more similar to traditional lightbox effects.
* Works well on mobile browsers.

Configuration
-------------

How to understand CSS rules: `.f` is the full image, and `.t` is the thumbnail.

For versions with the shadow effect, establish images like so:

    <img tabindex=1 src="image_thumbnail.png" /><span class="f"><img src="image_full.png" /></span>

For versions *without* the shadow effect, establish images like so:

    <img tabindex=1 src="image_thumbnail.png" /><img class="f" src="image_full.png" />

How does each version differ?
-----------------------------

The `default` version scales images to a max width and height filling the browser window.
These versions are mobile-friendly (on all versions, it is recommended to view full images
in widescreen mode, if you're viewing it on a smartphone).

The `nocursor` version removes the cursor icon that appears (on desktop browsers) when hovering
over images.

The `shadow` version adds a shadow effect, darkening what's behind the image. Depending on
your site, you may want to use this version (it looks very similar to normal lightbox).

Versions with `nocenter` do not center the image.

The `cursed` versions set the full image statically to fill the *height* of the browser window,
and sets the max width to the width of the browser window. It is recommended that you don't
use wide images with this one, and view in widescreen mode if using a mobile device. These versions
are highly optimized, but less technically correct versus the original lightbox behaviour.

The `supercursed` versions are like the `cursed` versions, but they do *not* set a maximum
width. Otherwise, the same rules apply.

The only versions that have the cursor icon appear over images (when hovering), on desktop
browsers, are `1337box_default.css` version and `1337box_shadow.css`. If you like this
behaviour, and want to add it on other versions, simply add this line in CSS:

    img{cursor:pointer}

Known problems and workarounds
------------------------------

If you have elements extending beyond the width of the browser screen, such
that horizontal scrolling is enabled, `1337box` will break horribly, because
it will scale to *that* extended size.

Please ensure that your pages don't horizontally scroll.

If using the `cursed` versions, please ensure that the aspect ratio of your
full sized images do not exceed the aspect ratio of the browser window.

Send patches
------------

Send a pull request:
<https://codeberg.org/1337box/1337box/pulls>

You can also send the patch via email. My info is on
the [contact page of vimuser.org](https://vimuser.org/contact.html).

Untitled Static Site Generator
------------------------------

You may also consider building websites using the [untitled static site
generator](https://untitled.vimuser.org/). With this, you can write pages in
Markdown but it uses Pandoc to generate HTML, and you can still insert HTML
into pandoc-style Markdown files.

Untitled and 1337box are both written with a simple goal: to make the web sane.

Copying
-------

`1337box` is released under the terms of the Creative Commons Zero 1.0
license. You can view that license text here:

<https://creativecommons.org/publicdomain/zero/1.0/legalcode>

A copy of that file has been included, alongside 1337box inside the
Git repository, in the `COPYING` file.

That license ALSO applies to this page/document that you are reading now! This
text is released under the terms of the Creative Commons Zero 1.0 license.

As such, you can freely use 1337box for any purpose you desire. It is
completely free, in every sense of the word.
