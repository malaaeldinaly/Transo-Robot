#include <stdio.h>
#include <wiringPi.h>
#include "utils.h"
#include "sensors.h"
#include "motors.h"
#include "servo.h"

int main() {
    printf("Transo-Robot Project\n");

    wiringPiSetup(); // Initialize WiringPi

    initSensors();
    initMotors();
    initServo();

    while (1) {
        int lineStatus = readLineSensors();
        int markStatus = readMarkSensors();
        
        if (markStatus == 7) { // Detected significant mark (all sensors high)
            stop();
            liftServo();
            moveForward();
        } else if (markStatus == 0) { // Detected release mark (all sensors low)
            stop();
            lowerServo();
            moveBackward();
        } else {
            switch (lineStatus) {
                case 0b000: // No line detected
                    stop();
                    break;
                case 0b001: // Line detected on the right
                    rotateRight();
                    break;
                case 0b010: // Line detected in the center
                    moveForward();
                    break;
                case 0b011: // Line detected on the center and right
                    rotateRight();
                    break;
                case 0b100: // Line detected on the left
                    rotateLeft();
                    break;
                case 0b101: // Line detected on the left and right
                    moveForward();
                    break;
                case 0b110: // Line detected on the left and center
                    rotateLeft();
                    break;
                case 0b111: // Line detected on all sensors
                    moveForward();
                    break;
            }
        }
    }

    return 0;
}