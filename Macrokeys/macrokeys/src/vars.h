#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>
#include <BleKeyboard.h>

// Native global variables
extern BleKeyboard ble_Keyboard;
extern String profiles;

// Button label globals
extern const char* lbl_btn_11;
extern const char* lbl_btn_12;
extern const char* lbl_btn_13;
extern const char* lbl_btn_11_1;
extern const char* lbl_btn_12_1;
extern const char* lbl_btn_13_1;
extern const char* lbl_btn_21;
extern const char* lbl_btn_22;
extern const char* lbl_btn_23;
extern const char* lbl_btn_21_1;
extern const char* lbl_btn_22_1;
extern const char* lbl_btn_23_1;


/* --------------------------------------------------------------------
 *  Inline accessors (getters / setters)
 *  ---------------------------------------------------------------*/
// ------------------------------------------------------------------
//  Button 11
// ------------------------------------------------------------------
inline const char* get_lbl_btn_11() noexcept  { return lbl_btn_11; }
inline void        set_lbl_btn_11(const char* v) noexcept { lbl_btn_11 = v; }

// ------------------------------------------------------------------
//  Button 12
// ------------------------------------------------------------------
inline const char* get_lbl_btn_12() noexcept  { return lbl_btn_12; }
inline void        set_lbl_btn_12(const char* v) noexcept { lbl_btn_12 = v; }

// ------------------------------------------------------------------
//  Button 13
// ------------------------------------------------------------------
inline const char* get_lbl_btn_13() noexcept  { return lbl_btn_13; }
inline void        set_lbl_btn_13(const char* v) noexcept { lbl_btn_13 = v; }

// ------------------------------------------------------------------
//  Button 11_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_11_1() noexcept  { return lbl_btn_11_1; }
inline void        set_lbl_btn_11_1(const char* v) noexcept { lbl_btn_11_1 = v; }

// ------------------------------------------------------------------
//  Button 12_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_12_1() noexcept  { return lbl_btn_12_1; }
inline void        set_lbl_btn_12_1(const char* v) noexcept { lbl_btn_12_1 = v; }

// ------------------------------------------------------------------
//  Button 13_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_13_1() noexcept  { return lbl_btn_13_1; }
inline void        set_lbl_btn_13_1(const char* v) noexcept { lbl_btn_13_1 = v; }

// ------------------------------------------------------------------
//  Button 21
// ------------------------------------------------------------------
inline const char* get_lbl_btn_21() noexcept  { return lbl_btn_21; }
inline void        set_lbl_btn_21(const char* v) noexcept { lbl_btn_21 = v; }

// ------------------------------------------------------------------
//  Button 22
// ------------------------------------------------------------------
inline const char* get_lbl_btn_22() noexcept  { return lbl_btn_22; }
inline void        set_lbl_btn_22(const char* v) noexcept { lbl_btn_22 = v; }

// ------------------------------------------------------------------
//  Button 23
// ------------------------------------------------------------------
inline const char* get_lbl_btn_23() noexcept  { return lbl_btn_23; }
inline void        set_lbl_btn_23(const char* v) noexcept { lbl_btn_23 = v; }

// ------------------------------------------------------------------
//  Button 21_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_21_1() noexcept  { return lbl_btn_21_1; }
inline void        set_lbl_btn_21_1(const char* v) noexcept { lbl_btn_21_1 = v; }

// ------------------------------------------------------------------
//  Button 22_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_22_1() noexcept  { return lbl_btn_22_1; }
inline void        set_lbl_btn_22_1(const char* v) noexcept { lbl_btn_22_1 = v; }

// ------------------------------------------------------------------
//  Button 23_1
// ------------------------------------------------------------------
inline const char* get_lbl_btn_23_1() noexcept  { return lbl_btn_23_1; }
inline void        set_lbl_btn_23_1(const char* v) noexcept { lbl_btn_23_1 = v; }

void   set_selected_str(const char *str);
const char *get_selected_str(void);   // returns a `const char*`


extern BleKeyboard get_var_ble_keyboard();
extern void set_var_ble_keyboard(BleKeyboard value);

#endif /*EEZ_LVGL_UI_VARS_H*/