/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _NAV,
    _SYM,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)

// Macros useful in keyboard layers
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
/* #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE) */
/* #define CTL_MINS MT(MOD_RCTL, KC_MINUS) */
/* #define RSFT_MINS MT(MOD_RCTL, KC_MINUS) */
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define AGRA RALT(KC_Z)
#define EGRA RALT(KC_F)
#define IGRA RALT(KC_V)
#define OGRA RALT(KC_COMM)
#define UGRA RALT(KC_H)
#define EACU RALT(KC_G)
#define EXPO LCMD(KC_MISSION_CONTROL)
#define CMDSPACE LCMD(KC_SPC)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | '   "  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  Opt | Cmd  |Space | LAlt/| Sym  |  | Nav  | Space| AltGr|  Cmd | Opt  |
 *                        |      |      |      | Enter|      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                           KC_Y ,   KC_U ,  KC_I  ,   KC_O ,   KC_P ,  KC_BSPC,
     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                           KC_H ,   KC_J ,  KC_K  ,   KC_L , KC_SCLN, KC_QUOTE,
     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,CMDSPACE, XXXXXXX,     XXXXXXX ,CMDSPACE,  KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH,  KC_RSFT,
                                KC_LOPT, KC_LCMD, KC_SPC , ALT_ENT,   SYM  ,     NAV     , KC_SPC ,KC_RALT, KC_RCMD, KC_ROPT
    ),

/*
 * Nav Layer: navigation, media, and Italian keyboards
 *
 * ,-----------------------------------------------.                              ,-------------------------------------------.
 * | Exposé |ms ctrl |   è    |   é  |      |      |                              |      |   ù  |  ì   |  ò   | VolUp| Delete |
 * |--------+--------+--------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F1    |  à     |  F2    |  F3  |  F4  |  F5  |                              |  ←   |   ↓  |  ↑   |  →   | VolDn| Insert |
 * |--------+--------+--------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F6    |  F7    |  F8  |  F9  |  F10 |      |      |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `--------------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                            |      |      |      |      |      |  |      |      |      |      |      |
 *                            |      |      |      |      |      |  |      |      |      |      |      |
 *                            `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      EXPO   , KC_MISSION_CONTROL, EGRA  , EACU   , _______, _______,                                     _______ , UGRA   , IGRA   , OGRA   , KC_VOLU, KC_DEL ,
      KC_F1  ,      AGRA         , KC_F2 , KC_F3  , KC_F4  , KC_F5  ,                                     KC_LEFT , KC_DOWN,  KC_UP ,KC_RIGHT, KC_VOLD, KC_INS ,
      _______,      KC_F6        , KC_F7 , KC_F8  , KC_F9  , KC_F10 , _______, _______, _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

 /*
  * Sym Layer: Numbers and symbols
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |  Tab   |  !   |  @   |   #  |  $   |  %   |                              |  ^   |  &   |  *   |  (   |  )   |   \    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |Ctrl/Esc|  1   |  2   |   3  |  4   |  5   |                              |  -   |  =   |  `   |  [   |  ]   |   |    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * | LShift |  6   |  7   |   8  |  9   |  0   |      |      |  |      |      |  _   |  +   |  ~   |  {   |  }   |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_SYM] = LAYOUT(
       _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_MINS, KC_EQL , KC_GRV , KC_LBRC, KC_RBRC, KC_PIPE,
       _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

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
