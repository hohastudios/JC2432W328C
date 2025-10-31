#include <lvgl.h>  
#include <Arduino.h>
#include "actions.h"
#include "vars.h"
#include "screens.h"
#include "ui.h"
#include <BleKeyboard.h>

void action_btn_engine_pressed(lv_event_t * e){
    Serial.println(F("✅ E Pressed!"));
    if(ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));    
        ble_Keyboard.print("e");
    }
}
void action_btn_ind_left_pressed(lv_event_t * e){
    Serial.println(F("✅ L Pressed!"));
    if(ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));    
        ble_Keyboard.print("l");
    }
}
void action_btn_ind_right_pressed(lv_event_t * e){
    Serial.println(F("✅ R Pressed!"));
    if(ble_Keyboard.isConnected()) {
        Serial.println(F("✅ Sending key stroke!"));    
        ble_Keyboard.print("r");
    }
}
