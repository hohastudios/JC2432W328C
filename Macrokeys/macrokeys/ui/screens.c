#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"
#include <Arduino.h>
#include <string.h>
#include <BleKeyboard.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
BleKeyboard bleKeyboard;

static void event_handler_cb_main_btn_ind_left(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_btn_ind_left_pressed(e);
        Serial.println(F("✅ L Pressed!"));
        if(bleKeyboard.isConnected()) {
            Serial.println(F("✅ Sending key stroke!"));    
            bleKeyboard.print("l");
        }
    }
}

static void event_handler_cb_main_btn_ind_right(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_btn_ind_right_pressed(e);
        Serial.println(F("✅ R Pressed!"));
        if(bleKeyboard.isConnected()) {
            Serial.println(F("✅ Sending key stroke!"));    
            bleKeyboard.print("r");
        }
    }
}

static void event_handler_cb_main_btn_engine(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        action_btn_engine_pressed(e);
        Serial.println(F("✅ E Pressed!"));
        if(bleKeyboard.isConnected()) {
            Serial.println(F("✅ Sending key stroke!"));    
            bleKeyboard.print("e");
        }
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 320, 240);
        }
        {
            lv_obj_t *obj = lv_menu_create(parent_obj);
            lv_obj_set_pos(obj, 4, 3);
            lv_obj_set_size(obj, 33, 25);
        }
        {
            // TabView
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tab_view = obj;
            lv_obj_set_pos(obj, 7, 29);
            lv_obj_set_size(obj, 305, 206);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 32);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Tab1
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Basic");
                    objects.tab1 = obj;
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btnIndLeft
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn_ind_left = obj;
                            lv_obj_set_pos(obj, 103, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_ind_left, LV_EVENT_ALL, flowState);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "<<");
                                }
                            }
                        }
                        {
                            // btnIndRight
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn_ind_right = obj;
                            lv_obj_set_pos(obj, 206, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_ind_right, LV_EVENT_ALL, flowState);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, ">>");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            lv_obj_set_pos(obj, 206, 80);
                            lv_obj_set_size(obj, 76, 66);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Button");
                                }
                            }
                        }
                        {
                            // btnEngine
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn_engine = obj;
                            lv_obj_set_pos(obj, 1, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_engine, LV_EVENT_ALL, flowState);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Engine");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            lv_obj_set_pos(obj, 103, 80);
                            lv_obj_set_size(obj, 76, 66);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Button");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            lv_obj_set_pos(obj, 1, 80);
                            lv_obj_set_size(obj, 76, 66);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Button");
                                }
                            }
                        }
                    }
                }
                {
                    // Advanced
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Advanced");
                    objects.advanced = obj;
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_subpage() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.subpage = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    
    tick_screen_subpage();
}

void tick_screen_subpage() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}


static const char *screen_names[] = { "Main", "subpage" };
static const char *object_names[] = { "main", "subpage", "btn_ind_left", "btn_ind_right", "btn_engine", "tab_view", "tab1", "advanced" };


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_subpage,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens(BleKeyboard blekdb) {
    bleKeyboard = blekdb;
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_subpage();
}
