/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
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
#include "../../../lib/rdr_lib/rdr_common.h"
#include <stdlib.h>
#include <math.h>

// --- 追加: sin8が見つからない場合のフォールバック ---
#ifndef sin8
#include <math.h>
static inline uint8_t sin8(uint8_t theta) {
    return (uint8_t)((sin((double)theta * 2.0 * 3.1415926535 / 255.0) + 1.0) * 127.5);
}
#endif

/**********************系统函数***************************/
/*  键盘扫描按键延时 */
void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

/*****************rgb矩阵驱动初始化********************/
led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       },
        { 12       , 13       , 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       }, 
	{ 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , 32       , 33       , 34       , 35       }, 
	{ 36       , 42       , 37       , 38       , 39       , 40       , 41       , 43       , 44       , 45       , 46       , 47       }
},{
    // 背光灯
        { 0,   0}, { 20,  0}, { 40,  0}, { 61,  0}, { 81,  0}, {101,  0}, {122,  0}, {142,  0}, {162,  0}, {183,  0}, {203,  0}, {224,  0},
        { 0,  21}, { 20, 21}, { 40, 21}, { 61, 21}, { 81, 21}, {101, 21}, {122, 21}, {142, 21}, {162, 21}, {183, 21}, {203, 21}, {224, 21},
        { 0,  42}, { 20, 42}, { 40, 42}, { 61, 42}, { 81, 42}, {101, 42}, {122, 42}, {142, 42}, {162, 42}, {183, 42}, {203, 42}, {224, 42},
        { 0,  64}, { 20, 64}, { 40, 64}, { 61, 64}, { 81, 64}, {101, 64}, {122, 64}, {142, 64}, {162, 64}, {183, 64}, {203, 64}, {224, 64},

        {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65},
        {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65},
        {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}, {255, 65}
}, {
    // 背光灯
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,

    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0
} };

// --- 発光モード定義 ---
#define LOGO_WAVE_RGB_MODE               (1)
#define LOGO_WAVE_DS_MODE                (2)
#define LOGO_SPECTRUM_MODE               (3)
#define LOGO_BREATH_MODE                 (4)
#define LOGO_LIGHT_MODE                  (5)
#define LOGO_OFF_MODE                    (6)
#define LOGO_BLINK_MODE                  (7)
#define LOGO_RGB_BLINK_MODE              (8)
#define LOGO_RANDOM_COLOR_BLINK_MODE     (9)
#define LOGO_RGB_BREATH_MODE             (10)
#define LOGO_RANDOM_COLOR_MODE           (11)
#define LOGO_RAINDROPS_MODE              (12)
#define LOGO_JELLYBEANRAINDROPS_MODE     (13)
#define LOGO_RGB_RAINDROPS_MODE          (14)
#define LOGO_RANDOM_COLOR_RAINDROPS_MODE (15)
#define LOGO_REACTIVE_MODE               (16)
#define LOGO_RANDOM_COLOR_WAVE_MODE      (17)

#define LOGO_MODE_MIN               (1)
#define LOGO_MODE_MAX               (17)

// --- 制御用パラメータ ---
#define LOGO_VAL_STEP               (17)
#define LOGO_VAL_MAX                (255)
#define LOGO_VAL_MIN                (0)

#define LOGO_HUE_STEP               (8)
#define LOGO_SAT_STEP               (17)

#define LOGO_SPEED_MIN              (1)
#define LOGO_SPEED_MAX              (5)
#define LOGO_SPEED_DEFAULT          (3)

// --- LED定義 ---
static const uint8_t logo_leds[] = {
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
    58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70, 71, 72, 73, 74, 75, 76
};
#define LOGO_LED_COUNT (sizeof(logo_leds) / sizeof(logo_leds[0]))

// --- グローバル変数 ---
bool logo_enable = true;
uint8_t logo_mode = LOGO_WAVE_RGB_MODE;
uint8_t logo_val = LOGO_VAL_MAX;
uint8_t logo_speed = LOGO_SPEED_DEFAULT;
uint8_t logo_hue = 0;
uint8_t logo_sat = 255;
uint32_t last_key_pressed_time = 0;

// ランダムカラー用変数
static uint8_t current_random_hue = 0;
static uint8_t target_random_hue = 0;

// Raindropsアニメーション用状態保持バッファ
static uint8_t drop_val[LOGO_LED_COUNT] = {0};
static uint8_t drop_hue[LOGO_LED_COUNT] = {0};

