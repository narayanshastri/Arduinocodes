# Arduino LED Blink Test

This repository contains a simple Arduino sketch to test the blinking functionality of an LED connected to a digital pin. The LED blinks at intervals of 100 milliseconds, demonstrating basic digital output control.

## Code Overview

- **Pin Used**: Digital pin 6 is configured as an output.
- **Functionality**: 
  - The LED is turned ON (`HIGH`) for 100 milliseconds.
  - Then, it is turned OFF (`LOW`) for another 100 milliseconds.
  - This loop repeats indefinitely.

## Setup

1. Connect an LED with an appropriate resistor to digital pin 6 on the Arduino.
2. Upload the code to your Arduino board.

## Code Snippet

```cpp
void setup() { 
    pinMode(6, OUTPUT);
}

void loop() {
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
}
