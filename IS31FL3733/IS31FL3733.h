#ifndef IS31FL3733_h
#define IS31FL3733_h

#include "Arduino.h"
#include "Wire.h"

#define IS31FL3733_WRITE_ADDR (0xA0 >> 1)
#define IS31FL3733_READ_ADDR (0xA0 >> 1)

class IS31FL3733
{
  public:
    IS31FL3733();
    void init();
    void setCurrent();
    bool checkConnectivity();

    void led_state(uint8_t addr, uint8_t data);
    void led_pwm(uint8_t addr, uint8_t data);

  private:
    uint8_t read_reg(uint8_t addr);
    void write_reg(uint8_t addr, uint8_t data);

    uint8_t set_page(uint8_t page);

    uint8_t read_paged_reg(uint8_t page, uint8_t addr);
    void write_paged_reg(uint8_t page, uint8_t addr, uint8_t data);
};

#endif