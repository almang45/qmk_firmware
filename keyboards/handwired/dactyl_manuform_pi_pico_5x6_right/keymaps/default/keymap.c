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
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [_FN]   = { ENCODER_CCW_CW(UG_SPDU, UG_SPDD),  ENCODER_CCW_CW(MS_WHLL, MS_WHLR)  }
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    render_logo();
    return false;
}
#endif
