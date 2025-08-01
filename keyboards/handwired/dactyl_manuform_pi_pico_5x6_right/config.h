/*
Copyright 2025 Coepoe.org <almang45@gmail.com>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// Encoder 1 is EC11 for volume control
// Encoder 2 is Mouse Wheel for scrolling
#define ENCODER_A_PINS { GP4, GP2 }
#define ENCODER_B_PINS { GP5, GP3 }

#define ENCODER_RESOLUTION 4

#define WS2812_DI_PIN GP7
#define RGBLIGHT_LED_COUNT 16
#define RGBLIGHT_LIMIT_VAL 155
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
