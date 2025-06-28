#include <LovyanGFX.hpp>   // https://github.com/lovyan03/LovyanGFX
#include "CST820.h"        // Make sure this header is in your project

// ====== Display Setup (ST7789 confirmed working) ======
class LGFX_JustDisplay : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789     _panel;
  lgfx::Bus_SPI          _bus;

public:
  LGFX_JustDisplay(void) {
    { // SPI config
      auto cfg = _bus.config();
      cfg.spi_host   = VSPI_HOST;
      cfg.spi_mode   = 0;
      cfg.freq_write = 27000000;
      cfg.freq_read  = 16000000;
      cfg.spi_3wire  = false;
      cfg.use_lock   = true;
      cfg.dma_channel = 1;
      cfg.pin_sclk   = 14;
      cfg.pin_mosi   = 13;
      cfg.pin_miso   = -1;
      cfg.pin_dc     = 2;
      _bus.config(cfg);
      _panel.setBus(&_bus);

      auto p_cfg = _panel.config();
      p_cfg.pin_cs           = 15;
      p_cfg.pin_rst          = -1;
      p_cfg.pin_busy         = -1;
      p_cfg.panel_width      = 240;
      p_cfg.panel_height     = 320;
      p_cfg.offset_rotation  = 0;
      p_cfg.dummy_read_pixel = 8;
      p_cfg.dummy_read_bits  = 1;
      p_cfg.readable         = false;
      p_cfg.invert           = false;
      p_cfg.rgb_order        = 0;
      p_cfg.dlen_16bit       = false;
      p_cfg.bus_shared       = true;
      _panel.config(p_cfg);
      setPanel(&_panel);
    }
  }
};

LGFX_JustDisplay tft;
CST820 touch(33, 32, 25, 21);  // SDA, SCL, RST, INT

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Touch + Display test starting...");

  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);  // Backlight ON

  tft.init();
  tft.setRotation(1);  // FIXED orientation
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(30, 100);
  tft.println("Touch to draw");

  touch.begin();
  Serial.println("Setup complete.");
}

void loop() {
  uint16_t rawX, rawY;
  uint8_t gesture;

  if (touch.getTouch(&rawX, &rawY, &gesture)) {
    // SWAP the axes
    uint16_t x = rawY;
    uint16_t y = 240 - rawX;

    Serial.printf("👉 Touch at x=%d, y=%d (raw: %d,%d), gesture=%d\n", x, y, rawX, rawY, gesture);
    tft.fillCircle(x, y, 4, TFT_CYAN);
  }

  delay(10);
}