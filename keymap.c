#include QMK_KEYBOARD_H

#define QWERTY 00
#define SYMBOLS 1
#define MODS 2
#define MEDIA 3
#define NUMBLOCK 4

#define LALT_GRV LALT_T(KC_GRV)
#define LT_MOD_SPC LT(MODS, KC_SPC)
#define JB_DOC LCTL(KC_1)
#define JB_FUS LALT(KC_F7)
#define COMM LCTL(KC_SLSH)
#define JB_REN LSFT(KC_F6)

enum custom_keycodes {
    DBL_EQUAL = SAFE_RANGE,
    NEQ,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DBL_EQUAL:
        if (record->event.pressed) { SEND_STRING("=="); }
        break;
    case NEQ: 
        if (record->event.pressed) { SEND_STRING("!="); }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* layer 0: qwerty
 *
 * NOTE: LGUI and LCTL 
 *       are switched with Karabiner-Elements on Mac 
 *       to provide similar experience 
 *       on win and mac
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |   =  |           |   \  |   6  |   7  |   8  |   9  |   0  |    ]   |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   q  |   w  |   e  |   r  |   t  |      |           |      |   y  |   u  |   i  |   o  |   p  |    [   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | JB_DOC |   a  |   s  |   d  |   f  |   g  | BSpc |           | BSpc |   h  |   j  |   k  |   l  |   ;  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | JB_FUS |   z  |   x  |   c  |   v  |   b  |      |           |      |   n  |   m  |   ,  |   .  |   /  |    -   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTL+/| SH+F6|  DEL |LALT(`)| LCTL|                                |LT(MODS, SPC)| BTN_4| BTN_5|  ==  |  !=  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | mMODS| LGUI |       |tMEDIA| RALT |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |  mL1 |      |
 *                                        | LSFT | mNUM |       |SYMBOL|  RET |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */
  [QWERTY] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,  KC_RBRC,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,   KC_EQL,                              KC_BSLS,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_LBRC,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        JB_DOC,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_BSPC,                              KC_BSPC,     KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,  KC_QUOT, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        JB_FUS,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B, MO(MODS),  KC_LGUI,        TG(MEDIA),  KC_RALT,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_MINS,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
          COMM,   JB_REN,   KC_DEL, LALT_GRV,       KC_LCTL,       KC_LSFT,MO(NUMBLOCK),   MO(SYMBOLS),   KC_ENT,   LT_MOD_SPC,        KC_BTN4,  KC_BTN5,DBL_EQUAL,      NEQ
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  ),



/* layer 1: symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |   @  |   \  |   $  |   #  |   !  |      |           |      |      |   {  |   }  |   <  |   >  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   /  |   *  |   -  |   +  |   =  |      |           |      |      |   (  |   )  |   &  |   |  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   %  |   ^  |      |      |           |      |      |   [  |   ]  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */
  [SYMBOLS] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                                    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_AT,  KC_BSLS,   KC_DLR,  KC_HASH,  KC_EXLM,  KC_TRNS,                              KC_TRNS,    KC_NO,  KC_LCBR,  KC_RCBR,    KC_LT,    KC_GT,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,  KC_SLSH,  KC_ASTR,  KC_MINS,  KC_PLUS,   KC_EQL,  KC_TRNS,                              KC_TRNS,    KC_NO,  KC_LPRN,  KC_RPRN,  KC_AMPR,  KC_PIPE,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,    KC_NO,  KC_PERC,  KC_CIRC,    KC_NO,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_NO,  KC_LBRC,  KC_RBRC,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  ),



/* layer 2: mods & arrows
 *
 * NOTE: ALT+TAB for windows, delete file for macos (CMD+ALT+BSPC)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | ALT+TAB|      |DELFIL|      |      |      |      |           |      | PGUP |      |   ▲  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | LGUI | LALT | LCTL |      | BSpc |           | BSpc | PGDN |   ◀  |   ▼  |   ▶  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   x  |   c  |   v  |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | LCTL |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */
  [MODS] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
  LALT(KC_TAB),  KC_NO,LCA(KC_BSPC),   KC_NO,    KC_NO,    KC_NO,    KC_NO,                                KC_NO,  KC_PGUP,    KC_NO,    KC_UP,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,  KC_LGUI,  KC_LALT,  KC_LCTL,    KC_NO,  KC_BSPC,                              KC_BSPC,  KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,    KC_NO,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,     KC_X,     KC_C,     KC_V,    KC_NO,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  ),



/* layer 3: media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      | SCR▲ |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | SCR◀ | SCR▼ | SCR▶ |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MUTE | VOL+ | VOL- |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | MUTE | VOL+ | VOL- |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  ~L0 |      |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */
  [MEDIA] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,    KC_NO,  KC_WH_U,    KC_NO,    KC_NO,  KC_TRNS,                              KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,  KC_WH_L,  KC_WH_D,  KC_WH_R,    KC_NO,  KC_TRNS,                              KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,  KC_TRNS,          KC_TRNS,    KC_NO,    KC_NO,    KC_NO,  KC_MUTE,  KC_VOLU,  KC_VOLD,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_TRNS,       KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,        KC_NO,       KC__MUTE,KC__VOLUP,  KC_VOLD,    KC_NO
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  ), 



/* layer 4: numblock
 * 
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   ,  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   /  |   *  |   -  |   +  |   =  | BSpc |           | BSpc |      |   4  |   5  |   6  |   :  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   =  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |      |  RET |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |  RET |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */
  [NUMBLOCK] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                KC_NO,    KC_NO,     KC_7,     KC_8,     KC_9,  KC_COMM,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,  KC_SLSH,  KC_ASTR,  KC_MINS,  KC_PLUS,   KC_EQL,  KC_TRNS,                              KC_TRNS,    KC_NO,     KC_4,     KC_5,     KC_6,  KC_COLN,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,  KC_TRNS,    KC_NO,     KC_1,     KC_2,     KC_3,   KC_EQL,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,         KC_NO,    KC_NO,            KC_NO,  KC_TRNS,         KC_0,         KC_DOT,    KC_NO,   KC_ENT,    KC_NO
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  )
};



/* empty template layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                        |------+------|       |------+------+
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        |      |      |       |      |      |
 *                                        --------------'       `--------------
 */

/*
  [TEMPLATE] = LAYOUT(
  //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                                               ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐                           ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, 
  //├─────────┼─────────┼─────────┼─────────┼────┬────┴────┬────┼─────────┼─────────┤       ├─────────┼─────────┼───┬─────┴───┬─────┼─────────┼─────────┼─────────┼─────────┤
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  //└─────────┴─────────┴─────────┴─────────┘    └─────────┘    └─────────┴─────────┘       └─────────┴─────────┘   └─────────┘     └─────────┴─────────┴─────────┴─────────┘
  ),
  */