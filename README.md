# LEDcontrol

This Repository contains two class libraries that are designed to support Particle microcontroller projects
that require visual and audible status and alarm indicators:

## LEDcontrolClass
Instances of the class encapsulate an LED, buzzer, or any other device that can be turned on and
off via digitalWrite().  The encapsulted device can be turned on, turned off, and flashed via methods of the object.
The state of objects of this class needs to be updated frequently by calling the refresh() method on the object.
Therefore, refresh() should be called in loop() and loop() code should be non-blocking.

### LEDcontrolClass Methods
- Constructor:  The constructor takes one argument which is the microcontroller pin on which the device is connected.
- begin():  this method must be called in setup() in order to set the pin mode for the connected device and to turn the
    device off.
- off():  this method is used to turn the device off.  The method actually just sets the internal device state to off.
    refresh() must be called to actually turn the device off.
- on():  this method is used to turn the device on.  The method actually just sets the internal device state to on.
    refresh() must be called to actually turn the device on.
- flash():  this method is used to set the device to flash.  The method actually just sets the internal device state to flash.
    refresh() must be called to actually flash the device.  The flashing rate can be set using the setRate() method.  The default
    flashing rate is 300 ms on and off.
- setRate(int flashTime): this method is used to change the flashing rate.  The argument is the on/off time, in milliseconds.
- refresh():  this method actually truns the device on and off and keeps internal time - therefore, it must be called frequently
    (i.e. in non-blocking loop() code).

## BtnStatusClass
Instances of the class encapsulate a momentary push button switch, or any other momentatry device whose status can be read
via digitalRead().  Instances of this class maintain an internal state that also manages debouncing the button.  A 10 ms debounce
internal is the default.  The isPressed() method is used to determine if the button has been pressed.  It returns true only once for
each press of the button.  The state of objects of this class needs to be updated frequently by calling the isPressed() method on the
object.  Therefore, isPressed() should be called in loop() and loop() code should be non-blocking.

### BtnStatusClass Methods
- Constructor:  The constructor takes one argument which is the microcontroller pin on which the button is connected.
- begin():  this method must be called in setup() in order to set the pin mode for the connected device and to set
    the inital button state to not pressed.
- isPressed():  this method returns a boolean - true after the button has been pressed and debounced, false otherwise.  This method requires
    that its internal time be updated frequently for accurate debouncing - therefore, it must be called frequently (i.e. in
    non-blocking loop() code).

## Test code
The Arduino/Particle program "LEDcontrolExample.ino" is provided to exercise these class libraries.  This program performs
the following functions:
* intantiates 3 LEDcontrolClass objects and one BtnStatusClass object.
* sets different flashing times for each of the connected LEDs.
* initializes all objects by calling their begin() functions in setup().
* waits until the Particle device connects to the Particle cloud and then turns each LED on for two seconds, individually, in turn.
* in loop() causes each LED device to flash, using non-blocking code.
* in loop(), continuously calls the isPressed() method on the connected button to refresh its state.  When the button is pressed
  and debounced, it resets the Particle device.

  
