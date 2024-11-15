# Arduino Bluetooth-Controlled Robot
![Alt text]((https://github.com/narayanshastri/Arduinocodes/blob/main/JoystickControlledRobot/Tank.png)
This repository contains an Arduino sketch for controlling a robot using serial commands. The robot's movement can be directed forward, backward, left, or right through commands sent via a serial interface (e.g., Bluetooth or USB).

## Code Overview

- **Pins Used**:
  - **Motor Pins**:
    - `r1` (Right Motor Forward) connected to pin 2.
    - `r2` (Right Motor Reverse) connected to pin 3.
    - `l1` (Left Motor Forward) connected to pin 4.
    - `l2` (Left Motor Reverse) connected to pin 5.

- **Serial Communication**:
  - Receives character commands via a serial connection at a baud rate of 9600.

- **Commands**:
  - `'F'`: Move forward.
  - `'B'`: Move backward.
  - `'L'`: Turn left.
  - `'R'`: Turn right.

## Functionality

1. The robot listens for commands sent over the serial interface.
2. Based on the received character:
   - **Forward (`F`)**: Both motors move forward.
   - **Backward (`B`)**: Both motors move backward.
   - **Left (`L`)**: The robot turns left by stopping the left motor and running the right motor briefly.
   - **Right (`R`)**: The robot turns right by stopping the right motor and running the left motor briefly.

## Setup

1. **Hardware**:
   - Connect motor drivers to pins `2`, `3`, `4`, and `5` for motor control.
   - Connect a Bluetooth module (e.g., HC-05) or use a USB serial connection to send commands.

2. **Code**:
   - Upload the code to your Arduino board.
   - Ensure the serial communication device is paired and configured.

3. **Testing**:
   - Open the Serial Monitor or use a Bluetooth terminal app to send commands (`F`, `B`, `L`, `R`) to the robot.

## Code Snippet

```cpp
char t;
const int r1 = 2, r2 = 3, l1 = 4, l2 = 5;

void setup() {
    Serial.begin(9600);
    pinMode(r1, OUTPUT); 
    pinMode(r2, OUTPUT);
    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
}

void loop() {
    if (Serial.available()) {
        t = Serial.read();
    }

    if (t == 'F') {
        digitalWrite(r1, HIGH);
        digitalWrite(r2, LOW);
        digitalWrite(l1, HIGH);
        digitalWrite(l2, LOW);
    } 
    else if (t == 'B') {
        digitalWrite(r1, LOW);
        digitalWrite(r2, HIGH);
        digitalWrite(l1, LOW);
        digitalWrite(l2, HIGH);
    } 
    else if (t == 'L') { 
        digitalWrite(r1, HIGH);
        digitalWrite(r2, LOW);
        digitalWrite(l1, LOW);
        digitalWrite(l2, HIGH);
        delay(100);
        t = 'S';
    } 
    else if (t == 'R') {
        digitalWrite(r1, LOW);
        digitalWrite(r2, HIGH);
        digitalWrite(l1, HIGH);
        digitalWrite(l2, LOW);
        delay(100);
        t = 'S';
    }
}
```
Purpose
This project demonstrates:
	• Using serial communication to control a robot.
	• Basic motor control for movement in multiple directions.
Creating an interactive robot using Arduino.
