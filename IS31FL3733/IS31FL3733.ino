#include <Wire.h>
#include "IS31FL3733.h"

IS31FL3733 device;

void setup()
{
    Serial.begin(9600);

    while (!Serial)
    {
    }

    Wire.begin();

    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);

    Serial.println("STARTED");

    Serial.println(device.checkConnectivity());
    device.init();
    device.setCurrent();

    device.led_state(0x00, 0x01); //red
    device.led_state(0x02, 0x01); //green
    device.led_state(0x04, 0x01); //blue

    device.led_pwm(0x00, 255); //red
    // device.led_pwm(0x10, 255); //green
    // device.led_pwm(0x20, 255); //blue
}

uint32_t prevTime;

void loop()
{
    for (int i = 0; i < 255; i++)
    {
        device.led_pwm(0x00, 255 - i); //red
        device.led_pwm(0x10, i);       //green
        delay(10);
    }

    for (int i = 0; i < 255; i++)
    {
        device.led_pwm(0x10, 255 - i); //green
        device.led_pwm(0x20, i);       //blue
        delay(10);
    }

    for (int i = 0; i < 255; i++)
    {
        device.led_pwm(0x20, 255 - i); //blue
        device.led_pwm(0x00, i);       //red
        delay(10);
    }
}