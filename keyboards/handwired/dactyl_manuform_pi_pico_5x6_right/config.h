/*
Copyright 2025 Coepoe.org <almang45@gmail.com>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

// RP2040 Bootloader Configuration
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// // Matrix Configuration - 5x6 layout
// #define MATRIX_ROWS 5
// #define MATRIX_COLS 6

// // Matrix Pin Assignments (matching your wiring plan)
// #define MATRIX_ROW_PINS { GP21, GP20, GP19, GP18, GP17 }
// #define MATRIX_COL_PINS { GP23, GP29, GP28, GP27, GP26, GP22 }

// // Diode Direction
// #define DIODE_DIRECTION COL2ROW

// // Split Keyboard Configuration
// #define SPLIT_HAND_PIN GP25  // Use GP25 for handedness detection (not GP22)
// #define SERIAL_USART_FULL_DUPLEX
// #define SERIAL_USART_TX_PIN GP1
// #define SERIAL_USART_RX_PIN GP0

// Encoder Configuration
// Encoder 1 is EC11 for volume control
// Encoder 2 is Mouse Wheel for scrolling
#define ENCODER_A_PINS { GP4, GP2 }
#define ENCODER_B_PINS { GP5, GP3 }
#define ENCODER_RESOLUTION 4

// #define OLED_IC OLED_IC_SSD1306
// #define OLED_DISPLAY_ADDRESS 0x3C

// I2C Configuration for OLED Display
#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN GP9
#define I2C1_SDA_PIN GP8
#define OLED_BRIGHTNESS 128

// RGB LED Configuration
#define WS2812_DI_PIN GP7
#define RGBLIGHT_LED_COUNT 16
#define RGBLIGHT_LIMIT_VAL 100

#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_EFFECT_RGB_TEST

// #define RGBLIGHT_RAINBOW_SWIRL_RANGE 16
