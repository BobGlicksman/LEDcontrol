/****************************************************************************************
 * LEDcontrolExample.ino.  Test code to exercize the LEDcontrolClass library.
 *
 *  This code is provided as an example of how to use the LEDcontrolClass library.
 *
 *  The code creates three instances of the LEDcontrolClass, one for each of the three LEDs on
 *  a Photon 2 that is placed on the TPP RFID pcb.  In setup(), the test code uses each LED
 *  instance to turn on and off each LED for 2 seconds.  In loop(), the test code causes
 *  each LED to flash at a different rate.  This demonstrates the library functionality when
 *  controlling multiple LEDs.
 *
 *  The loop() code must be non-blocking as the refresh() method must be called frequently
 *  to allow the LED flashing to occur accurately.
 *
 * Author: Bob Glicksman
 * (c) 2026, Bob Glicksman, Jim Schrempp, Team Practical Projects.  All rights reserved.
 *
 * Version 1.0.  Initial release. 7/01/26
 *
 */

#include <Particle.h>
#include <LEDcontrolClass.h>

#define RED S3    // pin to which the RED LED is connected
#define GREEN D4  // pin to which the GREEN LED is connected
#define YELLOW S4 // pin to which the YELLOW LED is connected

SYSTEM_MODE(AUTOMATIC);

// instantiate the LEDs
LEDcontrolClass redLED(RED);
LEDcontrolClass greenLED(GREEN);
LEDcontrolClass yellowLED(YELLOW);

void setup()
{
    // initialize the LED
    redLED.begin();
    greenLED.begin();
    yellowLED.begin();

    greenLED.setRate(100);
    yellowLED.setRate(200);
    redLED.setRate(500);

    waitUntil(Particle.connected);

    // test the LEDs by turning them on and off for 2 seconds each
    greenLED.on();
    greenLED.refresh(); // turn on the led
    delay(2000);

    greenLED.off();
    greenLED.refresh(); // turn off the led]
    yellowLED.on();
    yellowLED.refresh(); // turn on the led
    delay(2000);

    yellowLED.off();
    yellowLED.refresh(); // turn off the led
    redLED.on();
    redLED.refresh(); // turn on the led
    delay(2000);      // wait 4 seconds
}

void loop()
{

    greenLED.flash();
    yellowLED.flash();
    redLED.flash();

    // call refresh() frequently to allow flashing to occur accurately
    greenLED.refresh();
    yellowLED.refresh();
    redLED.refresh();
}
