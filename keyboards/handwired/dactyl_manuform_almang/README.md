# Custom Dactyl Manuform 5x6 Pi Pico

A custom Dactyl Manuform 5x6 keyboard featuring a Raspberry Pi Pico microcontroller with advanced features including dual encoders, OLED display, and RGB underglow.

## Features

- **Microcontroller**: Raspberry Pi Pico (YD-RP2040)
- **Layout**: 5x6 matrix with ergonomic split design
- **Encoders**: 
  - 1x EC11 rotary encoder (volume control/RGB adjustment)
  - 1x Mouse scroll wheel encoder (scrolling)
- **Display**: 128x32 OLED (SSD1306) for status information
- **RGB**: 16x WS2812S LEDs for underglow/backlight
- **Connectivity**: RJ9 socket for future left half connection
- **Firmware**: QMK with full feature support

## Hardware Requirements

### Components List

| Component | Quantity | Notes |
|-----------|----------|-------|
| Raspberry Pi Pico (YD-RP2040) | 1 | Primary microcontroller |
| MX-compatible switches | 30 | Per side (60 total for both sides) |
| 1N4148 diodes | 30 | One per switch, per side |
| EC11 rotary encoder | 1 | With push button |
| Mouse scroll wheel encoder | 1 | Salvaged from mouse or purchased |
| 128x32 OLED display (SSD1306) | 1 | I2C interface |
| WS2812S RGB LEDs | 16 | Addressable RGB strip |
| RJ9 (4P4C) socket | 1 | For split connection |
| RJ9 cable | 1 | For connecting sides |
| 3D printed case | 1 set | Dactyl Manuform 5x6 design |
| Wire (various colors) | As needed | 28-30 AWG recommended |
| Heat shrink tubing | As needed | For insulation |

### Tools Required

- Soldering iron (temperature controlled)
- Solder (60/40 or lead-free)
- Wire strippers
- Flush cutters
- Multimeter
- Heat gun or lighter (for heat shrink)
- 3D printer (or access to one)

## Assembly Instructions

### 1. 3D Printing
Print the Dactyl Manuform 5x6 case files. Recommended settings:
- **Layer height**: 0.2mm
- **Infill**: 20%
- **Supports**: Yes, for overhangs
- **Material**: PLA or PETG

### 2. Matrix Wiring
1. Install switches in the 3D printed case
2. Solder 1N4148 diodes to each switch:
   - Cathode (black line) connects to row
   - Anode connects to switch pin
3. Wire columns directly between switches
4. Wire rows through the diodes
5. Connect matrix to Pi Pico following the pin assignment table

### 3. Component Installation

#### OLED Display
```
OLED → Pi Pico
VCC  → 3V3
GND  → GND
SDA  → GP8
SCL  → GP9
```

#### EC11 Rotary Encoder
```
Encoder → Pi Pico
A       → GP4
B       → GP5
SW      → GP6
VCC     → 3V3
GND     → GND
```

#### Mouse Scroll Encoder
```
Encoder → Pi Pico
A       → GP2
B       → GP3
VCC     → 3V3 (if needed)
GND     → GND
```

#### RGB LEDs
```
LEDs → Pi Pico
VCC  → VBUS (5V) or 3V3
GND  → GND
DIN  → GP7
```
Connect LEDs in series: DOUT of LED1 → DIN of LED2, etc.

#### RJ9 Socket
```
RJ9 Pin → Pi Pico → Function
1       → GND     → Ground
2       → GP0     → UART RX
3       → GP1     → UART TX
4       → VBUS    → Power
```

## QMK Firmware Setup

### 1. Install QMK
```bash
python3 -m pip install --user qmk
qmk setup
```

### 2. Add Custom Keyboard
1. Copy the `qmk_config` folder to `qmk_firmware/keyboards/handwired/dactyl_manuform_5x6_pico_custom/`
2. Navigate to QMK directory:
```bash
cd qmk_firmware
```

