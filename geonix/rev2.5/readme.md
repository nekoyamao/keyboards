# Geonix Rev.2.5



A compact 40% (12x4) ortholinear keyboard kit designed by Masro and sold by Chosfox.

* Keyboard Maintainer: [Chosfox]
* Hardware Supported: rev.2.5 Dual-1u PCB
* Hardware Availability: [Chosfox](https://chosfox.com/)

## Source code for Vial port

Specification:
* **PCB**: Support for rev.2.5 Dual-1u PCB ONLY, NOT for other PCBs
* **Layout**: Support for Dual-1u layout(48 keys)
* **Layers**: 13 layers
* **LED**: Support for RGB Matrix
* **Tap Dance**: Supported and 16 settings are available
* **Combo**: Supported and 16 settings are available
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

Make example for this keyboard (after setting up your build environment):

    make geonix/rev2.5:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    To use QMK Tool Box to flash firmware

## Bootloader

Enter the bootloader in following way:

* **Keycode in layout**: Press the key mapped to `RESET` if it is available