// サイン波近似テーブル
static const uint8_t sin_lut[64] = {
      0,   0,   1,   3,   6,  10,  15,  21,
     28,  36,  45,  54,  64,  75,  87,  99,
    112, 125, 138, 151, 164, 177, 189, 200,
    211, 221, 230, 237, 244, 248, 252, 254,
    255, 254, 252, 248, 244, 237, 230, 221,
    211, 200, 189, 177, 164, 151, 138, 125,
    112,  99,  87,  75,  64,  54,  45,  36,
     28,  21,  15,  10,   6,   3,   1,   0
};

static uint8_t get_smooth_wave_val(uint16_t phase) {
    return sin_lut[(phase / 4) % 64];
}

// 全LED一括色設定
void set_logo_colors(uint8_t r, uint8_t g, uint8_t b) {
    uint8_t scaled_r = (uint16_t)r * logo_val / 255;
    uint8_t scaled_g = (uint16_t)g * logo_val / 255;
    uint8_t scaled_b = (uint16_t)b * logo_val / 255;

    for (uint8_t i = 0; i < LOGO_LED_COUNT; i++) {
        rgb_matrix_set_color(logo_leds[i], scaled_r, scaled_g, scaled_b);
    }
}

// 反時計回りに2つの波（2周分）で滑らかに周回するウェーブ関数
void set_logo_wave_colors(uint32_t scaled_time, bool is_rgb, uint8_t custom_hue) {
    uint16_t time_offset = (scaled_time / 16) % 65536;

    for (uint8_t i = 0; i < LOGO_LED_COUNT; i++) {
        uint8_t val = 255;
        uint8_t hue = custom_hue;

        uint16_t pos_phase = (uint16_t)i * 512 / LOGO_LED_COUNT;
        uint16_t current_phase = (pos_phase + 65536 - (time_offset % 512)) % 256;

        if (is_rgb) {
            hue = (custom_hue + current_phase) % 256;
        } else {
            val = get_smooth_wave_val(current_phase);
        }

        RGB rgb = hsv_to_rgb((HSV){hue, logo_sat, val});
        
        uint8_t scaled_r = (uint16_t)rgb.r * logo_val / 255;
        uint8_t scaled_g = (uint16_t)rgb.g * logo_val / 255;
        uint8_t scaled_b = (uint16_t)rgb.b * logo_val / 255;

        rgb_matrix_set_color(logo_leds[i], scaled_r, scaled_g, scaled_b);
    }
}

// Raindrops 処理共通関数
void process_raindrops(uint8_t mode_type, uint32_t scaled_time) {
    static uint32_t last_spawn = 0;
    uint32_t spawn_interval = 120 / logo_speed;

    if (timer_elapsed32(last_spawn) > spawn_interval) {
        last_spawn = timer_read32();
        uint8_t idx = rand() % LOGO_LED_COUNT;
        if (drop_val[idx] == 0) {
            drop_val[idx] = 255;
            if (mode_type == 1) {
                drop_hue[idx] = rand() % 256;
            }
        }
    }

    for (uint8_t i = 0; i < LOGO_LED_COUNT; i++) {
        if (drop_val[i] > 0) {
            uint8_t decay = 4 + logo_speed;
            drop_val[i] = (drop_val[i] > decay) ? (drop_val[i] - decay) : 0;
        }

        uint8_t h = logo_hue;
        if (mode_type == 1) {
            h = drop_hue[i];
        } else if (mode_type == 2) {
            h = (scaled_time / 80 + i * 8) % 256;
        } else if (mode_type == 3) {
            h = current_random_hue;
        }

        RGB rgb = hsv_to_rgb((HSV){h, logo_sat, drop_val[i]});
        uint8_t scaled_r = (uint16_t)rgb.r * logo_val / 255;
        uint8_t scaled_g = (uint16_t)rgb.g * logo_val / 255;
        uint8_t scaled_b = (uint16_t)rgb.b * logo_val / 255;

        rgb_matrix_set_color(logo_leds[i], scaled_r, scaled_g, scaled_b);
    }
}

