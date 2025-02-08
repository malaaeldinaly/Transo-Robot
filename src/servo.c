#include <wiringPi.h>
#include <softPwm.h>
#include "servo.h"

#define SERVO_PIN 8

void initServo() {
    wiringPiSetup();
    softPwmCreate(SERVO_PIN, 0, 200);
}

void liftServo() {
    softPwmWrite(SERVO_PIN, 15); // Adjust value as needed
    delay(1000); // Adjust delay as needed
}

void lowerServo() {
    softPwmWrite(SERVO_PIN, 5); // Adjust value as needed
    delay(1000); // Adjust delay as needed
}