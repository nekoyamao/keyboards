# Neo Ergo Wired - PCB

![neo ergo wired](https://qwertykeys.notion.site/Neo-Ergo-6bd2a7b8d309439aa515bf6185c99e6d)

An Alice style board with arrowkeys made by NEO Studio.

* Keyboard Maintainer: [NEO Studio](https://github.com/owlab-git)
* Hardware Supported: Neo Ergo Wired PCB

## Source code for Vial port

Specification:
* **MCU**: Support for RP2024
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

For more information, please see https://note.com/nekoyamaou/n/n73237d7be569.

## VERY IMPORTANT

Please note that using source code is requiring to take full responsibility for your own action. Unsuccessful flash results in a bricked PCB and your fantastic keyboard life with Neo Ergo ends up at this moment.

My environment is as followed;
- Wired Non-flex cut Hotswap PCB
- Windows
- QMK Tool Box to flash firmware

I am not responsible for any loss, any damage, any disadvantage or bricked PCB caused by using the information and source code on my page. Please consider the risks and "TAKE FULL RESPONSIBILITY FOR YOUR OWN ACTION".

Make example for this keyboard (after setting up your build environment):

    make neo/ergo:vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Flashing example for this keyboard:

    To use QMK Tool Box to flash firmware

## Bootloader

Enter the bootloader in following way:

* **Keycode in layout**: Press the key mapped to `RESET` if it is available
