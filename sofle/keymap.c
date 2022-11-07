#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "macros.h"

bool is_kc_window_active = false;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _M_QWERTY,
    _LOWER,
    _M_LOWER,
    _RAISE,
    _M_RAISE,
    _ADJUST,
};

// KC_NUBS or KC_GRV custom less than: < due to bug mac/linux not using the same key
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_M_QWERTY,
    KC_C_WINDOW,   // change window (win: alt+tab)
    KC_M_C_WINDOW, // change window (mac: gui+tab)
    KC_C_TAB,      // change tab (ctrl+tab)
    KC_C_TAB_PREV,  // change tab window prev (shift+ctrl+tab),
    KC_C_CBR,  // { and SHIFT({) = } 
    KC_C_BRK,  // [ and SHIFT([) = ]
    KC_C_PAR  // ( and SHIFT(() = )
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,  LGUI_T(KC_QUOT), XXXXXXX,
  XXXXXXX,LSFT_T(KC_Z),LALT_T(KC_X),KC_C,KC_V,    KC_B, KC_MUTE,        KC_MPLY, KC_N,    KC_M, KC_COMM,LALT_T(KC_DOT),RSFT_T(KC_SLSH),XXXXXXX,
  XXXXXXX, XXXXXXX,LCTL_T(KC_ESC),LT(_LOWER, KC_TAB),KC_SPC, KC_ENT,LT(_RAISE, KC_BSPC),KC_DELETE,    XXXXXXX, XXXXXXX
),
[_M_QWERTY] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  XXXXXXX,  KC_A,  KC_S,  KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L, LCTL_T(KC_QUOT),XXXXXXX,
  XXXXXXX,LSFT_T(KC_Z),LALT_T(KC_X),  KC_C,   KC_V,   KC_B, KC_MUTE,    KC_MPLY, KC_N,    KC_M, KC_COMM,LALT_T(KC_DOT), RSFT_T(KC_SLSH),XXXXXXX,
  XXXXXXX, XXXXXXX,LGUI_T(KC_ESC),LT(_M_LOWER, KC_TAB),KC_SPC,KC_ENT,LT(_M_RAISE, KC_BSPC),  KC_DELETE, XXXXXXX, XXXXXXX
),
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______ ,_______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_TAB, _______, PRV_WPC, NXT_WPC, _______,                     S(ES_6), S(ES_7),KC_C_PAR, S(ES_9), S(ES_0), _______,
  _______, _______, _______, _______,KC_C_WINDOW,ES_QUOT,                   S(ES_1),KC_NUBS,KC_C_CBR,KC_C_BRK,S(ES_QUOT),_______,
  _______, KC_LSFT, _______,KC_C_TAB_PREV,KC_C_TAB,ES_GRV,_______,  _______,KC_RBRC,S(ES_2),S(KC_COMM),S(KC_DOT),S(ES_MINS),_______,
                    _______, _______, _______, _______, _______,    _______, LT(_RAISE, KC_NO),WDEL,_______, _______
),
[_M_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______ ,_______,                     _______, _______, _______, _______, _______, _______,
  _______,  KC_TAB, _______, PRV_WPC,  NXT_WPC, _______,                    S(ES_6), S(ES_7),KC_C_PAR, S(ES_9), S(ES_0), _______,
  _______, _______, _______, _______,KC_M_C_WINDOW,ES_QUOT,                 S(ES_1),KC_GRV,KC_C_CBR,KC_C_BRK,S(ES_QUOT), _______,
  _______, KC_LSFT, _______,KC_C_TAB_PREV,KC_C_TAB,ES_GRV, _______,  _______,KC_RBRC,S(ES_2),S(KC_COMM),S(KC_DOT),S(ES_MINS), _______,
                    _______, _______, _______, _______, _______,     _______,LT(_M_RAISE, KC_NO),M_WDEL,_______,_______
),
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______,ALGR(ES_1),ALGR(ES_2),ALGR(ES_3),S(ES_4),S(ES_5),                 _______,   PRVWD,   KC_UP,   NXTWD, _______, _______,
  _______, _______, _______, _______, _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, KC_HOME, _______,  KC_END, _______, _______,
                    _______, _______, _______,MO(_LOWER),_______,  _______, _______, _______, _______, _______
),
[_M_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______,ALGR(ES_1),ALGR(ES_2),ALGR(ES_3),S(ES_4),S(ES_5),                  _______, M_PRVWD,   KC_UP, M_NXTWD, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______,   _______, _______,  M_HOME, _______,   M_END, _______, _______,
                    _______, _______, _______,MO(_M_LOWER),_______, _______, _______, _______, _______, _______
),
//  ALGR(ES_NTIL) no va en windows, sólo en linux
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_EQL,KC_QWERTY,ALGR(ES_E),XXXXXXX,KC_PLUS,                      XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  XXXXXXX,ALGR(ES_MORD),KC_M_QWERTY,XXXXXXX,XXXXXXX,XXXXXXX,                 XXXXXXX,    KC_4,    KC_5,    KC_6,ALGR(ES_NTIL),XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, ES_NTIL,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
  )
};

