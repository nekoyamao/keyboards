/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x85, 0xA2, 0x0D, 0xD5, 0x77, 0x30, 0x0E, 0x79}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

/* WS2812 Underglow Matrix options */
#ifdef RGBLIGHT_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

/* WS2812 Underglow Matrix options */
#ifdef RGB_MATRIX_ENABLE
#define RGBLIGHT_LAYERS        // レイヤーとの連動機能の有効化
#define RGBLIGHT_MAX_LAYERS 16  // 連動するレイヤー数(最大32)

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif