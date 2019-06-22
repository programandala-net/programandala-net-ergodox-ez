// programandala.net ErgoDox EZ
// By Marcos Cruz (programandala.net)
// 2019-06-11
// https://configure.ergodox-ez.com/ergodox-ez/layouts/JarGp/latest/0

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  TOGGLE_LAYER_COLOR,
  EPRM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,TG(2),KC_CAPSLOCK,KC_KP_DOT,KC_COMMA,ES_NTIL,KC_P,KC_Y,TG(1),KC_TAB,KC_A,KC_O,KC_E,KC_U,KC_I,KC_LSHIFT,KC_MINUS,KC_Q,KC_J,KC_K,KC_X,KC_CAPSLOCK,TG(1),ES_OVRR,ES_LESS,KC_LEFT,KC_RIGHT,KC_LCTRL,KC_LALT,KC_HOME,KC_BSPACE,KC_DELETE,KC_END,TG(2),KC_6,KC_7,KC_8,KC_9,KC_0,KC_QUOTE,KC_MINUS,KC_F,KC_G,KC_C,KC_H,KC_L,ES_CCED,KC_D,KC_R,KC_T,KC_N,KC_S,ES_APOS,KC_EQUAL,KC_B,KC_M,KC_W,KC_V,KC_Z,KC_RSHIFT,KC_UP,KC_DOWN,KC_GRAVE,ES_PLUS,KC_RGUI,RALT_T(KC_NO),RCTL_T(KC_NO),KC_PGUP,KC_PGDOWN,KC_ENTER,KC_SPACE),

};

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
