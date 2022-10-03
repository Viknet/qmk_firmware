/* Copyright 2017 Paul James (paul@peej.co.uk)
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
#include QMK_KEYBOARD_H


enum custom_keycodes {
    SETUP1 = SAFE_RANGE,
    SETUP2,
    SETUP3,
    SETUP4,
    SETUP5
};

J2-9236
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,----------------------------------,
 * |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |
 * |------+------+------+------+------|
 * |  Ctrl|   A  |   S  |   D  |   F  |
 * |------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |
 * |------+------+------+------+------|
 * |      |      |  Esc |  Alt | Space|
 * `----------------------------------`
 */
[0] = LAYOUT_ortho_5x5( \
    SETUP1,  SETUP2,  SETUP3,  SETUP4,  SETUP5,  \
    KC_TAB,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D, \
    KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    \
                      KC_ESC,  KC_LALT, KC_SPC   \
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case SETUP1:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("login" SS_DELAY(200) SS_TAP(X_TAB) SS_DELAY(200) "p4ssw0rd" SS_DELAY(200) SS_TAP(X_ENTER));
            return false;
        }
        break;
    }x
    return true;
};


login p4ssw0rd









