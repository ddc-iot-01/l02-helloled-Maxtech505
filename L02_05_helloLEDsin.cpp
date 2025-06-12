/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include <math.h> // Include math library for sin function

const int LEDPIN = D1;// Pin where the LED is connected
const int LEDPIN2 = A2;
const float A = 127.5; // Declare variables
const float B = 127.5; // Declare variables
const float v = 1/5.0; // Declare variables

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN2, OUTPUT); // Set LED pin as output

  // Put initialization like pinMode and begin functions here
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // Calculate the sine value and map it to the LED brightness
  float t = millis() / 1000.0; // Get time in seconds
  float brightness = A * sin(2 *M_PI * v * t) + B; // Calculate sine value
  float negative = A * cos(2 *M_PI * v * t) + B; // Calculate sine value for second LED
  analogWrite(LEDPIN, brightness); // Set LED brightness
  analogWrite(LEDPIN2, negative); // Set second LED brightness
 
}
