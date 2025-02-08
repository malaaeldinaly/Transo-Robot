#ifndef WIRINGPI_H
#define WIRINGPI_H

#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

void wiringPiSetup();
void pinMode(int pin, int mode);
int digitalRead(int pin);
void digitalWrite(int pin, int value);
void delay(int milliseconds);

#endif // WIRINGPI_H