/*
 * Copyright (c) 2018 Charlie Waters
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

#include "vortex.h"
#include "keymap_norwegian.h"

/* 
 * ,--------------------------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  +   |   \  | Bksp  |
 * |------+------+------+------+------+-------------+------+------+------+------+-------------+-------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |   ^  |       |
 * |------+------+------+------+------+------|------+------+------+------+------+-------------+ ENTER |
 * | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ø  |  Æ   |   '  |       |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Shift|   <  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  -   |      UP      |  
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+-------|
 * | Ctrl | META | Alt  |                 Space                          | ALTGR| Left | Down | RIGHT |
 * `--------------------------------------------------------------------------------------------------'
 */

const uint16_t keymaps_default[][MATRIX_ROWS][MATRIX_COLS] = {
#if defined(KEYMAP_60_ISO)
    [0] = LAYOUT_60_iso(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, NO_BSLS,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA, NO_QUOT,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE, NO_APOS, KC_ENT,
        KC_LSFT, NO_LESS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, LT(MO(1), KC_SPC),  NO_ALGR, KC_LEFT,   KC_DOWN, KC_RIGHT
    ),

/* 
 * ,--------------------------------------------------------------------------------------------------.
 * |   |  |   F1 |   F2 |   F3 |   F4 |   F5 |   F6 |   F7 |   F8 |   F9 |  F10 |  F11 |  F12 |  Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------+-------|
 * |      | HOME |  UP  | END  |      |AUTSFT|      | PG_UP|      |PG_DWN|PRNTSC|SCRLCK|PAUSE |       |
 * |------+------+------+------+------+------+------+------+------+------+------+-------------+ ENTER |
 * |      | LEFT | DOWN | RIGHT|      |      | LEFT | DOWN |  UP  | RGHT | INS  |      |      |       |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      | VOL- | VOL+ | MUTE |      |      |      |      |      |      |      |      |   R_SHIFT    |  
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+-------|
 * |      |      |      |                                                |      |      | PN   | CTRL  |
 * `--------------------------------------------------------------------------------------------------'
 */
    [1] = LAYOUT_60_iso(
        NO_PIPE,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_HOME, KC_UP, KC_END, _______, KC_ASTG, _______, KC_PGUP, _______,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, 
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_INS, _______ ,  M(0), _______, 
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______,  _______, BL_DEC,  BL_TOGG, BL_INC,  KC_RSFT,
        _______, _______, _______, _______, _______, _______, _______, KC_RCTL
    ),
#else
    #error "No Keymap!"
#endif
};

const uint16_t keymaps_default_size = sizeof(keymaps_default);
uint16_t keymaps[MAX_LAYERS][MATRIX_ROWS][MATRIX_COLS];

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch(id) {
        	// Macro to lock / release the keyboard from evdev passthrough.
            case 0:
                return MACRO(D(LCTRL), D(RCTRL), U(LCTRL), U(RCTRL), END);
        }
    }

    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

}
