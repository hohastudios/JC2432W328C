#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H
#include <FS.h>

#ifdef __cplusplus
extern "C" {
#endif

void read_config_file(fs::FS &fs, const char * path); 
void parse_json(char* input);
String read_sd_directory();



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/