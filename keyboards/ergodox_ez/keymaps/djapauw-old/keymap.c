/*
  Copyright 2019 Mario Arias <mario@marioarias.org>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"
#include "keymap_spanish.h"

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _MEDIA,
    _NUMERIC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Colemak layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |  1 ! | 2 "  | 3 ·  | 4 $  | 5 %  |  Esc |           |   =  |  6 & | 7 /  |  8 ( | 9 )  | 0 =  |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   F  |   P  |   G  |   \  |           |  [   |   J  |   L  |   U  |   Y  |  ;   |    ]   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Shft-F10|   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |  O   |   '    |
 * |--------+------+------+------+------+------| Media|           | Media|------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |  , ; |  . : |   /  |  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctlr |Home  | PgDn | PgUp | End  |                                       | Left | Down |  Up  | Right| Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.        ,--------------.
 *                                        | GUIL |Numeric|        | Qwer | GUIR |
 *                                 ,------|------|-------|        |------+-------+------.
 *                                 |      |      | Insert|        |Prints|       |      |
 *                                 |Backsp|  Del |-------|        |------|  ENT  |Space |
 *                                 |      |      |  ALt  |        |  Alt |       |      |
 *                                 `---------------------'        `---------------------'
 */
[_COLEMAK] = LAYOUT_ergodox(
// left hand
        KC_TILD,    KC_1,       KC_2,           KC_3,           KC_4,        KC_5,        KC_ESC,
        KC_TAB,     KC_Q,       KC_W,           KC_F,           KC_P,        KC_G,        KC_BSLS,
        LSFT(KC_F10),KC_A,      KC_R,           KC_S,           KC_T,        KC_D,
        KC_LSFT,    KC_Z,       KC_X,           KC_C,           KC_V,        KC_B,        MO(_MEDIA),
        KC_LCTL,    KC_HOME,    KC_PGDN,        KC_PGUP,         KC_END,

                                                                            KC_LGUI,     MO(_NUMERIC),
                                                                                        KC_INS,
                                                                KC_BSPC,    KC_DEL,     KC_LALT,

// right hand
        KC_EQUAL,       KC_6,           KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        KC_LBRC,        KC_J,           KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_RBRC,
                        KC_H,           KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
        MO(_MEDIA),     KC_K,           KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                        KC_LEFT,        KC_DOWN,    KC_UP,      KC_RGHT,    KC_RCTL,

        DF(_QWERTY),     KC_RGUI,
        KC_PSCR,
        KC_RALT,        KC_ENT,     KC_SPC
),
/* Keymap 1: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Base |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
        _______,        _______,    _______,    _______,    _______,    _______,    _______,
        _______,        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       _______,
        _______,        KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        _______,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       _______,
        _______,        _______,    _______,    _______,    _______,

                                                                        _______,    _______,
                                                                                    _______,
                                                        _______,        _______,    _______,

// right hand
        _______,        _______,    _______,    _______,    _______,    _______,    _______,
        _______,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       _______,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    _______,
        _______,        KC_N,       KC_M,       _______,    _______,    _______,    _______,
                                    _______,    _______,    _______,    _______,    _______,
        _______,   _______,
        _______,
        _______,    _______,    _______
),
/* Keymap 2: Function Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* |        |  Tab |   `  |  \   | S-F10|  Esc |      |           |      |   =  |   [  |   ]  |  '   |   -  |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |   1  |   2  |  3   |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | F11  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |      |      |      |      |      |                                       |      |      |      |      |      |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        |      |      |       |      |      |
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      |      |       |      |      |      |
*                                 |      |      |------|       |------|      |      |
*                                 |      |      |      |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
[_NUMERIC] = LAYOUT_ergodox(
        // left hand
        _______,        _______,      _______,     _______,    _______,     _______,    _______,
        _______,        KC_TAB ,      KC_GRAVE,    KC_BSLS,    LSFT(KC_F10),KC_ESC ,    _______,
        _______,        KC_1   ,      KC_2   ,     KC_3   ,    KC_4   ,     KC_5   ,
        _______,        KC_F1  ,      KC_F2  ,     KC_F3  ,    KC_F4  ,     KC_F5  ,    _______,
        _______,        _______,      _______,     _______,    _______,

                                                                            _______,    _______,
                                                                                        _______,
                                                                _______,    _______,    _______,

// right hand
        _______,        _______,      _______,      _______,    _______,    _______,    _______,
        _______,        KC_EQL ,      KC_LBRC,      KC_RBRC,    KC_QUOT,    KC_MINS,    _______,
                        KC_6   ,      KC_7   ,      KC_8   ,    KC_9   ,    KC_0   ,    _______,
        KC_F11,         KC_F6  ,      KC_F7  ,      KC_F8  ,    KC_F9  ,    KC_F10 ,    _______,
        _______,        _______,      _______,      _______,    _______,

        _______,        _______,
        _______,
        _______,        _______,      _______
),
/* Mouse and media controls
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | F11  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  TOG | SAI  | HUI  | VAI  | MOD  |      |           |      |      |      |VolDwn|VolUp | Mute |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Pgdn | PgUp | End  | Mute |------|           |------| Mbtn2| left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Play | Previ| Next | Stop |Colema|      |           |      | Mbtn1| MLeft| Mdown| MUp  |MRight|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |QWERTY|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------        |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_MEDIA] = LAYOUT_ergodox(
        // left hand
        _______,         KC_F1  ,      KC_F2  ,      KC_F3  ,    KC_F4  ,    KC_F5 ,       _______,
        _______,        RGB_TOG,      RGB_SAI,     RGB_HUI,    RGB_VAI,     RGB_MOD,       _______,
        _______,        KC_HOME,      KC_PGDN,     KC_PGUP,    KC_END ,     KC_MUTE,
        _______,        KC_MPLY,      KC_MPRV,     KC_MNXT,    KC_MSTP,     DF(_COLEMAK),  _______,
        _______,        _______,      _______,     _______,    _______,

                                                                            DF(_QWERTY),_______,
                                                                                        _______,
                                                                _______,    _______,    _______,

// right hand
        KC_F11 ,         KC_F6  ,      KC_F7  ,      KC_F8  ,    KC_F9  ,   KC_F10 ,   KC_F12,  
        _______,        _______,      _______,      KC_VOLD,    KC_VOLU,    KC_MUTE,    _______,
                        KC_BTN2,      KC_LEFT,      KC_DOWN,    KC_UP  ,    KC_RGHT,    _______,
        _______,        KC_BTN1,      KC_MS_L,      KC_MS_D,    KC_MS_U,    KC_MS_L,    _______,
        _______,        _______,      _______,      _______,    _______,

        _______,        _______,
        _______,
        _______,        _______,      _______
)
};


void led_1_off(void) {
    ergodox_right_led_1_off();
}

void led_2_off(void) {
    ergodox_right_led_2_off();
}

void led_3_off(void) {
    ergodox_right_led_3_off();
}

//Runs just one time when the keyboard initializes
void matrix_init_use(void) {
    led_1_off();
    led_2_off();
    led_3_off();
}

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;


void led_1_on(void) {
    ergodox_right_led_1_on();
    ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
    ergodox_right_led_2_on();
    ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
    ergodox_right_led_3_on();
    ergodox_right_led_3_set(max_led_value);
}

uint32_t layer_state_set_user(uint32_t state) {

    if(layer_state_cmp(state ,_NUMERIC) || layer_state_cmp(state ,_MEDIA) ) {
        led_2_on();
    } else {
        led_2_off();
    }

  return state;
};

void matrix_scan_user(void) {

    ergodox_board_led_off();
    led_1_off();
    //led_2_off();
    led_3_off();

    if(layer_state_cmp(default_layer_state,_QWERTY)) {
        led_3_on();
    }

    if(layer_state_cmp(default_layer_state,_COLEMAK)) {
        led_1_on();
    }
};
