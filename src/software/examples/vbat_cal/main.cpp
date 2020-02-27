#include "mbed.h"
#include "rda5981_flash.h"

/* Supported pins: ADC_PIN0, ADC_PIN1(U02)/ADC_PIN1A(U04), ADC_PIN2(VBAT) */
mbed::AnalogIn ain(ADC_PIN0);
//float k = 0;
//float b = 0;
float volt = 0;
//float voltage = 0;

int main(void)
{
    printf("Start VBAT test...\r\n");
//    int ret = rda5981_flash_read_vbat_cal(&k, &b);
//    printf("ret=%d, k=%1.5f, b=%1.5f\r\n", ret, k, b);

    while (true) {
//    	float fval = ain.read();
        unsigned short ival = ain.read_u16();
//        voltage = k * ival + b;
        /* Print the percentage and 16-bit normalized values */
        printf("normalized: 0x%04X\r\n", ival);
//        printf("percentage: %3.3f%%\r\n", fval*100.0f);
        printf("volt: %1.5fV \r\n", (ival * 1.98f) / 1024.0f);
//        printf("volatage: %1.5f\r\n\r\n", voltage);
        Thread::wait(1000);
    }
}

