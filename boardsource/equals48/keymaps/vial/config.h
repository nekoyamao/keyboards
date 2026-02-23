// Copyright 2023 Cole Smith (@boardsource)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once


/* define RP2040 boot用 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U


/* EEPROM Driver Configuration (RP2040用でレイヤー数の増加用に追加)*/
#define WEAR_LEVELING_LOGICAL_SIZE 8192 /*8192 is just an example*/
#define WEAR_LEVELING_BACKING_SIZE 16384 // (WEAR_LEVELING_LOGICAL_SIZE * 2)


/* define layer size */
#define DYNAMIC_KEYMAP_LAYER_COUNT 32


/* define macro size */
#define DYNAMIC_KEYMAP_MACRO_COUNT 32


/* define VIAL用 */
#define VIAL_KEYBOARD_UID {0x08, 0x37, 0xED, 0x19, 0xE1, 0x15, 0xCD, 0xEE}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}


#ifdef RGB_MATRIX_ENABLE
#define RGBLIGHT_LAYERS           // レイヤーとの連動機能の有効化
#define RGBLIGHT_MAX_LAYERS 32    // 連動するレイヤー数(最大32)
#define WS2812_PIO_USE_PIO1       // RP2040用に追加
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#endif
