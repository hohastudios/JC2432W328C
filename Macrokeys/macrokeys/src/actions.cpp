/* -------------------------------------------------------------------------- */
/*  Button press handlers – log the press and send a ‘r’ keystroke if a BLE   */
/*  keyboard is connected.                                                     */
/* -------------------------------------------------------------------------- */
#include <lvgl.h>  
#include <Arduino.h>
#include "actions.h"
#include "vars.h"
#include "screens.h"
#include "ui.h"
#include "configreader.h"
#include <BleKeyboard.h>

#ifdef __cplusplus
extern "C" {
#endif

void action_btn_11_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_11 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_12_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_12 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_13_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_13 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_profile_v_ok_pressed(lv_event_t * e)
{
    Serial.println(F("✅ OK Pressed!"));
}

void action_btn_11_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_11_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_12_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_12_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_13_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_13_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_21_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_21 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_22_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_22 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_23_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_23 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_21_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_21_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

void action_btn_22_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_22_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
     }
}

void action_btn_23_1_pressed(lv_event_t * e)
{
    Serial.println(String("✅ ") + lbl_btn_23_1 + " Pressed!");
    if (ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));
        ble_Keyboard.print("r");
    }
}

/* -------------------------------------------------------------------------- */
/*  Navigation handlers – currently no specific logic defined.             */
/* -------------------------------------------------------------------------- */

void action_goto_main_v(lv_event_t * e)
{
    
    loadScreen(SCREEN_ID_MAIN);   
}

void action_goto_profile_v(lv_event_t * e)
{
    loadScreen(SCREEN_ID_STARTUP);
}

#ifdef __cplusplus
}
#endif
