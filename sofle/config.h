#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// #define OLED_TIMEOUT 10000
// #define OLED_BRIGHTNESS 190
#undef TAPPING_TERM
#define TAPPING_TERM 150
#undef TAPPING_FORCE_HOLD

//                          TAPPING_TERM
//   +---------------------------|--------+
//   | +-------------+           |        |
//   | | LT(2, KC_A) |           |        |
//   | +-------------+           |        |
//   |       +--------------+    |        |
//   |       | KC_L         |    |        |
//   |       +--------------+    |        |
//   +---------------------------|--------+
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

#define RETRO_TAPPING_PER_KEY

#define TAPPING_FORCE_HOLD // this is outdated, should be QUICK_TAP_TERM https://docs.qmk.fm/#/ChangeLog/20230226?id=quick-tap-term