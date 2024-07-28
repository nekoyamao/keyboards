/* 
Copyright 2024 NEO

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define VIAL_KEYBOARD_UID {0x66, 0x43, 0x8B, 0x3D, 0xF4, 0xFE, 0x18, 0xBB}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}


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