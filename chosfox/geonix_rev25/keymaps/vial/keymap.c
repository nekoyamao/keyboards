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
#include "rdmctmzt_common.h"

enum layer_number {
    _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_00] = LAYOUT_tkl_ansi(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
        MO(2),   KC_DEL,  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_RGUI, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_01] = LAYOUT_tkl_ansi(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,
        MO(3),   KC_DEL,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_RGUI, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_02] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  RM_NEXT, TO(1),   TO(0),   KC_LBRC, KC_RBRC, KC_BSLS, RM_TOGG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_LSFT, KC_INS,  KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_M,    KC_COMM, KC_DOT,  RM_VALU, MW_CH,
        KC_NO,   DBG_SW,  QK_BAT,  KC_NO,   KC_LGUI, EE_CLR,  KC_NO,   KC_RGUI, KC_EQL,  RM_SPDD, RM_VALD, RM_SPDU
    ),
    [_03] = LAYOUT_tkl_ansi(
        MD_USB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  RM_NEXT, TO(1),   TO(0),   KC_LBRC, KC_RBRC, KC_BSLS, RM_TOGG,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_LSFT, KC_INS,  KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_M,    KC_COMM, KC_DOT,  RM_VALU, MW_CH,
        KC_NO,   DBG_SW,  QK_BAT,  KC_NO,   KC_LALT, EE_CLR,  KC_NO,   KC_RGUI, KC_EQL,  RM_SPDD, RM_VALD, RM_SPDU
    ),
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user_led(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    switch (layer) {
        case _01:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i==1 || i==36) {
                    rgb_matrix_set_color(i, RGB_RED);
                } else if ((i>=2 && i<=4) || i==15){
                    rgb_matrix_set_color(i, RGB_PINK);
                } else if (i==0 || i==11 || i==12 || i==18 || i==24 || i==30 || i==39 || (i>=41 && i<=42) || i==44) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else if (i==14 || i==17 || (i>=19 && i<=22)){
                    rgb_matrix_set_color(i, RGB_YELLOW);
                } else if (i==13 || (i>=25 && i<=26) || i==29){
                    rgb_matrix_set_color(i, RGB_GOLDENROD);
                } else if (i>=7 && i<=10){
                    rgb_matrix_set_color(i, RGB_GREEN);
                } else if (i==16){
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else if ((i>=27 && i<=28) || (i>=31 && i<=34)){
                    rgb_matrix_set_color(i, RGB_PURPLE);
                } else if (i==40 || i==43) {
                    rgb_matrix_set_color(i, RGB_SPRINGGREEN);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _03:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i==1 || i==3 || i==18 || i==30) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else if (i==2 || (i>=7 && i<=10) || (i>=13 && i<=15)){
                    rgb_matrix_set_color(i, RGB_GREEN);
                } else if (i>=19 && i<=22){
                    rgb_matrix_set_color(i, RGB_YELLOW);
                } else if (i>=31 && i<=34){
                    rgb_matrix_set_color(i, RGB_PURPLE);
                } else if (i>=42 && i<=43){
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _04:
           for (uint8_t i = led_min; i < led_max; i++) {
                if ((i>=1 && i<=2) || i==4 || (i>=6 && i<=7) || (i>=9 && i<=10)){
                    rgb_matrix_set_color(i, RGB_ORANGE);
                } else if (i==11 || (i>=22 && i<=23) || (i>=32 && i<=34)){
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else if ((i>=14 && i<=16) || (i>=26 && i<=27)){
                    rgb_matrix_set_color(i, RGB_CHARTREUSE);
                } else if (i==3 || i==5 || i==8 || (i>=17 && i<=18) || (i>=29 && i<=30)){
                    rgb_matrix_set_color(i, RGB_CYAN);
                } else if (i>=19 && i<=21){
                    rgb_matrix_set_color(i, RGB_PURPLE);
                } else if (i==24) {
                    rgb_matrix_set_color(i, RGB_RED);
                } else if (i==0 || i==12 || i==25 || (i>=41 && i<=42) || i==44) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else if (i==43) {
                    rgb_matrix_set_color(i, RGB_SPRINGGREEN);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _05:
            for (uint8_t i = led_min; i < led_max; i++) {
                if ((i>=1 && i<=2) || i==4 || (i>=6 && i<=7) || (i>=9 && i<=10)){
                    rgb_matrix_set_color(i, RGB_GREEN);
                } else if (i==3 || i==5 || i==8){
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else if ((i>=15 && i<=16) || (i>=27 && i<=28)){
                    rgb_matrix_set_color(i, RGB_TURQUOISE);
                } else if ((i>=17 && i<=18) || (i>=29 && i<=30)){
                    rgb_matrix_set_color(i, RGB_CYAN);
                } else if ((i>=19 && i<=22) || (i>=31 && i<=34)){
                    rgb_matrix_set_color(i, RGB_PURPLE);
                } else if (i==23 || i==35){
                    rgb_matrix_set_color(i, RGB_GOLDENROD);
                } else if (i==11) {
                    rgb_matrix_set_color(i, RGB_RED);
                } else if (i==0 || i==12 || i==24 || i==39 || (i>=41 && i<=42) || i==44) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else if (i==40 || i==43) {
                    rgb_matrix_set_color(i, RGB_SPRINGGREEN);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _06:
            for (uint8_t i = led_min; i < led_max; i++) {
                if ((i>=0 && i<=2) || i==4 || (i>=6 && i<=7) || (i>=9 && i<=11)|| (i>=22 && i<=23) || (i>=32 && i<=35)){
                    rgb_matrix_set_color(i, RGB_BLUE);
                } else if (i==3 || i==5 || i==8){
                    rgb_matrix_set_color(i, RGB_GREEN);
                } else if ((i>=14 && i<=16) || (i>=26 && i<=27)){
                    rgb_matrix_set_color(i, RGB_CHARTREUSE);
                } else if ((i>=17 && i<=18) || (i>=29 && i<=30)){
                    rgb_matrix_set_color(i, RGB_CYAN);
                } else if (i>=19 && i<=21){
                    rgb_matrix_set_color(i, RGB_PURPLE);
                } else if (i==12 || i==24 || i==39 || (i>=41 && i<=42)) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else if (i==40) {
                    rgb_matrix_set_color(i, RGB_SPRINGGREEN);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _07:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i==2 || i==5 || (i>=13 && i<=14) || i==16 || (i>=25 && i<=28)){
                    rgb_matrix_set_color(i, RGB_PINK);
                } else if (i==39 || i==44) {
                    rgb_matrix_set_color(i, RGB_MAGENTA);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        case _08:
            for (uint8_t i = led_min; i < led_max; i++) {
                if (i==3 || i==15 || i==10 || i==21){
                    rgb_matrix_set_color(i, RGB_PINK);
                } else {
                    rgb_matrix_set_color(i, RGB_OFF);
                }
            }
            break;
        default:
            break;
    }
    return false;
}
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user_lock(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.scroll_lock) {
        rgb_matrix_set_color(12, RGB_PURPLE);
    }
    if (led_state.compose) {
        rgb_matrix_set_color(12, RGB_CYAN);
    }
    if (led_state.kana) {
        rgb_matrix_set_color(12, RGB_PINK);
    }
    if (led_state.num_lock) {
        rgb_matrix_set_color(12, RGB_GOLD);
    }
    if (led_state.caps_lock) {
        rgb_matrix_set_color(12, RGB_RED);
    }
    return true;
}
#endif