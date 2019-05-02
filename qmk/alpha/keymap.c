#include QMK_KEYBOARD_H

#define BASE 0
#define FN 1
#define LOWER 2
#define RAISE 3

enum custom_keycodes {
	LAYER = 0,
	PASS = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(LAYER),
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_B,    KC_N,    KC_M),
		
	[FN] = LAYOUT(
		RGB_MOD, RGB_HUI, RGB_TOG, KC_TAB,  _______, _______, _______, KC_UP,   KC_ENT,  KC_BSPC,
		KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
		KC_MPRV, KC_MNXT, KC_MPLY, MO(2),   KC_ESC,  MO(3),   KC_LALT, KC_LCTRL),

	[LOWER] = LAYOUT(
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
		KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_COMM, KC_DOT,  KC_SLSH,
		_______, _______, _______, _______, KC_GRV,  _______, _______, RESET),

	[RAISE] = LAYOUT(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
		KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_COLN, KC_DQUO, KC_LABK, KC_RABK, KC_QUES,
		KC_F11,  KC_F12,  _______, _______, KC_TILD, _______, _______, RESET),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool fn_key;
void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
	if (state->pressed) {
		register_code (KC_LSFT);
		fn_key = true;
	}
	switch (state->count) {
	case 1:
		if (!state->pressed) {
		layer_off(FN);
		fn_key = false;
		}
		break;
	case 2:
		layer_on(FN);
		break;
	}
}

void dance_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (fn_key) {
		unregister_code (KC_LSFT);
		fn_key = false;
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers, dance_layers_reset)
};