// --- キー入力処理 ---
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    Usb_Change_Mode_Delay = 0;
    Usb_Change_Mode_Wakeup = false;

    if (record->event.pressed) {
        last_key_pressed_time = timer_read32();

        switch (keycode) {
            case LOGO_TOG:
                logo_enable = !logo_enable;
                break;

            case LOGO_HUI:
                logo_hue += LOGO_HUE_STEP;
                break;

            case LOGO_HUD:
                logo_hue -= LOGO_HUE_STEP;
                break;

            case LOGO_SAI:
                if (logo_sat + LOGO_SAT_STEP > 255) logo_sat = 255;
                else logo_sat += LOGO_SAT_STEP;
                break;

            case LOGO_SAD:
                if (logo_sat < LOGO_SAT_STEP) logo_sat = 0;
                else logo_sat -= LOGO_SAT_STEP;
                break;

            case LOGO_VAI:
                if (logo_val + LOGO_VAL_STEP > LOGO_VAL_MAX) logo_val = LOGO_VAL_MAX;
                else logo_val += LOGO_VAL_STEP;
                break;

            case LOGO_VAD:
                if (logo_val < LOGO_VAL_MIN + LOGO_VAL_STEP) logo_val = LOGO_VAL_MIN;
                else logo_val -= LOGO_VAL_STEP;
                break;

            case LOGO_SPI:
                if (logo_speed < LOGO_SPEED_MAX) logo_speed++;
                break;

            case LOGO_SPD:
                if (logo_speed > LOGO_SPEED_MIN) logo_speed--;
                break;

            case LOGO_MOD:
                logo_mode++;
                if (logo_mode > LOGO_MODE_MAX) logo_mode = LOGO_MODE_MIN;
                break;

            case LOGO_RMOD:
                if (logo_mode <= LOGO_MODE_MIN) {
                    logo_mode = LOGO_MODE_MAX;
                } else {
                    logo_mode--;
                }
                break;

            default:
                break;
        }
    }

    return Key_Value_Dispose(keycode, record);
}

