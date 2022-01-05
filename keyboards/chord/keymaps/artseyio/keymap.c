#include "chord.h"

#include "artsey.h"
#include "keymap_combo.h"
#include "artsey.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_A_BASE] = LAYOUT_3x4( \
        A_BASE_S, A_BASE_T, A_BASE_R, A_BASE_A, \
        A_BASE_O, A_BASE_I, A_BASE_Y, A_BASE_E, \
        _______,  KC_LALT,  KC_LSFT,  KC_LGUI
    ),

    [_A_NUM] = LAYOUT_3x4( \
        A_NUM_S, A_NUM_T, A_NUM_R, A_NUM_A, \
        A_NUM_O, A_NUM_I, A_NUM_Y, A_NUM_E, \
        _______, _______, _______, _______
    ),

    [_A_NAV] = LAYOUT_3x4( \
        A_NAV_S, A_NAV_T, A_NAV_R, A_NAV_A, \
        A_NAV_O, A_NAV_I, A_NAV_Y, A_NAV_E, \
        _______, _______, _______, _______
    ),

    [_A_SYM] = LAYOUT_3x4( \
        A_SYM_S, A_SYM_T, A_SYM_R, A_SYM_A, \
        A_SYM_O, A_SYM_I, A_SYM_Y, A_SYM_E, \
        _______, _______, _______, _______
    ),

    [_A_BRAC] = LAYOUT_3x4( \
        A_BRAC_S, A_BRAC_T, A_BRAC_R, A_BRAC_A, \
        A_BRAC_O, A_BRAC_I, A_BRAC_Y, A_BRAC_E, \
        _______,  _______,  _______,  _______
    ),

    [_A_MOU] = LAYOUT_3x4( \
        A_MOU_S, A_MOU_T, A_MOU_R, A_MOU_A, \
        A_MOU_O, A_MOU_I, A_MOU_Y, A_MOU_E, \
        _______, _______, _______, _______
    ),

    [_A_CUSTOM] = LAYOUT_3x4( \
        A_CUSTOM_S, A_CUSTOM_T, A_CUSTOM_R, A_CUSTOM_A, \
        A_CUSTOM_O, A_CUSTOM_I, A_CUSTOM_Y, A_CUSTOM_E, \
        _______,    _______,    _______,    _______
    ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_layer_state(void) {
    static const char PROGMEM base[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0};
    static const char PROGMEM numb[] = {0x85, 0x86, 0x87, 0x88, 0x89, 0};
    static const char PROGMEM navg[] = {0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0};
    static const char PROGMEM symb[] = {0x8f, 0x90, 0x91, 0x92, 0x93, 0};
    static const char PROGMEM brac[] = {0x94, 0x95, 0x96, 0x97, 0x98, 0};
    static const char PROGMEM mous[] = {0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0};
    static const char PROGMEM cust[] = {0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0};

    if(layer_state_is(_A_BASE)) {
        oled_write_ln_P(base, true);
    } else if(layer_state_is(_A_NUM)) {
        oled_write_ln_P(numb, true);
    } else if(layer_state_is(_A_NAV)) {
        oled_write_ln_P(navg, true);
    } else if(layer_state_is(_A_SYM)) {
        oled_write_ln_P(symb, true);
    } else if(layer_state_is(_A_BRAC)) {
        oled_write_ln_P(brac, true);
    } else if(layer_state_is(_A_MOU)) {
        oled_write_ln_P(mous, true);
    } else if(layer_state_is(_A_CUSTOM)) {
        oled_write_ln_P(cust, true);
    }
}

static void render_mod_status(uint8_t modifiers) {
    static const char PROGMEM shft[] = {0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0};
    static const char PROGMEM ctrl[] = {0xa8, 0xa9, 0xaa, 0xab, 0xac, 0};
    static const char PROGMEM supr[] = {0xad, 0xae, 0xaf, 0xb0, 0xb1, 0};
    static const char PROGMEM meta[] = {0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0};

    oled_write_ln_P(shft, modifiers & MOD_MASK_SHIFT);
    oled_write_ln_P(ctrl, modifiers & MOD_MASK_CTRL);
    oled_write_ln_P(supr, modifiers & MOD_MASK_GUI);
    oled_write_ln_P(meta, modifiers & MOD_MASK_ALT);
}

static void render_logo(void) {
    static const char PROGMEM line1[] = {0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0};
    static const char PROGMEM line2[] = {0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0};

    oled_write_P(line1, false);
    oled_write_P(line1, false);
    oled_write_ln_P(line2, false);
}

bool oled_task_user(void) {
    render_logo();
    render_layer_state();
    render_mod_status(get_mods()|get_oneshot_mods());
    return false;
}
#endif

