# Arduino Ultrasonic Obstacle Detection and Motor Control  

This project combines ultrasonic distance measurement with motor control, enabling a simple obstacle detection system for robotics applications. The system stops motor movement if an object is detected within a specified range (e.g., 100 cm) and resumes normal operation otherwise.  

## Code Overview  

- **Pins Used**:  
  - `trig`: Pin 6, used to send ultrasonic pulses.  
  - `echo`: Pin 5, used to receive the reflected ultrasonic pulses.  
  - `led`: Pin 13, optional LED for debugging or indicating system state.  
  - `1, 2, 3, 4`: Motor control pins.  

- **Key Variables**:  
  - `time`: Stores the duration of the ultrasonic pulse.  
  - `dist`: Distance to the nearest object in centimeters, calculated using the speed of sound.  

- **Functionality**:  
  - Sends an ultrasonic pulse and measures the time it takes to return.  
  - Converts the time into a distance reading.  
  - If the distance is less than 100 cm, the motors are stopped to prevent collision.  
  - If the distance is greater than or equal to 100 cm, the motors move the robot forward.  

## Setup  

1. **Hardware**:  
   - Connect the ultrasonic sensor:
     - `trig` pin to pin 6.  
     - `echo` pin to pin 5.  
   - Connect motor drivers to pins `1`, `2`, `3`, and `4` for motor control.  
   - (Optional) Connect an LED to pin 13 for debugging or indication.  

2. **Code**:  
   - Upload the provided code to your Arduino board.  

3. **Testing**:  
   - Open the Serial Monitor in the Arduino IDE to view distance measurements.  
   - Place obstacles at varying distances and observe motor behavior.  

## Code Snippet  

```cpp
#define echo 5
#define trig 6
#define led 13

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long time, dist;
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    time = pulseIn(echo, HIGH);
    dist = time / 2 / 29.1;  // Convert time to distance in cm
    Serial.println(dist);
    delay(1000);

    if (dist < 100) {
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);  // Stop motors
    } else {
        digitalWrite(1, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);  // Move motors forward
    }
}
```
How It Works
Ultrasonic Measurement:

A trigger pulse is sent, and the time for the echo to return is measured.
The distance is calculated using the formula:
Distance
=
Time (µs)
2
×
29.1
Distance= 
2×29.1
Time (µs)
​
 
Motor Control:

If the calculated distance is less than 100 cm, all motor pins are set to LOW, stopping the robot.
If the distance is greater than or equal to 100 cm, the robot moves forward.
Purpose
This project is ideal for:

Creating basic obstacle detection and avoidance systems for robots.
Understanding the integration of sensors and actuators with Arduino.
Experimenting with distance-based motor control.
