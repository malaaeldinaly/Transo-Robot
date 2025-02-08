#include <stdio.h>
#include "sensors.h"
#include "wiringPi.h" // Include the mock wiringPi.h

void test_sensors() {
    printf("Running test_sensors...\n");

    initSensors();
    int lineStatus = readLineSensors();
    int markStatus = readMarkSensors();

    printf("Line Status: %d\n", lineStatus);
    printf("Mark Status: %d\n", markStatus);
}

int main() {
    test_sensors();
    return 0;
}