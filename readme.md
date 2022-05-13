[![SofleKeyboard custom keymap](https://github.com/pouyio/keymaps/raw/master/keymap.png)](http://www.keyboard-layout-editor.com/#/gists/a8c20711f4953e7b41d8760d00769210)

[QMK official docs](https://docs.qmk.fm/#/)

# Custom keymap for Sofle Keyboard

**Removed top row**, resulting in 6x3+(4-3).

Adapted to **my** personal needs:
- Coding
- Easier transition from iso-es layout.
- Same shortcuts among mac/lin/win.

## Feature changes:
- Modifiers only in left (CMD/Super, Alt/Opt, Ctrl)
- Added more macros for both Mac and Linux/Win.
- The OLED has less info.
- Left encoder controls mute and next/prev track. Right encoder pause and .
- Layer tap in raise/lower buttons.
- Hold tap for `}`, `]` and `*`.
- Caps lock tapping both shifts.


## Install
Execute `qmk setup -H ./qmk_firmware` to install all qmk dependencies pointing to the qmk_firmware symlinked repo.

## Run
Execute `make sofle`