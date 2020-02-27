#include "mbed.h"
#include "rtos.h"

PwmOut pwm0(PD_0);
PwmOut pwm1(PD_1);
PwmOut pwm2(PD_2);
PwmOut pwm3(PD_3);

int main() {
    pwm0.period_rate(10000); /* set period rate to 10KHz. */
    pwm0.dutycycle(100);
    pwm1.period_rate(10000); /* set period rate to 10KHz. */
    pwm1.dutycycle(200);
    pwm2.period_rate(10000); /* set period rate to 10KHz. */
    pwm2.dutycycle(300);
    pwm3.period_rate(10000); /* set period rate to 10KHz. */
    pwm3.dutycycle(400);

    while(true) {
        printf("duty=%f\r\n", pwm0.read());
//        printf("base_clk = %d\r\n", (&(pwm0._pwm))->base_clk);
        Thread::wait(500);
    }
}
