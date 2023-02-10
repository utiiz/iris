#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "keymap_steno.h"

#define _ISRT 0
#define _SEMIMAK 1
#define _PLOVER 2
#define _FN 3

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
  SEMIMAK,
  PLOVER,
  FN,
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

  S_QUOT,
  S_SLASH,
  S_DOT,
  S_COMMA,
  S_MINUS,

  PLUS_EQ,
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
     KC_LCTL, FR_Q,    FR_V,    FR_W,    FR_D,    FR_J,    KC_LALT,          KC_END,  FR_B,    FR_H,    SLASH,   DOT,     FR_X,    _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LCTL, KC_SPC,                    FN,      KC_LSFT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SEMIMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  ONE,     TWO,     THREE,   FOUR,    FIVE,                               SIX,     SEVEN,   EIGHT,   NINE,    ZERO,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  FR_F,    FR_L,    FR_H,    FR_V,    FR_Z,                               FR_Q,    FR_W,    FR_U,    FR_O,    FR_Y,    COLUMN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     FN,      FR_S,    FR_R,    FR_N,    FR_T,    FR_K,                               FR_C,    FR_D,    FR_E,    FR_A,    FR_I,    KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   FR_X,    QUOTES,  FR_B,    FR_M,    FR_J,    KC_LALT,          FN,      FR_P,    FR_G,    S_COMMA, S_DOT,   S_SLASH, S_MINUS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LCTL, KC_SPC,                    FN,      KC_LSFT, KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_PLOVER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                             STN_N6,  STN_N7,  STN_N8,  STN_N9,  KC_NO,   KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                            STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                            STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     ISRT,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_NO,            KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_NO,   STN_A,   STN_O,                     STN_E,   STN_U,   FN
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, FR_LABK, FR_RABK, _______, _______,                            _______, FR_LBRC, FR_RBRC, _______, _______, ISRT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, FR_EQL,  FR_PLUS, FR_QUES, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     FR_TILD, FR_GRV,  FR_BSLS, FR_PIPE, _______, _______, PLOVER,           _______, _______, FR_LCBR, FR_RCBR, _______, _______, SEMIMAK,
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
    case SEMIMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_SEMIMAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PLOVER);
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

    case S_SLASH:
      SHIFT_NO(FR_SLSH, FR_QUES);
      break;
    case S_DOT:
      SHIFT_NO(FR_DOT, FR_RABK);
      break;
    case S_COMMA:
      SHIFT_NO(FR_COMM, FR_LABK);
      break;
    case S_MINUS:
      SHIFT_NO(FR_MINS, FR_UNDS);
      break;

    case PLUS_EQ:
      SHIFT_NO(FR_EQL, FR_PLUS);
      break;
  }
  return true;
}