// --- LED描画処理 ---
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();

    if (!logo_enable) {
        set_logo_colors(0, 0, 0);
        return false;
    }

    uint32_t scaled_time = timer_read32() * logo_speed;
    RGB current_hsv_rgb = hsv_to_rgb((HSV){logo_hue, logo_sat, 255});

    switch (logo_mode) {
        case LOGO_WAVE_RGB_MODE: {
            // 1
            set_logo_wave_colors(scaled_time, true, logo_hue);
            break;
        }

        case LOGO_WAVE_DS_MODE: {
            // 2
            set_logo_wave_colors(scaled_time, false, logo_hue);
            break;
        }

        case LOGO_SPECTRUM_MODE: {
            // 3
            uint8_t hue = (scaled_time / 80) % 256;
            RGB rgb = hsv_to_rgb((HSV){hue, logo_sat, 255});
            set_logo_colors(rgb.r, rgb.g, rgb.b);
            break;
        }

        case LOGO_BREATH_MODE: {
            // 4
            uint8_t val = get_smooth_wave_val((scaled_time / 15) % 256);
            RGB rgb = hsv_to_rgb((HSV){logo_hue, logo_sat, val});
            set_logo_colors(rgb.r, rgb.g, rgb.b);
            break;
        }

        case LOGO_LIGHT_MODE: {
            // 5
            set_logo_colors(current_hsv_rgb.r, current_hsv_rgb.g, current_hsv_rgb.b);
            break;
        }

        case LOGO_OFF_MODE: {
            // 6
            set_logo_colors(0, 0, 0);
            break;
        }

        case LOGO_BLINK_MODE: {
            // 7
            if ((scaled_time / 1500) % 2 == 0) {
                set_logo_colors(current_hsv_rgb.r, current_hsv_rgb.g, current_hsv_rgb.b);
            } else {
                set_logo_colors(0, 0, 0);
            }
            break;
        }

        case LOGO_RGB_BLINK_MODE: {
            // 8
            uint32_t blink_cycle = (scaled_time / 1500);
            if (blink_cycle % 2 == 0) {
                uint8_t hue = (blink_cycle * 32) % 256;
                RGB rgb = hsv_to_rgb((HSV){hue, logo_sat, 255});
                set_logo_colors(rgb.r, rgb.g, rgb.b);
            } else {
                set_logo_colors(0, 0, 0);
            }
            break;
        }

        case LOGO_RANDOM_COLOR_BLINK_MODE: {
            // 9
            uint32_t blink_cycle = (scaled_time / 1500);
            static uint32_t last_cycle = 0xFFFFFFFF;

            if (blink_cycle != last_cycle) {
                last_cycle = blink_cycle;
                if (blink_cycle % 2 == 0) {
                    current_random_hue = rand() % 256;
                }
            }

            if (blink_cycle % 2 == 0) {
                RGB rgb = hsv_to_rgb((HSV){current_random_hue, logo_sat, 255});
                set_logo_colors(rgb.r, rgb.g, rgb.b);
            } else {
                set_logo_colors(0, 0, 0);
            }
            break;
        }

        case LOGO_RGB_BREATH_MODE: {
            // 10
            uint8_t hue = (scaled_time / 80) % 256;
            uint8_t val = get_smooth_wave_val((scaled_time / 15) % 256);
            RGB rgb = hsv_to_rgb((HSV){hue, logo_sat, val});
            set_logo_colors(rgb.r, rgb.g, rgb.b);
            break;
        }

        case LOGO_RANDOM_COLOR_MODE: {
            // 11
            static uint32_t last_change = 0;
            uint32_t interval = 2000 / logo_speed;

            if (timer_elapsed32(last_change) > interval) {
                last_change = timer_read32();
                target_random_hue = rand() % 256;
            }

            if (current_random_hue != target_random_hue) {
                uint8_t diff = target_random_hue - current_random_hue;
                if (diff < 128) current_random_hue++;
                else current_random_hue--;
            }

            RGB rgb = hsv_to_rgb((HSV){current_random_hue, logo_sat, 255});
            set_logo_colors(rgb.r, rgb.g, rgb.b);
            break;
        }

        case LOGO_RAINDROPS_MODE: {
            // 12
            process_raindrops(0, scaled_time);
            break;
        }

        case LOGO_JELLYBEANRAINDROPS_MODE: {
            // 13
            process_raindrops(1, scaled_time);
            break;
        }

        case LOGO_RGB_RAINDROPS_MODE: {
            // 14
            process_raindrops(2, scaled_time);
            break;
        }

        case LOGO_RANDOM_COLOR_RAINDROPS_MODE: {
            // 15
            static uint32_t last_change = 0;
            if (timer_elapsed32(last_change) > (2000 / logo_speed)) {
                last_change = timer_read32();
                target_random_hue = rand() % 256;
            }
            if (current_random_hue != target_random_hue) {
                uint8_t diff = target_random_hue - current_random_hue;
                if (diff < 128) current_random_hue++;
                else current_random_hue--;
            }
            process_raindrops(3, scaled_time);
            break;
        }

        case LOGO_REACTIVE_MODE: {
            // 16
            if (timer_elapsed32(last_key_pressed_time) < 300) {
                set_logo_colors(current_hsv_rgb.r, current_hsv_rgb.g, current_hsv_rgb.b);
            } else {
                set_logo_colors(0, 0, 0);
            }
            break;
        }

        case LOGO_RANDOM_COLOR_WAVE_MODE: {
            // 17
            static uint32_t last_change = 0;
            uint32_t interval = 3000 / logo_speed;

            if (timer_elapsed32(last_change) > interval) {
                last_change = timer_read32();
                target_random_hue = rand() % 256;
            }

            if (current_random_hue != target_random_hue) {
                uint8_t diff = target_random_hue - current_random_hue;
                if (diff < 128) current_random_hue++;
                else current_random_hue--;
            }

            set_logo_wave_colors(scaled_time, false, current_random_hue);
            break;
        }

        default:
            break;
    }

    return false;
}

/************************休眠*****************************/
static bool usb_enum_done = false;

void notify_usb_device_state_change_user(struct usb_device_state usb_device_state)
{
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if (usb_device_state.configure_state == USB_DEVICE_STATE_CONFIGURED) {
            if (!usb_enum_done) { // 只在第一次 CONFIGURED 时执行
                Usb_If_Ok = true;
                Usb_If_Ok_Led = true;
                Usb_If_Ok_Delay = 0;
                usb_enum_done = true; // 标记已完成
            }
        } else {
            Usb_If_Ok = false;
            Usb_If_Ok_Led = false;
            usb_enum_done = false; // 断开时重置
        }
    } else {
        Usb_If_Ok = false;
        Usb_If_Ok_Led = false;
    }
}


void housekeeping_task_user(void) {
    User_Keyboard_Reset();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
        User_Keyboard_Post_Init();
}

void User_Consumer_Send(uint16_t Code, bool Status) {
    if (Status) {
        register_code(Code);
    } else {
        unregister_code(Code);
    }
}
