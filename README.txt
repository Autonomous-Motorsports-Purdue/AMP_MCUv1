You will need to take the two master files and move them to the same directory that the AMP_MCUv1 is in.
tc_lib-master, and pwm_lib-master

For information setting up the arduino DUE the official guide can be found here: https://www.arduino.cc/en/Guide/ArduinoDue

Basics:
1) plug the Arduino into your pc with the port closest to the DC input
2) navigate in the Arduino IDE to tools>Board>Boards Manager
![Alt text](https://github.com/Autonomous-Motorsports-Purdue/AMP_MCUv1/blob/LoganDev/Documentation/BoardManager.png?raw=true)
![alt text](https://github.com/Autonomous-Motorsports-Purdue/AMP_MCUv1/blob/d19106e8b4195177b46bcee4f507523b580a3cad/Documentation/BoardManager.png)
3) Search DUE and install the package that says: Arduino SAM Boards

After that navigate to tools>Board>Arduino ARM boards>DUE programming port
And you should be good to go!
