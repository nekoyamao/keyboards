/* Copyright 2024 Finalkey
 * Copyright 2024 LiWenLiu <https://github.com/LiuLiuQMK>
 * Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
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

#include "rdmctmzt_common.h"

#if LOGO_LED_ENABLE || SIDE_LED_ENABLE

// ============================================================================
// Variables for Idle Timeout
// ============================================================================
// 【追加】無操作でタイムアウト
static uint32_t led_idle_timer = 0;
static bool     led_is_timed_out = false;

// ============================================================================
// Helpers
// ============================================================================

void led_zone_set_color(led_zone_t *zone, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < zone->led_count; i++) {
        rgb_matrix_driver_set_color(zone->led_start + i, r, g, b);
    }
}

// ============================================================================
// Layer Priority Override Helper
// ============================================================================
// 【追加】LED_ZONEをレイヤーごとに色を変えるコマンド
static bool led_zone_apply_layer_priority(led_zone_t *zone) {
    uint8_t current_layer = get_highest_layer(layer_state);
    uint8_t r = 0, g = 0, b = 0;
    bool    override_active = true;

    switch (current_layer) {
        case 0:
            // Layer 0 のときは通常のエフェクトを維持
            override_active = false; 
            break;
        case 1:
            // Layer 1: Magenta (マゼンタ: 赤＋青)
            r = 255; g = 0; b = 255;
            break;
        case 2:
            // Layer 2 のときは通常のエフェクトを維持
            override_active = false; 
            break;
        case 3:
            // Layer 3: Pink (ピンク: マゼンタより少し明るい、または好みの配分)
            r = 255; g = 105; b = 180; // ホットピンクの例 (純粋なピンクなら r=255, g=192, b=203 など)
            break;
        case 4:
            // Layer 4: Cyan (シアン: 緑＋青)
            r = 0; g = 255; b = 255;
            break;
        case 5:
            // Layer 5: Blue (青)
            r = 0; g = 0; b = 255;
            break;
        case 6:
            // Layer 6: Green (緑)
            r = 0; g = 255; b = 0;
            break;
        case 7:
            // Layer 7: Red (赤)
            r = 255; g = 0; b = 0;
            break;
        case 8:
            // Layer 8: Chartreuse (黄緑)
            r = 127; g = 255; b = 0;
            break;
        case 9:
            // Layer 9: Orange (オレンジ)
            r = 255; g = 128; b = 0;
            break;
        case 10:
            // Layer 10: Teal (ティール)
            r = 0; g = 128; b = 128;
            break;
        case 11:
            // Layer 11: Turquoise (ターコイズ)
            r = 64; g = 224; b = 208;
            break;
        case 12:
            // Layer 12: Gold (ゴールド)
            r = 255; g = 215; b = 0;
            break;
        default:
            // Layer 13以上: Purple (パープル)
            r = 128; g = 0; b = 128;
            break;
    }

    // 上書きが有効なレイヤーの場合、他のエフェクトを無視してこの色を即座に適用
    if (override_active) {
        if (!(*zone->on_off)) {
            led_zone_set_color(zone, 0, 0, 0);
        } else {
            led_zone_set_color(zone, r, g, b);
        }
        return true; // 優先処理が適用されたことを示す
    }
    return false; // 通常のエフェクト処理に続行させる
}

// ============================================================================
// Effects (static — internal to this translation unit)
// ============================================================================

static void zone_effect_solid(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    HSV hsv = {*zone->hue, *zone->saturation, *zone->brightness};
    RGB rgb = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_breathe(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd    = (*zone->speed + 1) * 10;
    uint8_t breath = Led_Wave_Pwm_Tab[(zone->_step * spd / 10) % 128];
    uint8_t scaled = (breath * (*zone->brightness)) / 255;
    HSV     hsv    = {*zone->hue, *zone->saturation, scaled};
    RGB     rgb    = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_breathe_rgb(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd    = (*zone->speed + 1) * 10;
    
    // ブレスの明度変化（滑らかなサイン波風の明滅）
    uint8_t breath = Led_Wave_Pwm_Tab[(zone->_step * spd / 10) % 128];
    uint8_t scaled = (breath * (*zone->brightness)) / 255;
    
    // ブレスの周期に連動させつつ、色がなめらかにグラデーションしていくように調整
    uint8_t hue    = (zone->_step * spd / 20) % 256;
    
    HSV     hsv    = {hue, *zone->saturation, scaled};
    RGB     rgb    = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_spectrum(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 5;
    uint8_t hue = (zone->_step * spd / 5) % 256;
    HSV     hsv = {hue, *zone->saturation, *zone->brightness};
    RGB     rgb = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_wave(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {
        uint8_t off    = (zone->_step * spd / 10 + i * 25) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        HSV     hsv    = {*zone->hue, *zone->saturation, scaled};
        RGB     rgb    = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

static void zone_effect_wave_rgb(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {
        uint8_t off    = (zone->_step * spd / 10 + i * 25) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        uint8_t hue    = (zone->_step * spd / 10 + i * 50) % 256;
        HSV     hsv    = {hue, *zone->saturation, scaled};
        RGB     rgb    = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Additional Illumination
// ============================================================================

static void zone_effect_breathe_random(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd    = (*zone->speed + 1) * 10;
    
    uint8_t breath = Led_Wave_Pwm_Tab[(zone->_step * spd / 10) % 128];
    uint8_t scaled = (breath * (*zone->brightness)) / 255;
    
    uint32_t cycle = (zone->_step * spd / 10) / 128;
    
    static uint32_t last_cycle = 0;
    static uint8_t random_hue = 0;
    
    if (cycle != last_cycle) {
        last_cycle = cycle;
        random_hue = rand() % 256;
    }
    
    HSV     hsv    = {random_hue, *zone->saturation, scaled};
    RGB     rgb    = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_blink(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    
    uint8_t state = (zone->_step / 8) % 2;
    uint8_t scaled = state ? (*zone->brightness) : 0;
    
    HSV hsv = {*zone->hue, *zone->saturation, scaled};
    RGB rgb = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_rgb_blink(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    
    uint8_t state = (zone->_step / 8) % 2;
    uint8_t scaled = state ? (*zone->brightness) : 0;
    
    uint32_t cycle = zone->_step / 16;
    
    uint8_t hue = (cycle * 36) % 256;
    
    HSV hsv = {hue, *zone->saturation, scaled};
    RGB rgb = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_random_color_blink(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    
    uint8_t state = (zone->_step / 8) % 2;
    uint8_t scaled = state ? (*zone->brightness) : 0;
    
    uint32_t cycle = zone->_step / 16;
    
    static uint32_t last_cycle = 0;
    static uint8_t random_hue = 0;
    
    if (cycle != last_cycle) {
        last_cycle = cycle;
        random_hue = rand() % 256;
    }
    
    HSV hsv = {random_hue, *zone->saturation, scaled};
    RGB rgb = hsv_to_rgb(hsv);
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

static void zone_effect_random_color(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    
    uint8_t spd = (*zone->speed + 1) * 5;
    
    uint32_t interval = 50 / (spd > 0 ? spd : 1);
    if (interval < 5) interval = 5;
    
    uint32_t cycle = zone->_step / interval;
    
    static uint32_t last_cycle = 0;
    static uint8_t random_hue = 0;
    
    if (cycle != last_cycle) {
        last_cycle = cycle;
        random_hue = rand() % 256;
    }
    
    HSV hsv = {random_hue, *zone->saturation, *zone->brightness};
    RGB rgb = hsv_to_rgb(hsv);
    
    led_zone_set_color(zone, rgb.r, rgb.g, rgb.b);
}

// ============================================================================
// Wave RGB with raindrops
// ============================================================================

static void zone_effect_raindrops(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    
    // まず全LEDを一旦消灯
    led_zone_set_color(zone, 0, 0, 0);
    
    uint8_t spd = (*zone->speed + 1) * 5;
    // ステップが進むごとに変化するタイミング（ここで光るLEDの組み合わせを切り替え）
    uint32_t active_tick = (zone->_step * spd) / 20;
    
    // 同時に光らせたい数（2つ）のLEDを疑似乱数で選択して点灯
    for (uint8_t count = 0; count < 2; count++) {
        // 簡易ハッシュでランダムなLEDインデックスを算出
        uint8_t target_led = (active_tick * 17 + count * 31) % zone->led_count;
        
        // 点滅のアニメーション（フワッと光って消える）
        uint8_t off = (zone->_step * spd + count * 43) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        
        HSV hsv = {*zone->hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + target_led, rgb.r, rgb.g, rgb.b);
    }
}

static void zone_effect_jellybean_raindrops(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    led_zone_set_color(zone, 0, 0, 0);
    
    uint8_t spd = (*zone->speed + 1) * 5;
    uint32_t active_tick = (zone->_step * spd) / 20;
    
    for (uint8_t count = 0; count < 2; count++) {
        uint8_t target_led = (active_tick * 19 + count * 37) % zone->led_count;
        uint8_t off = (zone->_step * spd + count * 53) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        
        // LEDの位置に応じたジェリービーン風の固定カラー
        uint8_t hue = target_led * (256 / zone->led_count);
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + target_led, rgb.r, rgb.g, rgb.b);
    }
}

static void zone_effect_rgb_raindrops(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    led_zone_set_color(zone, 0, 0, 0);
    
    uint8_t spd = (*zone->speed + 1) * 5;
    uint32_t active_tick = (zone->_step * spd) / 20;
    
    for (uint8_t count = 0; count < 2; count++) {
        uint8_t target_led = (active_tick * 23 + count * 41) % zone->led_count;
        uint8_t off = (zone->_step * spd + count * 61) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        
        uint8_t hue = (zone->_step * 5 + target_led * 30) % 256;
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + target_led, rgb.r, rgb.g, rgb.b);
    }
}

static void zone_effect_random_color_raindrops(led_zone_t *zone) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    led_zone_set_color(zone, 0, 0, 0);
    
    uint8_t spd = (*zone->speed + 1) * 5;
    uint32_t active_tick = (zone->_step * spd) / 20;
    
    for (uint8_t count = 0; count < 2; count++) {
        uint8_t target_led = (active_tick * 23 + count * 41) % zone->led_count;
        uint8_t off = (zone->_step * spd + count * 61) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        
        uint8_t hue = (target_led * 73 + active_tick * 17 + count * 113) % 256;
        
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + target_led, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Single Color Wave with custom wave count (Clockwise)
// ============================================================================
static void zone_effect_wave_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {

        // 【調整ポイント】 i にかける数値を大きくする（例: 5 → 40）と、波の幅が狭くなります
        uint8_t off = (zone->_step * spd / 10 + i * 5 * wave_count) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;

        HSV hsv = {*zone->hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Single Color Wave with custom wave count (Counter-Clockwise)
// ============================================================================
static void zone_effect_wave_ccw_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {

        // 【調整ポイント】逆回転側も同様に、位置（zone->led_count - i）にかける数値を大きくします
        uint8_t off = (zone->_step * spd / 10 + (zone->led_count - i) * 5 * wave_count) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;

        HSV hsv = {*zone->hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Wave RGB with custom wave count (Clockwise)
// ============================================================================

static void zone_effect_wave_rgb_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {
        
        uint8_t scaled = *zone->brightness;
        
        // 色相の変化を速くするため、除算を小さく（spd / 4）または掛け算に変更
        uint8_t hue = (zone->_step * (spd / 4) + i * (256 / zone->led_count) * wave_count) % 256;
        
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Wave RGB with custom wave count (Counter-Clockwise)
// ============================================================================

static void zone_effect_wave_rgb_ccw_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    for (uint8_t i = 0; i < zone->led_count; i++) {

        uint8_t scaled = *zone->brightness;        
        
        // 色の変化を速くするため、除算を小さく（spd / 4）に変更
        uint8_t hue = (zone->_step * (spd / 4) - i * (256 / zone->led_count) * wave_count) % 256;
        
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Wave RGB (Single Color per Wave with Changing Hue)
// ============================================================================

static void zone_effect_random_color_wave_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    
    // 波全体で共有する単色の色相（時間経過とともに滑らかに変化）
    uint8_t hue = (zone->_step * (spd / 16)) % 256;

    for (uint8_t i = 0; i < zone->led_count; i++) {
        // 【調整ポイント】 i にかける数値を大きくする（例: 5 → 45）と、波の幅が狭くなります
        uint8_t off = (zone->_step * spd / 10 + i * 5 * wave_count) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;
        
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Wave RGB (Single Color per Wave with Changing Hue)
// ============================================================================

static void zone_effect_random_color_wave_ccw_count(led_zone_t *zone, uint8_t wave_count) {
    if (!(*zone->on_off)) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }
    uint8_t spd = (*zone->speed + 1) * 10;
    
    // 波全体で共有する単色の色相（時間経過とともに滑らかに変化）
    uint8_t hue = (zone->_step * (spd / 16)) % 256;

    for (uint8_t i = 0; i < zone->led_count; i++) {
        // 【調整ポイント】逆回転側も同様に、位置にかける数値を大きくします
        uint8_t off = (zone->_step * spd / 10 + (zone->led_count - i) * 5 * wave_count) % 128;
        uint8_t scaled = (Led_Wave_Pwm_Tab[off] * (*zone->brightness)) / 255;    
        
        HSV hsv = {hue, *zone->saturation, scaled};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(zone->led_start + i, rgb.r, rgb.g, rgb.b);
    }
}

// ============================================================================
// Public API
// ============================================================================

void led_zone_update(led_zone_t *zone) {

    // 【追加】180秒（180000ミリ秒）無操作でタイムアウト
    if (!led_is_timed_out) {
        if (led_idle_timer == 0) {
            led_idle_timer = timer_read32();
        }
        if (timer_elapsed32(led_idle_timer) > 180000) {
            led_is_timed_out = true;
        }
    }
    // 【追加】タイムアウト中は強制消灯
    if (led_is_timed_out) {
        led_zone_set_color(zone, 0, 0, 0);
        return;
    }

    if (timer_elapsed(zone->_timer) > 20) {
        zone->_timer = timer_read();
        zone->_step++;
    }

    // 【追加】レイヤーによる上書き処理をここで実行
    // Layer 1以上などで強制カラーが適用された場合は、そのまま関数を抜けて他のエフェクトを実行させない
    if (led_zone_apply_layer_priority(zone)) {
        return;
    }

    switch (*zone->mode) {
        case LED_ZONE_MODE_NONE:
            led_zone_set_color(zone, 0, 0, 0);
            break;
        case LED_ZONE_MODE_FIXED_WAVE:
            zone_effect_wave(zone);
            break;
        case LED_ZONE_MODE_WAVE_RGB:
            zone_effect_wave_rgb(zone);
            break;
        case LED_ZONE_MODE_SPECTRUM:
            zone_effect_spectrum(zone);
            break;
        case LED_ZONE_MODE_BREATHE:
            zone_effect_breathe(zone);
            break;
        case LED_ZONE_MODE_BREATHE_RGB:
            zone_effect_breathe_rgb(zone);
            break;
        case LED_ZONE_MODE_BREATHE_RANDOM:
            zone_effect_breathe_random(zone);
            break;
        case LED_ZONE_BLINK_MODE:
            zone_effect_blink(zone);
            break;
        case LED_ZONE_RGB_BLINK_MODE:
            zone_effect_rgb_blink(zone);
            break;
        case LED_ZONE_RANDOM_COLOR_BLINK_MODE:
            zone_effect_random_color_blink(zone);
            break;
        case LED_ZONE_RANDOM_COLOR_MODE:
            zone_effect_random_color(zone);
            break;
        case LED_ZONE_RAINDROPS_MODE:
            zone_effect_raindrops(zone);
            break;
        case LED_ZONE_JELLYBEANRAINDROPS_MODE:
            zone_effect_jellybean_raindrops(zone);
            break;
        case LED_ZONE_RGB_RAINDROPS_MODE:
            zone_effect_rgb_raindrops(zone);
            break;
        case LED_ZONE_RANDOM_COLOR_RAINDROPS_MODE:
            zone_effect_random_color_raindrops(zone);
            break;
        case LED_ZONE_WAVE_DS_MODE_cw1:
            zone_effect_wave_count(zone, 1);
            break;
        case LED_ZONE_WAVE_DS_MODE_cw2:
            zone_effect_wave_count(zone, 2);
            break;
        case LED_ZONE_WAVE_DS_MODE_cw4:
            zone_effect_wave_count(zone, 4);
            break;
        case LED_ZONE_WAVE_DS_MODE_cw7:
            zone_effect_wave_count(zone, 7);
            break;
        case LED_ZONE_WAVE_DS_MODE_cw9:
            zone_effect_wave_count(zone, 9);
            break;
        case LED_ZONE_WAVE_DS_MODE_ccw1:
            zone_effect_wave_ccw_count(zone, 1);
            break;
        case LED_ZONE_WAVE_DS_MODE_ccw2:
            zone_effect_wave_ccw_count(zone, 2);
            break;
        case LED_ZONE_WAVE_DS_MODE_ccw4:
            zone_effect_wave_ccw_count(zone, 4);
            break;
        case LED_ZONE_WAVE_DS_MODE_ccw7:
            zone_effect_wave_ccw_count(zone, 7);
            break;
        case LED_ZONE_WAVE_DS_MODE_ccw9:
            zone_effect_wave_ccw_count(zone, 9);
            break;
        case LED_ZONE_WAVE_RGB_MODE_cw1:
            zone_effect_wave_rgb_count(zone, 1);
            break;
        case LED_ZONE_WAVE_RGB_MODE_cw2:
            zone_effect_wave_rgb_count(zone, 2);
            break;
        case LED_ZONE_WAVE_RGB_MODE_cw4:
            zone_effect_wave_rgb_count(zone, 4);
            break;
        case LED_ZONE_WAVE_RGB_MODE_cw7:
            zone_effect_wave_rgb_count(zone, 7);
            break;
        case LED_ZONE_WAVE_RGB_MODE_cw9:
            zone_effect_wave_rgb_count(zone, 9);
            break;
        case LED_ZONE_WAVE_RGB_MODE_ccw1:
            zone_effect_wave_rgb_ccw_count(zone, 1);
            break;
        case LED_ZONE_WAVE_RGB_MODE_ccw2:
            zone_effect_wave_rgb_ccw_count(zone, 2);
            break;
        case LED_ZONE_WAVE_RGB_MODE_ccw4:
            zone_effect_wave_rgb_ccw_count(zone, 4);
            break;
        case LED_ZONE_WAVE_RGB_MODE_ccw7:
            zone_effect_wave_rgb_ccw_count(zone, 7);
            break;
        case LED_ZONE_WAVE_RGB_MODE_ccw9:
            zone_effect_wave_rgb_ccw_count(zone, 9);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_cw1:
            zone_effect_random_color_wave_count(zone, 1);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_cw2:
            zone_effect_random_color_wave_count(zone, 2);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_cw4:
            zone_effect_random_color_wave_count(zone, 4);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_cw7:
            zone_effect_random_color_wave_count(zone, 7);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_cw9:
            zone_effect_random_color_wave_count(zone, 9);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_ccw1:
            zone_effect_random_color_wave_ccw_count(zone, 1);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_ccw2:
            zone_effect_random_color_wave_ccw_count(zone, 2);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_ccw4:
            zone_effect_random_color_wave_ccw_count(zone, 4);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_ccw7:
            zone_effect_random_color_wave_ccw_count(zone, 7);
            break;
        case LED_ZONE_RANDOM_COLOR_WAVE_MODE_ccw9:
            zone_effect_random_color_wave_ccw_count(zone, 9);
            break;
        case LED_ZONE_MODE_LIGHT:
        default:
            zone_effect_solid(zone);
            break;
    }
}

bool process_led_zone_keycodes(led_zone_t *zone, uint16_t keycode, keyrecord_t *record) {
    // 【追加】どのキーであっても操作されたらアイドルタイマーをリセットし、消灯状態を解除する
    if (record->event.pressed) {
        led_idle_timer = timer_read32();
        led_is_timed_out = false;
    }

    if (keycode < zone->keycode_base || keycode > (uint16_t)(zone->keycode_base + 10)) {
        return false;
    }
    if (record->event.pressed) {
        return true; // consume on press, act on release
    }
    uint8_t offset = (uint8_t)(keycode - zone->keycode_base);
    switch (offset) {
        case 0: // TOG
            *zone->on_off = !(*zone->on_off);
            break;
        case 1: // MOD
            (*zone->mode)++;
            if (*zone->mode > 45) *zone->mode = 0;
            break;
        case 2: // RMOD
            if (*zone->mode == 0)
                *zone->mode = 45;
            else
                (*zone->mode)--;
            break;
        case 3: // HUI
            *zone->hue += 8;
            break;
        case 4: // HUD
            *zone->hue -= 8;
            break;
        case 5: // SAI
            *zone->saturation = (*zone->saturation <= 247) ? (*zone->saturation + 8) : 255;
            break;
        case 6: // SAD
            *zone->saturation = (*zone->saturation >= 8) ? (*zone->saturation - 8) : 0;
            break;
        case 7: // VAI
            *zone->brightness = (*zone->brightness <= 247) ? (*zone->brightness + 8) : 255;
            break;
        case 8: // VAD
            *zone->brightness = (*zone->brightness >= 8) ? (*zone->brightness - 8) : 0;
            break;
        case 9: // SPI
            if (*zone->speed < 4) (*zone->speed)++;
            break;
        case 10: // SPD
            if (*zone->speed > 0) (*zone->speed)--;
            break;
    }
    Save_Flash_Set();
    return true;
}

void via_led_zone_command(led_zone_t *zone, uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    uint8_t *channel_id = &(data[1]);
    uint8_t *value_id   = &(data[2]);
    uint8_t *value_data = &(data[3]);

    if (*channel_id != zone->via_channel) return;

    switch (*command_id) {
        case 0x07: // id_custom_set_value
            switch (*value_id) {
                case 1:
                    *zone->brightness = value_data[0];
                    break;
                case 2:
                    *zone->mode   = value_data[0];
                    *zone->on_off = (value_data[0] > 0) ? 1 : 0;
                    break;
                case 3:
                    *zone->speed = value_data[0];
                    break;
                case 4:
                    *zone->hue        = value_data[0];
                    *zone->saturation = value_data[1];
                    break;
            }
            Save_Flash_Set();
            break;
        case 0x08: // id_custom_get_value
            switch (*value_id) {
                case 1:
                    value_data[0] = *zone->brightness;
                    break;
                case 2:
                    value_data[0] = (*zone->on_off) ? *zone->mode : 0;
                    break;
                case 3:
                    value_data[0] = *zone->speed;
                    break;
                case 4:
                    value_data[0] = *zone->hue;
                    value_data[1] = *zone->saturation;
                    break;
            }
            break;
        case 0x09: // id_custom_save
            Save_Flash_Set();
            break;
    }
}

#endif // LOGO_LED_ENABLE || SIDE_LED_ENABLE
