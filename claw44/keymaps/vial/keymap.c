/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

#include QMK_KEYBOARD_H
#include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12, _13, _14, _15,
    _16, _17, _18, _19, _20
};


#define KC_03_ENT LT(_03,KC_ENT)
#define KC_04_BSP LT(_04,KC_BSPC)
#define KC_05_ENT LT(_05,KC_ENT)
#define KC_05_BN1 LT(_05,KC_BTN1)
#define KC_06_BSP LT(_06,KC_BSPC)
#define KC_06_BN2 LT(_06,KC_BTN2)
#define KC_07_DEL LT(_07,KC_DEL)
#define KC_09_TAB LT(_09,KC_TAB)
#define KC_10_A LT(_10,KC_A)
#define KC_10_MNS LT(_10,KC_MINS)
#define KC_11_Z LT(_11,KC_Z)
#define KC_11_SLH LT(_11,KC_SLSH)


void keyboard_post_init_user_td0(void) {
    vial_tap_dance_entry_t td = { LCTL(KC_SPC),
                                  KC_ESC,
                                  KC_NO,
                                  KC_NO,
                                  200 };
    dynamic_keymap_set_tap_dance(0, &td); // the first value corresponds to the TD(i) slot
}

void keyboard_post_init_user_td1(void) {
    vial_tap_dance_entry_t td = { KC_ENT,
                                  MO(_03),
                                  KC_NO,
                                  TO(_01),
                                  200 };
    dynamic_keymap_set_tap_dance(1, &td); // the first value corresponds to the TD(i) slot
}

void keyboard_post_init_user_td2(void) {
    vial_tap_dance_entry_t td = { KC_NO,
                                  MO(_02),
                                  KC_NO,
                                  TO(_02),
                                  200 };
    dynamic_keymap_set_tap_dance(2, &td); // the first value corresponds to the TD(i) slot
}

void keyboard_post_init_user_td3(void) {
    vial_tap_dance_entry_t td = { TO(_00),
                                  KC_ESC,
                                  KC_NO,
                                  KC_NO,
                                  200 };
    dynamic_keymap_set_tap_dance(3, &td); // the first value corresponds to the TD(i) slot
}

