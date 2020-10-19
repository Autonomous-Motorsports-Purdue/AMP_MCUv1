#ifndef STEERING_H
#define STEERING_H

#define STEERING_PIN 2 //Steering


// 1kHz (left)
// 3kHz (center)
// 5kHz (right)

#define STEERING_PACKET_MAX 255
#define STEERING_PACKET_MIN 0

#define STEERING_CONTROL_MAX 5000
#define STEERING_CONTROL_MIN 1000

bool set_steering_raw(int steeringRequest)
{
  if(steeringRequest < STEERING_PACKET_MIN || steeringRequest > STEERING_PACKET_MAX)
  {
    return false;
  }
  //TODO: set the pwm frequency value of the steering pin
  SerialUSB.print("inside set steering raw: steering = ");
  SerialUSB.println(steeringRequest);

  //Scales floating point steering value to int value to request from PWM
  int steeringCommand = STEERING_CONTROL_MIN + (steeringRequest - STEERING_PACKET_MIN) * (STEERING_CONTROL_MAX - STEERING_CONTROL_MIN) / (STEERING_PACKET_MAX - STEERING_PACKET_MIN);

  //analogWrite(STEERING_PIN, steeringCommand);
  //tone(STEERING_PIN, steeringCommand);

  return true; 
}

#endif /* STEERING_H */
