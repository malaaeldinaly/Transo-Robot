#include <stdio.h>
#include "wiringPi.h"
#include "softPwm.h"

void wiringPiSetup() {
    printf("Mock: wiringPiSetup called\n");
}

void pinMode(int pin, int mode) {
    printf("Mock: pinMode called with pin=%d, mode=%d\n", pin, mode);
}

int digitalRead(int pin) {
    printf("Mock: digitalRead called with pin=%d\n", pin);
    return 0; // Return a simulated value
}

void digitalWrite(int pin, int value) {
    printf("Mock: digitalWrite called with pin=%d, value=%d\n", pin, value);
}

void delay(int milliseconds) {
    printf("Mock: delay called with milliseconds=%d\n", milliseconds);
}

void softPwmCreate(int pin, int initialValue, int pwmRange) {
    printf("Mock: softPwmCreate called with pin=%d, initialValue=%d, pwmRange=%d\n", pin, initialValue, pwmRange);
}

void softPwmWrite(int pin, int value) {
    printf("Mock: softPwmWrite called with pin=%d, value=%d\n", pin, value);
}