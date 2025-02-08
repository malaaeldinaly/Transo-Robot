#include "sensors.h"
#include <wiringPi.h>

#define LINE_SENSOR_PIN_1 0
#define LINE_SENSOR_PIN_2 1
#define LINE_SENSOR_PIN_3 2

#define MARK_SENSOR_PIN_1 3
#define MARK_SENSOR_PIN_2 4
#define MARK_SENSOR_PIN_3 5

void initSensors() {
    wiringPiSetup();
    pinMode(LINE_SENSOR_PIN_1, INPUT);
    pinMode(LINE_SENSOR_PIN_2, INPUT);
    pinMode(LINE_SENSOR_PIN_3, INPUT);
    pinMode(MARK_SENSOR_PIN_1, INPUT);
    pinMode(MARK_SENSOR_PIN_2, INPUT);
    pinMode(MARK_SENSOR_PIN_3, INPUT);
}

int readLineSensors() {
    int sensor1 = digitalRead(LINE_SENSOR_PIN_1);
    int sensor2 = digitalRead(LINE_SENSOR_PIN_2);
    int sensor3 = digitalRead(LINE_SENSOR_PIN_3);
    return (sensor1 << 2) | (sensor2 << 1) | sensor3;
}

int readMarkSensors() {
    int sensor1 = digitalRead(MARK_SENSOR_PIN_1);
    int sensor2 = digitalRead(MARK_SENSOR_PIN_2);
    int sensor3 = digitalRead(MARK_SENSOR_PIN_3);
    return (sensor1 << 2) | (sensor2 << 1) | sensor3;
}