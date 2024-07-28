#pragma once

/* OLED */
#ifdef OLED_ENABLE

#define HAL_USE_I2C TRUE

#endif

#include_next "halconf.h"
