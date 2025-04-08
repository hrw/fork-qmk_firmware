// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// If console is enabled, it will print the matrix position and status of each
// key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, "
            "time: %5u, int: %u, count: %u\n",
            keycode, record->event.key.col, record->event.key.row,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count);
#endif
    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
            ENCODER_CCW_CW(KC_VOLU, KC_VOLD), // Volume control (Mute on press)
            ENCODER_CCW_CW(MS_WHLU, MS_WHLD), // slow scrolling
    },
    [1] = {
            ENCODER_CCW_CW(KC_MPRV, KC_MNXT), // Next/Prev song
            ENCODER_CCW_CW(KC_PGUP, KC_PGDN), // fast scrolling
    }
};
#endif