### 3. Compile Firmware
```bash
qmk compile -kb handwired/dactyl_manuform_5x6_pico_custom -km default
```

### 4. Flash Firmware
1. Hold BOOTSEL button while connecting Pi Pico via USB
2. Pi Pico will appear as mass storage device
3. Copy the generated `.uf2` file to the Pi Pico drive

## Configuration

### Encoder Functions

#### Default Layer (Layer 0)
- **Encoder 1 (EC11)**: Volume Up/Down
- **Encoder 2 (Scroll)**: Mouse Wheel Up/Down

#### Function Layer (Layer 2)
- **Encoder 1**: RGB Brightness/Hue adjustment
- **Encoder 2**: RGB Hue/Saturation adjustment

### RGB Lighting
- **Toggle**: RGB_TOG key
- **Modes**: Use RGB_MOD to cycle through animations
- **Brightness**: RGB_VAI/RGB_VAD keys or encoder
- **Color**: RGB_HUI/RGB_HUD keys or encoder

### OLED Display
The OLED displays:
- Current layer
- Caps Lock status
- RGB mode and settings
- Split connection status
- Custom graphics/logos

## Customization

### Adding Left Side
1. Build identical hardware for left side
2. Connect GP22 to GND on left side (handedness detection)
3. Use RJ9 cable to connect both sides
4. Flash same firmware to both sides

### Custom Keymaps
1. Modify `keymaps/default/keymap.json`
2. Add new layers as needed
3. Customize encoder functions
4. Recompile and flash firmware

### OLED Customization
Edit the OLED display code in the keymap file to show:
- Custom graphics
- System information
- Layer-specific icons
- RGB status indicators

## Troubleshooting

### Common Issues

#### Matrix Not Responding
- Check diode orientation (cathode to row)
- Verify solder joints
- Test continuity with multimeter
- Ensure correct pin assignments

#### OLED Not Working
- Verify I2C connections (SDA/SCL)
- Check OLED address (typically 0x3C)
- Ensure proper power connections
- Test with simple OLED test code

#### RGB LEDs Not Working
- Check data pin connection (GP7)
- Verify power supply (5V recommended)
- Test LED chain continuity
- Check for damaged LEDs

#### Encoders Not Responding
- Verify pin assignments
- Check encoder wiring
- Test encoder with multimeter
- Ensure proper pull-up resistors (usually internal)

#### Split Connection Issues
- Check RJ9 cable and connections
- Verify UART pins (GP0/GP1)
- Test handedness detection (GP22)
- Ensure both sides have same firmware

### Debug Commands
```bash
# Enable QMK console for debugging
qmk console

# Test matrix
qmk console -kb handwired/dactyl_manuform_5x6_pico_custom

# Check encoder values
# Use QMK Configurator for real-time testing
```

## Advanced Features

### Power Management
- USB-C power through Pi Pico
- Optional battery power for wireless operation
- Power management through split connection

### Wireless Operation
- Consider adding wireless module (future enhancement)
- Battery management circuitry
- Low-power sleep modes

### Additional Sensors
- Temperature/humidity sensor via I2C
- Gesture sensor for additional input
- Light sensor for automatic brightness

## Resources

- [QMK Documentation](https://docs.qmk.fm/)
- [Dactyl Manuform Repository](https://github.com/abstracthat/dactyl-manuform)
- [Pi Pico Pinout](https://pinout.xyz/pinout/raspberry_pi_pico)
- [WS2812 LED Guide](https://learn.adafruit.com/adafruit-neopixel-uberguide)

## License

This project is released under the GPL v2 license, same as QMK firmware.

## Contributing

Feel free to submit issues, fork the repository, and create pull requests for improvements.

## Acknowledgments

- QMK Firmware team
- Dactyl Manuform designers
- Raspberry Pi Foundation
- Open source hardware community 
