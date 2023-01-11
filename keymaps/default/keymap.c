#include QMK_KEYBOARD_H

#include "keymap_french.h"

#define _ISRT 0
#define _DVORAK 1
#define _ENGRAM 2
#define _FN 3
#define _LOWER 4

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
  ENGRAM,
  FN,
  LOWER,
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

  E_ONE,
  E_TWO,
  E_THREE,
  E_FOUR,
  E_FIVE,
  E_SIX,
  E_SEVEN,
  E_EIGHT,
  E_NINE,
  E_ZERO,

  E_QUOT,
  E_DQUO,
  E_COMM,
  E_DOT,
  E_MINS,
  E_QUES,

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
     KC_LCTL, FR_Q,    FR_V,    FR_W,    FR_D,    FR_J,    KC_LGUI,          KC_END,  FR_B,    FR_H,    SLASH,   DOT,     FR_X,    _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL,   KC_SPC,                  FN,      KC_LSFT, LOWER
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
     KC_LCTL, D_COLUMN,FR_Q,    FR_J,    FR_K,    FR_X,    KC_LGUI,          KC_END,  FR_B,    FR_M,    FR_W,    FR_V,    FR_Z,    _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL,   KC_SPC,                  FN,      KC_LSFT, LOWER
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ENGRAM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  E_ONE,   E_TWO,   E_THREE, E_FOUR,  E_FIVE,                             E_SIX,   E_SEVEN, E_EIGHT, E_NINE,  E_ZERO,  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  FR_B,    FR_Y,    FR_O,    FR_U,    E_QUOT,                             E_DQUO,  FR_L,    FR_D,    FR_W,    FR_V,    FR_Z,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, FR_C,    FR_I,    FR_E,    FR_A,    E_COMM,                             E_DOT,   FR_H,    FR_T,    FR_S,    FR_N,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, FR_G,    FR_X,    FR_J,    FR_K,    E_MINS,  KC_LGUI,          KC_END,  E_QUES,  FR_R,    FR_M,    FR_F,    FR_P,    FR_Q,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LCTL,   KC_SPC,                  LOWER,   KC_LSFT, FN
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, FR_LABK, FR_RABK, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, FR_EQL,  FR_PLUS, FR_QUES, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     FR_TILD, FR_GRV,  FR_BSLS, FR_PIPE, _______, _______, _______,          _______, _______, FR_LCBR, FR_RCBR, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, ISRT,    DVORAK,  ENGRAM,  _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, FR_GRV,  _______, FR_LBRC,                            FR_RBRC, _______, FR_DEG,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, FR_EURO, FR_AT,   FR_LCBR,                            FR_RCBR, FR_HASH, FR_DLR,  _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, FR_BSLS, _______,          _______, FR_SLSH, _______, _______, _______, _______, _______,
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
    case ENGRAM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ENGRAM);
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
      } else {
        layer_off(_LOWER);
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

    // ENGRAM NUMBERS
    case E_ONE:
      SHIFT_NO(FR_PIPE, FR_1);
      break;
    case E_TWO:
      SHIFT_NO(FR_EQL, FR_2);
      break;
    case E_THREE:
      SHIFT_NO(FR_TILD, FR_3);
      break;
    case E_FOUR:
      SHIFT_NO(FR_PLUS, FR_4);
      break;
    case E_FIVE:
      SHIFT_NO(FR_LABK, FR_5);
      break;
    case E_SIX:
      SHIFT_NO(FR_RABK, FR_6);
      break;
    case E_SEVEN:
      SHIFT_NO(FR_CIRC, FR_7);
      break;
    case E_EIGHT:
      SHIFT_NO(FR_AMPR, FR_8);
      break;
    case E_NINE:
      SHIFT_NO(FR_PERC, FR_9);
      break;
    case E_ZERO:
      SHIFT_NO(FR_ASTR, FR_0);
      break;

    case E_QUOT:
      SHIFT_NO(FR_QUOT, FR_LPRN);
      break;
    case E_DQUO:
      SHIFT_NO(FR_DQUO, FR_RPRN);
      break;
    case E_COMM:
      SHIFT_NO(FR_COMM, FR_SCLN);
      break;
    case E_DOT:
      SHIFT_NO(FR_DOT, FR_COLN);
      break;
    case E_MINS:
      SHIFT_NO(FR_MINS, FR_UNDS);
      break;
    case E_QUES:
      SHIFT_NO(FR_QUES, FR_EXLM);
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
