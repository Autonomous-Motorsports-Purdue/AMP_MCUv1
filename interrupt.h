#include "serial.h"
#include "kart.h"
void check_Serial()
{
    if(serial_pkt_recieved == 0)
    {
        set_error();
        //return -1;
    }
    //return 1;
}

void (*check_ptr)() = &check_Serial;

void start_Interrupt()
{
    Timer3.attachInterrupt(check_ptr).start(1000);
}
