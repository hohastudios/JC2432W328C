#include <LovyanGFX.hpp>
#include "CST820.h"
#include <lvgl.h>
#include <WiFi.h>

// ======= App Info =======
static const char* App_Name = "Internet Clock";
static const char* App_Publisher = "Hill Valley Labs";

// ======= Display Setup =======
class LGFX_JustDisplay : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_SPI _bus;
public:
  LGFX_JustDisplay() {
    auto cfg = _bus.config();
    cfg.spi_host = VSPI_HOST;
    cfg.spi_mode = 0;
    cfg.freq_write = 27000000;
    cfg.freq_read  = 16000000;
    cfg.spi_3wire  = false;
    cfg.use_lock   = true;
    cfg.dma_channel= 1;
    cfg.pin_sclk   = 14;
    cfg.pin_mosi   = 13;
    cfg.pin_miso   = -1;
    cfg.pin_dc     = 2;
    _bus.config(cfg);
    _panel.setBus(&_bus);

    auto p_cfg = _panel.config();
    p_cfg.pin_cs          = 15;
    p_cfg.pin_rst         = -1;
    p_cfg.pin_busy        = -1;
    p_cfg.panel_width     = 240;
    p_cfg.panel_height    = 320;
    p_cfg.offset_rotation = 0;
    p_cfg.dummy_read_pixel= 8;
    p_cfg.dummy_read_bits = 1;
    _panel.config(p_cfg);
    setPanel(&_panel);
  }
};

LGFX_JustDisplay tft;
CST820 touch(33, 32, 25, 21);

#define LVGL_TICK_PERIOD 5
static unsigned long lastLvTick = 0;

// LVGL flush callback
enum { DISP_W = 320, DISP_H = 240 };
void lv_flush_cb(lv_display_t* disp, const lv_area_t* area, uint8_t* color_p) {
  tft.pushImage(area->x1, area->y1,
                area->x2 - area->x1 + 1,
                area->y2 - area->y1 + 1,
                (lgfx::rgb565_t*)color_p);
  lv_display_flush_ready(disp);
}

// Touch input callback
void touchpad_read_cb(lv_indev_t* indev, lv_indev_data_t* data) {
  uint16_t rawX, rawY;
  if (touch.getTouch(&rawX, &rawY)) {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = rawY;
    data->point.y = DISP_H - rawX;
    Serial.printf("🖐 Touch at (%d,%d) Raw:(%d,%d)\n", data->point.x, data->point.y, rawX, rawY);
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

// UI objects
lv_obj_t* ddlist;
lv_obj_t* ta_pass;
lv_obj_t* kb;

// Show welcome screen (10s)
void show_welcome_screen() {
  lv_obj_clean(lv_screen_active());
  auto scr = lv_screen_active();
  // Gradient background
  lv_obj_set_style_bg_color(scr, lv_color_hex(0x111111), LV_PART_MAIN);
  lv_obj_set_style_bg_grad_color(scr, lv_color_hex(0x444444), LV_PART_MAIN);
  lv_obj_set_style_bg_grad_dir(scr, LV_GRAD_DIR_VER, LV_PART_MAIN);

  auto lbl = lv_label_create(scr);
  lv_label_set_text(lbl, App_Name);
  lv_obj_set_style_text_color(lbl, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_text_font(lbl, &lv_font_montserrat_14, LV_PART_MAIN);
  lv_obj_center(lbl);

  auto pub = lv_label_create(scr);
  lv_label_set_text(pub, App_Publisher);
  lv_obj_set_style_text_color(pub, lv_color_hex(0xFF6600), LV_PART_MAIN);
  lv_obj_set_style_text_font(pub, &lv_font_montserrat_14, LV_PART_MAIN);
  lv_obj_align_to(pub, lbl, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

  unsigned long start = millis();
  while (millis() - start < 10000) {
    if (millis() - lastLvTick >= LVGL_TICK_PERIOD) {
      lv_tick_inc(LVGL_TICK_PERIOD);
      lv_timer_handler();
      lastLvTick = millis();
    }
    delay(1);
  }
}

// Show Wi-Fi selection
void show_wifi_selection() {
  // clear and set bg
  lv_obj_clean(lv_screen_active());
  lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0xDDDDDD), LV_PART_MAIN);

  // scan networks
  Serial.println("🔍 Scanning Wi-Fi...");
  int n = WiFi.scanNetworks();
  Serial.printf("🔍 Found %d networks\n", n);
  String opts;
  for (int i = 0; i < n; ++i) {
    opts += WiFi.SSID(i);
    if (i < n - 1) opts += '\n';
    Serial.printf("   %s\n", WiFi.SSID(i).c_str());
  }
  if (n == 0) opts = "<none>";

  // title bar
  auto title = lv_obj_create(lv_screen_active());
  lv_obj_set_size(title, DISP_W, 30);
  lv_obj_set_pos(title, 0, 0);
  lv_obj_set_style_bg_color(title, lv_color_hex(0x3366FF), LV_PART_MAIN);
  lv_obj_set_style_radius(title, 0, LV_PART_MAIN);
  lv_obj_set_style_border_width(title, 0, LV_PART_MAIN);

  auto tlabel = lv_label_create(title);
  lv_label_set_text(tlabel, "CONNECT TO WIFI");
  lv_obj_set_style_text_color(tlabel, lv_color_white(), LV_PART_MAIN);
  lv_obj_center(tlabel);

  // SSID dropdown
  ddlist = lv_dropdown_create(lv_screen_active());
  lv_obj_set_width(ddlist, 300);
  lv_obj_align(ddlist, LV_ALIGN_TOP_MID, 0, 35);
  lv_dropdown_set_options(ddlist, opts.c_str());

  // password
  ta_pass = lv_textarea_create(lv_screen_active());
  lv_textarea_set_password_mode(ta_pass, true);
  lv_textarea_set_one_line(ta_pass, true);
  lv_textarea_set_placeholder_text(ta_pass, "Enter Password");
  lv_obj_set_width(ta_pass, 300);
  lv_obj_align_to(ta_pass, ddlist, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

  // keyboard
  kb = lv_keyboard_create(lv_screen_active());
  lv_obj_set_height(kb, 120);
  lv_obj_align(kb, LV_ALIGN_BOTTOM_MID, 0, 0);
  lv_keyboard_set_textarea(kb, ta_pass);

  // done event
  lv_obj_add_event_cb(kb, [](lv_event_t* e) {
    if (lv_event_get_code(e) == LV_EVENT_READY) {
      char buf[64];
      lv_dropdown_get_selected_str(ddlist, buf, sizeof(buf));
      const char* pwd = lv_textarea_get_text(ta_pass);
      Serial.printf("SSID:%s PWD:%s\n", buf, pwd);
    }
  }, LV_EVENT_ALL, NULL);
}

void setup() {
  Serial.begin(115200);
  delay(1500);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  tft.init();
  tft.setRotation(1);
  touch.begin();

  lv_init();
  static lv_color_t buf[240 * 10];
  auto disp = lv_display_create(DISP_W, DISP_H);
  lv_display_set_flush_cb(disp, lv_flush_cb);
  lv_display_set_buffers(disp, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
  auto indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);

  show_welcome_screen();
  show_wifi_selection();
}

void loop() {
  if (millis() - lastLvTick >= LVGL_TICK_PERIOD) {
    lv_tick_inc(LVGL_TICK_PERIOD);
    lv_timer_handler();
    lastLvTick = millis();
  }
  delay(5);
}
