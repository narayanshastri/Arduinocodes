# Arduino Robotics and Sensor Control Projects  
(All the codes were written and tested on a Arduino UNO R3)

This repository contains a collection of beginner-friendly Arduino projects focusing on robotics and sensor-based control systems. Each project demonstrates the use of Arduino for real-world applications, including LED control, motor control, ultrasonic distance measurement, and Bluetooth-based robot control. The goal is to provide simple and modular examples to help others learn and experiment with Arduino programming and hardware integration.  

## Projects Included  

### 1. **LED Blink Test**  
- **Description**: A basic sketch to test the blinking functionality of an LED using Arduino. The LED blinks at a fixed interval to demonstrate basic output control.  
- **Features**:  
  - Blinks an LED connected to a digital pin.  
  - Adjustable delay intervals.  

---

### 2. **Line Following Robot Control**  
- **Description**: A line-following robot that uses two sensors to detect and follow a line on a surface. The motors adjust based on sensor input to keep the robot on track.  
- **Features**:  
  - Reads input from left and right sensors.  
  - Controls motor directions for forward, backward, and turning movements.  

---

### 3. **Bluetooth-Controlled Robot**  
- **Description**: A robot controlled via serial commands, such as those sent from a Bluetooth terminal or Serial Monitor. Commands like `'F'`, `'B'`, `'L'`, and `'R'` dictate the robot's movement.  
- **Features**:  
  - Serial communication to receive commands.  
  - Motor control for forward, backward, left, and right movements.  

---

### 4. **Ultrasonic Distance Measurement**  
- **Description**: A sketch to measure distance using an ultrasonic sensor. It calculates the time taken for sound waves to travel to an object and back, converting it into a distance reading.  
- **Features**:  
  - Trigger and echo functionality using ultrasonic sensors.  
  - Real-time distance measurement displayed on the Serial Monitor.  

---

### 5. **Ultrasonic Obstacle Detection and Motor Control**  
- **Description**: Combines ultrasonic distance measurement with motor control for a simple obstacle detection system. If an obstacle is detected within 100 cm, the robot stops; otherwise, it moves forward.  
- **Features**:  
  - Real-time distance measurement using an ultrasonic sensor.  
  - Conditional motor control based on proximity to objects.  

## How to Use  

1. Clone this repository:  
   ```bash
   git clone https://github.com/narayanshastri/arduino-robotics-projects.git
   ```
   Navigate to the folder of the project you want to try.
Open the respective .ino file in the Arduino IDE.
Follow the project-specific setup instructions mentioned in each README.md file.
Prerequisites
Hardware:

Arduino Uno or similar microcontroller.
Basic electronic components like LEDs, resistors, sensors, motor drivers, and ultrasonic sensors.
Optional: Bluetooth module for the Bluetooth-controlled robot.
Software:

Arduino IDE.
Learning Objectives
This repository helps you learn:

Basic Arduino programming.
Interfacing with sensors and motors.
Implementing serial communication.
Real-world applications of robotics and automation.
Future Plans
This repository may be expanded with additional projects, such as:

Advanced obstacle-avoiding robots.
Temperature and humidity monitoring systems.
Robotic navigation with GPS integration.
