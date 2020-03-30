#include "mbed.h"
#include "Servo.h"

AnalogIn photoresistor(A0);
DigitalIn button(USER_BUTTON);
DigitalOut led(LED1);
Servo servo1(D9);
Servo servo2(D10);
Servo servo3(D11);

float lightMin = 1.0;  // minimum sensor value
float lightMax = 0.0;     // maximum sensor value
float lightValue = 0.0;         // the sensor value

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void calibrate() {
  // turn on the indicator LED to indicate that calibration is happening:
  led = 1;
  
  // read the sensor:
  lightValue = photoresistor.read();

  // record the maximum sensor value
  if (lightValue > lightMax) {
    lightMax = lightValue;
  }

  // record the minimum sensor value
  if (lightValue < lightMin) {
    lightMin = lightValue;
  }
  // turn on the indicator LED to indicate that calibration is happening:
}

int main() {
    while(1) {
        // while the button is pressed, take calibration readings:
        while (button == 0) {
            printf("Calibrating...\n"); 
            calibrate();
        }
        
        // done calibrating
        led = 0;
          
        lightValue = photoresistor.read();
        
        // apply the calibration to the sensor reading
        lightValue = map(lightValue, lightMin, lightMax, 0, 1);

        // in case the sensor value is outside the range seen during calibration
        lightValue = constrain(lightValue, 0, 1);
        
        if (lightValue > 0.85f) {
            servo1 = 180;
            servo2 = 0;
            servo3 = 0;
            wait(1.5);
        } else {
            servo1 = 0;
            servo2 = 180;
            servo3 = 180;
        }
        printf("light level = %f\n", lightValue); 
    }
}


