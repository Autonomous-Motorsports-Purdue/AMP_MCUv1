#ifndef KART_H
#define KART_H

#include "serial.h"

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
    return true;
}

bool req_kart_state_change(KART_STATE req)
{
    switch (cur_kart_state)
    {
    case IDLE:
        if (req == ENABLE)
        {
            cur_kart_state = ENABLED;
            return true;
        }
        else if (req == ERROR)
        {
            cur_kart_state = ERROR;
        }
        break;
    case ENABLED:
        if (req == ERROR)
        {
            cur_kart_state = ERROR;
            return true;
        }
        break;
    case ERROR:
        if (req == IDLE)
        {
            cur_kart_state = IDLE;
        }
        break;
    }

    //all valid cases handled above
    cur_kart_state = ERROR;
    return false;
}

#endif /* KART_H */