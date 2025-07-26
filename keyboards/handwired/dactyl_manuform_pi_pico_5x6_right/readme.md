# Custom Dactyl Manuform 5x6 Pi Pico

A custom Dactyl Manuform 5x6 keyboard featuring a Raspberry Pi Pico microcontroller with advanced features including dual encoders, OLED display, and RGB underglow. The case is generated using [bullwinkle3000's dactyl-manuform generator](https://github.com/bullwinkle3000/dactyl-keyboard/tree/master).

* Keyboard Maintainer: [almang45](https://github.com/almang45)
* Hardware Supported: Raspberry Pi Pico and other RP2040
* Hardware Availability: https://circuitpython.org/board/vcc_gnd_yd_rp2040/

Make example for this keyboard (after setting up your build environment):

    make handwired/dactyl_manuform_pi_pico_custom:default

Flashing example for this keyboard:

    make handwired/dactyl_manuform_pi_pico_custom:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

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
