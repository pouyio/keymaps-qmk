# Custom 36 keymap for corne/sofle Keyboard

[![corne Keyboard custom keymap](https://api.microlink.io/?url=http%3A%2F%2Fwww.keyboard-layout-editor.com%2F%23%2Fgists%2Fbf533ff812829bf261ab7ea44d985077&screenshot=true&meta=false&embed=screenshot.url&element=%23keyboard-bg)](http://www.keyboard-layout-editor.com/#/gists/bf533ff812829bf261ab7ea44d985077)

[QMK official docs](https://docs.qmk.fm/#/)

**Removed top, side rows and some bottom keys**, resulting in 5x3+3.

Adapted to **my** personal needs:

- Coding
- iso-es layout.
- Same shortcuts among mac/lin/win.

## Features:

- Shift/Alt mod tap in base row, both sides.
- Added macros for both Mac and Linux/Win (change workspace, change tab).
- Left encoder controls mute and next/prev track. Right encoder pause and volumne.
- Layer tap in raise/lower buttons.
- Caps lock tapping both shifts.

## Install

Execute `qmk setup -H ./qmk_firmware` to install all qmk dependencies pointing to the qmk_firmware symlinked repo.

## Run

Execute `make crkbd` or `make sofle` depending on the board you are using.

---

_Note_: if changes are made in `config.h` then intermediate folders must be deleted before compiling again.
