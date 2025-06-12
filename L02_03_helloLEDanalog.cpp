/*
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// Define pins (ensure both are on PWM-capable pins)
const int aurora  = D1;   // LED that will fade up and down
const int lazer1 = A2;   // LED that will invert the brightness of aurora

// Calculate delay per step so that half-cycle (0 to 255) takes about 5000 ms.
// Using integer math: 5000/255 gives ~19 and then we add one to be safe.
const long tacoTime = 5000 / 255 + 1;

int j;  // Loop variable

void setup() {
  // Set the LED pins as outputs.
  pinMode(aurora, OUTPUT);
  pinMode(lazer1, OUTPUT);
}

void loop() {
  // Ascending phase: ramp up aurora from 0 to 255,
  // while simultaneously ramping down lazer1 from 255 to 0.
  for (j = 0; j <= 255; j++) {
    analogWrite(aurora, j);      // Increase brightness of aurora
    analogWrite(lazer1, 255 - j);  // Decrease brightness of lazer1 (inverted)
    delay(tacoTime);             // Delay controls the fade speed
  }

  // Descending phase: ramp down aurora from 255 to 0,
  // while simultaneously ramping up lazer1 from 0 to 255.
  for (j = 255; j >= 0; j--) {
    analogWrite(aurora, j);      // Decrease brightness of aurora
    analogWrite(lazer1, 255 - j);  // Increase brightness of lazer1 (inverted)
    delay(tacoTime);
  }
}