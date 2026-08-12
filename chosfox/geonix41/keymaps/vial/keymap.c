/* Copyright 2023 Yiancar-Designs
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
#include QMK_KEYBOARD_H
#include "../../../lib/rdr_lib/rdr_common.h"

enum planck_layers {
    _00, _01, _02, _03, _04, _05, _06,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_00] = LAYOUT_tkl_ansi(
        KC_TAB,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,  
        KC_ESC,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_UP ,   KC_ENT,
        MO(2),   KC_DEL,  KC_LCTL,   KC_LALT,  KC_LGUI,    KC_SPC,    KC_SPC,   KC_RGUI, KC_SLSH, KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [_01] = LAYOUT_tkl_ansi(
        KC_TAB,  KC_Q,    KC_W,      KC_E,     KC_R,       KC_T,      KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,  
        KC_ESC,  KC_A,    KC_S,      KC_D,     KC_F,       KC_G,      KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  
        KC_LSFT, KC_Z,    KC_X,      KC_C,     KC_V,       KC_B,      KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_UP ,   KC_ENT,
        MO(3),   KC_DEL,  KC_LCTL,   KC_LGUI,  KC_LALT,    KC_SPC,    KC_SPC,   KC_RGUI, KC_SLSH, KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
    [_02] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     RGB_MOD,   TO(1),    TO(0),   KC_LBRC, KC_RBRC,  KC_BSLS,  RGB_RTOG,  
        KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  
        KC_LSFT, KC_INS,  KC_DEL,    KC_HOME,  KC_END,     KC_PGUP,   KC_PGDN,  KC_M,    KC_COMM, KC_DOT,   RGB_VAI , LOGO_MOD,
        KC_NO,   QK_DEB,  QK_BAT,   TIME_ST,   KC_LGUI,    U_EE_CLR,  KC_SPC,   KC_RGUI, KC_EQL,  RGB_SPD,  RGB_VAD,  RGB_SPI
    ),
    [_03] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G,     RGB_MOD,   TO(1),    TO(0),   KC_LBRC, KC_RBRC,  KC_BSLS,  RGB_RTOG,  
        KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,       KC_5,      KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  
        KC_LSFT, KC_INS,  KC_DEL,    KC_HOME,  KC_END,     KC_PGUP,   KC_PGDN,  KC_M,    KC_COMM, KC_DOT,   RGB_VAI , LOGO_MOD,
        KC_NO,   QK_DEB,  QK_BAT,   TIME_ST,   KC_LALT,    U_EE_CLR,  KC_SPC,   KC_RGUI, KC_EQL,  RGB_SPD,  RGB_VAD,  RGB_SPI
    ),
    [_04] = LAYOUT_tkl_ansi(
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO, 
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,  
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
    ),
    [_05] = LAYOUT_tkl_ansi(
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO, 
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,  
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
    ),
    [_06] = LAYOUT_tkl_ansi(
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO, 
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,  
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
    ),
};

#ifdef RGB_MATRIX_ENABLE
layer_state_t layer_state_set_user(layer_state_t state){
  uint8_t layer = biton32(state);
  switch (layer){
        case _01:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_effect_goon);
            break;
        case _03:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_effect_numrow);
            break;
        case _04:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_effect_function);
            break;
        case _05:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_effect_symbol);
            break;
        case _06:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_my_effect_mouse);
            break;
       default:
            rgb_matrix_reload_from_eeprom();
    }
  return state;
}
#endif