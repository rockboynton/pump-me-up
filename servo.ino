/*
Sweep a servo back and forth through its full range of motion.
*/

#include <Servo.h>  // servo library

// Once you "include" a library, you'll have access to those
// functions. You can find a list of the functions in the servo
// library at: http://arduino.cc/en/Reference/Servo
// Most libraries also have example sketches you can load from
// the "file/examples" menu.

// Now we'll create a servo "object", called myservo. You should
// create one of these for each servo you want to control. 
// You can control a maximum of twelve servos on the Uno 
// using this library. (Other servo libraries may let you
// control more). Note that this library disables PWM on
// pins 9 and 10!

Servo servo1;  // servo control object


void setup() {
  servo1.attach(10);
}


void loop() {
  int position;

  servo1.write(90);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(180);   // Tell servo to go to 180 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(0);     // Tell servo to go to 0 degrees

  delay(1000);         // Pause to get it time to move
  
  // Change position at a slower speed:

  // To slow down the servo's motion, we'll use a for() loop
  // to give it a bunch of intermediate positions, with 20ms
  // delays between them. You can change the step size to make 
  // the servo slow down or speed up. Note that the servo can't
  // move faster than its full speed, and you won't be able
  // to update it any faster than every 20ms.

  // Tell servo to go to 180 degrees, stepping by two degrees
 
  for(position = 0; position < 180; position += 2) {
    servo1.write(position);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }

  // Tell servo to go to 0 degrees, stepping by one degree

  for(position = 180; position >= 0; position -= 1) {                                
    servo1.write(position);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }
}