void keyboard_post_init_user_td4(void) {
    vial_tap_dance_entry_t td = { KC_NO,
                                  MO(_08),
                                  KC_NO,
                                  KC_LCTL,
                                  200 };
    dynamic_keymap_set_tap_dance(3, &td); // the first value corresponds to the TD(i) slot
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_00] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(0)     , KC_Q      , KC_W      , KC_E      , KC_R      , KC_T      ,                   KC_Y      , KC_U      , KC_I      , KC_O      , KC_P      , KC_SCLN   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
       LGUI_T(KC_TAB),KC_10_A , KC_S      , KC_D      , KC_F      , KC_G      , KC_MUTE, KC_NO  , KC_H      , KC_J      , KC_K      , KC_L      , KC_10_MNS ,RGUI_T(KC_QUOT),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_LCTL   , KC_11_Z   , KC_X      , KC_C      , KC_V      , KC_B      , KC_NO  , KC_NO  , KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_11_SLH , KC_BSLS   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL),KC_04_BSP ,LSFT_T(KC_SPC), TD(1)  ,                   TD(2)     , KC_05_ENT , KC_06_BSP , KC_07_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_01] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(3)     , KC_MUTE   , LCTL(KC_W), LGUI(KC_E),LALT(KC_F4), KC_NO     ,                  LALT(KC_RGHT), KC_NO   , KC_MS_U   , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_09_TAB , KC_NO     , KC_MS_L   , LGUI(KC_D), KC_BTN1   , KC_MS_R   , KC_MUTE, KC_NO  ,LALT(KC_LEFT), KC_MS_L , KC_MS_D   , KC_MS_R   , KC_NO     , MO(_09)   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(4)     , KC_NO     , KC_MPRV   , KC_LEFT   , KC_RGHT   , KC_MNXT   , KC_NO  , KC_NO  , KC_NO     , KC_WH_L   , KC_WH_D   , KC_WH_U   , KC_WH_R   , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL),KC_04_BSP , _______   , KC_03_ENT ,                   TO(_00)   , KC_05_BN1 , KC_06_BN2 , KC_07_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_02] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(0)     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_PERC   ,                   KC_NO     , KC_P7     , KC_P8     , KC_P9     ,LSFT(KC_EQL),LSFT(KC_8),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_09_TAB , KC_NO     ,LSFT(KC_EQL), KC_MINS  , KC_EQL    , KC_NO     , KC_NO  , KC_NO  , KC_PERC   , KC_P4     , KC_P5     , KC_P6     , KC_MINS   , KC_SLSH   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(4)     , KC_NO     ,LSFT(KC_8) , KC_SLSH   , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_P0     , KC_P1     , KC_P2     , KC_P3     , KC_EQL    , KC_RSFT   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL),KC_04_BSP , _______   , KC_03_ENT ,                   TO(_00)   , _______   , KC_06_BSP , KC_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_03] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(0)     , KC_Q      , KC_W      , KC_E      , KC_R      , KC_T      ,                   KC_Y      , KC_U      , KC_I      , KC_O      , KC_P      , KC_SCLN   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
       LGUI_T(KC_TAB), KC_A   , KC_S      , KC_D      , KC_F      , KC_G      , KC_NO  , KC_NO  , KC_H      , KC_J      , KC_K      , KC_L      , KC_MINS   ,RGUI_T(KC_QUOT),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_LCTL   , KC_Z      , KC_X      , KC_C      , KC_V      , KC_B      , KC_NO  , KC_NO  , KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_SLSH   , KC_BSLS   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL),KC_04_BSP , _______   , KC_NO     ,                   KC_NO     , _______   , KC_06_BSP , KC_07_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_04] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_ESC    , KC_1      , KC_2      , KC_3      , KC_4      , KC_5      ,                   KC_6      , KC_7      , KC_8      , KC_9      , KC_0      ,LSFT(KC_SCLN),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        QK_BOOT   , KC_NO     ,LSFT(KC_EQL), KC_MINS  , KC_EQL    , KC_LPRN   , KC_NO  , KC_NO  , KC_RPRN   , KC_LEFT   , KC_DOWN   , KC_UP     , KC_MINS   , KC_QUOT   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_LCTL   , KC_NO     ,LSFT(KC_8) , KC_SLSH   , KC_NO     , KC_LBRC   , KC_NO  , KC_NO  , KC_RBRC   , KC_NO     , KC_COMM   , KC_DOT    , KC_SLSH   , KC_RSFT   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_06_BSP , KC_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_05] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_ESC    , KC_F1     , KC_F2     , KC_F3     , KC_F4     , KC_F5     ,                   KC_F6     , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_MUTE   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , KC_NO     , KC_NO     ,LALT(KC_LEFT),LALT(KC_RGHT),KC_LPRN, KC_NO  , KC_NO  , KC_RPRN   , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RGHT   , KC_VOLU   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_LCTL   , KC_NO     , KC_NO     , KC_WH_L   , KC_WH_R   , KC_LBRC   , KC_NO  , KC_NO  , KC_RBRC   , KC_HOME   , KC_PGDN   , KC_PGUP   , KC_END    , KC_VOLD   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL), KC_BSPC  , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_06] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TILD   , KC_EXLM   , KC_AT     , KC_HASH   , KC_DLR    , KC_PERC   ,                   KC_CIRC   , KC_AMPR   , KC_ASTR   , KC_LPRN   , KC_RPRN   , KC_SCLN   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , KC_NO     ,LSFT(KC_EQL),KC_MINS   , KC_EQL    , KC_LPRN   , KC_NO  , KC_NO  , KC_RPRN   , KC_LEFT   , KC_DOWN   , KC_UP     , KC_MINS   , KC_QUOT   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_LCTL   , KC_NO     , LSFT(KC_8), KC_SLSH   , KC_NO     , KC_LBRC   , KC_NO  , KC_NO  , KC_RBRC   , KC_NO     , KC_COMM   , KC_DOT    , KC_SLSH   , KC_BSLS   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LALT_T(KC_DEL), KC_BSPC  , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_07] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , RGB_RMOD  , RGB_MOD   , RGB_TOG   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , RGB_TOG, KC_NO  , RGB_SPI   , KC_NO     , KC_NO     , RGB_HUD   , RGB_HUI   , RGB_VAI   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , RGB_SPD   , KC_NO     , KC_NO     , RGB_SAD   , RGB_SAI   , RGB_VAD   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_08] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , LCTL(KC_W), KC_NO     , KC_NO     , LCTL(KC_T),                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , LCTL(KC_A), LCTL(KC_S), KC_NO     , LCTL(KC_F), KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                             LCTL(KC_LALT), KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_DEL
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_09] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , LGUI(KC_E), KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , LGUI(KC_P), KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , LGUI(KC_D), KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_10] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_WH_U   , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO   , KC_MS_U   , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_WH_L   , KC_WH_D   , KC_WH_R   ,LALT(KC_RGHT),KC_NO , KC_NO  ,LALT(KC_RGHT), KC_MS_L , KC_MS_D   , KC_MS_R   , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,LALT(KC_LEFT),KC_NO , KC_NO  ,LALT(KC_LEFT), KC_WH_L   , KC_WH_D   , KC_WH_U   , KC_WH_R   , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , KC_BTN1   , KC_BTN2   , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_11] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_UP     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_UP     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_12] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_13] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_14] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_15] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_16] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_17] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_18] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),


    [_19] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

    [_20] = LAYOUT(
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,                   KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO  , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO     ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------+-----------+-----------|
                                KC_NO     , KC_NO     , _______   , KC_NO     ,                   KC_NO     , _______   , KC_NO     , KC_NO
    //                        |-----------+-----------+-----------+-----------|                 |-----------+-----------+-----------+-----------|
    ),

};


