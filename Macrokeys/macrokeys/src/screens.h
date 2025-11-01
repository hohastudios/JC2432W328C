#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *startup;
    lv_obj_t *main;
    lv_obj_t *btn_ok;
    lv_obj_t *lblok;
    lv_obj_t *config_selector;
    lv_obj_t *tab_view;
    lv_obj_t *tab1;
    lv_obj_t *btn12;
    lv_obj_t *lbl12;
    lv_obj_t *btn13;
    lv_obj_t *lbl13;
    lv_obj_t *btn23;
    lv_obj_t *lbl23;
    lv_obj_t *btn11;
    lv_obj_t *lbl11;
    lv_obj_t *btn22;
    lv_obj_t *lbl22;
    lv_obj_t *btn21;
    lv_obj_t *lbl21;
    lv_obj_t *custom2;
    lv_obj_t *btn23_1;
    lv_obj_t *lbl23_1;
    lv_obj_t *btn22_1;
    lv_obj_t *lbl22_1;
    lv_obj_t *btn21_1;
    lv_obj_t *lbl21_1;
    lv_obj_t *btn11_1;
    lv_obj_t *lbl11_1;
    lv_obj_t *btn13_1;
    lv_obj_t *lbl13_1;
    lv_obj_t *btn12_1;
    lv_obj_t *lbl12_1;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_STARTUP = 1,
    SCREEN_ID_MAIN = 2,
};

void create_screen_startup();
void tick_screen_startup();

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/