graph TD
    subgraph "Raspberry Pi Pico (YD-RP2040)"
        PICO["Pi Pico<br/>GP0-GP28"]
    end

    subgraph "Matrix (5x6)"
        R0["Row 0 (GP21)"]
        R1["Row 1 (GP20)"]
        R2["Row 2 (GP19)"]
        R3["Row 3 (GP18)"]
        R4["Row 4 (GP17)"]
        R5["Row 5 (GP16)"]

        C0["Col 0 (GP10)"]
        C1["Col 1 (GP11)"]
        C2["Col 2 (GP12)"]
        C3["Col 3 (GP13)"]
        C4["Col 4 (GP14)"]
        C5["Col 5 (GP15)"]

        SW1["30 Switches<br/>+ Diodes"]
    end

    subgraph "Encoders"
        ENC1["EC11 Rotary<br/>A: GP4, B: GP5<br/>SW: GP6"]
        ENC2["Scroll Wheel<br/>A: GP2, B: GP3"]
    end

    subgraph "Display"
        OLED["128x32 OLED<br/>SDA: GP8<br/>SCL: GP9"]
    end

    subgraph "RGB LEDs"
        RGB["16x WS2812S<br/>Data: GP7<br/>VCC: VBUS/3V3"]
    end

    subgraph "Split Connection"
        RJ9["RJ9 Socket<br/>Pin 1: GND<br/>Pin 2: GP0 (RX)<br/>Pin 3: GP1 (TX)<br/>Pin 4: VBUS"]
    end

    subgraph "Power"
        PWR["Power Rails<br/>3V3, GND, VBUS"]
    end

    subgraph "Handedness"
        HAND["GP22<br/>Right: Floating<br/>Left: GND"]
    end

    PICO --> R0
    PICO --> R1
    PICO --> R2
    PICO --> R3
    PICO --> R4
    PICO --> R5
    PICO --> C0
    PICO --> C1
    PICO --> C2
    PICO --> C3
    PICO --> C4
    PICO --> C5

    R0 --> SW1
    R1 --> SW1
    R2 --> SW1
    R3 --> SW1
    R4 --> SW1
    R5 --> SW1
    C0 --> SW1
    C1 --> SW1
    C2 --> SW1
    C3 --> SW1
    C4 --> SW1
    C5 --> SW1

    PICO --> ENC1
    PICO --> ENC2
    PICO --> OLED
    PICO --> RGB
    PICO --> RJ9
    PICO --> HAND

    PWR --> OLED
    PWR --> ENC1
    PWR --> ENC2
    PWR --> RGB
    PWR --> RJ9
