#include <LovyanGFX.hpp>     // Display library
#include "src/CST820.h"          // Capacitive touch driver
#include <BleKeyboard.h>
#include "src/ui.h"
#include "src/configreader.h"
#include <lvgl.h> 
#include "src/vars.h"

extern BleKeyboard ble_Keyboard;
extern String profiles;

// ======= Display Setup for ST7789 on ESP32 =======
class LGFX_JustDisplay : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 _panel;
  lgfx::Bus_SPI _bus;

public:
  LGFX_JustDisplay(void) {
    { // SPI config
      auto cfg = _bus.config();
      cfg.spi_host   = HSPI_HOST;
      cfg.spi_mode   = 0;
      cfg.freq_write = 27000000;
      cfg.freq_read  = 16000000;
      cfg.spi_3wire  = false;
      cfg.use_lock   = true;
      cfg.dma_channel = 1;
      cfg.pin_sclk   = 14;
      cfg.pin_mosi   = 13;
      cfg.pin_miso   = 12;
      cfg.pin_dc     = 2;
      _bus.config(cfg);
      _panel.setBus(&_bus);
    }

    { // Panel config
      auto cfg = _panel.config();
      cfg.pin_cs           = 15;
      cfg.pin_rst          = -1;
      cfg.pin_busy         = -1;
      cfg.panel_width      = 240;
      cfg.panel_height     = 320;
      cfg.offset_rotation  = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits  = 1;
      cfg.readable         = false;
      cfg.invert           = false;
      cfg.rgb_order        = 0;
      cfg.dlen_16bit       = false;
      cfg.bus_shared       = true;
      _panel.config(cfg);
    }

    setPanel(&_panel);
  }
};

LGFX_JustDisplay tft;
CST820 touch(33, 32, 25, 21);  // SDA, SCL, RST, INT

#define LVGL_TICK_PERIOD 5
unsigned long lastLvTick = 0;

// LVGL flush callback
void lv_flush_cb(lv_display_t* disp, const lv_area_t* area, uint8_t* color_p) {
  tft.pushImage(area->x1, area->y1,
                area->x2 - area->x1 + 1,
                area->y2 - area->y1 + 1,
                (lgfx::rgb565_t*)color_p);
  lv_display_flush_ready(disp);
}

// Touch input for LVGL
void touchpad_read_cb(lv_indev_t* indev, lv_indev_data_t* data) {
  uint16_t rawX, rawY;
  if (touch.getTouch(&rawX, &rawY)) {
    data->state = LV_INDEV_STATE_PRESSED;
    data->point.x = rawY;
    data->point.y = 240 - rawX;

    Serial.printf("🖐 LVGL Touch at (%d, %d) | Raw: (%d, %d)\n",
                  data->point.x, data->point.y, rawX, rawY);
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.println(F("🧪 LVGL v9 + CST820 + ST7789"));
  Serial.println(F("MacroKeys Launching..."));
  profiles=read_sd_directory();
  Serial.println(profiles);
  // Backlight
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  // Display init
  tft.init();
  tft.setRotation(1);  // Use native portrait orientation
  // ble keybbd init
  ble_Keyboard.begin();
  // Touch init
  touch.begin();
  Serial.printf("🔍 Touch Chip ID: 0x%02X\n", touch.readChipID());


   // LVGL init
  lv_init();

  // Display driver
  static lv_color_t buf1[240 * 10];
  static lv_display_t* disp = lv_display_create(320, 240);
  lv_display_set_flush_cb(disp, lv_flush_cb);
  lv_display_set_buffers(disp, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

  // Input device (touch)
  lv_indev_t* indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);
  ui_init();



}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastLvTick > LVGL_TICK_PERIOD) {
    lv_tick_inc(LVGL_TICK_PERIOD);
    lastLvTick = millis();
  }

  lv_timer_handler();
  delay(5);
  ui_tick();

}
