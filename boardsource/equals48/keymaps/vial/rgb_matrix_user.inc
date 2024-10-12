RGB_MATRIX_EFFECT(my_effect_numpad)
RGB_MATRIX_EFFECT(my_effect_numrow)
RGB_MATRIX_EFFECT(my_effect_function)
RGB_MATRIX_EFFECT(my_effect_symbol)
RGB_MATRIX_EFFECT(my_effect_audio)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool my_effect_numpad(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if  ((i>=17 && i<=19) || (i>=29 && i<=31) || (i>=40 && i<=43)) {
            rgb_matrix_set_color(i, RGB_ORANGE);
       } else if ((i>=20 && i<=21) || i==28 || (i>=32 && i<=33) || i==44){
            rgb_matrix_set_color(i, RGB_BLUE);
        } else if ((i>=12 && i<=13) || (i>=23 && i<=25) || (i>=35 && i<=38)){
            rgb_matrix_set_color(i, RGB_PINK);
        } else if (i==10 || i==22 || i==34 || (i>=45 && i<=46) || i==49 ||(i>=51 && i<=52) || i==54) {
            rgb_matrix_set_color(i, RGB_MAGENTA);
        } else if (i==50 || i==53) {
            rgb_matrix_set_color(i, RGB_SPRINGGREEN);
        } else {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_numrow(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if (i>=11 && i<=20){
            rgb_matrix_set_color(i, RGB_ORANGE);
       } else if (i==21 || (i>=32 && i<=33) || (i>=24 && i<=26) || (i>=36 && i<=37) || (i>=42 && i<=44)){
            rgb_matrix_set_color(i, RGB_BLUE);
        } else if ((i>=27 && i<=28) || (i>=39 && i<=40)){
            rgb_matrix_set_color(i, RGB_CYAN);
        } else if (i>=29 && i<=31){
            rgb_matrix_set_color(i, RGB_PURPLE);
        } else if (i==22) {
            rgb_matrix_set_color(i, RGB_RED);
        } else if (i==10 || i==34 || i==45 || (i>=51 && i<=52) || i==54) {
            rgb_matrix_set_color(i, RGB_MAGENTA);
        } else if (i==53) {
            rgb_matrix_set_color(i, RGB_SPRINGGREEN);
        } else {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_function(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if (i>=11 && i<=20){
            rgb_matrix_set_color(i, RGB_GREEN);
        } else if ((i>=25 && i<=26) || (i>=37 && i<=38)){
            rgb_matrix_set_color(i, RGB_TURQUOISE);
        } else if ((i>=27 && i<=28) || (i>=39 && i<=40)){
            rgb_matrix_set_color(i, RGB_CYAN);
        } else if ((i>=29 && i<=32) || (i>=41 && i<=44)){
            rgb_matrix_set_color(i, RGB_PURPLE);
        } else if (i==33 || i==45){
            rgb_matrix_set_color(i, RGB_GOLDENROD);
        } else if (i==21) {
            rgb_matrix_set_color(i, RGB_RED);
        } else if (i==10 ||i==22 || i==34 || i==49 ||(i>=51 && i<=52) || i==54) {
            rgb_matrix_set_color(i, RGB_MAGENTA);
        } else if (i==50 || i==53) {
            rgb_matrix_set_color(i, RGB_SPRINGGREEN);
        } else {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_symbol(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if ((i>=10 && i<=21) || (i>=24 && i<=26) || (i>=36 && i<=37) || (i>=32 && i<=33) || (i>=42 && i<=45)){
            rgb_matrix_set_color(i, RGB_BLUE);
        } else if ((i>=27 && i<=28) || (i>=39 && i<=40)){
            rgb_matrix_set_color(i, RGB_CYAN);
        } else if (i>=29 && i<=31){
            rgb_matrix_set_color(i, RGB_PURPLE);
        } else if (i==22 || i==34 || i==49 ||(i>=51 && i<=52)) {
            rgb_matrix_set_color(i, RGB_MAGENTA);
        } else if (i==50) {
            rgb_matrix_set_color(i, RGB_SPRINGGREEN);
        } else {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_audio(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if (i==33 || i==45 || (i>=42 && i<=43)){
            rgb_matrix_set_color(i, RGB_GOLDENROD);
        } else if (i==21 || i==41) {
            rgb_matrix_set_color(i, RGB_RED);
        } else {
            rgb_matrix_set_color(i, RGB_OFF);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);

}
#endif
