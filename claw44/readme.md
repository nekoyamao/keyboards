# Claw44

![Claw44](https://assets.st-note.com/production/uploads/images/135718401/rectangle_large_type_2_d21fc52b6de4c4c14190d6a1ab387e15.jpeg?width=1200)

A split keyboard with 3x6 vertically staggered keys and 4 thumb keys.

* Keyboard Maintainer: [yfuku](https://github.com/yfuku)
* Hardware Supported: Claw44 PCB
* Hardware Availability: https://shop.dailycraft.jp/
* * MUC Supported: RP2040

## Source code for Vial port

Specification:
* **MCU**: Necessary to upgrade to RP2040 and please see [blog](https://note.com/nekoyamaou/n/n1f1c29d85832).
* **Layers**: 21 layers
* **Rotary Encoder**: Support for 4 rotary encoders
* **OLED**: Supported
* **LED**: Support for RGB Matrix and 6 LEDs for each side
* **Tap Dance**: Supported and 32 settings are available
* **Combo**: Supported and 32 settings are available
* **Macro**: Supported and 16 settings are available
* **Extrakey**: Supported
* **Mousekey**: Supported
* **N-key Rollover**: Supported
* **Space Cadet**: Supported
* **Key Overrides**: Supported
* **Magic Keycodes**: Supported
* **Grave Escape**: Supported
* **Auto Shift**: Supported
* **One Shot Keys**: Supported
* **QMK settings in Vial**:  Supported and all features in Vial QMK settings are available

For more information, please see [blog](https://note.com/nekoyamaou/n/n671948beb4d8).

Make example for this keyboard (after setting up your build environment):

    make claw44:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    To use QMK Tool Box to flash firmware

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
