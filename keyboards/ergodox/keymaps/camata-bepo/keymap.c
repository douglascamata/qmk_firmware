#include "ergodox.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_french.h"
#include "keymap_bepo.h"

#define BASE 0 // default layer
#define NUML 1 // numeric layer
#define NUML 2 // numeric layer

// TODO: thumb cluster of the right side
// TODO: numeric layer
// TODO: movement/support layer
// TODO: function keys layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   $    |   "  |   «  |   »  |   (  |   )  | Del  |           | Del  |   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   B  |   É  |   P  |   O  |   È  |   [  |           |  ]   |   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Escape |   A  |   U  |   I  |   E  |   ,  |------|           |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * |   Ê    |   À  |   Y  |   X  |   .  |   K  |      |           |      |   '  |   Q  |   G  |   H  |   F  |   Ç    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Prev | Play | Next |                                       | AltGr|      |   %  |   W  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Vol- | Vol+ |       | Prev |  Next  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Enter| Cmd+Z|------|       |------| Bckspc | Space|
 *                                 |      |      | Mute |       | Play |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        BP_DLR,         BP_DQOT,      BP_LGIL,     BP_RGIL,     BP_LPRN,     BP_RPRN,      KC_DEL,
        KC_TAB,         BP_B,         BP_E_ACUTE,  BP_P,        BP_O,        BP_E_GRAVE,   KC_BSPC,
        KC_ESC,         BP_A,         BP_U,        BP_I,        BP_E,        BP_COMMA,
        BP_ECRC,        BP_A_GRAVE,   BP_Y,        BP_X,        BP_DOT,      BP_K,         KC_ENT,
        KC_NO,          KC_NO,        KC_NO,       KC_NO,       KC_NO,
                                             KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
                                                                KC_NO,
                                          KC_ENTER, LGUI(KC_Z), KC_AUDIO_MUTE),
        // right hand
             KC_DEL,      BP_AT,     BP_PLUS,     BP_MINUS,     BP_SLASH,     BP_ASTR,      BP_EQUAL,
             KC_BSPC,     BP_DCRC,   BP_V,        BP_D,         BP_L,         BP_J,         BP_Z,
                          BP_C,      BP_T,        BP_S,         BP_R,         BP_N,         BP_M,
             KC_ENT,      BP_APOS,   BP_Q,        BP_G,         BP_H,         BP_F,         BP_CCED,
                                  KC_NO,  KC_NO,  BP_PERC,BP_W,             KC_NO,
             CTL_T(KC_CALC),  KC_LALT,
             MO(NUML),
             MO(SPFN), OSM(MOD_LSFT), KC_RALT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Mute |      |      |      |      |      | Version|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  |  F10 |      |           | VolUp|      | Home |  Up  | End  | PgUp |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |------|           |------|      | Left | Down | Right| PgDn |        |
 * |--------+------+------+------+------+------|      |           | VolDn|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
// Space Fn layer
[SPFN] = KEYMAP(
       // left hand
       RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_TRNS,
       KC_TRNS,KC_F11, KC_F12, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_MUTE, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, M(0),
       KC_VOLU, KC_TRNS, KC_HOME,KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
                KC_TRNS, KC_LEFT,KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
       KC_VOLD, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Numeric Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  (   |  )   |      |      |      |           |      |      |  7   |  8   |  9   |  *   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  [   |  ]   |  <   |  >   |------|           |------|      |  4   |  5   |  6   |  +   |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  {   |  }   |      |      |      |           |      |      |  1   |  2   |  3   |  /   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |n.lock|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  .   |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// numeric layer
[NUML] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_4,   KC_5,   KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,RALT(KC_4),RALT(KC_5),RALT(KC_2),RALT(KC_3),
       KC_TRNS,KC_TRNS,RALT(KC_X),RALT(KC_C),KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P7,  KC_P8,   KC_P9,   KC_PAST, KC_TRNS,
                KC_TRNS, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
       KC_TRNS, KC_TRNS, KC_P1,  KC_P2,   KC_P3,   KC_PSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_NLCK,
       KC_TRNS,
       KC_TRNS, KC_PDOT, KC_P0
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SPFN)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
