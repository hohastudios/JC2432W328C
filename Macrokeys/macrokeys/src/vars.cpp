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
const char* selected_str;
static std::string g_current_selected;

BleKeyboard get_var_ble_keyboard() {
    return ble_Keyboard;
}

void set_var_ble_keyboard(BleKeyboard value) {
    ble_Keyboard = value;
}


void set_selected_str(const char *str)
{
    /* Guard against a nullptr – fall back to an empty string */
    if (str) {
        g_current_selected = str;           // std::string handles the copy
    } else {
        g_current_selected.clear();         // make it empty
    }
    // If you need to do something with the string immediately
    // (e.g., update UI, log, etc.) do it here
    ESP_LOGI(TAG, "Selected profile value now: %s", g_current_selected.c_str());

    // ... any other logic that uses g_current_selected ...
}

const char *get_selected_str(void)
{
    return g_current_selected.c_str();   // always valid
}