/*
Copyright 2025 Coepoe.org <almang45@gmail.com>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H

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
    [0] = LAYOUT(
        KC_PMNS, KC_PPLS, KC_PSLS, KC_PAST, KC_DEL,  KC_BSPC,
        KC_P7,   KC_P8,   KC_P9,   UG_TOGG, KC_HOME, KC_PGUP,
        KC_P4,   KC_P5,   KC_P6,   KC_COMM, KC_END,  KC_PGDN,
        KC_P1,   KC_P2,   KC_P3,   KC_PDOT, KC_VOLD, KC_VOLU,
        KC_PENT, KC_NO,   KC_P0,   KC_EQL
    )
};

#ifdef ENCODER_ENABLE
#include "encoder.h"
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {
    if (clockwise) {
        tap_code(MS_WHLU);
    } else {
        tap_code(MS_WHLD);
    }
  }
  return true;
}
#endif
