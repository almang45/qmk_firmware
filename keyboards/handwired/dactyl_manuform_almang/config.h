/*
 * Custom Dactyl Manuform 5x6 Pi Pico Configuration
 * Features: OLED, dual encoders, RGB underglow, split keyboard
 */

#pragma once

// Basic keyboard configuration
#define VENDOR_ID       0xCUST
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Custom
#define PRODUCT         Dactyl Manuform 5x6 Pi Pico

// Matrix configuration
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// Split keyboard configuration
#define SPLIT_HAND_PIN GP22
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0
#define SPLIT_TRANSACTION_IDS_KB \
    RPC_ID_KB_CONFIG_SYNC

// OLED Configuration
#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X32
    #define OLED_BRIGHTNESS 128
    #define OLED_TIMEOUT 30000
    #define OLED_SCROLL_TIMEOUT 0
    #define I2C_DRIVER I2CD1
    #define I2C1_SDA_PIN GP8
    #define I2C1_SCL_PIN GP9
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif

// Encoder configuration
#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { GP4, GP2 }
    #define ENCODERS_PAD_B { GP5, GP3 }
    #define ENCODER_RESOLUTION 4
    #define ENCODER_MAP_ENABLE
    #define SPLIT_ENCODER_MIRROR
#endif

// RGB Light configuration
#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN GP7
    #define RGBLED_NUM 16
    #define RGBLED_SPLIT { 8, 8 }
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

    // RGB Animations
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
#endif

// Debounce configuration
#define DEBOUNCE 5

// USB Configuration
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 4

// Memory optimization
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Additional features
#define MOUSEKEY_ENABLE
#define EXTRAKEY_ENABLE
#define NKRO_ENABLE

// Tap-hold configuration
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// Power management
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

// Layer switching
#define LAYER_STATE_8BIT

// Custom user configurations
#define CUSTOM_OLED_DRIVER
#define CUSTOM_ENCODER_CALLBACK
