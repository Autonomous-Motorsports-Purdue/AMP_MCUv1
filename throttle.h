#ifndef THROTTLE_H
#define THROTTLE_H

#define DAC_PIN DAC0 //DAC output

#define THROTTLE_PACKET_MAX 0x00FF //max value expected from Jetson
#define THROTTLE_PACKET_MIN 0x0000  //min value expected form Jetson
//Range of the arduino due DAC is from 0.55V - 2.75V
#define THROTTLE_CONTROL_MAX 0x0D54 //max value commanded from Throttle DAC, Decimal Number: 3412
#define THROTTLE_CONTROL_MIN 0x02AB //min value commanded from Throttle DAC, Decimal Number: 683

bool set_throttle_raw(int throttleRequest)
{
  if(throttleRequest < THROTTLE_PACKET_MIN || throttleRequest > THROTTLE_PACKET_MAX)
  {
    return false;
  }
  
  // Perform Scaling to Voltage Value
  int throttleCommand = THROTTLE_CONTROL_MIN + (throttleRequest - THROTTLE_PACKET_MIN) * (THROTTLE_CONTROL_MAX - THROTTLE_CONTROL_MIN) / (THROTTLE_PACKET_MAX - THROTTLE_PACKET_MIN);

  SerialUSB.print("throttleCommand that that has been assembled is: ");
  SerialUSB.println(throttleCommand);

  analogWrite(DAC_PIN, throttleCommand);

  return true;
}

#endif /* THROTTLE_H */
