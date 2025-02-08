#include <stdio.h>
#include "servo.h"
#include "wiringPi.h" // Include the mock wiringPi.h
#include "softPwm.h"  // Include the mock softPwm.h

void test_servo() {
    printf("Running test_servo...\n");

    initServo();
    liftServo();
    lowerServo();
}

int main() {
    test_servo();
    return 0;
}