#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>
#include <BleKeyboard.h>

// Native global variables
extern BleKeyboard ble_Keyboard;
extern String profiles;

extern BleKeyboard get_var_ble_keyboard();
extern void set_var_ble_keyboard(BleKeyboard value);

#endif /*EEZ_LVGL_UI_VARS_H*/