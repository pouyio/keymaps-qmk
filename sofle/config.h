#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// #define OLED_TIMEOUT 10000
// #define OLED_BRIGHTNESS 190
#undef TAPPING_TERM
#define TAPPING_TERM 150

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

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64