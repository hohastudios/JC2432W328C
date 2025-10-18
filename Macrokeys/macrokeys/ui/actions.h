#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>  

#ifdef __cplusplus
extern "C" {
#endif

extern void action_btn_engine_pressed(lv_event_t * e);
extern void action_btn_ind_left_pressed(lv_event_t * e);
extern void action_btn_ind_right_pressed(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/