#include "vars.h"
#include <BleKeyboard.h>

BleKeyboard ble_Keyboard;
String profiles;

const char* lbl_btn_11="B11";
const char* lbl_btn_12="B12";
const char* lbl_btn_13="B13";
const char* lbl_btn_11_1="B11";
const char* lbl_btn_12_1="B12";
const char* lbl_btn_13_1="B13";
const char* lbl_btn_21="B21";
const char* lbl_btn_22="B22";
const char* lbl_btn_23="B23";
const char* lbl_btn_21_1="B21";
const char* lbl_btn_22_1="B22";
const char* lbl_btn_23_1="B23";

BleKeyboard get_var_ble_keyboard() {
    return ble_Keyboard;
}

void set_var_ble_keyboard(BleKeyboard value) {
    ble_Keyboard = value;
}