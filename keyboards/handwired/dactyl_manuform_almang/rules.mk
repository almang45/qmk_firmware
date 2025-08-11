# Bootloader selection
BOOTLOADER = rp2040

# Optional: Custom build optimizations
LTO_ENABLE = yes

# Optional: Reduce firmware size
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Note: The following features are now configured in keyboard.json:
# - SPLIT_KEYBOARD (conflicts resolved)
# - ENCODER_ENABLE (conflicts resolved)
# - OLED_ENABLE (conflicts resolved)
# - RGB_MATRIX_ENABLE (conflicts resolved)
# - All other features moved to JSON
