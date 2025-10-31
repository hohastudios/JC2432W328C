#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>
#include <BleKeyboard.h>

// enum declarations

// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_BLE_KEYBOARD = 0
};

// Native global variables
extern BleKeyboard ble_Keyboard;
extern BleKeyboard get_var_ble_keyboard();
extern void set_var_ble_keyboard(BleKeyboard value);

#endif /*EEZ_LVGL_UI_VARS_H*/