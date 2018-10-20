#include QMK_KEYBOARD_H

#define BASE 0
#define FN 1
#define UTIL 2
#define MKEY 3
#define AKEY 4

#define _______ KC_TRNS

enum {
    PASS = SAFE_RANGE,
	NUT,
	TWO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_all ( \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
        KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
        KC_LSFT, _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MO(FN),  _______, \
        MO(FN),  KC_LGUI, KC_LALT,                   KC_SPC,                             _______, KC_RALT, MO(UTIL),KC_RCTL),
        
    [FN] = LAYOUT_all( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_INS,  \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, KC_BSLS, \
        KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT, \
        _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, _______, _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, KC_LSFT),
		
	[UTIL] = LAYOUT_all( \
		RESET,   PASS,    NUT,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
		_______, _______, _______,                   _______,                            _______, _______, _______, _______),
};

const uint16_t PROGMEM fn_actions[] = {};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case PASS:
      if (record->event.pressed) {
        SEND_STRING("Obelisk267!");
      }
      return false;
      break;
	case NUT:
      if (record->event.pressed) {
		  SEND_STRING(SS_RALT("1234")SS_LSFT(SS_TAP(X_ENTER)));		  
		  SEND_STRING(SS_RALT("qwer")SS_LSFT(SS_TAP(X_ENTER)));		  
		  SEND_STRING(SS_RALT("wert")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("erty")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("rtyu")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("tyui")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("yuio")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("uiop")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("iop[")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("op][")SS_LSFT(SS_TAP(X_ENTER)));
		  SEND_STRING(SS_RALT("2345")SS_LSFT(SS_TAP(X_ENTER)));		  
	  }
	  return false;
      break;
	case TWO:
      if (record->event.pressed) {
		  }
	  return false;
      break;    
  }	  
  return true;
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
};
