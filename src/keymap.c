// programandala.net ErgoDox EZ
// Version 0.4.0+202002162146

// By Marcos Cruz (programandala.net), 2019,2020

// http://programandala.net/es.programa.programandala_net_ergodox_ez.html

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

#define _QL 0 // Spanish Qwerty layer
#define _DL 1 // Spanish Dvorak layer
#define _FL 2 // Function keys layer

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
};

// =============================================================
// Layouts

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ---------------------------------------------
// Layout 0: Spanish QWERTY
//
// This layout is needed in order to use the Spanish Dvorak layout when it's
// already selected in the OS, which is the case with my computers. That's why
// this is the first layer.

  [_QL] = LAYOUT_ergodox(

  // .........................
  // Left hand

  ES_IEXL,         KC_1,      KC_2,      KC_3,      KC_4,       KC_5,   KC_NO,
  KC_CAPSLOCK,     KC_Q,      KC_W,      KC_E,      KC_R,       KC_T,   KC_ESCAPE,
  KC_TAB,          KC_A,      KC_S,      KC_D,      KC_F,       KC_G,
  OSM(MOD_LSFT),   KC_Z,      KC_X,      KC_C,      KC_V,       KC_B,   OSL(_FL),
  TO(_DL),         ES_OVRR,   ES_LESS,   KC_LEFT,   KC_RIGHT,

             OSM(MOD_LCTL), OSM(MOD_LALT),
                            KC_HOME,
  KC_BSPACE, KC_DELETE,     KC_END,

  // .........................
  // Right hand

  KC_NO,            KC_6,      KC_7,     KC_8,       KC_9,      KC_0,      ES_APOS,
  KC_ESCAPE,        KC_Y,      KC_U,     KC_I,       KC_O,      KC_P,      ES_CCED,
                    KC_H,      KC_J,     KC_K,       KC_L,      ES_NTIL,   ES_ACUT,
  OSL(_FL),         KC_N,      KC_M,     KC_COMMA,   KC_DOT,    ES_MINS,   OSM(MOD_RSFT),
                               KC_UP,    KC_DOWN,    ES_GRV,    ES_PLUS,   TO(_DL),

  OSM(MOD_RALT), OSM(MOD_RCTL),
  KC_PGUP,
  KC_PGDOWN,     KC_ENTER,      KC_SPACE),

// ---------------------------------------------
// Layout 1: Spanish Dvorak

// This layout is needed only when the Spanish Dvorak layout is not already
// selected in the OS.

  [_DL] = LAYOUT_ergodox(

  // .........................
  // Left hand

  ES_IEXL,        KC_1,       KC_2,      KC_3,     KC_4,      KC_5,  KC_NO,
  KC_CAPSLOCK,    KC_DOT,     KC_COMMA,  ES_NTIL,  KC_P,      KC_Y,  KC_ESCAPE,
  KC_TAB,         KC_A,       KC_O,      KC_E,     KC_U,      KC_I,
  OSM(MOD_LSFT),  ES_MINS,    KC_Q,      KC_J,     KC_K,      KC_X,  OSL(_FL),
  TO(_QL),        ES_OVRR,    ES_LESS,   KC_LEFT,  KC_RIGHT,

             OSM(MOD_LCTL), OSM(MOD_LALT),
                            KC_HOME,
  KC_BSPACE, KC_DELETE,     KC_END,

  // .........................
  // Right hand

  KC_NO,           KC_6,  KC_7,    KC_8,     KC_9,    KC_0,     ES_APOS,
  KC_ESCAPE,       KC_F,  KC_G,    KC_C,     KC_H,    KC_L,     ES_CCED,
                   KC_D,  KC_R,    KC_T,     KC_N,    KC_S,     ES_ACUT,
  OSL(_FL),        KC_B,  KC_M,    KC_W,     KC_V,    KC_Z,     OSM(MOD_RSFT),
                          KC_UP,   KC_DOWN,  ES_GRV,  ES_PLUS,  TO(_QL),

  RALT_T(KC_NO), RCTL_T(KC_NO),
  KC_PGUP,
  KC_PGDOWN,     KC_ENTER,      KC_SPACE),

// ---------------------------------------------
// Layout 2: one-shot function keys

// This layout replaces the numbers with function keys. This layout is selected
// from the other layouts by `OSL()` (one-shoot layer), so a key press in this
// layout returns to the previous one.

  [_FL] = LAYOUT_ergodox(

  // .........................
  // Left hand

  KC_TRNS,         KC_F1,     KC_F2,     KC_F3,     KC_F4,      KC_F5,     KC_FN11,
  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,
  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,
  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

             KC_TRNS,       KC_TRNS,
                            KC_TRNS,
  KC_TRNS,   KC_TRNS,       KC_TRNS,

  // .........................
  // Right hand

  KC_FN12,          KC_F6,     KC_F7,    KC_F8,      KC_F9,     KC_F10,    KC_TRNS,
  KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
                    KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
  KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
                               KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,

  KC_TRNS,       KC_TRNS,
  KC_TRNS,
  KC_TRNS,       KC_TRNS,       KC_TRNS),

};

// =============================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
  }
  return true;
}

// =============================================================
// LEDs

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 0:
      break;
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    default:
      break;
  }
  return state;
};
