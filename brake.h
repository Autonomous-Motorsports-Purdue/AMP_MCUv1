#ifndef BRAKE_H
#define BRAKE_H

#define BRAKE_PIN 8 //Brake

bool set_brake_raw(int brakeRequest)
{
  
  analogWrite(BRAKE_PIN, brakeRequest);
  return true;

}

#endif /* BRAKE_H */