/* ロータリーエンコーダの設定 */
/* ENCODER_MAP_ENABLEのパターン キーマップのレイヤー数を減らす必要がある */
#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
          // Mappings for 1st Encoder          // Mappings for 2nd Encoder
    [_00] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_01] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_02] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_03] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_04] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_05] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_06] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_07] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_08] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_09] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_10] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_11] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_12] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_13] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_14] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_15] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_16] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_17] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_18] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_19] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_20] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
};
#endif


/* RGBの設定 */
#ifdef RGBLIGHT_ENABLE
//const rgblight_segment_t PROGMEM rgb_layer_00[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 12, HSV_RED}  // 開始LEDインデックス, 連続する個数, 光らせる色(ここではプリセットを使用)
//);
const rgblight_segment_t PROGMEM rgb_layer_01[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM rgb_layer_02[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM rgb_layer_03[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GOLD}
);
const rgblight_segment_t PROGMEM rgb_layer_04[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CYAN}
);
const rgblight_segment_t PROGMEM rgb_layer_05[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_layer_06[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GREEN}
);
//const rgblight_segment_t PROGMEM rgb_layer_07[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 12, HSV_SPRINGGREEN}
//);
const rgblight_segment_t PROGMEM rgb_layer_08[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);
const rgblight_segment_t PROGMEM rgb_layer_09[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM rgb_layer_10[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_CORAL}
);
const rgblight_segment_t PROGMEM rgb_layer_11[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_GOLDENROD}
);
const rgblight_segment_t PROGMEM rgb_layer_12[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PINK}
);
const rgblight_segment_t PROGMEM rgb_layer_13[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_layer_14[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM rgb_layer_15[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_TEAL}
);
const rgblight_segment_t PROGMEM rgb_layer_16[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_TURQUOISE}
);
const rgblight_segment_t PROGMEM rgb_layer_17[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_WHITE}
);
const rgblight_segment_t PROGMEM rgb_layer_18[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM rgb_layer_19[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM rgb_layer_20[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_AZURE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    rgb_layer_00,
    rgb_layer_01,
    rgb_layer_02,
    rgb_layer_03,
    rgb_layer_04,
    rgb_layer_05,
    rgb_layer_06,
//    rgb_layer_07     // ,不要 
    rgb_layer_08,
    rgb_layer_09,
    rgb_layer_10,
    rgb_layer_11,
    rgb_layer_12,
    rgb_layer_13,
    rgb_layer_14,
    rgb_layer_15,
    rgb_layer_16,
    rgb_layer_17,
    rgb_layer_18,
    rgb_layer_19,
    rgb_layer_20      // ,不要
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _00));
    rgblight_set_layer_state(0, layer_state_cmp(state, _01));
    rgblight_set_layer_state(1, layer_state_cmp(state, _02));
    rgblight_set_layer_state(2, layer_state_cmp(state, _03));
    rgblight_set_layer_state(3, layer_state_cmp(state, _04));
    rgblight_set_layer_state(4, layer_state_cmp(state, _05));
    rgblight_set_layer_state(5, layer_state_cmp(state, _06));
//    rgblight_set_layer_state(5, layer_state_cmp(state, _07));
    rgblight_set_layer_state(6, layer_state_cmp(state, _08));
    rgblight_set_layer_state(7, layer_state_cmp(state, _09));
    rgblight_set_layer_state(8, layer_state_cmp(state, _10));
    rgblight_set_layer_state(9, layer_state_cmp(state, _11));
    rgblight_set_layer_state(10, layer_state_cmp(state, _12));
    rgblight_set_layer_state(11, layer_state_cmp(state, _13));
    rgblight_set_layer_state(12, layer_state_cmp(state, _14));
    rgblight_set_layer_state(13, layer_state_cmp(state, _15));
    rgblight_set_layer_state(14, layer_state_cmp(state, _16));
    rgblight_set_layer_state(15, layer_state_cmp(state, _17));
    rgblight_set_layer_state(16, layer_state_cmp(state, _18));
    rgblight_set_layer_state(17, layer_state_cmp(state, _19));
    rgblight_set_layer_state(18, layer_state_cmp(state, _20));
    return state;
}
#endif


