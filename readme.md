# Custom 36 keymap for corne/sofle Keyboard

[![corne Keyboard custom keymap](https://github.com/user-attachments/assets/af7a94ba-a5ce-4b20-b30a-146d8fa049db)](http://www.keyboard-layout-editor.com/#/gists/bf533ff812829bf261ab7ea44d985077)

[QMK official docs](https://docs.qmk.fm/#/)

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
- Only sofle: [Gaming layers for left half](./sofle/README.md).

## Install

Execute `qmk setup -H ./qmk_firmware` to install all qmk dependencies pointing to the qmk_firmware symlinked repo.

## Run

Execute `make crkbd` or `make sofle` depending on the board you are using.

---

_Note_: if changes are made in `config.h` then intermediate folders must be deleted before compiling again.
