// Copyright 2023 Cole Smith (@boardsource)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once


/* define RP2040 boot用 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U


/* define layer size */
#define DYNAMIC_KEYMAP_LAYER_COUNT 30
#define LAYER_STATE_30BIT


/* define VIAL用 */
#define VIAL_KEYBOARD_UID {0x08, 0x37, 0xED, 0x19, 0xE1, 0x15, 0xCD, 0xEE}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}


#ifdef RGB_MATRIX_ENABLE
#define RGBLIGHT_LAYERS           // レイヤーとの連動機能の有効化
#define RGBLIGHT_MAX_LAYERS 30   // 連動するレイヤー数(最大32)
#define WS2812_PIO_USE_PIO1       // RP2040用に追加
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#endif

