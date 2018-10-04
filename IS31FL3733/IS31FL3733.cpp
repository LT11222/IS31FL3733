#include "IS31FL3733.h"

IS31FL3733::IS31FL3733()
{
}

uint8_t IS31FL3733::read_reg(uint8_t addr)
{
    uint8_t readVal;

    Wire.beginTransmission(IS31FL3733_WRITE_ADDR);
    Wire.write(byte(addr));
    Wire.endTransmission();

    Wire.requestFrom(IS31FL3733_READ_ADDR, 1);

    if (1 <= Wire.available())
    {
        readVal = Wire.read();
    }

    return readVal;
}

void IS31FL3733::write_reg(uint8_t addr, uint8_t data)
{
    Wire.beginTransmission(IS31FL3733_WRITE_ADDR);
    Wire.write(byte(addr));
    Wire.write(byte(data));
    Wire.endTransmission();
}

uint8_t IS31FL3733::set_page(uint8_t page)
{
    write_reg(0xFE, 0xC5);
    write_reg(0xFD, page);
}

uint8_t IS31FL3733::read_paged_reg(uint8_t page, uint8_t addr)
{
    set_page(page);
    return read_reg(addr);
}

void IS31FL3733::write_paged_reg(uint8_t page, uint8_t addr, uint8_t data)
{
    set_page(page);
    write_reg(addr, data);
}

void IS31FL3733::init()
{
    set_page(0x03);
    read_reg(0x11);
    write_reg(0x00, 0x01);
}

void IS31FL3733::setCurrent()
{
    write_paged_reg(0x03, 0x01, 127);
}

bool IS31FL3733::checkConnectivity()
{
    write_reg(0xFE, 0xC5);
    if (read_reg(0xFE) == 0xC5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IS31FL3733::led_state(uint8_t addr, uint8_t data)
{
    write_paged_reg(0x00, addr, data);
}

void IS31FL3733::led_pwm(uint8_t addr, uint8_t data)
{
    write_paged_reg(0x01, addr, data);
}