// #ifdef OLED_ENABLE

// static void render_logo(void) {
//     // static const char PROGMEM raw_logo[] = {
//     //     0,  0,  0,128,128,  0,  0,  0,  0,128,128,128,  0,  0,  0,  0,128,128,128,128,128,128,128,  0,  0,  0,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0, 12,144,176,224,114, 49,155,222,206,236,238,233,233,236,207,218,153, 62, 98,228,196,112, 16, 16,  0,  0,  0,  0,  0,  0,  0, 96,192,192,128,128,  2,133,133,135,133,137,137,146,234,198,196, 72, 80, 96, 64, 64, 64, 64,192,224, 80, 40, 16, 16, 96,192, 64, 64, 64, 64,128,128,128,128,128,224,248,252,248,240,  0,  0,  0,  0,  0,  0,
//     //     0,127,195,192,192,112, 15,  1,  1,193,255,  0,  0,  0,192,192,192,192,192,192,255,127,  0,  0,192,224,176,152,140,134,131,129,192,  0,  0,  0,  0,  0,  0,  0,  0, 64, 33, 51, 59,123,255,  0,124,255,255,255,255,255,255,255,255,255,255,255,255,255,124,  1,255,222,140,  4, 12,  8,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,127,128,128,190,190,128,128,128,193,255,128,  4, 50, 94, 28, 61, 38, 16,193,255, 62,  0,  0,  8, 54,193,  8,  8, 20,119,148,148,148,247,148,247,156,156,255,255, 30,  0,  0,  0,  0,  0,  0,  0, 
//     //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  2,  6, 77, 79,140,249,115, 55, 39, 47, 47,175,239,111,119, 23, 51,121,204, 31, 49, 32, 33,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,224,160,160,208,144, 72, 72, 37, 43, 17,  9,  5,  3,  1,  1,  1,  1,  1,  1,  1,  3,  2,  4,  3,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  3, 15, 31, 15,  3,  0,  0,  0,  0,
//     // };
//     // oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }

// static void print_status_narrow(void) {
//     oled_write_P(PSTR("\n\n\n"), false);
//     switch (get_highest_layer(default_layer_state)) {
//         case _QWERTY:
//             oled_write_ln_P(PSTR("  WIN"), false);
//             break;
//         case _M_QWERTY:
//             oled_write_ln_P(PSTR("  MAC"), false);
//             break;
//         default:
//             oled_write_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n\n"), false);

