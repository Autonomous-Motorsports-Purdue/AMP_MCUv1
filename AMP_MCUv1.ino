#include <NeoHWSerial.h>
#include "serial.h"
#include "kart.h"

void setup()
{
    serial_init();
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000);                     // wait for a second
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);                     // wait for a second
    if (serial_pkt_recieved)
    {
        if (kart_control())
        {
            serial_pkt_recieved = 0; //packet recieved
        }
    }
}
