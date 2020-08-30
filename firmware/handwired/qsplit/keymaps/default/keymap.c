#include QMK_KEYBOARD_H
// #include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _BASE 0
// #define _FN1 1
enum layer_names {
    _QWERTY_WIN,
    _QWERTY_MAC,
    _FN1,
    _FN2,
};

// char wpm_str[10];

enum custom_keycodes { QWERTY = SAFE_RANGE, LAYERMOD, ENCMOD, ENC_SWITCH };

enum enc_modes {  media, scroll, brightness, backlit };
enum operating_systems  { macos, windows };
uint8_t LAYER_MODE = _QWERTY_MAC;
uint8_t ENCODER_MODE   = media;
uint8_t OS_MODE   = macos;
bool is_capslock = false, is_scrolllock = false, is_lsft = false, is_lctl = false, is_lalt = false, is_lgui = false, is_fn1 = false, is_fn2 = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY_WIN] = KEYMAP(
                      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_6,                   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, ENC_SWITCH,
        KC_F1, KC_F2, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_5,                    KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_F3, KC_F4, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_T,                   KC_Y, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
        KC_F5, KC_F6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_G,                   KC_H, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_UP, KC_PGDN,
        KC_F7, KC_F8,  KC_LCTL, KC_LGUI, KC_LALT,MO(_FN2), KC_SPC, KC_B,       KC_N, KC_SPC, KC_LALT, MO(_FN1), KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_QWERTY_MAC] = KEYMAP(
                      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_6,                   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, ENC_SWITCH,
        KC_F1, KC_F2, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_5,                    KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_F3, KC_F4, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_T,                   KC_Y, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
        KC_F5, KC_F6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_G,                   KC_H, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_UP, KC_PGDN,
        KC_F7, KC_F8,  KC_LCTL,  KC_LALT, KC_LGUI, MO(_FN2), KC_SPC, KC_B,       KC_N, KC_SPC, KC_LGUI, MO(_FN1), KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    // [_COLEMAK] = KEYMAP(
    //                 KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_6,               KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, ENC_SWITCH,
    //     KC_F1, KC_F2, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_5,                    KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    //     KC_F3, KC_F4, KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_G,                   KC_J, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT, KC_PGUP,
    //     KC_F5, KC_F6, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_D,                   KC_H, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_UP, KC_PGDN,
    //     KC_F7, KC_F8,  KC_LCTL, KC_LALT, KC_LGUI, MO(_FN2), KC_SPC, KC_B,      KC_K, KC_SPC, KC_LGUI, MO(_FN2), KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = KEYMAP(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F6,                                     KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, ENCMOD,
        _______, _______, _______, _______, _______, _______, _______, KC_F5,          _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______,_______, _______, _______, _______, _______, _______, _______),

    [_FN2] = KEYMAP(
        RGB_TOG, RGB_MODE_FORWARD, _______, RGB_MODE_SWIRL, RGB_MODE_RAINBOW, RGB_MODE_BREATHE,                          RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, RGB_MOD, LAYERMOD,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______, _______),
};




void handle_encoder_media(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            tap_code(KC_MNXT);
        }else if(fn2){
            tap_code(KC_MFFD);
        }else{
            tap_code(KC_VOLU);
        }
    }else {
        if(fn1){
            tap_code(KC_MPRV);
        }else if(fn2){
            tap_code(KC_MRWD);
        }else{
            tap_code(KC_VOLD);
        }
    }
}

void handle_encoder_backlit(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            rgblight_increase_hue();
        }else if(fn2){
            rgblight_increase_sat();
        }else{
            rgblight_increase_val();
        }
    }else {
        if(fn1){
            rgblight_decrease_hue();
        }else if(fn2){
            rgblight_decrease_sat();
        }else{
            rgblight_decrease_val();
        }
    }
}

void handle_encoder_scroll(bool clockwise, bool fn1, bool fn2){
    if(clockwise){
        if(fn1){
            tap_code(KC_WH_R);
        }else if(fn2){
            tap_code(KC_WH_R);
        }else{
            tap_code(KC_WH_D);
        }
    }else {
        if(fn1){
            tap_code(KC_WH_L);
        }else if(fn2){
            tap_code(KC_WH_L);
        }else{
            tap_code(KC_WH_U);
        }
    }
}

