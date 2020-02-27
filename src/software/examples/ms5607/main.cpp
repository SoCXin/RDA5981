#include "mbed.h"

/* I2C Pins: sda, scl */
I2C i2c(PB_2, PB_3);

static const uint8_t I2C_ADDR = 0xEC;

static uint16_t CalibData[8];
static uint32_t TempRaw = 0x00;
static uint32_t PresRaw = 0x00;
static int32_t TempUnitData = 0;
static int32_t PresUnitData = 0;

static int ms5607_reset(void);
static int ms5607_start_pressure(void);
static int ms5607_start_temperature(void);
static int ms5607_read_adc_raw(uint32_t *pbuf);
static void ms5607_calculate(int32_t *p, int32_t *t);
static int I2C_ReadPROM(uint8_t offset, uint16_t *pbuf);

int main()
{
	int ret = 0;
	uint8_t idx = 0;
    printf("Start I2C test...\r\n");

    /* reset device */
    if(ms5607_reset() != 0) {
    	ret = -1;
    	printf("ms5607 reset failed! \r\n");
    } else {
    	wait_ms(20);
    	for(idx = 0; idx < 8; idx ++) {
    		if(I2C_ReadPROM(idx, CalibData + idx) != 0) {
    			ret = -1;
    			printf("read prom %d failed! \r\n", idx);
    		}
    	}
    }

    idx = 0;

    if(ret == 0) {
		while(true) {
			wait_ms(20);
			ms5607_read_adc_raw(&PresRaw);
			ms5607_start_temperature();
			ms5607_calculate(&PresUnitData, &TempUnitData);
			wait_ms(20);
			ms5607_read_adc_raw(&TempRaw);
			ms5607_start_pressure();
			ms5607_calculate(&PresUnitData, &TempUnitData);
			idx ++;
			if(idx >= 20) {
				idx = 0;
				printf("pres = %d, temp = %d .\r\n", PresUnitData, TempUnitData);
			}
		}
    } else {
    	while(true) {
    		wait_ms(500);
    		printf("init failed!, keep reset ... \r\n");
    		ms5607_reset();
    	}
    }
    for(;;);
}

static void ms5607_calculate(int32_t *p, int32_t *t)
{
	uint32_t press;
	int64_t delta = 0, T2 = 0;
	int32_t dT = (int64_t)TempRaw - ((uint64_t)CalibData[5] << 8);
	int64_t off = ((int64_t)CalibData[2] << 17) + (((int64_t)CalibData[4] * dT) >> 6);
	int64_t sens = ((int64_t)CalibData[1] << 16) + (((int64_t)CalibData[3] * dT) >> 7);
	int64_t temp = 2000 + ((dT * (int64_t)CalibData[6]) >> 23);
	if(temp < 2000) {
		T2 = dT;
		T2 *= T2;
		T2 >>= 31;
		delta = temp - 2000;
		delta *= delta;
		off -= (61 * delta) >> 4;
		sens -= delta << 1;
		if(temp < -1500) {
			delta = temp + 1500;
			delta *= delta;
			off += 15 * delta;
			sens += delta << 3;
		}
	}
	press = ((((int64_t)PresRaw * sens) >> 21) - off) >> 15;
	temp -= T2;
	*p = press;
	*t = temp;
}

static int ms5607_reset(void)
{
	uint8_t cmd = 0x1E;
	return i2c.write(I2C_ADDR, (const char *)&cmd, 1);
}

static int ms5607_start_pressure(void)
{
	int8_t cmd = 0x48;
	return i2c.write(I2C_ADDR, (const char *)&cmd, 1);
}

static int ms5607_start_temperature(void)
{
	uint8_t cmd = 0x58;
	return i2c.write(I2C_ADDR, (const char *)&cmd, 1);
}

static int ms5607_read_adc_raw(uint32_t *pbuf)
{
	int ret = 0;
	uint8_t addr = 0x00;
	uint8_t rxbuf[3];
	if((ret = i2c.write(I2C_ADDR, (const char *)&addr, 1, true)) != 0) return ret;
	if((ret = i2c.read(I2C_ADDR | 0x01, (char *)rxbuf, 3, false)) != 0) return ret;
	pbuf[0] = (rxbuf[0] << 16) | (rxbuf[1] << 8) | rxbuf[2];
	return ret;
}

static int I2C_ReadPROM(uint8_t offset, uint16_t *pbuf)
{
	int ret = 0;
	uint8_t rxbuf[2] = {0, 0};
	uint8_t addr = 0xA0 + offset * 2;
	if((ret = i2c.write(I2C_ADDR, (const char *)&addr, 1, true)) != 0) return ret;
	if((ret = i2c.read(I2C_ADDR | 0x01, (char *)rxbuf, 2, false)) != 0) return ret;
	pbuf[0] = (rxbuf[0] << 8) | rxbuf[1];
	return ret;
}
