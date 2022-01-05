bool is_shift_lock_active = false; 
bool other_key_pressed = false;
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c;
uint16_t key_timer = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCK_SHIFT:
      if (record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code16(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code16(KC_LSFT);
        }
      }
    break;
    case A_BASE_AR:
      if(record->event.pressed) {
        register_code16(KC_F);
      } else {
        unregister_code16(KC_F);
      }
      break;
    case A_BASE_AS:
      if(record->event.pressed) {
        register_code16(KC_W);
      } else {
        unregister_code16(KC_W);
      }
      break;
    case A_BASE_RT:
      if(record->event.pressed) {
        register_code16(KC_G);
      } else {
        unregister_code16(KC_G);
      }
      break;
    case A_BASE_RS:
      if(record->event.pressed) {
        register_code16(KC_V);
      } else {
        unregister_code16(KC_V);
      }
      break;
    case A_BASE_RI:
      if(record->event.pressed) {
        register_code16(KC_DEL);
      } else {
        unregister_code16(KC_DEL);
      }
      break;
    case A_BASE_TS:
      if(record->event.pressed) {
        register_code16(KC_J);
      } else {
        unregister_code16(KC_J);
      }
      break;
    case A_BASE_ART:
      if(record->event.pressed) {
        register_code16(KC_D);
      } else {
        unregister_code16(KC_D);
      }
      break;
    case A_BASE_ATS:
      if(record->event.pressed) {
        register_code16(KC_Q);
      } else {
        unregister_code16(KC_Q);
      }
      break;
    case A_BASE_RTS:
      if(record->event.pressed) {
        register_code16(KC_X);
      } else {
        unregister_code16(KC_X);
      }
      break;
    case A_BASE_EY:
      if(record->event.pressed) {
        register_code16(KC_C);
      } else {
        unregister_code16(KC_C);
      }
      break;
    case A_BASE_EI:
      if(record->event.pressed) {
        register_code16(KC_H);
      } else {
        unregister_code16(KC_H);
      }
      break;
    case A_BASE_EO:
      if(record->event.pressed) {
        register_code16(KC_B);
      } else {
        unregister_code16(KC_B);
      }
      break;
    case A_BASE_YI:
      if(record->event.pressed) {
        register_code16(KC_U);
      } else {
        unregister_code16(KC_U);
      }
      break;
    case A_BASE_YO:
      if(record->event.pressed) {
        register_code16(KC_K);
      } else {
        unregister_code16(KC_K);
      }
      break;
    case A_BASE_IO:
      if(record->event.pressed) {
        register_code16(KC_N);
      } else {
        unregister_code16(KC_N);
      }
      break;
    case A_BASE_EYI:
      if(record->event.pressed) {
        register_code16(KC_L);
      } else {
        unregister_code16(KC_L);
      }
      break;
    case A_BASE_EIO:
      if(record->event.pressed) {
        register_code16(KC_P);
      } else {
        unregister_code16(KC_P);
      }
      break;
    case A_BASE_YIO:
      if(record->event.pressed) {
        register_code16(KC_M);
      } else {
        unregister_code16(KC_M);
      }
      break;
    case A_BASE_ARTS:
      if(record->event.pressed) {
        register_code16(KC_Z);
      } else {
        unregister_code16(KC_Z);
      }
      break;
    case A_BASE_AYI:
      if(record->event.pressed) {
        register_code16(KC_QUOT);
      } else {
        unregister_code16(KC_QUOT);
      }
      break;
    case A_BASE_AI:
      if(record->event.pressed) {
        register_code16(KC_COMMA);
      } else {
        unregister_code16(KC_COMMA);
      }
      break;
    case A_BASE_AY:
      if(record->event.pressed) {
        register_code16(KC_DOT);
      } else {
        unregister_code16(KC_DOT);
      }
      break;
    case A_BASE_TI:
      if(record->event.pressed) {
        SEND_STRING("!");
      }
      break;
    case A_BASE_AO:
      if(record->event.pressed) {
        register_code16(KC_SLSH);
      } else {
        unregister_code16(KC_SLSH);
      }
      break;
    case A_BASE_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_NUM_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_SYM_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_BRAC_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_NAV_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_MOU_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_CUSTOM_RE:
      if(record->event.pressed) {
        register_code16(KC_BSPC);
      } else {
        unregister_code16(KC_BSPC);
      }
      break;
    case A_BASE_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_NUM_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_SYM_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_BRAC_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_NAV_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_MOU_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_CUSTOM_TE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LSFT),
        });
      break;
    case A_BASE_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_NUM_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_SYM_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_BRAC_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_NAV_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_MOU_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_CUSTOM_AE:
      if(record->event.pressed) {
        register_code16(KC_ENTER);
      } else {
        unregister_code16(KC_ENTER);
      }
      break;
    case A_BASE_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_NUM_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_SYM_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_BRAC_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_NAV_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_MOU_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_CUSTOM_ARO:
      if(record->event.pressed) {
        register_code16(KC_TAB);
      } else {
        unregister_code16(KC_TAB);
      }
      break;
    case A_BASE_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_NUM_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_SYM_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_BRAC_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_NAV_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_MOU_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_CUSTOM_SE:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LCTL),
        });
      break;
    case A_BASE_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_NUM_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_SYM_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_BRAC_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_NAV_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_MOU_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_CUSTOM_SY:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LGUI),
        });
      break;
    case A_BASE_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_NUM_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_SYM_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_BRAC_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_NAV_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_MOU_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_CUSTOM_SI:
      action_tapping_process((keyrecord_t){
          .event = (keyevent_t){.pressed = record->event.pressed, .time = (timer_read() | 1),},
          .keycode = OSM(MOD_LALT),
        });
      break;
    case A_BASE_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_NUM_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_SYM_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_BRAC_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_NAV_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_MOU_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_CUSTOM_EYIO:
      if(record->event.pressed) {
        register_code16(KC_SPACE);
      } else {
        unregister_code16(KC_SPACE);
      }
      break;
    case A_BASE_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_NUM_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_SYM_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_BRAC_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_NAV_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_MOU_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_CUSTOM_RY:
      if(record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        } else {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        };
      }
      break;
    case A_NUM_AR:
      if(record->event.pressed) {
        register_code16(KC_7);
      } else {
        unregister_code16(KC_7);
      }
      break;
    case A_NUM_RT:
      if(record->event.pressed) {
        register_code16(KC_8);
      } else {
        unregister_code16(KC_8);
      }
      break;
    case A_NUM_EY:
      if(record->event.pressed) {
        register_code16(KC_9);
      } else {
        unregister_code16(KC_9);
      }
      break;
    case A_NUM_YI:
      if(record->event.pressed) {
        register_code16(KC_0);
      } else {
        unregister_code16(KC_0);
      }
      break;
    case A_BASE_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_NUM_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_SYM_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_BRAC_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_NAV_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_CUSTOM_ATY:
      if(record->event.pressed) {
        layer_move(_A_MOU);
      }
      break;
    case A_MOU_ATY:
      if(record->event.pressed) {
        layer_move(_A_BASE);
      }
      break;
    case A_BASE_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_NUM_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_SYM_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_BRAC_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_MOU_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_CUSTOM_REI:
      if(record->event.pressed) {
        layer_move(_A_NAV);
      }
      break;
    case A_NAV_REI:
      if(record->event.pressed) {
        layer_move(_A_BASE);
      }
      break;
    case A_BASE_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_NUM_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_SYM_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_BRAC_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_NAV_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_MOU_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_CUSTOM_SO:
      if(record->event.pressed) {
        register_code16(KC_ESC);
      } else {
        unregister_code16(KC_ESC);
      }
      break;
    case A_BASE_AYIO:
      if(record->event.pressed) {
        register_code16(KC_CAPS);
      } else {
        unregister_code16(KC_CAPS);
      }
      break;
  }
  return true;
}
