// Copyright 2024 Sierra (@Cheena-gb)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ANALOG_JOYSTICK_X_AXIS_PIN ADC0
#define ANALOG_JOYSTICK_Y_AXIS_PIN ADC1
#define ANALOG_JOYSTICK_AUTO_AXIS
#define POINTING_DEVICE_DEBUG
