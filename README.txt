You will need to take the two master files and move them to the same directory that the AMP_MCUv1 is in.
tc_lib-master, and pwm_lib-master

For information setting up the arduino DUE the official guide can be found here: https://www.arduino.cc/en/Guide/ArduinoDue

Basics:
1) plug the Arduino into your pc with the port closest to the DC input
2) navigate in the Arduino IDE to tools>Board>Boards Manager
3) Search DUE and install the package that says: Arduino SAM Boards

After that navigate to tools>Board>Arduino ARM boards>DUE programming port
And you should be good to go!
