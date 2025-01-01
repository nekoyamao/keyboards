#pragma once

/* define RP2040 boot用 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when entering the bootloader


/* define RP2040 PC起動時認識用（SPLIT_USB_DETECTが有効となっているため） */
#define SPLIT_USB_TIMEOUT 10000  //Default 2000
#define SPLIT_USB_TIMEOUT_POLL 25  //Default 10
//#define USB_VBUS_PIN GP17  //SPLIT_USB_TIMEOUTを設定せずにVBUS_PINを物理的に利用する場合


/* define layer size */
#define DYNAMIC_KEYMAP_LAYER_COUNT 21
#define LAYER_STATE_24BIT


/* define VIAL用 */
#define VIAL_KEYBOARD_UID {0x43, 0x07, 0x36, 0x20, 0xAE, 0xFA, 0xDA, 0x1C}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}


/* WS2812B RGB LED */
#ifdef RGBLIGHT_ENABLE
#define WS2812_PIO_USE_PIO1      // RP2040用に追加
#endif


#ifdef RGB_MATRIX_ENABLE
#define RGBLIGHT_LAYERS          // レイヤーとの連動機能の有効化
#define RGBLIGHT_MAX_LAYERS 21    // 連動するレイヤー数(最大32)
#define WS2812_PIO_USE_PIO1      // RP2040用に追加
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#endif


/*  OLED driver and pins */
#define HAL_USE_I2C TRUE
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3


/*  define OLED Scroll and timeout */
#ifdef OLED_ENABLE
#define OLED_SCROLL_TIMEOUT 10000   //Default 0
#define OLED_TIMEOUT 180000          //Default 60000
#endif
