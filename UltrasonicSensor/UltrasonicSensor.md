# Arduino Ultrasonic Distance Measurement

This repository contains an Arduino sketch to measure distance using an ultrasonic sensor. The code utilizes a trigger and echo pin to calculate the time it takes for sound waves to travel to an object and back, then converts this time into distance.

## Code Overview

- **Pins Used**:
  - `trigPin` (Trigger Pin): Pin 5, used to send ultrasonic pulses.
  - `echoPin` (Echo Pin): Pin 6, used to receive the reflected ultrasonic pulses.

- **Key Variables**:
  - `duration`: Time taken for the pulse to return.
  - `distance`: Distance to the object in centimeters.

- **Functionality**:
  - Sends a short ultrasonic pulse through the trigger pin.
  - Measures the time taken for the pulse to return using the echo pin.
  - Converts the time into distance using the speed of sound.

## Setup

1. **Hardware**:
   - Connect the `trigPin` to the trigger pin of the ultrasonic sensor.
   - Connect the `echoPin` to the echo pin of the ultrasonic sensor.
   - Provide power (VCC) and ground (GND) to the sensor.

2. **Code**:
   - Upload the provided code to your Arduino board.

3. **Testing**:
   - Open the Serial Monitor in the Arduino IDE to view distance measurements.

## Code Snippet

```cpp
const int trigPin = 5;
const int echoPin = 6;

float duration, distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0343) / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(100);
}

