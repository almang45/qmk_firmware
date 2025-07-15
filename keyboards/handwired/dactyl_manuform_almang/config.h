/*
 * Custom Dactyl Manuform 5x6 Pi Pico Configuration
 * Features: OLED, dual encoders, RGB underglow, split keyboard
 */

#pragma once

// RP2040-specific settings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

// OLED Display Configuration
#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X32
    #define OLED_TIMEOUT 30000
    #define OLED_BRIGHTNESS 128
    #define OLED_UPDATE_INTERVAL 50
#endif

// Split keyboard configuration
#ifdef SPLIT_KEYBOARD
    #define SPLIT_HAND_PIN_LOW_IS_LEFT
    #define SERIAL_USART_FULL_DUPLEX
    #define SERIAL_USART_TX_PIN GP0
    #define SERIAL_USART_RX_PIN GP1
    #define SERIAL_USART_PIN_SWAP
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_OLED_ENABLE
    #define SPLIT_TRANSPORT_MIRROR
#endif

// Encoder configuration
#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTION 4
    #define ENCODER_DEFAULT_POS 0x3
#endif

// RGB Matrix Configuration
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_TIMEOUT 300000
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_KEYRELEASES
#endif

// Timing and debounce settings
#define DEBOUNCE 5
#define MATRIX_IO_DELAY 30
#define TAP_CODE_DELAY 10

// USB power management
#define USB_SUSPEND_WAKEUP_DELAY 0

// Performance optimizations
// Note: FORCE_NKRO and QMK_KEYS_PER_SCAN moved to JSON configuration

// Feature configurations
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// Unicode support
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

// Bootmagic configuration
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

// Tapping term
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
