#ifndef EEZ_LVGL_UI_GUI_H
#define EEZ_LVGL_UI_GUI_H

#include <lvgl/lvgl.h>
#include <BleKeyboard.h>
#include "eez-flow.h"



#if !defined(EEZ_FOR_LVGL)
#include "screens.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern const uint8_t assets[1452];

void ui_init(BleKeyboard bleKeyboard);
void ui_tick();

#if !defined(EEZ_FOR_LVGL)
void loadScreen(enum ScreensEnum screenId);
#endif

#ifdef __cplusplus
}
#endif

#endif // EEZ_LVGL_UI_GUI_H