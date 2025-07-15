# Minimal rules.mk for Dactyl Manuform Pi Pico
# Most configuration moved to keyboard.json

# Only include non-conflicting build rules here
# All features are now defined in keyboard.json to avoid conflicts

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
