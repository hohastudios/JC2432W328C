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

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_btn_ind_left(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    
    if (event == LV_EVENT_PRESSED) {
        
        action_btn_ind_left_pressed(e);
    }
}

static void event_handler_cb_main_btn_ind_right(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);

    if (event == LV_EVENT_PRESSED) {
        
        action_btn_ind_right_pressed(e);
    }
}

static void event_handler_cb_main_btn_engine(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    
    if (event == LV_EVENT_PRESSED) {
        
        action_btn_engine_pressed(e);
    }
}


void create_screen_main() {

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
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_ind_left, LV_EVENT_ALL, (void *)0);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_ind_right, LV_EVENT_ALL, (void *)0);
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
                            lv_obj_add_event_cb(obj, event_handler_cb_main_btn_engine, LV_EVENT_ALL, (void *)0);
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
}

void create_screen_subpage() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.subpage = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    
    tick_screen_subpage();
}

void tick_screen_subpage() {
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

void create_screens() {

    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_subpage();
}
