#include <LovyanGFX.hpp> //Search for LovyanGFX by lovyan03 

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
      p_cfg.invert           = false;  // try disabling inversion
      p_cfg.rgb_order        = 0;      // RGB instead of BGR
      p_cfg.dlen_16bit       = false;
      p_cfg.bus_shared       = true;
      _panel.config(p_cfg);
      setPanel(&_panel);
    }
  }
};

LGFX_JustDisplay tft;

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Display-only test starting...");

  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);  // Backlight
  Serial.println("Backlight ON");

  tft.init();
  Serial.println("tft.init() done");

  tft.setRotation(1);
  tft.fillScreen(tft.color565(0, 0, 0));  // Black
  tft.setTextColor(tft.color565(255, 255, 0));
  tft.setTextSize(2);
  tft.setCursor(20, 100);
  tft.println("Display OK");
  Serial.println("Finished drawing.");
}

void loop() {
  int x = random(tft.width());
  int y = random(tft.height());
  int r = random(10, 40);
  uint16_t color = tft.color565(random(256), random(256), random(256));

  tft.fillCircle(x, y, r, color);

  delay(1000);  // wait 1 second
}