/*
Copyright 2025 Coepoe.org <almang45@gmail.com>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐
     * │ - │ + │ / │ * │Del│Bsp│
     * ├───┼───┼───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │RGB│Hom│PgU│
     * ├───┼───┼───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ , │End│PgD│
     * ├───┼───┼───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ . │V- │V+ │
     * └───┴───┼───┼───┼───┴───┘
     *     ┌───┤ 0 │ = │
     * ┌───┤   ├───┴───┘
     * │Ent├───┘
     * └───┘
     */
    [_BASE] = LAYOUT(
        KC_PMNS,   KC_PPLS,   KC_PSLS,   KC_PAST,   KC_DEL,    KC_BSPC,
        KC_P7,     KC_P8,     KC_P9,     UG_NEXT,   KC_HOME,   KC_PGUP,
        KC_P4,     KC_P5,     KC_P6,     KC_PCMM,   KC_END,    KC_PGDN,
        KC_P1,     KC_P2,     KC_P3,     KC_PDOT,   KC_VOLD,   KC_VOLU,
        KC_PENT,   MO(_FN),   KC_P0,     KC_PEQL
    ),
    [_FN] = LAYOUT(
        KC_ESC,    _______,   _______,   _______,   _______,   KC_DEL,
        _______,   _______,   KC_UP,     UG_PREV,   UG_TOGG,   _______,
        _______,   KC_LEFT,   KC_DOWN,   KC_RIGHT,  _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,
        KC_SPC,    _______,   _______,   _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FN]   = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(UG_SPDU, UG_SPDD)  }
};
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: Default\n"), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
