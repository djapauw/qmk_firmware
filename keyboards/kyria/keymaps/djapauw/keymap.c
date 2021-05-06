/* 2021 Dennis Pauw <d@pauw.es>
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

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _NUMERIC,
    _MEDIA,
};

enum custom_keycodes {
    Colemak = SAFE_RANGE,
    Qwerty,
    CurrentWord
};

bool bColemak = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: COLEMAK
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  Media |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   ;  |  Media |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |LShift  |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  | RShift |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | Ctrl   |   Z  |   X  |   C  |   V  |   B  |Media |  Esc |  |Insert|Media |   K  |   M  |   ,  |   .  |   /  |  Ctrl  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |  GUI |Numeri| Back | Del  | Alt  |  | Alt  | Enter| Space|Numeri| GUI  |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_COLEMAK] = LAYOUT(
            MO(_MEDIA),  KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,                                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, MO(_MEDIA),
            KC_LSFT,     KC_A,   KC_R,   KC_S,   KC_T,   KC_D,                                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O   , KC_RSFT,
            KC_LCTRL,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,MO(_MEDIA),KC_ESC,KC_INS, MO(_MEDIA), KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTRL,
            KC_LGUI,  MO(_NUMERIC), KC_BSPC, KC_DEL, KC_LALT, KC_RALT, KC_ENT, KC_SPC, MO(_NUMERIC), KC_LGUI
        ),

    /*
     * Base Layer: QWERTY
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  Media |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | Media  |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * | LShift |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | RShift |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | Ctrl   |   Z  |   X  |   C  |   V  |   B  |Media |  Esc |  |Insert|Media |   N  |   M  | ,  < | . >  | /  ? |  Ctrl  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        | GUI  |Numeri| Back | Del  | Alt  |  | Alt  | Enter| Space|Numeri| GUI  |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_QWERTY] = LAYOUT(
            MO(_MEDIA), KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MO(_MEDIA),
            KC_LSFT,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
            KC_LCTRL,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, MO(_MEDIA),KC_ESC , KC_INS, MO(_MEDIA),      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTRL,
            KC_LGUI, MO(_NUMERIC), KC_BSPC, KC_DEL, KC_LALT, KC_RALT, KC_ENT, KC_SPC, MO(_NUMERIC), KC_LGUI
        ),

    /*
     * Lower Layer: Numeric
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |  Tab |   `  |  \   |S-F10 | Esc  |                              |   =  |   [  |   ]  |   '  |   -  |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |  F11 |  F12 |   F6 |  F7  |  F8  |  F9  | F10  |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_NUMERIC] = LAYOUT(
            _______, KC_TAB , KC_TILD, KC_BSLS, LSFT(KC_F10), KC_ESC,                                KC_EQL , KC_LBRC, KC_RBRC, KC_QUOT,KC_MINS , _______,
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7  ,  KC_8   , KC_9  , KC_0    , _______,
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, _______, KC_F11 , KC_F6  , KC_F7 ,  KC_F8  , KC_F9 , KC_F10  , _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
    
    /*
     * Raise Layer: Number keys, media, navigation
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |  TOG | SAI  | HUI  | VAI  | MOD  |                              |      |      |VolDwn|VolUp | Mute |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | Home | Pgdn | PgUp | End  | Mute |                              | Mbtn2| left | Down |  Up  | Right|        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        | Play | Previ| Next | Stop |Colema|      |QWERTY|  |      |      | Mbtn1| MLeft| Mdown| MUp  |MRight|        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_MEDIA] = LAYOUT(
            _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______,_______, KC_VOLD, KC_VOLU, KC_MUTE , _______,
            _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_MUTE,                                     KC_BTN2,KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT , _______,
            _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, DF(_COLEMAK), _______, DF(_QWERTY), _______, _______, KC_BTN1,KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_L , _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
/*
     * Lower Layer: Numeric
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |  _     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |  -     |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LShift |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  |  F11 |  F12 |   F6 |  F7  |  F8  |  F9  | F10  | RShift |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     *
    [_RNUMERIC] = LAYOUT(
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_UNDS,
            KC_GRV , KC_1   , KC_2   ,  KC_3  , KC_4   , KC_5   ,                                     KC_6   , KC_7  ,  KC_8   , KC_9  , KC_0    , KC_MINS,
            KC_LSFT, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______, _______, KC_F11 , KC_F12 , KC_F6  , KC_F7 ,  KC_F8  , KC_F9 , KC_F10  , KC_RSFT,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
*/

