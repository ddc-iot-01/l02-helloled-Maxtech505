/* 
 * Project: L02_02_HELLOLEDVAR
 * Author: MAXIMO
 * Date: 6/15/25
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

const int REDDYPIN = D1;
const int LEDDELAY = 100;
int i;

void setup() {
  pinMode(REDDYPIN, OUTPUT);

  i = 100;
  // Put initialization like pinMode and begin functions here
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  digitalWrite(REDDYPIN, HIGH);
  delay(LEDDELAY);
  digitalWrite(REDDYPIN, LOW);
  delay(LEDDELAY+1);
  i = i + 200;
  // The core of your code will likely live here.

  // Example: Publish event to cloud every 10 seconds. Uncomment the next 3 lines to try it!
  // Log.info("Sending Hello World to the cloud!");
  // Particle.publish("Hello world!");
  // delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}