#ifdef RGB_MATRIX_ENABLE
layer_state_t layer_state_set_user(layer_state_t state){
  uint8_t layer = biton32(state);
  switch (layer){
//        case _00:
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//            rgb_matrix_sethsv_noeeprom(HSV_RED);
//            break;
        case _01:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _02:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_GOLD);
            break;
        case _03:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _04:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            break;
        case _05:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case _06:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            break;
//        case _07:
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//            rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
//            break;
        case _08:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;
        case _09:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_CHARTREUSE);
            break;
        case _10:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break;
        case _11:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_GOLDENROD);
            break;
        case _12:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_PINK);
            break;
        case _13:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _14:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        case _15:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_TEAL);
            break;
        case _16:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_TURQUOISE);
            break;
        case _17:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            break;
        case _18:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_YELLOW);
            break;
        case _19:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
        case _20:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_AZURE);
            break;
       default:
            rgb_matrix_reload_from_eeprom();
    }
  return state;
}
#endif 


/* OLEDの設定 */
#ifdef OLED_ENABLE

bool should_process_keypress(void) { return true; } // OLEDの情報をSlaveに伝える

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()){return OLED_ROTATION_270;
    } else {return OLED_ROTATION_270;
    }
    return rotation;
}


/* OLEDに表示するレイヤー毎に変化する画像の設定 */
static void render_logo(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!
0x00, 0xf0, 0xf8, 0x0c, 0x0c, 0x98, 0x90, 0x00, 0xff, 0xff, 0x00, 0xf0, 0xf8, 0x0c, 0x0c, 0xf8,
0xf0, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0xf8, 0xf0, 0x00, 0xf0, 0xf8, 0x4c, 0x4c, 0x78, 0x70, 0x00,

0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x83, 0x63, 0x10, 0x90, 0x11, 0x13, 0xf3, 0x01,
0x00, 0x80, 0x63, 0x13, 0x90, 0x10, 0x13, 0xf3, 0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00,

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x46, 0x41, 0x4c, 0x4f, 0xcf, 0x00, 0x00, 0xff, 0x78,
0x46, 0x41, 0x4c, 0x4f, 0xcf, 0x00, 0x00, 0xcf, 0x48, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

0x00, 0x00, 0x00, 0x08, 0xf8, 0xf8, 0xf8, 0x08, 0x00, 0x00, 0x00, 0x01, 0xe1, 0x01, 0x01, 0x00,
0xe0, 0x00, 0x80, 0xa0, 0x01, 0x01, 0x01, 0x81, 0x80, 0x00, 0x00, 0x00, 0x20, 0xe0, 0x00, 0x00,

0x18, 0x1c, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1c, 0x18, 0x00, 0x03, 0x04, 0x08, 0x04,
0x03, 0x00, 0x08, 0x0f, 0x08, 0x00, 0x04, 0x0a, 0x0a, 0x0f, 0x08, 0x00, 0x08, 0x0f, 0x08, 0x00,

0xfe, 0x12, 0x32, 0x52, 0x8c, 0x00, 0xfe, 0x12, 0x12, 0x12, 0x0c, 0x00, 0xc4, 0xa2, 0x92, 0x92,
0x8c, 0x7c, 0xa2, 0x92, 0x8a, 0x7c, 0x30, 0x2c, 0x22, 0xfe, 0x20, 0x7c, 0xa2, 0x92, 0x8a, 0x7c
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}



