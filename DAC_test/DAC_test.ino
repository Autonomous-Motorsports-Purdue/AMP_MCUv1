#define DAC_PIN DAC0 //DAC output

#define THROTTLE_CONTROL_MAX 0x0D54 //max value commanded from Throttle DAC, Decimal Number: 3412
#define THROTTLE_CONTROL_MIN 0x02AB //min value commanded from Throttle DAC, Decimal Number: 683


void setup()
{
    throttle_init();
}

void loop()
{
    for (int i = THROTTLE_CONTROL_MIN; i < THROTTLE_CONTROL_MAX; i++)
    {
        analogWrite(DAC_PIN, i);
    }
}

void throttle_init()
{
    pinMode(DAC_PIN, OUTPUT);

    analogWriteResolution(12); //Sets the analog resolution to 12 bits (0 - 4095)
}
