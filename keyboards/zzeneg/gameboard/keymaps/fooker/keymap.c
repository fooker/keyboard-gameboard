// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *        .-----------------------------------------.
     *        |  Esc |   1  |   2  |   3  |   4  |   5  |
     * .------+------+------+------+------+------+------|
     * |   ^  |  Tab |   Q  |   W  |   E  |   R  |   T  |
     * |------+------+------+------+------+------+------|
     * |  F5  | Shift|   A  |   S  |   D  |   F  |   G  |
     * |------+------+------+------+------+------+------|
     * |  F8  | Ctrl |   Y  |   X  |   C  |   V  |   B  |
     * '------------------------------------------------|
     *   TG(2)    -      -  | Enter| MO(1)| Space|  Alt |
     *                      '---------------------------'
     *  Left, Down, Up, Right
     */
    // clang-format off
    [0] = LAYOUT(
                 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,
        KC_GRV,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,
        KC_F5,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,
        KC_F8,   KC_LCTL, KC_Y,    KC_X,    KC_C,    KC_V,     KC_B,
        TG(2),   XXXXXXX, XXXXXXX, KC_ENT,  MO(1),   KC_SPC,   KC_LALT,
        KC_LEFT, KC_UP,   KC_RGHT, KC_DOWN, XXXXXXX
    ),

    [1] = LAYOUT(
                 _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1,   KC_BSPC,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_F2,   KC_DEL,     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
        KC_F3,   _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______,
        KC_HOME, KC_PGUP,  KC_END, KC_PGDN, XXXXXXX
    ),

    [2] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    // clang-format on
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	if (layer_state_is(0)) {
        // WASD
		RGB_MATRIX_INDICATOR_SET_COLOR( 9, 255, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(12, 255, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(13, 255, 0, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(17, 255, 0, 0);

		return true;
	}

	if (layer_state_is(1)) {
        // BOOTLOADER
		RGB_MATRIX_INDICATOR_SET_COLOR(27, 255, 155, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(28, 255, 155, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(29, 255, 155, 0);
		RGB_MATRIX_INDICATOR_SET_COLOR(30, 255, 155, 0);

		return true;
	}

	if (layer_state_is(2)) {
        // BOOTLOADER
		RGB_MATRIX_INDICATOR_SET_COLOR(23, 255, 255, 255);

		return true;
	}

    return false;
}


void keyboard_post_init_user(void) {
	// Enables RGB, without saving settings
	rgb_matrix_enable_noeeprom();
	rgb_matrix_sethsv_noeeprom(0xC9, 0xFF, 0xFF);
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
	rgb_matrix_set_speed_noeeprom(100);
}

