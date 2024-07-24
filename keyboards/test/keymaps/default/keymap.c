// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.h"
#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_4x4(
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,            KC_PDOT
    )
// #include QMK_KEYBOARD_H の後に以下を追加




//
// 省略（キーマップやマクロ、LEDの設定など）
//


//ここからポインティングデバイス

#ifdef MASTER_RIGHT

// Set Parameters
uint16_t minAxisValue = 190;  // Depends on each stick
uint16_t maxAxisValue = 840;

uint8_t maxCursorSpeed = 2;
uint8_t maxScrollSpeed = 1;
uint8_t speedRegulator = 5;  // Lower Values Create Faster Movement

int8_t xPolarity = -1;
int8_t yPolarity = 1;
int8_t hPolarity = 1;
int8_t vPolarity = 1;

uint8_t cursorTimeout = 10;
uint8_t scrollTimeout = 100;

int16_t xOrigin, yOrigin;

uint16_t lastCursor = 0;

int16_t axisCoordinate(uint8_t pin, uint16_t origin) {
   int8_t  direction;
   int16_t distanceFromOrigin;
   int16_t range;

   int16_t position = analogReadPin(pin);

   if (origin == position) {
       return 0;
   } else if (origin > position) {
       distanceFromOrigin = origin - position;
       range              = origin - minAxisValue;
       direction          = -1;
   } else {
       distanceFromOrigin = position - origin;
       range              = maxAxisValue - origin;
       direction          = 1;
   }

   float   percent    = (float)distanceFromOrigin  / range;
   int16_t coordinate = (int16_t)(percent * 127);
   if (coordinate < 0) {
       return 0;
   } else if (coordinate > 127) {
       return 127 * direction;
   } else {
       return coordinate * direction;
   }
}

int8_t axisToMouseComponent(uint8_t pin, int16_t origin, uint8_t maxSpeed, int8_t polarity) {
   int coordinate = axisCoordinate(pin, origin);
   if (coordinate == 0) {
       return 0;
   } else {
       float percent = (float)coordinate / 127;
       return percent * maxSpeed * polarity * (abs(coordinate) / speedRegulator);
   }
}

void pointing_device_task(void) {

   if (is_master == true){
   report_mouse_t report = pointing_device_get_report();

   if(layer_state_is(_RAISE)) {
       if (timer_elapsed(lastCursor) > scrollTimeout) {
           lastCursor = timer_read();
           report.h   = axisToMouseComponent(B4, xOrigin, maxCursorSpeed, hPolarity);
           report.v   = axisToMouseComponent(B5, yOrigin, maxCursorSpeed, vPolarity);
       }
   } else {
       if (timer_elapsed(lastCursor) > cursorTimeout) {
           lastCursor = timer_read();
           report.x   = axisToMouseComponent(B4, xOrigin, maxCursorSpeed, xPolarity);
           report.y   = axisToMouseComponent(B5, yOrigin, maxCursorSpeed, yPolarity);
       }
   }

   pointing_device_set_report(report);
   pointing_device_send();

   }
}

void matrix_init_user(void) {
   if (is_master == true){
   xOrigin = analogReadPin(B4);
   yOrigin = analogReadPin(B5);
   }
}
#endif

};
