#include QMK_KEYBOARD_H

#define BASE 0
#define FN 1
#define UTIL 2
#define MOUS 3
#define AROW 4

#define _______ KC_TRNS

enum {
    PSWD = SAFE_RANGE,
	ARMO = 0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_60_tsangan_hhkb(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,	\
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,			\
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,					\
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(FN),	\
  MO(FN),  KC_LGUI, KC_LALT,                   KC_SPC,                                                        TD(ARMO),MO(UTIL),KC_RCTL),

[FN] = LAYOUT_60_tsangan_hhkb(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_GRV, \
  _______, RGB_MOD, RGB_HUI, RGB_TOG, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, _______, 		\
  KC_CAPS, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT, 					\
  _______,          KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,          _______, _______,\
  _______, _______, _______,                   _______,                                                       _______, _______, _______),

[UTIL] = LAYOUT_60_tsangan_hhkb(
  KC_SLEP, KC_MYCM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,	\
  _______, PSWD   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 		\
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 					\
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
  _______, _______, _______,                   _______,                                                       _______, _______, _______),
  
[MOUS] = LAYOUT_60_tsangan_hhkb(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, 		\
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______, 					\
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
  _______, _______, _______,                   KC_BTN1,                                                       _______, _______, _______),
  
[AROW] = LAYOUT_60_tsangan_hhkb(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, 		\
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, 					\
  _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
  _______, _______, _______,                   _______,                                                       _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case PSWD:
      if (record->event.pressed) {
        SEND_STRING("Obelisk267!");
      }
      return false;
      break;
  }	  
  return true;
};

bool mous_held;
void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
	if (state->pressed) {
		layer_on(MOUS);
		mous_held = true;
	}
	switch (state->count) {
	case 1: //off all layers, just base on
		if (!state->pressed) {
		layer_off(MOUS);
		layer_off(AROW);
		mous_held = false;
		}
		break;
	case 2:
		layer_on(AROW);
		layer_off(MOUS);
		break;
	}
}

void dance_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (mous_held) {
		layer_off(MOUS);
		mous_held = false;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[ARMO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_reset)
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
};