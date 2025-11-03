This repository contains an Arduino sketch to control a basic line-following robot. The code uses two sensors to detect the presence of a line and adjusts the movement of the robot accordingly by controlling its motors.

## Code Overview

- **Pins Used**:
  - **Inputs**: 
    - `LS` (Left Sensor) connected to pin 6.
    - `RS` (Right Sensor) connected to pin 5.
  - **Outputs**: 
    - `r1` (Right Motor Forward) connected to pin 1.
    - `r2` (Right Motor Reverse) connected to pin 2.
    - `l1` (Left Motor Forward) connected to pin 3.
    - `l2` (Left Motor Reverse) connected to pin 4.

- **Functionality**:
  - Reads the states of the left (`LS`) and right (`RS`) sensors.
  - Controls motor directions based on the sensor inputs:
    - If the left sensor detects the line, the left motor moves forward.
    - If the right sensor detects the line, the right motor moves forward.

## Setup

1. **Hardware Connections**:
    - Connect the left and right sensors to pins `6` and `5` respectively.
    - Connect motor drivers to pins `1`, `2`, `3`, and `4` for motor control.
    - Ensure the sensors are properly aligned to detect the line on the surface.

2. **Code Configuration**:
    - Verify pin assignments match your hardware setup.

3. Upload the code to your Arduino board.

## Code Snippet

```cpp
const int r1 = 1, r2 = 2, l1 = 3, l2 = 4;
const int LS = 6; // Left sensor pin
const int RS = 5; // Right sensor pin
int L, R;

void setup() {
    pinMode(LS, INPUT);
    pinMode(RS, INPUT);
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
    digitalWrite(r2, LOW); 
    digitalWrite(l2, LOW);
}

void loop() {
    L = digitalRead(LS);
    R = digitalRead(RS);
    digitalWrite(r1, !R);
    digitalWrite(l1, !L);
}
```
How It Works
	1. The code continuously reads the states of the left and right sensors.
	2. Based on the sensor readings:
		○ If the left sensor detects a line (LOW state), the left motor moves forward.
		○ If the right sensor detects a line (LOW state), the right motor moves forward.
	3. The logic ensures the robot adjusts its direction to follow the line.
Purpose
This code is ideal for:
	• Learning about basic robotics and line-following algorithms.
	• Experimenting with Arduino-based motor and sensor control.