/*
     * Raise Layer: Number keys, media, navigation
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      |  SAD | HUD  | VAD  | RMOD |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              |      | left | Down |  Up  | Right|        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      | Mbtn1| MLeft| Mdown| MUp  |MRight|  Mbtn2 |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     *
    [_LMEDIA] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                                      _______,RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
            _______, _______, _______, _______, _______, _______,                                      KC_BTN2,KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1,KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_L, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
*/
    // /*
    //  * Layer template
    //  *
    //  * ,-------------------------------------------.                              ,-------------------------------------------.
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        `----------------------------------'  `----------------------------------'
    //  */
    //     [_LAYERINDEX] = LAYOUT(
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //     ),
};

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _QWERTY, _LNUMERIC, _RNUMERIC, _MEDIA);
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case Colemak:
            if (record->event.pressed) {
                default_layer_set(_COLEMAK);
                bColemak = true;
            }
            break;
        case Qwerty:
            if (record->event.pressed) {
                default_layer_set(_QWERTY);
                bColemak = false;
            }
            break;
        case CurrentWord:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_RGHT);
                unregister_code(KC_LCTL);
                tap_code(KC_LEFT);
            }
            break;
    }
    return true;
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x60, 0x90, 0x98, 0x98, 
0x10, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x3c, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0xfd, 
0x7f, 0x01, 0x81, 0x80, 0xc0, 0x60, 0x38, 0x0f, 0x01, 0xc0, 0xe0, 0xf0, 0xf0, 0xe0, 0xe0, 0x80, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0x8e, 0x87, 0x83, 0x83, 0x83, 0x07, 0x0f, 0xfe, 0xfe, 0xc3, 
0x43, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 0xfe, 0x78, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x67, 0x47, 0x77, 
0x62, 0xfe, 0x80, 0x01, 0x07, 0x0c, 0x38, 0xe1, 0x82, 0x04, 0x08, 0x71, 0xe7, 0xc6, 0x9c, 0xcf, 
0x70, 0x31, 0x19, 0x18, 0x0c, 0x84, 0xc2, 0x60, 0x30, 0x39, 0x8f, 0xc7, 0x63, 0x33, 0x13, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0xfc, 0xff, 0x3f, 0xbd, 
0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x30, 0x18, 0x8c, 0xc7, 0x03, 0x00, 0x00, 0xc0, 0xc0, 0x00, 
0x00, 0x80, 0xc0, 0x40, 0x00, 0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0x08, 0x18, 0x10, 0x30, 0x30, 
0x60, 0x41, 0xc3, 0x87, 0x0c, 0x18, 0x30, 0xe0, 0x83, 0x00, 0x00, 0xfc, 0xff, 0xc3, 0xc3, 0xe3, 
0xfe, 0xfe, 0x80, 0x02, 0x23, 0x31, 0x18, 0x0c, 0x06, 0x03, 0x81, 0xc0, 0xfc, 0x7e, 0x3f, 0x3f, 
0x3f, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xff, 0x03, 0x60, 0xf0, 
0x18, 0x18, 0x18, 0x18, 0xfb, 0xff, 0x7e, 0x00, 0xff, 0xff, 0x80, 0x00, 0x80, 0xff, 0xff, 0x90, 
0xfe, 0xff, 0x01, 0x00, 0xc0, 0xf0, 0xe0, 0x83, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x18, 0x18, 0x10, 0x31, 0x33, 0x06, 0x04, 0x80, 0xf8, 0x1e, 0x07, 0x03, 0x01, 0x00, 0x03, 0x0f, 
0x03, 0x00, 0x03, 0x0f, 0xfc, 0xe0, 0x00, 0x06, 0xc6, 0x43, 0x21, 0x21, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x00, 0x00, 0x03, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 
0x01, 0x03, 0x03, 0x03, 0x01, 0x01, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}


static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev 1.4 djapauw\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            if(bColemak) {
                oled_write_P(PSTR("Colemake\n"), false);
            } else {
                oled_write_P(PSTR("QWERTY\n"), false);
            }
            break;
        case _QWERTY:
            if(bColemak) {
                oled_write_P(PSTR("->Colemake<-\n"), false);
            } else {
                oled_write_P(PSTR("->QWERTY<-\n"), false);
            }
            break;
        case _NUMERIC:
            oled_write_P(PSTR("Numeric\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        default:
            oled_write_P(PSTR("Default???\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif


#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM shift_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  8, 1, 120, 255, 255},
    { 18, 1, 120, 255, 255}
);
const rgblight_segment_t PROGMEM control_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  6, 1, 0, 255, 255},
    { 16, 1, 0, 255, 255}
);
const rgblight_segment_t PROGMEM alt_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  2, 1, 240, 255, 255},
    { 17, 1, 250, 255, 255}
);
const rgblight_segment_t PROGMEM gui_layers[] = RGBLIGHT_LAYER_SEGMENTS(
    {  7, 1, 51, 255, 255},
    { 12, 1, 51, 255, 255}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    shift_layers,
    control_layers,
    alt_layers,
    gui_layers
);

void keyboard_post_init_keymap(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _MEDIA ));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUMERIC));
    return state;
}

void matrix_scan_keymap(void) {
        uint8_t mods = mod_config(get_mods()|get_oneshot_mods());
        rgblight_set_layer_state(0, mods & MOD_MASK_SHIFT);
        rgblight_set_layer_state(1, mods & MOD_MASK_CTRL);
        rgblight_set_layer_state(2, mods & MOD_MASK_ALT);
        rgblight_set_layer_state(3, mods & MOD_MASK_GUI);
}
#endif