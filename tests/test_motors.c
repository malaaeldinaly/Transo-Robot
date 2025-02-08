#include <stdio.h>
#include "motors.h"
#include "wiringPi.h" // Include the mock wiringPi.h

void test_motors() {
    printf("Running test_motors...\n");

    initMotors();
    moveForward();
    moveBackward();
    stop();
    rotateLeft();
    rotateRight();
}

int main() {
    test_motors();
    return 0;
}