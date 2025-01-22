#include <AFMotor.h>
#include <SoftwareSerial.h>
// Define motor pins
#define motor1Pin1 2  // Connect to pin 2 on the motor shield for motor 1
#define motor1Pin2 4  // Connect to pin 4 on the motor shield for motor 1
#define motor2Pin1 7  // Connect to pin 7 on the motor shield for motor 2
#define motor2Pin2 8  // Connect to pin 8 on the motor shield for motor 2
#define motor3Pin1 12 // Connect to pin 12 on the motor shield for motor 3
#define motor3Pin2 13 // Connect to pin 13 on the motor shield for motor 3
// Define Bluetooth communication pins
#define rxPin 0
#define txPin 1
// Create motor objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
// Create Bluetooth serial object
SoftwareSerial bluetooth(rxPin, txPin);
void setup()
{
    // Set motor control pins as outputs
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
    // Set up Bluetooth communication
    bluetooth.begin(9600);
}
void loop()
{
    if (bluetooth.available() > 0)
    {
        char command = bluetooth.read();
        // Execute commands based on Bluetooth input
        switch (command)
        {
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
// Function to move motors upward
void upward()
{
    motor1.setSpeed(255); // Adjust speed as needed
    motor1.run(upward);
    motor2.setSpeed(255);
    motor2.run(upward);
    motor3.setSpeed(255);
    motor3.run(upward);
}
// Function to move motors downward
void downward()
{
    motor1.setSpeed(255);
    motor1.run(downward);
    motor2.setSpeed(255);
    motor2.run(downward);
    motor3.setSpeed(255);
    motor3.run(downward);
}
// Function to stop all motors
void stopMotors()
{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}