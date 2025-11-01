#include "vars.h"
#include <BleKeyboard.h>

BleKeyboard ble_Keyboard;
String profiles;

BleKeyboard get_var_ble_keyboard() {
    return ble_Keyboard;
}

void set_var_ble_keyboard(BleKeyboard value) {
    ble_Keyboard = value;
}