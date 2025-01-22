# Arduino Motor Control Project

This project demonstrates how to control three DC motors using an Arduino and an Adafruit Motor Shield. The code supports basic motor operations such as moving forward, backward, and stopping.

## Features

- Control three DC motors simultaneously.
- Perform forward and backward motions.
- Easily adjust speed and delay timings for customized operation.

## Components Required

1. Arduino board (e.g., Uno, Mega)
2. Adafruit Motor Shield
3. Three DC motors
4. Power supply for motors
5. Jumper wires

## Circuit Diagram

1. Connect motor 1 to pins 2 and 4 of the motor shield.
2. Connect motor 2 to pins 7 and 8 of the motor shield.
3. Connect motor 3 to pins 12 and 13 of the motor shield.
4. Attach the Adafruit Motor Shield to the Arduino.
5. Provide external power supply for the motors if needed.

## Code Explanation

### Libraries Used

```cpp
#include <AFMotor.h>
The AFMotor library is used to control the motors through the Adafruit Motor Shield.

Pin Configuration
Motor control pins are defined as follows:

cpp
Copy
Edit
#define motor1Pin1 2
#define motor1Pin2 4
#define motor2Pin1 7
#define motor2Pin2 8
#define motor3Pin1 12
#define motor3Pin2 13
Motor Control Functions
Forward Motion: Runs all motors in the forward direction.

cpp
Copy
Edit
void forward() {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    motor3.setSpeed(255);
    motor3.run(FORWARD);
}
Backward Motion: Runs all motors in the backward direction.

cpp
Copy
Edit
void backward() {
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.setSpeed(255);
    motor2.run(BACKWARD);
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
}
Stop Motors: Releases all motors, stopping their movement.

cpp
Copy
Edit
void stopMotors() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}
Setup and Loop
The setup initializes motor pins, while the loop cycles through forward and backward motions with delays in between:

cpp
Copy
Edit
void setup() {
    // Set motor control pins as outputs
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
}

void loop() {
    forward();
    delay(10000); // Forward for 10 seconds
    stopMotors();
    delay(2500); // Stop for 2.5 seconds
    backward();
    delay(10000); // Backward for 10 seconds
    stopMotors();
    delay(2500); // Stop for 2.5 seconds
}
```
## How to Use
1. Upload the code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Power the Arduino and the motors.
4. Observe the motors moving forward and backward with pauses.
## Customization
- Adjust motor speed in the setSpeed() function.
- Modify delays in the delay() function to control operation timing.
## Prerequisites
- Install the Adafruit Motor Shield library in the Arduino IDE.License
- This project is open-source and available under the MIT License. Feel free to use and modify it as needed.
