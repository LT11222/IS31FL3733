#include <Wire.h>
#include "IS31FL3733.h"

IS31FL3733 device;

void setup()
{
    // Serial.begin(9600);

    // while (!Serial)
    // {
    // }

    Wire.begin();

    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH);

    // Serial.println("STARTED");

    // Serial.println(device.checkConnectivity());
    device.init();
    device.setCurrent();

    device.led_state(0x00, 0x03); //red
    device.led_state(0x02, 0x03); //green
    device.led_state(0x04, 0x03); //blue

    device.led_state(0x06, 0x03); //red
    device.led_state(0x08, 0x03); //green
    device.led_state(0x0A, 0x03); //blue

    device.led_pwm(0x00, 255); //red
    device.led_pwm(0x30, 255); //red
    device.led_pwm(0x01, 255); //red
    device.led_pwm(0x31, 255); //red

    device.led_pwm(0x10, 255); //green
    device.led_pwm(0x40, 255); //green
    device.led_pwm(0x11, 255); //green
    device.led_pwm(0x41, 255); //green

    device.led_pwm(0x20, 255); //blue
    device.led_pwm(0x50, 255); //blue
    device.led_pwm(0x21, 255); //blue
    device.led_pwm(0x51, 255); //blue

    delay(1000);
}

uint32_t prevTime;

void loop()
{
    // for (int i = 0; i < 256; i++)
    // {
    //     device.led_pwm(0x00, 255 - i); //red
    //     device.led_pwm(0x10, i);       //green
    //     device.led_pwm(0x30, 255 - i); //red
    //     device.led_pwm(0x40, i);       //green
    //     device.led_pwm(0x01, 255 - i); //red
    //     device.led_pwm(0x11, i);       //green
    //     device.led_pwm(0x31, 255 - i); //red
    //     device.led_pwm(0x41, i);       //green
    //     delay(1);
    // }

    // for (int i = 0; i < 256; i++)
    // {
    //     device.led_pwm(0x10, 255 - i); //green
    //     device.led_pwm(0x20, i);       //blue
    //     device.led_pwm(0x40, 255 - i); //green
    //     device.led_pwm(0x50, i);       //blue
    //     device.led_pwm(0x11, 255 - i); //green
    //     device.led_pwm(0x21, i);       //blue
    //     device.led_pwm(0x41, 255 - i); //green
    //     device.led_pwm(0x51, i);       //blue
    //     delay(1);
    // }

    // for (int i = 0; i < 256; i++)
    // {
    //     device.led_pwm(0x20, 255 - i); //blue
    //     device.led_pwm(0x00, i);       //red
    //     device.led_pwm(0x50, 255 - i); //blue
    //     device.led_pwm(0x30, i);       //red
    //     device.led_pwm(0x21, 255 - i); //blue
    //     device.led_pwm(0x01, i);       //red
    //     device.led_pwm(0x51, 255 - i); //blue
    //     device.led_pwm(0x31, i);       //red
    //     delay(1);
    // }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x00, 255 - i); //red
        device.led_pwm(0x10, i);       //green
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x10, 255 - i); //green
        device.led_pwm(0x20, i);       //blue
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x20, 255 - i); //blue
        device.led_pwm(0x00, i);       //red
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x30, 255 - i); //red
        device.led_pwm(0x40, i);       //green
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x40, 255 - i); //green
        device.led_pwm(0x50, i);       //blue
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x50, 255 - i); //blue
        device.led_pwm(0x30, i);       //red
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x01, 255 - i); //red
        device.led_pwm(0x11, i);       //green
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x11, 255 - i); //green
        device.led_pwm(0x21, i);       //blue
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x21, 255 - i); //blue
        device.led_pwm(0x01, i);       //red
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x31, 255 - i); //red
        device.led_pwm(0x41, i);       //green
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x41, 255 - i); //green
        device.led_pwm(0x51, i);       //blue
        delay(1);
    }

    for (int i = 0; i < 256; i++)
    {
        device.led_pwm(0x51, 255 - i); //blue
        device.led_pwm(0x31, i);       //red
        delay(1);
    }    
}