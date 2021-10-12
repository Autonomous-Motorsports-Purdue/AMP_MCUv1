
#include "serial.h"
#include "kart.h"
#include "brake.h"
#include "steering.h"
#include "throttle.h"
#include "interrupt.h"

int connection = 0;

void setup()
{
    pinMode(13, OUTPUT);
  
    kart_init();

    serial_init();

    steering_init();

    throttle_init();

    pinMode(LED_BUILTIN, OUTPUT);

}

//int on = 0;
void loop()
{
    //    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    //    delay(1000);                     // wait for a second
    //    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
    //    delay(1000);                     // wait for a second
    if (SerialUSB.available()) //was serial_pkt_recieved
    {
        handleRxChar(); //deal with the incoming data
        if(!connection)
        {
            //start_Interrupt();
            connection = 1;
        }
    }

    if (control_flag)
    {
        inter = 0;
        kart_control();
        serial_pkt_recieved = 0; //packet recieved
    }
}