void handle_encoder_brightnes(bool clockwise, bool fn1, bool fn2){
    if (clockwise) {
        tap_code(KC_BRIU);
    } else {
        tap_code(KC_BRID);
    }
}

void handle_encoder_layer_change(void){
    if(ENCODER_MODE == 3){
        ENCODER_MODE = 0;
    }else{
        ENCODER_MODE+=1;
    }
}

void handle_encoder(bool clockwise){
    bool is_fn1 = layer_state_is(_FN1);
    bool is_fn2 = layer_state_is(_FN2);

    if(ENCODER_MODE == media){
        handle_encoder_media(clockwise,is_fn1,is_fn2);
    }else if(ENCODER_MODE==scroll){
        handle_encoder_scroll(clockwise,is_fn1,is_fn2);
    }else if(ENCODER_MODE == backlit){
        handle_encoder_backlit(clockwise,is_fn1,is_fn2);
    }else{
        handle_encoder_brightnes(clockwise,is_fn1,is_fn2);
    }
}

void handle_encoder_switch(void){
    if(ENCODER_MODE == media){
        tap_code(KC_MPLY);
    }else if(ENCODER_MODE == backlit) {
        rgblight_step();
    }else if(ENCODER_MODE == scroll){
        tap_code(KC_LSCR);
    }else{
        // do nothing
    }
}

void handle_base_layer_change(void){
    if(LAYER_MODE == _QWERTY_MAC){
        set_single_persistent_default_layer(_QWERTY_WIN);
        LAYER_MODE = _QWERTY_WIN;
    }else{
        set_single_persistent_default_layer(_QWERTY_MAC);
         LAYER_MODE = _QWERTY_MAC;
    }
}
 #ifdef OLED_DRIVER_ENABLE
void render_base_layer_indicator(void){

    // Layer legend
    // static const char PROGMEM layer_one[] = {0xc8, 0xc9, 0};
    // static const char PROGMEM layer_two[] = {0xca, 0xcb, 0};
    static const char PROGMEM mac_os[] = {0x94, 0x95, 0x96, 0x97, 0};
    static const char PROGMEM win_os[] = {0xb4, 0xb5, 0xb6, 0xb7, 0};
    // static const char PROGMEM layer_three[] = {0xcc, 0xcd, 0};
    // static const char PROGMEM layer_four[] = {0xce, 0xcf, 0};
    // static const char PROGMEM layer_five[] = {0xd0, 0xd1,0};

    oled_write_P(PSTR("OS  "), false);
    if(LAYER_MODE == _QWERTY_MAC){
        oled_write_P(mac_os, false);
    }else{
        oled_write_P(win_os, false);
    }

}
 #endif
#ifdef OLED_DRIVER_ENABLE

void render_encoder_layer_indicator(void){

    // Encoder legend
    static const char PROGMEM enc_med[] = {0xa8, 0xa9, 0xaa, 0xab,0};
    static const char PROGMEM enc_brt[] = {0x8c, 0x8d, 0x8e, 0x8f,0};
    static const char PROGMEM enc_bkl[] = {0xac, 0xad, 0xae, 0xaf,0};
    static const char PROGMEM enc_scr[] = {0x84, 0x85, 0x86, 0x87,0};

    oled_write_P(PSTR("ENC "), false);
    if(ENCODER_MODE == media){
        oled_write_P(enc_med, false);
    }else if(ENCODER_MODE == brightness){
        oled_write_P(enc_brt, false);
    }else if(ENCODER_MODE == backlit){
        oled_write_P(enc_bkl, false);
    }else{
        oled_write_P(enc_scr, false);
    }

}
#endif
 #ifdef OLED_DRIVER_ENABLE
