#include "mbed.h"
#include "rtos.h"

#include "WiFiStackInterface.h"
#include "rda_sys_wrapper.h"
#include "rda5981_sniffer.h"

#define BUF_LENGTH           1024

UDPSocket udpsocket;
uint16_t local_port = 6000;
char rx_buffer[BUF_LENGTH] = {0};

int main(void) {
	int rLen;
	SocketAddress addr("192.168.22.1", 6000);

	WiFiStackInterface wifi;
	printf("Start wifi AP test ...\r\n");

	wifi.init();
	/* - 1 -
	wifi.set_dhcp(true);
	wifi.set_network("192.168.22.1", "255.255.255.0", "192.168.22.1");
	*/
	/* - 2 - */
	wifi.set_network_ap("192.168.22.1", "255.255.255.0", "192.168.22.1", "192.168.22.50", "192.168.22.100");
	wifi.start_ap((const char *)"kyChu_RDA_Wifi", (const char *)"123456789", 6, 0);

	/* udp create */
	udpsocket.open(&wifi);
	udpsocket.bind(local_port);
	printf("UDP Trans start. \r\n");

	if (!addr) {
		printf("address error\r\n");
		while(1);
	}
	memset(rx_buffer, 0, BUF_LENGTH);

	do {
		rLen = udpsocket.recvfrom(&addr,(void *) rx_buffer, BUF_LENGTH);
		if (rLen <= 0) {
			printf("ERROR: UDP recv error, len is %d .\r\n", rLen);
			break;
		} else {
//			rx_buffer[rLen] = 0;
//			printf("recv: %s .\r\n", rx_buffer);
		}

		rLen = udpsocket.sendto(addr, rx_buffer, rLen);
		wait(0.01);
		if (rLen <= 0) {
			printf("ERROR:UDP send error, len is %d .\r\n", rLen);
			break;
		}
	} while(1);
	udpsocket.close();
	while(1);
}
