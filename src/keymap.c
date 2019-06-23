// programandala.net ErgoDox EZ
// Version 0.2.0+201906231724
 
// By Marcos Cruz (programandala.net), 2019

// 2019-06-23

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

  [0] = LAYOUT_ergodox(

	// Left hand, row 1:
	ES_IEXL,
	KC_1,
	KC_2,
	KC_3,
	KC_4,
	KC_5,
	KC_TRANSPARENT,

	// Left hand, row 2:
	KC_CAPSLOCK,
	KC_Q,
	KC_W,
	KC_E,
	KC_R,
	KC_T,
	KC_ESCAPE,

	// Left hand, row 3:
	KC_TAB,
	KC_A,
	KC_S,
	KC_D,
	KC_F,
	KC_G,

	// Left hand, row 4:
	OSM(MOD_LSFT),
	KC_Z,
	KC_X,
	KC_C,
	KC_V,
	KC_B,
	KC_TRANSPARENT,

	// Left hand, row 5:
	TG(1),
	ES_OVRR,
	ES_LESS,
	KC_LEFT,
	KC_RIGHT,

	// Left thumb:
	OSM(MOD_LCTL),
	OSM(MOD_LALT),
	KC_HOME,
	KC_BSPACE,
	KC_DELETE,
	KC_END,

	// Right hand, row 1:
	KC_TRANSPARENT,
	KC_6,
	KC_7,
	KC_8,
	KC_9,
	KC_0,
	ES_APOS,

	// Right hand, row 2:
	KC_ESCAPE,
	KC_Y,
	KC_U,
	KC_I,
	KC_O,
	KC_P,
	ES_CCED,

	// Right hand, row 3:
	KC_H,
	KC_J,
	KC_K,
	KC_L,
	ES_NTIL,
	ES_ACUT,

	// Right hand, row 4:
	KC_TRANSPARENT,
	KC_N,
	KC_M,
	KC_COMMA,
	KC_DOT,
	ES_MINS,
	OSM(MOD_RSFT),

	// Right hand, row 5:
	KC_UP,
	KC_DOWN,
	ES_GRV,
	ES_PLUS,
	TG(2),

	// Right thumb:
	OSM(MOD_RALT),
	OSM(MOD_RCTL),
	KC_PGUP,
	KC_PGDOWN,
	KC_ENTER,
	KC_SPACE),

// ---------------------------------------------
// Layout 1: Functions and movement

  [1] = LAYOUT_ergodox(

	// Left hand, row 1:
	KC_F12,
	KC_F1,
	KC_F2,
	KC_F3,
	KC_F4,
	KC_F5,
	KC_TRANSPARENT,

	// Left hand, row 2:
	KC_TRANSPARENT,
	KC_MS_WH_LEFT,
	KC_MS_WH_UP,
	KC_MS_WH_DOWN,
	KC_MS_WH_RIGHT,
	KC_PC_CUT,
	KC_ESCAPE,

	// Left hand, row 3:
	KC_TAB,
	KC_MS_LEFT,
	KC_MS_UP,
	KC_MS_DOWN,
	KC_MS_RIGHT,
	KC_PC_COPY,

	// Left hand, row 4:
	OSM(MOD_LSFT),
	KC_LEFT,
	KC_UP,
	KC_DOWN,
	KC_RIGHT,
	KC_PC_PASTE,
	KC_TRANSPARENT,

	// Left hand, row 5:
	TG(1),
	KC_TRANSPARENT,
	KC_TRANSPARENT,
	KC_LEFT,
	KC_RIGHT,

	// Left thumb:
	KC_MS_BTN3,
	KC_TRANSPARENT,
	KC_HOME,
	KC_MS_BTN2,
	KC_MS_BTN1,
	KC_END,

	// Right hand, row 1:
	KC_TRANSPARENT,
	KC_F6,
	KC_F7,
	KC_F8,
	KC_F9,
	KC_F10,
	KC_F11,

	// Right hand, row 2:
	KC_ESCAPE,
	KC_PC_CUT,
	KC_MS_WH_LEFT,
	KC_MS_WH_DOWN,
	KC_MS_WH_UP,
	KC_MS_WH_RIGHT,
	KC_TRANSPARENT,

	// Right hand, row 3:
	KC_PC_COPY,
	KC_MS_LEFT,
	KC_MS_DOWN,
	KC_MS_UP,
	KC_MS_RIGHT,
	KC_TAB,

	// Right hand, row 4:
	KC_TRANSPARENT,
	KC_PC_PASTE,
	KC_LEFT,
	KC_DOWN,
	KC_UP,
	KC_RIGHT,
	OSM(MOD_RSFT),

	// Right hand, row 5:
	KC_UP,
	KC_DOWN,
	KC_TRANSPARENT,
	KC_TRANSPARENT,
	TG(2),

	// Right thumb:
	KC_TRANSPARENT,
	KC_MS_BTN3,
	KC_PGUP,
	KC_PGDOWN,
	KC_MS_BTN1,
	KC_MS_BTN2),
	
// ---------------------------------------------
// Layout 2: Spanish Dvorak

// This layout is needed only when the Spanish Dvorak layout is not already
// selected in the OS.

	[2] = LAYOUT_ergodox(

	// Left hand, row 1:
	ES_IEXL,
	KC_1,
	KC_2,
	KC_3,
	KC_4,
	KC_5,
	KC_TRANSPARENT,

	// Left hand, row 2:
	KC_CAPSLOCK,
	KC_KP_DOT,
	KC_COMMA,
	ES_NTIL,
	KC_P,
	KC_Y,
	KC_ESCAPE,

	// Left hand, row 3:
	KC_TAB,
	KC_A,
	KC_O,
	KC_E,
	KC_U,
	KC_I,

	// Left hand, row 4:
	OSM(MOD_LSFT),
	ES_MINS,
	KC_Q,
	KC_J,
	KC_K,
	KC_X,
	KC_TRANSPARENT,

	// Left hand, row 5:
	TG(1),
	ES_OVRR,
	ES_LESS,
	KC_LEFT,
	KC_RIGHT,

	// Left thumb:
	OSM(MOD_LCTL),
	OSM(MOD_LALT),
	KC_HOME,
	KC_BSPACE,
	KC_DELETE,
	KC_END,

	// Right hand, row 1:
	KC_TRANSPARENT,
	KC_6,
	KC_7,
	KC_8,
	KC_9,
	KC_0,
	ES_APOS,

	// Right hand, row 2:
	KC_ESCAPE,
	KC_F,
	KC_G,
	KC_C,
	KC_H,
	KC_L,
	ES_CCED,

	// Right hand, row 3:
	KC_D,
	KC_R,
	KC_T,
	KC_N,
	KC_S,
	ES_ACUT,

	// Right hand, row 4:
	KC_TRANSPARENT,
	KC_B,
	KC_M,
	KC_W,
	KC_V,
	KC_Z,
	OSM(MOD_RSFT),

	// Right hand, row 5:
	KC_UP,
	KC_DOWN,
	ES_GRV,
	ES_PLUS,
	TG(2),

	// Right thumb:
	RALT_T(KC_NO),
	RCTL_T(KC_NO),
	KC_PGUP,
	KC_PGDOWN,
	KC_ENTER,
	KC_SPACE),
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
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
