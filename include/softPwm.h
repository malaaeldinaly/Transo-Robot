#ifndef SOFTPWM_H
#define SOFTPWM_H

void softPwmCreate(int pin, int initialValue, int pwmRange);
void softPwmWrite(int pin, int value);

#endif // SOFTPWM_H