// Include the necessary libraries
#include <AFMotor.h>
// Define motor pins
#define motor1Pin1 2  // Connect to pin 2 on the motor shield for motor 1
#define motor1Pin2 4  // Connect to pin 4 on the motor shield for motor 1
#define motor2Pin1 7  // Connect to pin 7 on the motor shield for motor 2
#define motor2Pin2 8  // Connect to pin 8 on the motor shield for motor 2
#define motor3Pin1 12 // Connect to pin 12 on the motor shield for motor 3
#define motor3Pin2 13 // Connect to pin 13 on the motor shield for motor 3

// Create motor objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
void setup()
{
    // Set motor control pins as outputs
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(motor3Pin1, OUTPUT);
    pinMode(motor3Pin2, OUTPUT);
}
void loop()
{
    // Forward motion
    forward();
    delay(10000); // Adjust delay for desired speed
    // Stop after forward motion
    stopMotors();
    delay(2500); // Add a delay of 3 seconds
    // Backward motion
    backward();
    delay(10000);
    // Stop after backward motion
    stopMotors();
    delay(2500);
}
// Function to move motors forward

void forward()
{
    motor1.setSpeed(255); // Adjust speed as needed
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    motor3.setSpeed(255);
    motor3.run(FORWARD);
}
// Function to move motors backward
void backward()
{
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.setSpeed(255);
    motor2.run(BACKWARD);
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
}
// Function to stop all motors
void stopMotors()
{
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}