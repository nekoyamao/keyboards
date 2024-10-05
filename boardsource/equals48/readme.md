# Equals48 DIY Kit

![Equals48 DIY Kit](https://assets.st-note.com/production/uploads/images/156822118/rectangle_large_type_2_8e4901cf086dc99239141d703f787824.jpeg?width=2000&height=2000&fit=bounds&quality=85)

A compact 40% (12x4) ortholinear keyboard kit sold by Boardsource.

* Keyboard Maintainer: [Cole Smith](https://github.com/boardsource)
* Hardware Supported: Equals Kit
* Hardware Availability: [boardsource](https://boardsource.xyz)
* MUC Supported: RP2040

## Source code for Vial port

Specification:
* **MCU**: Necessary to upgrade to RP2040
* **Layout**: Support for multi-layout, 48 Keys and 2u Spacebar
* **Layers**: 30 layers
* **LED**: Support for RGB Matrix, per key RGB and underglow
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

For more information, please see [blog](https://note.com/nekoyamaou/n/n7b6ce9ac2726).

Make example for this keyboard (after setting up your build environment):

    make boardsource/equals48:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    Drag-and-drop firmware in DFU mode

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
