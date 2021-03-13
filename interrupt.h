#include "serial.h"
#include "kart.h"

bool inter = false;

void check_Serial()
{
    if(inter == true)
    {
        set_error();
        //return -1;
    }
    inter == true;
    //return 1;
}

void (*check_ptr)() = &check_Serial;

void start_Interrupt()
{
    Timer3.attachInterrupt(check_ptr).start(500000);
}
