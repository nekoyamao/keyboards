/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define VIAL_KEYBOARD_UID { 0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0x11, 0x22 }

#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1919
#define EEPROM_SIZE 1920

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4

#define EECONFIG_KB_DATA_SIZE 1

#define TRANSIENT_EEPROM_SIZE 4096



/* EEPROM Driver Configuration */
#define WEAR_LEVELING_LOGICAL_SIZE 1920 /*1536 is just an example*/
#define WEAR_LEVELING_BACKING_SIZE 3840 // (WEAR_LEVELING_LOGICAL_SIZE * 2)



/* define layer size */
#define DYNAMIC_KEYMAP_LAYER_COUNT 13

/* define macro size */
#define DYNAMIC_KEYMAP_MACRO_COUNT 16

/* define combo size */
#define VIAL_COMBO_ENTRIES 16

/* define tapdance size */
#define VIAL_TAP_DANCE_ENTRIES 16