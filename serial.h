#ifndef SERIAL_H
#define SERIAL_H

#include "kart.h"

#define BAUD_RATE 9600

//serial byte identifiers
const uint8_t START_BYTE = 0x02;
const uint8_t STOP_BYTE = 0x03;
const uint8_t ID_ENABLE = 0xf0;
const uint8_t ID_CONTROL = 0xf1;
const uint8_t ID_KILL = 0xf2;
const uint8_t RESET_SERIAL_STATE = 0xdd;
const uint8_t DATA_LEN_1 = 0xe1;
const uint8_t DATA_LEN_2 = 0xe2;
const uint8_t DATA_LEN_3 = 0xe3;

//serial data byte buffers
uint8_t brake_buf;    //holds incoming breaking data
uint8_t throttle_buf; //holds incoming throttle data
uint8_t steering_buf; //holds incoming steering data
uint8_t serial_crc;

uint8_t serial_pkt_recieved; //flag to indicate new serial packet

enum SERIAL_STATE
{
    DEFAULT_STATE,
    ID_SEEKING,
    KILL_STATE,
    DATA_LEN_SEEKING,
    BRAKE_DATA_SEEKING,
    THROTTLE_DATA_SEEKING,
    STEERING_DATA_SEEKING,
    CRC_SEEKING,
    STOP_SEEKING
};

SERIAL_STATE cur_serial_state;

void restart_serial()
{
    //move serial buffers into kart control vars
    kart_brake = brake_buf;
    kart_throttle = throttle_buf;
    kart_steering = steering_buf;

    //clear buffers
    brake_buf = 0;
    throttle_buf = 0;
    steering_buf = 0;

    //clear crc
    serial_crc = 0;

    //set serial pkt recieved flag
    serial_pkt_recieved = 1;
}

//serial rx interrupt callback function

//be carefule that this function uses the cur_serial_state variable
//and not the cur_kart_state variable (easy to confuse maybe rename)
static void handleRxChar(uint8_t cmd)
{
    NeoSerial.println(cmd); //echoback serial for debugging

    int valid_cmd_byte = 0;

    switch (cur_serial_state)
    {
    case DEFAULT_STATE:
        if (cmd == START_BYTE)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = ID_SEEKING;
        }
        break;
    case ID_SEEKING:
        if (cmd == ID_ENABLE && req_kart_state_change(ENABLED))
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = CRC_SEEKING;
        }
        else if (cmd == ID_CONTROL && cur_kart_state == ENABLED)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = DATA_LEN_SEEKING;
        }
        else if (cmd == ID_KILL && req_kart_state_change(ERROR))
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = KILL_STATE;
        }
        break;
    case KILL_STATE:
        if (cmd == RESET_SERIAL_STATE)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = DEFAULT_STATE;
        }
        break;
    case DATA_LEN_SEEKING:
        if (cmd == DATA_LEN_3)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = BRAKE_DATA_SEEKING;
        }
        else if (cmd == DATA_LEN_2)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = THROTTLE_DATA_SEEKING;
        }
        else if (cmd == DATA_LEN_1)
        {
            valid_cmd_byte = 1;
            serial_crc += cmd;
            cur_serial_state = STEERING_DATA_SEEKING;
        }
        break;
    case BRAKE_DATA_SEEKING:
        valid_cmd_byte = 1;
        serial_crc += cmd;
        brake_buf = cmd;
        cur_serial_state = THROTTLE_DATA_SEEKING;
        break;
    case THROTTLE_DATA_SEEKING:
        valid_cmd_byte = 1;
        serial_crc += cmd;
        throttle_buf = cmd;
        cur_serial_state = STEERING_DATA_SEEKING;
        break;
    case STEERING_DATA_SEEKING:
        valid_cmd_byte = 1;
        serial_crc += cmd;
        steering_buf = cmd;
        cur_serial_state = CRC_SEEKING;
        break;
    case CRC_SEEKING:
        if (cmd == serial_crc)
        {
            valid_cmd_byte = 1;
            cur_serial_state = STOP_SEEKING;
        }
        break;
    case STOP_SEEKING:
        if (cmd == STOP_BYTE)
        {
            valid_cmd_byte = 1;
            restart_serial();
        }
        break;
    }

    if (!valid_cmd_byte)
    {
        cur_serial_state = KILL_STATE;
    }
}

bool serial_init()
{
    cur_serial_state = DEFAULT_STATE;
    serial_crc = 0;
    brake_buf = 0;
    throttle_buf = 0;
    steering_buf = 0;
    NeoSerial.attachInterrupt(handleRxChar);
    NeoSerial.begin(BAUD_RATE); // Instead of 'Serial'
    return true;
}

#endif /* SERIAL_H */