#include <wiringPi.h>
#include "motors.h"

#define MOTOR_PIN_1 6
#define MOTOR_PIN_2 7
#define MOTOR_PIN_3 8
#define MOTOR_PIN_4 9

void initMotors() {
    wiringPiSetup();
    pinMode(MOTOR_PIN_1, OUTPUT);
    pinMode(MOTOR_PIN_2, OUTPUT);
    pinMode(MOTOR_PIN_3, OUTPUT);
    pinMode(MOTOR_PIN_4, OUTPUT);
}

void moveForward() {
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
    digitalWrite(MOTOR_PIN_3, HIGH);
    digitalWrite(MOTOR_PIN_4, LOW);
}

void moveBackward() {
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, HIGH);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH);
}

void stop() {
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, LOW);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, LOW);
}

void rotateLeft() {
    digitalWrite(MOTOR_PIN_1, LOW);
    digitalWrite(MOTOR_PIN_2, HIGH);
    digitalWrite(MOTOR_PIN_3, HIGH);
    digitalWrite(MOTOR_PIN_4, LOW);
}

void rotateRight() {
    digitalWrite(MOTOR_PIN_1, HIGH);
    digitalWrite(MOTOR_PIN_2, LOW);
    digitalWrite(MOTOR_PIN_3, LOW);
    digitalWrite(MOTOR_PIN_4, HIGH);
}