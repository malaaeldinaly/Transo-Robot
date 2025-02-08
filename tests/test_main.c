#include <stdio.h>
#include "utils.h"
#include "sensors.h"
#include "motors.h"
#include "servo.h"
#include "wiringPi.h" // Include the mock wiringPi.h
#include "softPwm.h"  // Include the mock softPwm.h

void test_main() {
    printf("Running test_main...\n");

    wiringPiSetup(); // Initialize WiringPi

    initSensors();
    initMotors();
    initServo();

    // Simulate sensor readings and test the logic
    int lineStatus = 0b010; // Line detected in the center
    int markStatus = 7;     // Detected significant mark (all sensors high)

    if (markStatus == 7) {
        stop();
        liftServo();
        moveForward();
    } else if (markStatus == 0) {
        stop();
        lowerServo();
        moveBackward();
    } else {
        switch (lineStatus) {
            case 0b000:
                stop();
                break;
            case 0b001:
                rotateRight();
                break;
            case 0b010:
                moveForward();
                break;
            case 0b011:
                rotateRight();
                break;
            case 0b100:
                rotateLeft();
                break;
            case 0b101:
                moveForward();
                break;
            case 0b110:
                rotateLeft();
                break;
            case 0b111:
                moveForward();
                break;
        }
    }
}

int main() {
    test_main();
    return 0;
}