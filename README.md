# Delphi Tips

This project contains a bunch of Delphi language tips.

Some of the tips are published on a micro-site that can be found at **[tips.delphidabbler.com](https://tips.delphidabbler.com)**.

> **Health Warning!** All the tips are very old now. Very few have been tested, and those that have were tested quite some time back on an old version of Delphi. Consider yourself warned!

The project has the following folders:

## `db`

Contains a single SQL file - `tips-v2.sql` - that provides meta data about the tips. The SQL can be used to create a database.

Such a database would need to be used in conjunction with the files in the `docs/_tips` folder, and some suitable CSS and HTML templates, to generate complete web pages for each tip.

## `demos`

Contains Delphi Pascal demo projects associated with some of the tips in the `docs/_tips` directory.

Each demo has its own sub-directory whose name is the number of the associated tip. Where there is more than one demo for a single tip there are further sub-directories for each demo.

> **Warning:** `.html` files in `docs/_tips` link to this directory. Should the directory, or any of its sub-directories, be renamed or moved then links in the affected `.html` files must be updated accordingly.

## `docs`

This folder contains the source code of the **[mini website](https://tips.delphidabbler.com)**.

The site is developed and deployed using Jekyll. Builds are published via GitHub Pages.

> **Warning:** The `CNAME` file in this directory should not be changed or removed: it ensure the micro-site is treated as a sub-domain of [delphidabbler.com](https://delphidabbler.com).

> **Note:** The tips in this folder were derived from those in the `tips` folder, but have since been updated. These tips are the most current.

## `extra`

There are two open document format documents in this directory.

* One contains a large number of tips downloaded from the former _Delphi Pool_ website.
* The second contains tips collected online by _"topellina"_.

There may be some duplication of tips between the PDF files. Further, some tips that appear in the `docs/_tips` and `tips` directories may have been sourced, and later deleted, from these files.

## `tips`

Contains a PDF "print out" of tips pages that appeared on an earlier, now defunct, version of [delphidabbler.com](https://delphidabbler.com).

> **Note:** The tips in the `docs/_tips` directory represent the most recent version of the collection. These PDFs are now **deprecated** and may be removed at some point.
