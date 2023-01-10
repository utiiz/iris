#include QMK_KEYBOARD_H

#include "keymap_french.h"

#define _ISRT 0
#define _DVORAK 1
#define _FN 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

#define SHIFT_NO(kc1, kc2) \
if (record->event.pressed) { \
  if (get_mods() & MOD_MASK_SHIFT) { \
    uint8_t mods_temp = get_mods(); \
    del_mods(MOD_MASK_SHIFT); \
    unregister_code16(kc2); \
    register_code16(kc2); \
    set_mods(mods_temp); \
  } else { \
    unregister_code16(kc1); \
    register_code16(kc1); \
  } \
} else { \
  unregister_code16(kc1); \
  unregister_code16(kc2); \
} return false;

enum custom_keycodes {
  ISRT = SAFE_RANGE,
  DVORAK,
  FN,
  LOWER,
  RAISE,
  ADJUST,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  ZERO,
  QUOTES,
  COLUMN,
  SLASH,
  DOT,
  COMMA,
  D_COLUMN,
  D_SLASH,
  D_DOT,
  D_COMMA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ISRT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  ONE,     TWO,     THREE,   FOUR,    FIVE,                               SIX,     SEVEN,   EIGHT,   NINE,    ZERO,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  FR_Y,    FR_C,    FR_L,    FR_M,    FR_K,                               FR_Z,    FR_F,    FR_U,    COLUMN,  QUOTES,  COMMA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, FR_I,    FR_S,    FR_R,    FR_T,    FR_G,                               FR_P,    FR_N,    FR_E,    FR_A,    FR_O,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, FR_Q,    FR_V,    FR_W,    FR_D,    FR_J,    KC_LGUI,          KC_END,  FR_B,    FR_H,    SLASH,   DOT,     FR_X,    DVORAK,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL,   KC_SPC,                  FN,      KC_LSFT, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  ONE,     TWO,     THREE,   FOUR,    FIVE,                               SIX,     SEVEN,   EIGHT,   NINE,    ZERO,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  QUOTES,  D_COMMA, D_DOT,   FR_P,    FR_Y,                               FR_F,    FR_G,    FR_C,    FR_R,    FR_L,    D_SLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, FR_A,    FR_O,    FR_E,    FR_U,    FR_I,                               FR_D,    FR_H,    FR_T,    FR_N,    FR_S,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, D_COLUMN,  FR_Q,    FR_J,    FR_K,    FR_X,    KC_LGUI,          KC_END,  FR_B,    FR_M,    FR_W,    FR_V,    FR_Z,    ISRT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL,   KC_SPC,                  FN,      KC_LSFT, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ISRT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ISRT);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ONE:
      SHIFT_NO(FR_EXLM, FR_1);
      break;
    case TWO:
      SHIFT_NO(FR_AT, FR_2);
      break;
    case THREE:
      SHIFT_NO(FR_HASH, FR_3);
      break;
    case FOUR:
      SHIFT_NO(FR_DLR, FR_4);
      break;
    case FIVE:
      SHIFT_NO(FR_PERC, FR_5);
      break;
    case SIX:
      SHIFT_NO(FR_CIRC, FR_6);
      break;
    case SEVEN:
      SHIFT_NO(FR_AMPR, FR_7);
      break;
    case EIGHT:
      SHIFT_NO(FR_ASTR, FR_8);
      break;
    case NINE:
      SHIFT_NO(FR_LPRN, FR_9);
      break;
    case ZERO:
      SHIFT_NO(FR_RPRN, FR_0);
      break;
    case QUOTES:
      SHIFT_NO(FR_QUOT, FR_DQUO);
      break;
    case COLUMN:
      SHIFT_NO(FR_COLN, FR_SCLN);
      break;
    case SLASH:
      SHIFT_NO(FR_SLSH, FR_UNDS);
      break;
    case DOT:
      SHIFT_NO(FR_DOT, FR_EXLM);
      break;
    case COMMA:
      SHIFT_NO(FR_COMM, FR_MINS);
      break;
    case D_COLUMN:
      SHIFT_NO(FR_SCLN, FR_COLN);
      break;
    case D_DOT:
      SHIFT_NO(FR_DOT, FR_RABK);
      break;
    case D_COMMA:
      SHIFT_NO(FR_COMM, FR_LABK);
      break;
    case D_SLASH:
      SHIFT_NO(FR_SLSH, FR_QUES);
      break;
  }
  return true;
}
