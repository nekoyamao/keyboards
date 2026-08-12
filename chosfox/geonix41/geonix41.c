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
    { 0,  10},  { 20, 10},  { 40, 10},  { 60, 10}, { 80, 10}, { 100, 10}, { 120, 10}, { 140, 10}, { 160, 10}, { 180, 10}, { 200, 10}, { 224, 10}, 
    { 0,  20},  { 20, 20},  { 40, 20},  { 60, 20}, { 80, 20}, { 100, 20}, { 120, 20}, { 140, 20}, { 160, 20}, { 180, 20}, { 200, 20}, { 224, 20}, 
    { 0,  30},  { 20, 30},  { 40, 30},  { 60, 30}, { 80, 30}, { 100, 30}, { 120, 30}, { 140, 30}, { 160, 30}, { 180, 30}, { 200, 30}, { 224, 30}, 
    { 0,  40},  { 20, 40},  { 40, 40},  { 60, 40}, { 80, 40}, { 100, 40}, { 120, 40}, { 140, 40}, { 160, 40}, { 180, 40}, { 200, 40}, { 224, 40},

    { 255,65},  { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65},  { 255,65}, { 255,65},
    { 255,65},  { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65},  { 255,65}, { 255,65},
    { 255,65},  { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65}, { 255,65},  { 255,65}
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    return Key_Value_Dispose(keycode, record);
}
