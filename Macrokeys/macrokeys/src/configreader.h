#ifndef CONFIGREADER_H          // ← NEW, unique guard
#define CONFIGREADER_H
#include <FS.h>

#ifdef __cplusplus
extern "C" {
#endif

void parse_json(const char* input);

#ifdef __cplusplus
}
#endif

void read_config_file(String path); 
String read_sd_directory();
#endif /* CONFIGREADER_H */