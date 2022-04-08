#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "serial.h"
#include "kart.h"

#include <avr/io.h>
#include <avr/interrupt.h>


bool inter = false;
int timeOut = 2; //number of seconds witout a packet until error state
IntervalTimer myTimer;

void check_Serial()
{

    if(inter == true)
    {
        set_error();
        while(true)
            digitalWrite(13, LOW);
        //return -1;
    }
    inter = true;
    //return 1;
}


void start_Interrupt()
{

    myTimer.begin(check_Serial, timeOut*1000000);

    //Timer3.attachInterrupt(check_ptr).start(5000000);//5 second interrupt
}
#endif