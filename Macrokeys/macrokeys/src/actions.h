#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_btn_11_pressed(lv_event_t * e);
extern void action_btn_12_pressed(lv_event_t * e);
extern void action_btn_13_pressed(lv_event_t * e);
extern void action_btn_profile_v_ok_pressed(lv_event_t * e);
extern void action_goto_main_v(lv_event_t * e);
extern void action_btn_11_1_pressed(lv_event_t * e);
extern void action_btn_12_1_pressed(lv_event_t * e);
extern void action_btn_13_1_pressed(lv_event_t * e);
extern void action_btn_21_pressed(lv_event_t * e);
extern void action_btn_22_pressed(lv_event_t * e);
extern void action_btn_23_pressed(lv_event_t * e);
extern void action_btn_21_1_pressed(lv_event_t * e);
extern void action_btn_22_1_pressed(lv_event_t * e);
extern void action_btn_23_1_pressed(lv_event_t * e);
extern void action_goto_profile_v(lv_event_t * e);
extern void action_profile_value_changed(lv_event_t *e); 

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/