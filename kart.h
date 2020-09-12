#ifndef KART_H
#define KART_H

#include "serial.h"

uint8_t kart_brake;    //holds kart braking control data
uint8_t kart_throttle; //holds kart throttle control data
uint8_t kart_steering; //holds kart steering control data

//serial state acknowledge bytes
const uint8_t KART_IDLE_ACK = 0xa0;
const uint8_t KART_ENABLE_ACK = 0xa1;
const uint8_t KART_ERROR_ACK = 0xa2;
const uint8_t KART_CTRL_ACK = 0xa3;

enum KART_STATE
{
    IDLE,
    ENABLED,
    ERROR
};

KART_STATE cur_kart_state;

bool kart_init()
{
    cur_kart_state = IDLE;
    NeoSerial.print(KART_IDLE_ACK);
    return true;
}

bool kart_control()
{
    NeoSerial.print(KART_CTRL_ACK);
    NeoSerial.print(kart_brake);
    NeoSerial.print(kart_throttle);
    NeoSerial.print(kart_steering);
    return true;
}

bool req_kart_state_change(KART_STATE req)
{
    switch (cur_kart_state)
    {
    case IDLE:
        if (req == ENABLED)
        {
            cur_kart_state = ENABLED;
            NeoSerial.print(KART_ENABLE_ACK);
            return true;
        }
        else if (req == ERROR)
        {
            cur_kart_state = ERROR;
            NeoSerial.print(KART_ERROR_ACK);
        }
        break;
    case ENABLED:
        if (req == ERROR)
        {
            cur_kart_state = ERROR;
            NeoSerial.print(KART_ERROR_ACK);
            return true;
        }
        break;
    case ERROR:
        if (req == IDLE)
        {
            cur_kart_state = IDLE;
            NeoSerial.print(KART_ERROR_ACK);
        }
        break;
    }

    //all valid cases handled above
    cur_kart_state = ERROR;
    return false;
}

#endif /* KART_H */