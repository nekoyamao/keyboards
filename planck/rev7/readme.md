# Planck rev7

![Planck](https://assets.st-note.com/production/uploads/images/138024849/rectangle_large_type_2_ae8bebd81e6a8477c89120ab45729b98.jpeg?width=2000&height=2000&fit=bounds&quality=85)

A compact 40% (12x4) ortholinear keyboard kit designed by OLKB and sold by Drop. A complete hardware rework of the rev7 Planck PCB, with support for up to 8 rotary encoders.

* Keyboard Maintainer: [Jack Humbert](https://github.com/jackhumbert)
* Hardware Supported: rev7 Planck PCB
* Hardware Availability: [Drop](https://drop.com/buy/planck-mechanical-keyboard?mode=guest_open)

## Source code for Vial port

Specification:
* **PCB**: Support for rev7 PCB ONLY, NOT for other PCBs
* **Layout**: Support for multi-layout ex.) 48 Keys, 2u Spacebar-Center/-Left&Right/-Left/-Right
* **Layers**: 23 layers
* **Rotary Encoder**: Support for 8 rotary encoders with "ENCODER_MAP_ENABLE = yes"
* **LED**: Support for RGB Matrix
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

For more information, please see [blog](https://note.com/nekoyamaou/n/nef832302f7c5).

Make example for this keyboard (after setting up your build environment):

    make planck/rev7:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    To use QMK Tool Box to flash firmware

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

## Special Thanks

[ykeisuke's achievement](https://github.com/ykeisuke/vial-qmk/tree/fix/planck-v7-wip/keyboards/planck/rev7) enables to use "ENCODER_MAP_ENABLE = yes" for Planck rev7.
