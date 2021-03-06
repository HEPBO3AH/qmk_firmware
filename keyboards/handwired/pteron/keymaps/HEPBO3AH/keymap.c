#include QMK_KEYBOARD_H

enum pteron_layers {
  _QWERTY,
  _WIN,
  _LOWER,
  _RAISE,
  _ADJUST
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WIN DF(_WIN)
#define MAC DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * +-----------------------------------------+      +-----------------------------------------+
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |Enter |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |  GUI | SPC  |Lower | Mute |      | Play |Lower |Raise | Alt  |
 *               +---------------------------+      +---------------------------+
 */
[_QWERTY] = LAYOUT( \
  GRAVE_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,  \
  KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  \
                      KC_LGUI, KC_SPC,  LOWER,   KC_MUTE,         KC_MPLY, LOWER,   RAISE,   KC_LALT  \
),

/* Win
 * +-----------------------------------------+      +-----------------------------------------+
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |  Alt |      |      |      |      |      |      |      | GUI  |
 *               +---------------------------+      +---------------------------+
 */
[_WIN] = LAYOUT( \
  _______,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, \
                      KC_LALT, _______, _______, _______,        _______, _______, _______, KC_LGUI  \
),

/* Lower
 * +-----------------------------------------+      +-----------------------------------------+
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  F11 |  F12 | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |      |      |      | Vol- |      | Vol+ |      |      |      |
 *               +---------------------------+      +---------------------------+
 */
[_LOWER] = LAYOUT( \
  GRAVE_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,   \
  KC_GRAVE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  KC_DEL,  \
  _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
                      _______, _______, _______, KC__VOLDOWN,     KC__VOLUP, _______, _______, _______  \
),

/* Raise
 * +-----------------------------------------+      +-----------------------------------------+
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |  `   |      |      |   [  |   ]  |  +   |      |      |      |  UP  |  F11 |  F12 | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |   (  |   )  |  =   |      |      | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |   {  |   }  |  -   |      |   _  |      |      |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |      | ALT  |      | Br-  |      | Br+  |      |      |      |
 *               +---------------------------+      +---------------------------+
 */
[_RAISE] = LAYOUT( \
  GRAVE_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_BSPC,   \
  KC_GRAVE,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_PPLS,     XXXXXXX, XXXXXXX, KC_UP,   KC_F11,   KC_F12,  KC_DEL,  \
  _______,   XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_PEQL,     XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, \
  _______,   XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PMNS,     KC_UNDS, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______, \
                      _______, KC_LALT, _______, KC_BRID,     KC_BRIU, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * +-----------------------------------------+      +-----------------------------------------+
 * |  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |  `   |      | WIN  |      |Reset |      |      |      |      |      |  F11 |  F12 | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |Debug |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  MAC |      |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |      |      |      |      |      |      |      |      |      |      
 *               +---------------------------+      +---------------------------+
 */
[_ADJUST] = LAYOUT( \
  GRAVE_ESC, KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,   \
  KC_GRAVE,  _______, WIN,     _______,   RESET, _______,        _______, _______, _______, KC_F11,  KC_F12,  KC_DEL,  \
  _______,   _______, _______,   DEBUG, _______, _______,        _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______,        _______, MAC    , _______, _______, _______, _______, \
                      _______, _______, _______, _______,        _______, _______, _______, _______  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
