#include "ergodox.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_bepo.h"
#include "keymap_french.h"

#define BASE 0 // default layer
#define NUML 1 // numeric layer
#define FUNL 2 // function keys layer
#define NAVL 3 // navigation layer

#define KP_00 0	// keypad "double 0"


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
 *   |      |      |      |      | NAVL |                                       | AltGr|      |   %  |   W  |      |
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
        BP_DLR,         BP_DQOT,      BP_LGIL,     BP_RGIL,        BP_LPRN,         BP_RPRN,      KC_DEL,
        KC_TAB,         BP_B,         BP_E_ACUTE,  LT(NUML, BP_P), LT(FUNL, BP_O),  BP_E_GRAVE,   KC_BSPC,
        KC_ESC,         BP_A,         BP_U,        BP_I,           BP_E,            BP_COMMA,
        BP_ECRC,        BP_A_GRAVE,   BP_Y,        BP_X,           BP_DOT,          BP_K,         KC_ENT,
        KC_NO,          KC_NO,        KC_NO,       KC_NO,          MO(NAVL),
                                             KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
                                                                KC_NO,
                                          KC_ENTER, LGUI(KC_Z), KC_AUDIO_MUTE,
        // right hand
             KC_DEL,      BP_AT,     BP_PLUS,     BP_MINUS,     BP_SLASH,     BP_ASTR,      BP_EQUAL,
             KC_BSPC,     BP_DCRC,   BP_V,        BP_D,         BP_L,         BP_J,         BP_Z,
                          BP_C,      BP_T,        BP_S,         BP_R,         BP_N,         BP_M,
             KC_ENT,      BP_APOS,   BP_Q,        BP_G,         BP_H,         BP_F,         BP_CCED,
                          BP_ALGR,   KC_NO,       BP_PERC,      BP_W,         KC_NO,
             KC_MPRV,  KC_MNXT,
             KC_NO,
             KC_MPLY, KC_BSPC, KC_SPC
    ),
/* Keymap 1: numeric keypad layer, sends keypad codes
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      | NumLo|   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |   1  |   2  |   3  | Enter|        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |   0  |  00  |   .  | Enter|      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NUML] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_NUMLOCK,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_KP_MINUS,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_PLUS,	KC_NO,
						KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_PLUS,	KC_NO,
				KC_NO,		KC_NO,		KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_ENTER,	KC_NO,
								KC_KP_0,	M(KP_00),	KC_KP_COMMA,	KC_KP_ENTER,	KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO),

/* Keymap 2: function keys layer (F1, F2...)
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      |  F10 |  F11 | F12  |      |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |  F1  |  F2  |  f3  |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NUML] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_F12,	KC_F11,	KC_F12,	KC_NO,	KC_NO,
				KC_NO,		KC_NO,		KC_F7,	KC_F8,	KC_F9,	KC_NO,	KC_NO,
				            KC_NO,		KC_F4,	KC_F5,	KC_F6,	KC_NO,	KC_NO,
				KC_NO,		KC_NO,		KC_F1,	KC_F2,	KC_F3,	KC_NO,	KC_NO,
							KC_KP_0,	KC_NO,	KC_NO,	KC_NO,	KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO),

/* Keymap 3: navigation layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      | HOME |  UP  |  END |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|                                  |------|      | LEFT | DOWN |RIGHT |      |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[NAVL] = KEYMAP(
// Left hand
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
KC_NO,		KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,
														KC_TRNS,	KC_TRNS,
																KC_TRNS,
												KC_NO,		KC_TRNS,	KC_TRNS,
// Right hand
				KC_NO,		KC_NO,		KC_NO,	     KC_NO,	     KC_NO,	        KC_NO,	KC_NO,
				KC_NO,		KC_NO,		KC_MS_BTN1,	 KC_MS_UP,	 KC_MS_BTN2,	KC_NO,	KC_NO,
				            KC_NO,		KC_MS_LEFT,	 KC_MS_DOWN, KC_MS_RIGHT,	KC_NO,	KC_NO,
				KC_NO,		KC_NO,		KC_NO,	     KC_NO,	     KC_NO,	        KC_NO,	KC_NO,
							KC_KP_0,	KC_NO,	     KC_NO,	     KC_NO,	        KC_NO,
KC_TRNS,	KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,	KC_NO)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    // keypad "double 0"
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
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
