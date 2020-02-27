#include "mbed.h"

/* SPI Pins: mosi, miso, sclk, ssel */
SPI spi(PC_0, PC_1, PB_4, NC);//PB_5//NC

DigitalOut SPI_CS(PB_5, 1);

//static uint8_t mpu_tx_buffer[15] = {0};
//static uint8_t mpu_rx_buffer[15] = {0};

static uint8_t mpu_id = 0xFF; /* mpu_id = 0x70 */

static void mpu6500_init(void);
static void mpu_write_reg(uint8_t reg, uint8_t val);
static void mpu_read_reg_util(uint8_t reg, uint8_t num, uint8_t *r);

int main()
{
	int t = 0;
    printf("Start SPI test...\r\n");

    /* Setup the spi for 8 bit data, high state clock, */
    /* second edge capture, with a 4MHz clock rate (max spi rate on this board, need more test!!!) */
    spi.format(8, 1);
    spi.frequency(4000000);

    wait(0.5f);
    mpu6500_init();
    while(true) {
    	mpu_read_reg_util(0x75, 1, (uint8_t *)&mpu_id);
    	wait_ms(10);
    	t ++;
    	if(t >= 100) {
    		t= 0;
    		printf("mpu6500 id = 0x%x .\r\n", mpu_id);
    	}
    }
}

static void mpu6500_init(void)
{
	mpu_write_reg(0x6B, 0x80);
	wait_ms(10);
	mpu_write_reg(0x68, 0x07);
	mpu_write_reg(0x6B, 0x00);
	wait_ms(10);
	mpu_write_reg(0x19, 0x00);
	mpu_write_reg(0x1A, 0x03);
	mpu_write_reg(0x1D, 0x06);
	mpu_write_reg(0x1C, 0x10);
	mpu_write_reg(0x1B, 0x18);
	wait_ms(1);
	mpu_read_reg_util(0x75, 1, (uint8_t *)&mpu_id);
	printf("mpu6500 id = 0x%x .\r\n", mpu_id);
}

static void mpu_write_reg(uint8_t reg, uint8_t val)
{
	SPI_CS.write(0);
	spi.write(reg);
	spi.write(val);
	SPI_CS.write(1);
}

static void mpu_read_reg_util(uint8_t reg, uint8_t num, uint8_t *r)
{
	SPI_CS.write(0);
	uint8_t i = 0;
	spi.write(reg | 0x80);
	for(i = 0; i < num; i ++) {
		r[i] = spi.write(0xFF);
	}
	SPI_CS.write(1);
}
