RGB_MATRIX_EFFECT(my_effect_goon)
RGB_MATRIX_EFFECT(my_effect_numrow)
RGB_MATRIX_EFFECT(my_effect_function)
RGB_MATRIX_EFFECT(my_effect_symbol)
RGB_MATRIX_EFFECT(my_effect_mouse)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
static bool my_effect_goon(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (i==1 || i==36) {
            rgb_matrix_set_color(i, RGB_RED);
        } else if ((i>=2 && i<=4) || i==15){
            rgb_matrix_set_color(i, RGB_PINK);
        } else if (i==0 || i==12 || i==18 || i==24 || i==30 || i==39 || (i>=41 && i<=42) || i==44) {
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
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_numrow(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if ((i>=1 && i<=2) || (i>=4 && i<=7) || (i>=9 && i<=10)){
            rgb_matrix_set_color(i, RGB_ORANGE);
        } else if (i==11 || (i>=22 && i<=23) || (i>=32 && i<=34)){
            rgb_matrix_set_color(i, RGB_BLUE);
        } else if ((i>=14 && i<=16) || (i>=26 && i<=27)){
            rgb_matrix_set_color(i, RGB_CHARTREUSE);
        } else if (i==3 || i==8 || (i>=17 && i<=18) || (i>=29 && i<=30)){
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
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_function(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if ((i>=1 && i<=2) || (i>=4 && i<=7) || (i>=9 && i<=10)){
            rgb_matrix_set_color(i, RGB_GREEN);
        } else if (i==3 || i==8){
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
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_symbol(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();       
        if ((i>=1 && i<=2) || (i>=4 && i<=7) || (i>=9 && i<=11)|| (i>=22 && i<=23) || (i>=32 && i<=35)){
            rgb_matrix_set_color(i, RGB_BLUE);
        } else if (i==3 || i==8){
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
    return rgb_matrix_check_finished_leds(led_max);

}


static bool my_effect_mouse(effect_params_t* params) {

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

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
    return rgb_matrix_check_finished_leds(led_max);

}

#endif
