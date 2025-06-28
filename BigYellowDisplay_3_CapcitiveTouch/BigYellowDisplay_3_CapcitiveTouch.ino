#include <LovyanGFX.hpp>   // Display library: https://github.com/lovyan03/LovyanGFX
#include "CST820.h"        // Custom I2C driver for CST820 capacitive touchscreen

// ====== Custom Display Class for ST7789 TFT ======
class LGFX_JustDisplay : public lgfx::LGFX_Device {
  lgfx::Panel_ST7789 _panel;   // ST7789 panel instance
  lgfx::Bus_SPI _bus;          // SPI bus instance

public:
  LGFX_JustDisplay(void) {
    { // SPI bus configuration
      auto cfg = _bus.config();
      cfg.spi_host   = VSPI_HOST;     // Use VSPI (default high-speed SPI)
      cfg.spi_mode   = 0;             // SPI mode 0
      cfg.freq_write = 27000000;      // Write speed: 27 MHz
      cfg.freq_read  = 16000000;      // Read speed (not used here)
      cfg.spi_3wire  = false;
      cfg.use_lock   = true;
      cfg.dma_channel = 1;            // Use DMA channel 1
      cfg.pin_sclk   = 14;            // Clock pin
      cfg.pin_mosi   = 13;            // Data out (MOSI)
      cfg.pin_miso   = -1;            // No data in
      cfg.pin_dc     = 2;             // Data/command pin
      _bus.config(cfg);
      _panel.setBus(&_bus);
    }

    { // Display panel configuration
      auto cfg = _panel.config();
      cfg.pin_cs           = 15;      // Chip select
      cfg.pin_rst          = -1;      // No reset pin
      cfg.pin_busy         = -1;      // Not used
      cfg.panel_width      = 240;     // Native width
      cfg.panel_height     = 320;     // Native height
      cfg.offset_rotation  = 0;       // No offset
      cfg.dummy_read_pixel = 8;       // For compatibility
      cfg.dummy_read_bits  = 1;
      cfg.readable         = false;
      cfg.invert           = false;   // No inversion
      cfg.rgb_order        = 0;       // RGB (not BGR)
      cfg.dlen_16bit       = false;
      cfg.bus_shared       = true;
      _panel.config(cfg);
    }

    setPanel(&_panel);
  }
};

// Create display and touch controller instances
LGFX_JustDisplay tft;
CST820 touch(33, 32, 25, 21);  // Touch: SDA, SCL, RST, INT

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("🧪 Touch + Display test starting...");

  // Enable backlight (GPIO 27 must be HIGH)
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  // Initialize display
  tft.init();
  tft.setRotation(1);  // Landscape orientation
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(30, 100);
  tft.println("Touch to draw");

  // Initialize touchscreen
  touch.begin();

  Serial.println("✅ Setup complete");
}

void loop() {
  uint16_t rawX, rawY;

  // If a touch is detected, get coordinates
  if (touch.getTouch(&rawX, &rawY)) {
    // Map raw touchscreen coordinates to screen orientation
    uint16_t x = rawY;          // Y becomes X (landscape)
    uint16_t y = 240 - rawX;    // Flip vertical axis

    // Debug output - I was unable to get Gestures Working so Just X, Y Touches for now.
    Serial.printf("👉 Touch at x=%d, y=%d (raw: %d,%d)\n", x, y, rawX, rawY);

    // Draw a small circle where the user touched
    tft.fillCircle(x, y, 4, TFT_CYAN);
  }

  delay(10);  // Small delay to prevent I2C flooding
}