static void render_logo_00(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_01(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_02(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_03(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_04(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0xc4, 0xe2, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_05(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0xc4, 0xe2, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_06(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0xc4, 0xe2, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_07(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0xc4, 0xe2, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_08(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0x47, 0x23, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_09(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0x47, 0x23, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_10(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0x47, 0x23, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_11(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0x47, 0x23, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x22, 0x44, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,


0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_12(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0xc7, 0xe3, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_13(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0xc7, 0xe3, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_14(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0xc7, 0xe3, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_15(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x4f, 0xb7, 0xb7, 0xb7, 0x4f, 0xfe, 0xfc, 0xf8, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x08, 0x14, 0xfa, 0x01, 0xf1, 0x49, 0x49, 0x49, 0x92, 0x04, 0x08, 0xf0,

0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1d, 0x1d, 0x1d, 0x1e, 0x8f, 0xc7, 0xe3, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe2, 0xc4, 0x8b, 0x10, 0x11, 0x12, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_16(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0xf8, 0xec, 0x06, 0xff, 0x0f, 0xb7, 0xb7, 0xb7, 0x6e, 0xfc, 0xf8, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x23, 0x47, 0x8c, 0x1f, 0x1e, 0x1d, 0x1d, 0x1d, 0x0e, 0x07, 0x03, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_17(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0xf8, 0xec, 0x06, 0xff, 0x0f, 0xb7, 0xb7, 0xb7, 0x6e, 0xfc, 0xf8, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x23, 0x47, 0x8c, 0x1f, 0x1e, 0x1d, 0x1d, 0x1d, 0x0e, 0x07, 0x03, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_18(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0xf8, 0xec, 0x06, 0xff, 0x0f, 0xb7, 0xb7, 0xb7, 0x6e, 0xfc, 0xf8, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x23, 0x47, 0x8c, 0x1f, 0x1e, 0x1d, 0x1d, 0x1d, 0x0e, 0x07, 0x03, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_19(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0xf8, 0xec, 0x06, 0xff, 0x0f, 0xb7, 0xb7, 0xb7, 0x6e, 0xfc, 0xf8, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0x44, 0x22, 0x11, 0x08, 0x88,
0x48, 0xc8, 0x08, 0x11, 0x23, 0x47, 0x8c, 0x1f, 0x1e, 0x1d, 0x1d, 0x1d, 0x0e, 0x07, 0x03, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x8f, 0x10, 0x20, 0x40, 0x86, 0x85,
0x84, 0x9f, 0x84, 0x40, 0x20, 0x10, 0x8f, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0xfe, 0xff, 0xff, 0x7b, 0x7d, 0x01, 0x7f, 0x7f, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0xfe, 0xff, 0xff, 0x3b, 0x5d, 0x6d, 0x6d, 0x73, 0xff, 0xff, 0xfe, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void render_logo_20(void) {
    
    static const char PROGMEM my_logo[] = {
        // Paste the code from the previous step below this line!

0x00, 0xf0, 0x08, 0x04, 0x02, 0xb1, 0x49, 0x49, 0x49, 0xb1, 0x02, 0x04, 0x08, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0xf8, 0xec, 0x06, 0xff, 0x0f, 0xb7, 0xb7, 0xb7, 0x6e, 0xfc, 0xf8, 0xf0,

0x00, 0x01, 0x02, 0x04, 0x08, 0x11, 0x12, 0x12, 0x12, 0x11, 0x88, 0xc4, 0xe2, 0xf1, 0xf8, 0x78,
0xb8, 0x38, 0xf8, 0xf1, 0xe3, 0xc7, 0x8c, 0x1f, 0x1e, 0x1d, 0x1d, 0x1d, 0x0e, 0x07, 0x03, 0x01,

0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x8f, 0x1f, 0x3f, 0x7f, 0xf9, 0xfa,
0xfb, 0xe0, 0xfb, 0x7f, 0x3f, 0x1f, 0x8f, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00,

0x00, 0x7c, 0x82, 0x01, 0x00, 0x84, 0x82, 0xfe, 0x80, 0x80, 0x00, 0x01, 0x82, 0x7c, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7c, 0x82, 0x01, 0x00, 0xc4, 0xa2, 0x92, 0x92, 0x8c, 0x00, 0x01, 0x82, 0x7c,

0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}


/* OLEDの表示内容の設定 容量削減のためカット_復活させる場合は、下記のロゴのstate_1をstate_2に変更する*/

void render_layer_state_1(void) {
    switch (get_highest_layer(layer_state)) {
        case _00:
            oled_write_ln_P(PSTR("-Alph"), false);
            break;
        case _01:
            oled_write_ln_P(PSTR("-Goon"), false);
            break;
        case _02:
            oled_write_ln_P(PSTR("-Npad"), false);
            break;
        case _03:
            oled_write_ln_P(PSTR("-Alph"), false);
            break;
        case _04:
            oled_write_ln_P(PSTR("-Nrow"), false);
            break;
        case _05:
            oled_write_ln_P(PSTR("-Funk"), false);
            break;
        case _06:
            oled_write_ln_P(PSTR("-Symb"), false);
            break;
        case _07:
            oled_write_ln_P(PSTR("-RGB "), false);
            break;
        case _08:
            oled_write_ln_P(PSTR("-Ctrl"), false);
            break;
        case _09:
            oled_write_ln_P(PSTR("-Win "), false);
            break;
        case _10:
            oled_write_ln_P(PSTR("-Mous"), false);
            break;
        case _11:
            oled_write_ln_P(PSTR("-Arow"), false);
            break;
        case _12:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _13:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _14:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _15:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _16:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _17:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _18:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _19:
            oled_write_ln_P(PSTR("-    "), false);
            break;
        case _20:
            oled_write_ln_P(PSTR("-    "), false);
            break;
    }
}


void render_layer_state_2(void) {
    switch (get_highest_layer(layer_state)) {
        case _00:
            render_logo_00();
            break;
        case _01:
            render_logo_01();
            break;
        case _02:
            render_logo_02();
            break;
        case _03:
            render_logo_03();
            break;
        case _04:
            render_logo_04();
            break;
        case _05:
            render_logo_05();
            break;
        case _06:
            render_logo_06();
            break;
        case _07:
            render_logo_07();
            break;
        case _08:
            render_logo_08();
            break;
        case _09:
            render_logo_09();
            break;
        case _10:
            render_logo_10();
            break;
        case _11:
            render_logo_11();
            break;
        case _12:
            render_logo_12();
            break;
        case _13:
            render_logo_13();
            break;
        case _14:
            render_logo_14();
            break;
        case _15:
            render_logo_15();
            break;
        case _16:
            render_logo_16();
            break;
        case _17:
            render_logo_17();
            break;
        case _18:
            render_logo_18();
            break;
        case _19:
            render_logo_19();
            break;
        case _20:
            render_logo_20();
            break;
    }
}

/* key logの表示の設定 */
/*
 char keylog_str[24]  = {};
 char keylogs_str[11] = {};
 int  keylogs_str_idx = 0;

 const char code_to_name[60] = {
    '(', ')', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '!', '@', '#', '$', '%', '?',
    '&', '*', '\'', '+', '-', '=', '/', ',', '.', ';'};

 void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d: %c", record->event.key.row, record->event.key.col, keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
        keylogs_str_idx = 0;
        for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
            keylogs_str[i] = ' ';
        }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
 }

 const char *read_keylog(void) { return keylog_str; }
 const char *read_keylogs(void) { return keylogs_str; }
*/


/* OLEDの表示の制御設定 */
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo();
        oled_set_cursor(0, 7);
        render_layer_state_1();
        render_layer_state_2();
//        oled_write_ln_P(PSTR("K-log"), false);
//        oled_set_cursor(0, 13);
//        oled_write_ln(read_keylog(), false);
    } else {
        render_logo();
        oled_set_cursor(0, 7);
        render_layer_state_1();
        render_layer_state_2();
//        oled_write_ln_P(PSTR("K-log"), false);
//        oled_set_cursor(0, 13);
//        oled_write_ln(read_keylog(), false);
    }
    return false;
}

/* keyrecordの表示の設定 */
/*
 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
 }
*/

#endif