//     switch (get_highest_layer(layer_state)) {
//         case _M_QWERTY:
//         case _QWERTY:
//             oled_write_P(PSTR("     "), false);
//             break;
//         case _RAISE:
//             oled_write_P(PSTR("RAISE"), false);
//             break;
//         case _M_RAISE:
//             oled_write_P(PSTR("MRAI"), false);
//             break;
//         case _LOWER:
//             oled_write_P(PSTR("LOWER"), false);
//             break;
//         case _M_LOWER:
//             oled_write_P(PSTR("MLOW"), false);
//             break;
//         case _ADJUST:
//             oled_write_P(PSTR("ADJUS"), false);
//             break;
//         default:
//             oled_write_ln_P(PSTR("Undef"), false);
//     }
//     oled_write_P(PSTR("\n\n\n"), false);
//     led_t led_usb_state = host_keyboard_led_state();
//     if (led_usb_state.caps_lock) {
//         oled_write_ln_P(PSTR("CAPS"), true);
//     } else {
//         oled_write_ln_P(PSTR("     "), false);
//     }
// }

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     if (is_keyboard_master()) {
//         return OLED_ROTATION_270;
//     }
//     return OLED_ROTATION_180;
// }

// bool oled_task_user(void) {
//     if (is_keyboard_master()) {
//         print_status_narrow();
//     } else {
//         render_logo();
//     }
//     return false;
// }

// #endif

layer_state_t layer_state_set_user(layer_state_t state) {
    // unregister mods from K_C_WINDOW and  KC_C_TAB
    if (is_kc_window_active) {
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        unregister_code(KC_LGUI);
        is_kc_window_active = false;
    }

    // update _ADJUST layer
    if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)) {
        state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    } else if (IS_LAYER_ON(_M_LOWER) || IS_LAYER_ON(_M_RAISE)) {
        state = update_tri_layer_state(state, _M_LOWER, _M_RAISE, _ADJUST);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Detect the activation of both Shifts
    if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT) {
        tap_code(KC_CAPS);
    }
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_M_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M_QWERTY);
            }
            return false;
        case KC_C_WINDOW:
            if (record->event.pressed) {
                if (!is_kc_window_active) {
                    is_kc_window_active = true;
                    register_code(KC_LALT);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case KC_M_C_WINDOW:
            if (record->event.pressed) {
                if (!is_kc_window_active) {
                    is_kc_window_active = true;
                    register_code(KC_LGUI);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case KC_C_TAB:
            if (record->event.pressed) {
                if (!is_kc_window_active) {
                    is_kc_window_active = true;
                    register_code(KC_LCTL);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case KC_C_TAB_PREV:
            if (record->event.pressed) {
                if (!is_kc_window_active) {
                    is_kc_window_active = true;
                    register_code(KC_LCTL);
                }
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_mods(MOD_LSFT);
            }
            break;
        case KC_C_CBR:{
                bool isShifted = get_mods() & MOD_MASK_SHIFT;
                if (record->event.pressed) {
                    if(isShifted) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code16(ES_RCBR);
                        register_code(KC_LSFT);
                    } else {
                        register_code16(ES_LCBR);
                    }
                } else {
                    if(isShifted) {
                        unregister_code16(ES_RCBR);
                    } else {
                        unregister_code16(ES_LCBR);
                    }
                }
                break;
            }
        case KC_C_BRK:{
                bool isShifted = get_mods() & MOD_MASK_SHIFT;
                if (record->event.pressed) {
                    if(isShifted) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code16(ES_RBRC);
                        register_code(KC_LSFT);
                    } else {
                        register_code16(ES_LBRC);
                    }
                } else {
                    if(isShifted) {
                        unregister_code16(ES_RBRC);
                    } else {
                        unregister_code16(ES_LBRC);
                    }
                }
                break;
            }
        case KC_C_PAR:{
                bool isShifted = get_mods() & MOD_MASK_SHIFT;
                if (record->event.pressed) {
                    if(isShifted) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code16(ES_RPRN);
                        register_code(KC_LSFT);
                    } else {
                        register_code16(ES_LPRN);
                    }
                } else {
                    if(isShifted) {
                        unregister_code16(ES_RPRN);
                    } else {
                        unregister_code16(ES_LPRN);
                    }
                }
                break;
            }
        case LT(_RAISE, KC_NO):
            if(record->tap.count && record->event.pressed) {
                tap_code16(WBSPC);
                return false;
            }
            return true;
        case LT(_M_RAISE, KC_NO):
            if(record->tap.count && record->event.pressed) {
                tap_code16(M_WBSPC);
                return false;
            }
            return true;
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_QUOT):
        case LCTL_T(KC_QUOT):
        case LSFT_T(KC_Z):
        case LALT_T(KC_X):
        case LALT_T(KC_DOT):
        case RSFT_T(KC_SLSH):
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SLSH):
            return true;
        default:
            return false;
    }
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            // next track
            tap_code(KC_MNXT);
        } else {
            // previous track
            tap_code(KC_MPRV);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif
