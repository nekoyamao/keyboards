/* Copyright 2022 vertex
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


enum planck_layers {
    _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12, _13, _14, _15
};


void keyboard_post_init_user_td0(void) {
    vial_tap_dance_entry_t td = { LCTL(KC_SPC),
                                  KC_ESC,
                                  KC_NO,
                                  KC_NO,
                                  200 };
    dynamic_keymap_set_tap_dance(0, &td); // the first value corresponds to the TD(i) slot
}


void keyboard_post_init_user_td1(void) {
    vial_tap_dance_entry_t td = { KC_NO,
                                  MO(_05),
                                  KC_NO,
                                  KC_LCTL,
                                  200 };
    dynamic_keymap_set_tap_dance(1, &td); // the first value corresponds to the TD(i) slot
}

void keyboard_post_init_user_td2(void) {
    vial_tap_dance_entry_t td = { LALT(KC_A),
                                  MO(_03),
                                  KC_NO,
                                  KC_NO,
                                  200 };
    dynamic_keymap_set_tap_dance(2, &td); // the first value corresponds to the TD(i) slot
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_00] = LAYOUT_all(
        TD(0)  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_GRV , KC_DEL ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,         KC_BSPC,
        LGUI_T(KC_TAB),KC_A, KC_S, KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, XXXXXXX, RGUI_T(KC_ENT),
        KC_LSFT, XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          KC_RSFT, MO(4)  ,
        TD(1)  , KC_LCTL, LALT_T(KC_ENT), LSFT_T(KC_SPC),     LT(1,KC_ENT),              LT(2,KC_BSPC),    XXXXXXX, KC_RALT, KC_RGUI, TD(2)
    ),

    [_01] = LAYOUT_all(
        KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO  ,
        KC_TAB , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_BSLS,
        KC_LGUI, KC_NO  ,LSFT(KC_EQL),KC_MINS,KC_EQL,KC_LPRN, KC_RPRN,KC_LEFT , KC_UP  , KC_DOWN, KC_RGHT, KC_NO  , XXXXXXX, KC_ENT ,
        KC_LSFT, XXXXXXX, KC_NO  ,LSFT(KC_8),KC_SLASH, KC_NO, KC_LBRC,KC_RBRC , KC_HOME, KC_PGUP, KC_PGDN, KC_END ,          KC_RSFT, KC_NO  ,
        KC_LCTL, KC_LCTL, KC_LALT, LSFT_T(KC_SPACE),          KC_ENT ,                   KC_BSPC,          XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_02] = LAYOUT_all(
        KC_NO  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_GRV , KC_DEL ,
        KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LBRC, KC_RBRC,          KC_BSLS,
        KC_LGUI, KC_NO  ,LSFT(KC_EQL),KC_MINS,KC_EQL,KC_LPRN, KC_RPRN,KC_LEFT , KC_UP  , KC_DOWN, KC_RGHT, KC_NO  , XXXXXXX, KC_ENT ,
        KC_LSFT, XXXXXXX, KC_NO  ,LSFT(KC_8),KC_SLASH, KC_NO, KC_LBRC,KC_RBRC , KC_HOME, KC_PGUP, KC_PGDN, KC_END ,          KC_RSFT, KC_NO  ,
        KC_LCTL, KC_LCTL, KC_LALT, LSFT_T(KC_SPACE),          KC_ENT ,                   KC_BSPC,          XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_03] = LAYOUT_all(
        KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_LSFT, XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MUTE, KC_VOLD, KC_VOLU, KC_NO  ,          KC_RSFT, KC_NO  ,
        KC_LCTL, KC_LCTL, KC_LALT, LSFT_T(KC_SPACE),          KC_ENT ,                   KC_BSPC,          XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
    ),

    [_04] = LAYOUT_all(
        KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_VAI, RGB_M_X, RGB_M_G, RGB_M_T, RGB_HUI, RGB_MOD, RGB_TOG,          KC_BSLS,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_VAD,RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_HUD,RGB_RMOD, XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_M_P, RGB_M_B, RGB_M_R, KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_05] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_DEL ,
        QK_BOOT, KC_NO  ,LCTL(KC_W), KC_NO, KC_NO  ,LCTL(KC_T), KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  ,LCTL(KC_A),LCTL(KC_S),KC_NO,LCTL(KC_F),KC_NO, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_V),KC_NO,KC_NO, KC_NO, KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  ,LCTL(KC_LALT),     KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX,LCTL(KC_RALT),KC_NO, KC_NO
    ),

    [_06] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_07] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_08] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_09] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO 
    ),

    [_10] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_11] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [12] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_13] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),


    [_14] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),

    [_15] = LAYOUT_all(
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , XXXXXXX, KC_NO  ,
        KC_NO  , XXXXXXX, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,          KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  ,          KC_NO  ,          KC_NO  ,                   KC_NO  ,          XXXXXXX, KC_NO  , KC_NO  , KC_NO
    ),
};


/* RGBの設定 */
#ifdef RGBLIGHT_ENABLE
//const rgblight_segment_t PROGMEM rgb_layer_00[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 1, HSV_RED}  // 開始LEDインデックス, 連続する個数, 光らせる色(ここではプリセットを使用)
//);
const rgblight_segment_t PROGMEM rgb_layer_01[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_layer_02[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM rgb_layer_03[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}
);
//const rgblight_segment_t PROGMEM rgb_layer_04[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 1, HSV_MAGENTA}
//);
const rgblight_segment_t PROGMEM rgb_layer_05[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM rgb_layer_06[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM rgb_layer_07[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GOLD}
);
const rgblight_segment_t PROGMEM rgb_layer_08[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM rgb_layer_09[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM rgb_layer_10[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CORAL}
);
const rgblight_segment_t PROGMEM rgb_layer_11[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GOLDENROD}
);
const rgblight_segment_t PROGMEM rgb_layer_12[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PINK}
);
const rgblight_segment_t PROGMEM rgb_layer_13[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_layer_14[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM rgb_layer_15[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_TEAL}
);


const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    rgb_layer_00,
    rgb_layer_01,
    rgb_layer_02,
    rgb_layer_03,
//    rgb_layer_04,
    rgb_layer_05,
    rgb_layer_06,
    rgb_layer_07,
    rgb_layer_08,
    rgb_layer_09,
    rgb_layer_10,
    rgb_layer_11,
    rgb_layer_12,
    rgb_layer_13,
    rgb_layer_14,
    rgb_layer_15     // ,不要
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
//    rgblight_set_layer_state(0, layer_state_cmp(state, _00));
    rgblight_set_layer_state(0, layer_state_cmp(state, _01));
    rgblight_set_layer_state(1, layer_state_cmp(state, _02));
    rgblight_set_layer_state(2, layer_state_cmp(state, _03));
//    rgblight_set_layer_state(3, layer_state_cmp(state, _04));
    rgblight_set_layer_state(3, layer_state_cmp(state, _05));
    rgblight_set_layer_state(4, layer_state_cmp(state, _06));
    rgblight_set_layer_state(5, layer_state_cmp(state, _07));
    rgblight_set_layer_state(6, layer_state_cmp(state, _08));
    rgblight_set_layer_state(7, layer_state_cmp(state, _09));
    rgblight_set_layer_state(8, layer_state_cmp(state, _10));
    rgblight_set_layer_state(9, layer_state_cmp(state, _11));
    rgblight_set_layer_state(10, layer_state_cmp(state, _12));
    rgblight_set_layer_state(11, layer_state_cmp(state, _13));
    rgblight_set_layer_state(12, layer_state_cmp(state, _14));
    rgblight_set_layer_state(13, layer_state_cmp(state, _15));
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
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case _02:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            break;
        case _03:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;
//        case _04:
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
//            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
//            break;
        case _05:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;
        case _06:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        case _07:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_GOLD);
            break;
        case _08:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_CHARTREUSE);
            break;
        case _09:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_CYAN);
            break;
        case _10:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break;
        case _11:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_GOLDENROD);
            break;
        case _12:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_PINK);
            break;
        case _13:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
            break;
        case _14:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_AZURE);
            break;
        case _15:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
            rgb_matrix_sethsv_noeeprom(HSV_TEAL);
            break;
       default:
            rgb_matrix_reload_from_eeprom();
    }
  return state;
}
#endif 
