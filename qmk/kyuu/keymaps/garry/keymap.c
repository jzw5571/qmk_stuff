#include "kyuu.h"

enum {
	PASS = SAFE_RANGE,
	WILT,
	CLIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_DEL, 
		KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_PGUP, 
		KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   			KC_PGDN,  KC_NO, 
		KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_LSFT,  		  KC_UP,	MO(1), 
		MO(1),    KC_LGUI,  KC_LALT,  								KC_SPC,   								MO(2),  			KC_LEFT,  KC_DOWN,  KC_RGHT),

	KEYMAP(
		KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TILD,  KC_INS,
		KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_UP,    _______,  _______,  _______,  
		_______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT, 			  _______,  _______,  _______, 
		_______,  KC_MPRV,  KC_MNXT,  KC_MPLY,  _______,  _______,  _______,  _______,  KC_END,   KC_PGDN,  KC_DOWN,  _______,  		  _______,  _______,
		_______,  _______,  _______,  								_______,  								_______,  			_______,  _______,  _______),

	KEYMAP(
		KC_SLEP,  KC_MYCM,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,  
		_______,  PASS   ,  WILT,     CLIN,     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, 			_______,  _______,  
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  
		_______,  _______,  _______,  								_______,  								_______,  			_______,  _______,  _______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case PASS:
      if (record->event.pressed) {
        SEND_STRING("Obelisk267!");
      }
      return false;
      break;
	case WILT:
      if (record->event.pressed) {
        SEND_STRING("marthandroy45!");
      }
      return false;
      break;
	case CLIN:
      if (record->event.pressed) {
        SEND_STRING("clin9255561278");
      }
      return false;
      break;
  }
  return true;
};