void render_led_state(void){

    static const char PROGMEM led_cap_on[] = {0x80, 0x81, 0x82, 0x83,0};
    static const char PROGMEM led_cap_off[] = {0xa0, 0xa1, 0xa2, 0xa3,0};
    // static const char PROGMEM caps_icon[] = { 0x9a, 0x9b, 0};

    // static const char PROGMEM led_scr_on[] = {0x84, 0x85, 0x86, 0x87,0};
    // static const char PROGMEM led_scr_off[] = {0xa4, 0xa5, 0xa6, 0xa7,0};
    oled_write_P(PSTR("LED "), false);
    // oled_write_P(caps_icon, false);
    if(is_capslock){
        oled_write_P(led_cap_on, false);
    }else{
        oled_write_P(led_cap_off, false);
    }
    // if(is_scrolllock){
    //     oled_write_P(led_scr_on, false);
    // }else{
    //     oled_write_P(led_scr_off, false);
    // }

}
#endif
#ifdef OLED_DRIVER_ENABLE
void render_pressed_mod_key(void){

        // Modifier icon
    // static const char PROGMEM mod_s_on[] = {0xc0, 0xc1, 0};
    // static const char PROGMEM mod_c_on[] = {0xc2, 0xc3, 0};
    // static const char PROGMEM mod_a_on[] = {0xc4, 0xc5, 0};
    // static const char PROGMEM mod_g_on[] = {0xc6, 0xc7, 0};
    // static const char PROGMEM mod_s_off[] = {0x90, 0x91, 0};
    // static const char PROGMEM mod_c_off[] = {0x92, 0x93, 0};
    // static const char PROGMEM mod_a_off[] = {0xb0, 0xb1,0};
    // static const char PROGMEM mod_g_off[] = { 0xb2, 0xb3, 0};
    static const char PROGMEM shift_icon[] = { 0xb8, 0xb9, 0};
    static const char PROGMEM control_icon[] = { 0xd6, 0xd7, 0};
    static const char PROGMEM command_icon[] = { 0xd8, 0xd9, 0};
    static const char PROGMEM win_icon[] = { 0xd4, 0xd5, 0};
    static const char PROGMEM option_icon[] = { 0x98, 0x99, 0};
    if(is_lsft){
        oled_write_P(shift_icon, false);
    }
    // else{
    //     oled_write_P(mod_s_off, false);
    // }
    if(is_lctl){
        oled_write_P(control_icon, false);
    }
    // else{
    //     oled_write_P(mod_c_off, false);
    // }
    if(is_lalt){
        oled_write_P(option_icon, false);
    }
    // else{
    //     oled_write_P(mod_a_off, false);
    // }
     if(is_lgui){
        oled_write_P(LAYER_MODE == _QWERTY_MAC?command_icon:win_icon, false);
    }
    // else{
    //     oled_write_P(mod_g_off, false);
    // }

    oled_write_P(PSTR("\n"), false);


    }
 #endif



void encoder_update_user(uint8_t index, bool clockwise) {
   handle_encoder(clockwise);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYERMOD:
            if (record->event.pressed) {
                handle_base_layer_change();
            }
            return false;
        case ENCMOD:
            if (record->event.pressed) {
                handle_encoder_layer_change();
            }
            return false;
        case ENC_SWITCH:
            if (record->event.pressed) {
                handle_encoder_switch();
            }
            return false;
        case KC_LSFT:
            if (record->event.pressed) {
                is_lsft = true;
                register_code(KC_LSFT);
            }else{
                is_lsft = false;
                unregister_code(KC_LSFT);
            }
            return false;
        case KC_LCTL:
            if (record->event.pressed) {
                is_lctl = true;
                register_code(KC_LCTL);
            }else{
                is_lctl = false;
                unregister_code(KC_LCTL);
            }
            return false;
        case KC_LGUI:
            if (record->event.pressed) {
                is_lgui = true;
                register_code(KC_LGUI);
            }else{
                is_lgui = false;
                unregister_code(KC_LGUI);
            }
            return false;
        case KC_LALT:
            if (record->event.pressed) {
                is_lalt = true;
                register_code(KC_LALT);
            }else{
                is_lalt = false;
                unregister_code(KC_LALT);
            }
            return false;
    }
    return true;
}

bool led_update_user(led_t led_state) {

    if(led_state.caps_lock){
        is_capslock = true;
    } else{
        is_capslock = false;
    }

    if(led_state.scroll_lock){
        is_scrolllock = true;
    } else{
        is_scrolllock = false;
    }

    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    render_base_layer_indicator();
    oled_write_P(PSTR(" "), false);
    render_encoder_layer_indicator();
    oled_write_P(PSTR("\n"), false);
    render_led_state();
    render_pressed_mod_key();
    // sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    // oled_write(wpm_str, false);
}
#endif
