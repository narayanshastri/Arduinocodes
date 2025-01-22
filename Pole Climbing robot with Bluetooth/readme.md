# Bluetooth-Controlled Motor Project

This project demonstrates controlling three DC motors using an Arduino and an Adafruit Motor Shield, with commands sent via Bluetooth communication.

## Features

- Control three DC motors wirelessly using a Bluetooth-enabled device.
- Support for upward, downward, and stop commands.
- Simple integration with an Android/iOS Bluetooth terminal app.

## Components Required

1. Arduino board (e.g., Uno, Mega)
2. Adafruit Motor Shield
3. HC-05/HC-06 Bluetooth module
4. Three DC motors
5. Power supply for motors
6. Jumper wires

## Circuit Diagram

1. Connect motor 1 to pins 2 and 4 of the motor shield.
2. Connect motor 2 to pins 7 and 8 of the motor shield.
3. Connect motor 3 to pins 12 and 13 of the motor shield.
4. Connect the HC-05/HC-06 Bluetooth module:
   - `VCC` to 5V on Arduino
   - `GND` to GND on Arduino
   - `RX` to Arduino pin 1 (TX of Arduino)
   - `TX` to Arduino pin 0 (RX of Arduino)
5. Attach the Adafruit Motor Shield to the Arduino.
6. Provide an external power supply for the motors if needed.

## Code Explanation

### Libraries Used

```cpp
#include <AFMotor.h>
#include <SoftwareSerial.h>
The AFMotor library controls the motors through the Adafruit Motor Shield.
The SoftwareSerial library enables Bluetooth communication on custom pins.
Pin Configuration
Motor and Bluetooth pins are defined as:

#define motor1Pin1 2
#define motor1Pin2 4
#define motor2Pin1 7
#define motor2Pin2 8
#define motor3Pin1 12
#define motor3Pin2 13
#define rxPin 0
#define txPin 1
Bluetooth Communication
The SoftwareSerial object initializes Bluetooth communication:

SoftwareSerial bluetooth(rxPin, txPin);
Commands sent via Bluetooth are read and processed in the loop.

Commands
'U': Move motors upward.
'D': Move motors downward.
'S': Stop all motors.
Motor Control Functions
Upward Motion:

void upward() {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    motor3.setSpeed(255);
    motor3.run(FORWARD);
}
Downward Motion:

void downward() {
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.setSpeed(255);
    motor2.run(BACKWARD);
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
}
Stop Motors:

void stopMotors() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}
Setup and Loop
The setup initializes the motor pins and Bluetooth communication. The loop processes incoming Bluetooth commands:


void setup() {
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
    bluetooth.begin(9600); // Start Bluetooth communication
}

void loop() {
    if (bluetooth.available() > 0) {
        char command = bluetooth.read();
        switch (command) {
        case 'U':
            upward();
            break;
        case 'D':
            downward();
            break;
        case 'S':
            stopMotors();
            break;
        default:
            break;
        }
    }
}
```
## How to Use
- Upload the code to your Arduino board.
- Assemble the circuit as described.
- Pair your Bluetooth module with a smartphone or computer.
- Open a Bluetooth terminal app (e.g., Serial Bluetooth Terminal).
- Send the following commands:
- 'U' to move motors upward.
- 'D' to move motors downward.
- 'S' to stop motors.
## Adjust motor speed using the setSpeed() function.
- Modify Bluetooth pins if required (ensure compatibility with your Arduino model).
## Prerequisites
- Install the Adafruit Motor Shield and SoftwareSerial libraries in the Arduino IDE.
## License
This project is open-source and available under the MIT License. Feel free to use and modify it as needed.

