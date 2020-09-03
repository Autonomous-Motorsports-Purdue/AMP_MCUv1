#define BAUD_RATE 9600

String msg = "";

static void handleRxChar(uint8_t c)
{
    if (c == '\n')
    {
        NeoSerial.println(msg);
        msg = "";
    }
    else
    {
        msg += (char)c;
    }
}

bool serial_init()
{
    NeoSerial.attachInterrupt(handleRxChar);
    NeoSerial.begin(BAUD_RATE); // Instead of 'Serial'
    return true;
}
