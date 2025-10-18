#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>
#include <BleKeyboard.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *subpage;
    lv_obj_t *btn_ind_left;
    lv_obj_t *btn_ind_right;
    lv_obj_t *btn_engine;
    lv_obj_t *tab_view;
    lv_obj_t *tab1;
    lv_obj_t *advanced;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SUBPAGE = 2,
};

void create_screen_main();
void tick_screen_main();

void create_screen_subpage();
void tick_screen_subpage();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens(BleKeyboard blekdb);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/