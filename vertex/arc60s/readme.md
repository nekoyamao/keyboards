# Arc60

![Arc60](https://assets.st-note.com/production/uploads/images/150460964/rectangle_large_type_2_baeb9379c952e50905f05f8a878aedcd.jpeg?width=2000&height=2000&fit=bounds&quality=85)

A customizable hotswap 60% keyboard.

* Keyboard Maintainer: [EASON](https://github.com/EasonQian1)
* Hardware Supported: Arc60
* Hardware Availability: [vertex-kb](https://github.com/Vertex-kb)

## Source code for Vial port

Specification:

* **PCB**: Support for 60% layout, NOT for 64-key PCB
* **Layout**: Support for multi-layout ex.) split-BS, split left shift, split right shift, tsangan, split spacebar, ANSI and ISO and so on
* **Layers**: 16 layers
* **LED**: Support for RGB Light
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

For more information, please see [blog](https://note.com/nekoyamaou/n/n42a6f4ab4669).

Make example for this keyboard (after setting up your build environment):

    make vertex/arc60s:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    Drag-and-drop firmware in DFU mode

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
