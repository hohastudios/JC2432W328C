#ifndef CST820_H
#define CST820_H

#include <Wire.h>

class CST820 {
public:
  CST820(uint8_t sda, uint8_t scl, uint8_t rst, uint8_t irq)
    : _sda(sda), _scl(scl), _rst(rst), _irq(irq) {}

  void begin() {
    pinMode(_rst, OUTPUT);
    digitalWrite(_rst, LOW);
    delay(10);
    digitalWrite(_rst, HIGH);
    delay(100);
    Wire.begin(_sda, _scl);
  }

  bool getTouch(uint16_t* x, uint16_t* y, uint8_t* gesture = nullptr) {
  Wire.beginTransmission(0x15);      // I2C address of CST820
  Wire.write(0x00);                  // Start reading from register 0
  if (Wire.endTransmission(false) != 0 || Wire.requestFrom(0x15, 7) != 7) {
    return false;
  }

  uint8_t buf[7];
  for (int i = 0; i < 7; i++) buf[i] = Wire.read();

  uint8_t touches = buf[2] & 0x0F;
  if (touches == 0) return false;

  if (gesture) *gesture = buf[1];

  *x = ((buf[3] & 0x0F) << 8) | buf[4];  // Proper MSB/LSB for X
  *y = ((buf[5] & 0x0F) << 8) | buf[6];  // Proper MSB/LSB for Y

  return true;
}

private:
  uint8_t _sda, _scl, _rst, _irq;
};

#endif