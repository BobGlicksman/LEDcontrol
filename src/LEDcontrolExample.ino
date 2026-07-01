/****************************************************************************************
 * LEDcontrolExample.ino.  Test code to exercize the LEDcontrolClass library.
 *
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
