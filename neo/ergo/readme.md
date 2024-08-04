# Neo Ergo Wired - PCB

![neo ergo wired](https://assets.st-note.com/production/uploads/images/148034529/rectangle_large_type_2_99daf56016a3eb9778a23512267d6527.jpeg?width=2000&height=2000&fit=bounds&quality=85)

An Alice style board with arrowkeys made by NEO Studio.

* Keyboard Maintainer: [NEO Studio](https://github.com/owlab-git)
* Hardware Supported: Neo Ergo Wired PCB

## Source code for Vial port

Specification:

* **PCB**: Support for WIRED PCB ONLY, NOT for wireless PCB
* **Layout**: Support for multi-layout ex.) split-BS, split left shift, arrow keys and so on
* **Layers**: 16 layers
* **LED**: Support for RGB Matrix and 16 LEDs
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

For more information, please see [blog](https://note.com/nekoyamaou/n/n73237d7be569).

Make example for this keyboard (after setting up your build environment):

    make neo/ergo:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    To use QMK Tool Box to flash firmware

## Bootloader

Enter the bootloader in following way:

* **Keycode in layout**: Press the key mapped to `RESET` if it is available
