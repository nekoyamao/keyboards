# Geonix Rev.2.5

![Geonix Rev.2.5](https://assets.st-note.com/production/uploads/images/308398206/rectangle_large_type_2_236c92406a0fa10a2d15a813c13ea77e.jpeg?width=2000&height=2000&fit=bounds&quality=85)


A compact 40% (12x4) ortholinear keyboard kit designed by Masro and sold by Chosfox.

* Keyboard Maintainer: [Chosfox]
* Hardware Supported: rev.2.5 Dual-1u/2u PCB
* Hardware Availability: [Chosfox](https://chosfox.com/)

## Source code for Vial port

Specification:
* **PCB**: Support for rev.2.5 PCB, NOT for other PCBs
* **Layout**: Support for both "Dual 1u(48 keys)" and "2u Spacebar" layouts
* **Layers**: 13 layers
* **LED**: Support for RGB Matrix
* **Indicator**: Support for the status of "Num Lock", "Caps Lock", "Scroll Lock", "Compose Lock" and "Kana Lock"
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

Fork from [carlosedp/qmk_firmware](https://github.com/carlosedp/qmk_firmware),
Or copy the "rdmctmzt_common" folder and files and paste them into /vial-qmk/lib:

    Then, you will find /vial-qmk/lib/rdmctmzt_common

Make example for this keyboard (after setting up your build environment):

    make chosfox/geonix_rev25:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    Drag-and-drop firmware in DFU mode by holding TAB & Q keys in plugging the keyboard

## Bootloader

Enter the bootloader in following way:

* **Keycode in layout**: Press the key mapped to `RESET` if it is available
