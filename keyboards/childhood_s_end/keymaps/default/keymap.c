#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
enum layer_number {
  _QWERTY = 0,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(

       KC_ESC, JP_ZKHK,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, JP_MINS, JP_CIRC,  JP_YEN,

      RGB_HUI,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   JP_AT, JP_LBRC,  KC_ENT,

      RGB_SAI, KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L, JP_SCLN, JP_COLN, JP_RBRC,

      RGB_VAI, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, JP_SLSH, JP_BSLS, KC_RSFT, MO(_FN),

      RGB_TOG, KC_LCTL, KC_LGUI, KC_LALT, JP_MHEN,  KC_SPC,         KC_SPC,        JP_HENK, JP_KANA, KC_RALT,  KC_APP, KC_RCTL, KC_BSPC

  ),
  [_FN] = LAYOUT(

      _______, _______,   KC_F1,   KC_F2,  KC_F3,    KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,

      _______, _______, _______, _______, _______, _______,_______,_______,_______,_______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______,_______,_______,_______,_______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______,_______,_______,_______,_______, _______, _______, _______, _______, _______,

      RGB_MOD, _______, _______, _______, _______, _______,        _______,        _______, _______, _______, _______, _______,  KC_DEL
  )
};

