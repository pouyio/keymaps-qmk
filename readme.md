[![SofleKeyboard custom keymap](https://github.com/pouyio/keymaps/raw/master/keymap.png)](http://www.keyboard-layout-editor.com/#/gists/bf533ff812829bf261ab7ea44d985077)

[QMK official docs](https://docs.qmk.fm/#/)

# Custom keymap for Sofle Keyboard

**Removed top, side rows and some bottom keys**, resulting in 5x3+3.

Adapted to **my** personal needs:
- Coding
- Easier transition from iso-es layout.
- Same shortcuts among mac/lin/win.

## Feature changes:
- Shift/Alt mod tap in base row, both sides.
- Added more macros for both Mac and Linux/Win.
- The OLED has less info.
- Left encoder controls mute and next/prev track. Right encoder pause and volumne.
- Layer tap in raise/lower buttons.
- Caps lock tapping both shifts.


## Install
Execute `qmk setup -H ./qmk_firmware` to install all qmk dependencies pointing to the qmk_firmware symlinked repo.

## Run
Execute `make sofle`

---

*Note*: if changes are made in `config.h` then intermediate folders must be deleted before compiling again.
