#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    karnadii
#define PRODUCT         qsplit65
#define DESCRIPTION     "handwired 65 keyboard + 8 macro with oled display and rotary encoder"

// #define MASTER_RIGHT // Comment this line for the left half firmware
#define MASTER_LEFT // Comment this line for the right half firmware

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS { B3, B2, B6, E6, D7, C6, D4, D2 }
#define MATRIX_ROW_PINS_RIGHT { B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS_RIGHT { B3, B2, B6, E6, D7, C6, D4, D2 }
#define UNUSED_PINS
// #define USE_I2C
#define SOFT_SERIAL_PIN D3
/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// Right encoder.
// I can not use only right encoder, I have to define left encoder as well
#define ENCODERS_PAD_A { D1 } // dummy encoder to passs error. there is no left encoder.
#define ENCODERS_PAD_B { D0 } // dummy encoder to passs error. there is no left encoder.
#define ENCODERS_PAD_A_RIGHT { D1 }
#define ENCODERS_PAD_B_RIGHT { D0 }
#define ENCODER_RESOLUTION 4

// #define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLED_NUM 22
#define RGBLED_SPLIT { 11, 11 }
#define RGB_DI_PIN B4

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 0
#define OLED_FONT_H "keyboards/handwired/qsplit/keymaps/default/glcdfont.c"

#endif

