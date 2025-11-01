#include <string.h>
#include <string>

extern "C" {
#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"
}

#include "vars.h"

#ifndef _
/* When LVGL i18n support is not enabled, fall back to a no‑op macro.
 * This keeps the source compatible with the original code that uses the _() syntax.
 */
#define _(text) (text)
#endif

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_startup() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.startup = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // btn_ok
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_ok = obj;
            lv_obj_set_pos(obj, 106, 193);
            lv_obj_set_size(obj, 109, 32);
            lv_obj_add_event_cb(obj, action_goto_main_v, LV_EVENT_PRESSED, (void *)0);
            add_style_green(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // lblok
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.lblok = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // config_selector
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.config_selector = obj;
            lv_obj_set_pos(obj, 0, 26);
            lv_obj_set_size(obj, 320, 153);
            lv_roller_set_options(obj, profiles.c_str(), LV_ROLLER_MODE_INFINITE);
            lv_obj_add_event_cb(obj, action_profile_value_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
            {
                char buffer[64]; 
                /* Retrieve the currently selected string  */
                lv_roller_get_selected_str(obj, buffer, sizeof(buffer));
                set_selected_str(buffer);   
            }
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff39b47a), LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 17, 4);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Select Profile");
        }
    }
    
    tick_screen_startup();
}

void tick_screen_startup() {
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // TabView
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.tab_view = obj;
            lv_obj_set_pos(obj, 0, 29);
            lv_obj_set_size(obj, 320, 211);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 32);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Tab1
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Custom1");
                    objects.tab1 = obj;
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btn12
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn12 = obj;
                            lv_obj_set_pos(obj, 103, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_12_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff77bc86), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl12
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl12 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_12());
                                }
                            }
                        }
                        {
                            // btn13
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn13 = obj;
                            lv_obj_set_pos(obj, 206, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_13_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5e740), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl13
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl13 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_13());
                                }
                            }
                        }
                        {
                            // btn23
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn23 = obj;
                            lv_obj_set_pos(obj, 206, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_23_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd43ee7), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl23
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl23 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_23());
                                }
                            }
                        }
                        {
                            // btn11
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn11 = obj;
                            lv_obj_set_pos(obj, 1, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_11_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffda1e37), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 1255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl11
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl11 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_11());
                                }
                            }
                        }
                        {
                            // btn22
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn22 = obj;
                            lv_obj_set_pos(obj, 103, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_22_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffa700), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl22
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl22 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_22());
                                }
                            }
                        }
                        {
                            // btn21
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn21 = obj;
                            lv_obj_set_pos(obj, 1, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_21_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl21
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl21 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_21());
                                }
                            }
                        }
                    }
                }
                {
                    // Custom2
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Custom2");
                    objects.custom2 = obj;
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // btn23_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn23_1 = obj;
                            lv_obj_set_pos(obj, 206, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_23_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffd43ee7), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl23_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl23_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_23_1()); 
                                }
                            }
                        }
                        {
                            // btn22_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn22_1 = obj;
                            lv_obj_set_pos(obj, 103, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_22_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffa700), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl22_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl22_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_22_1()); 
                                }
                            }
                        }
                        {
                            // btn21_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn21_1 = obj;
                            lv_obj_set_pos(obj, 1, 80);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_21_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl21_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl21_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_21_1()); 
                                }
                            }
                        }
                        {
                            // btn11_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn11_1 = obj;
                            lv_obj_set_pos(obj, 1, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_11_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffda1e37), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 1255, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl11_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl11_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_11_1());
                                }
                            }
                        }
                        {
                            // btn13_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn13_1 = obj;
                            lv_obj_set_pos(obj, 206, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_13_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5e740), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl13_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl13_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_13_1());
                                }
                            }
                        }
                        {
                            // btn12_1
                            lv_obj_t *obj = lv_button_create(parent_obj);
                            objects.btn12_1 = obj;
                            lv_obj_set_pos(obj, 103, 3);
                            lv_obj_set_size(obj, 76, 66);
                            lv_obj_add_event_cb(obj, action_btn_12_1_pressed, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff77bc86), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // lbl12_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.lbl12_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, get_lbl_btn_12_1());
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            lv_obj_set_pos(obj, 7, 3);
            lv_obj_set_size(obj, 65, 24);
            lv_obj_add_event_cb(obj, action_goto_profile_v, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "<");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_startup,
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_startup();
    create_screen_main();
}
