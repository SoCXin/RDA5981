�����һ��ʹ�ô�д����AT����\r\n��β��
���������ԡ�,���ָ����ַ������ֽ���ʹ�����ţ���ֹ�����������ʱ������AT+WSCONN=��a��,��qqqqqqqq��
δ������͵������Ϊִ�����ֱ��ִ�м��ɣ���AT+RST

�������ͣ�
�������AT+<x>=<...>  ��AT+WSMAC=123456789abc
��ѯ���AT+<x>=?		��AT+WSMAC=��
ִ�����AT+<x>		��AT+RST

����ֵ
+ok            			ִ�гɹ�
+ok=<...>				ִ�гɹ����з�����Ϣ
+error=err code			ִ��ʧ�ܲ����ش�����

err code��
�޴�ָ�	-1
������ִ�У�-2
ִ��ʧ�ܣ�	-3
�����д���-4


1.��������
1.1	AT 								����ATģʽ�Ƿ�ʹ��
1.2 AT+H							�鿴AT����
1.3	AT+RST 							����ģ��
1.4	AT+VER	 						�鿴����汾
1.5 AT+ECHO         				�򿪻��߹رմ��ڻ���
	AT+ECHO=1/0						1��ʾ�򿪣�0��ʾ�رգ�������Ĭ���Ǵ򿪵�

1.6 AT+WDBG							������ģ���debug level
	AT+WDBG=DRV,2					����driver debug level������Ϊ0~3��Ĭ��Ϊ0
	AT+WDBG=WPA,2					����wpa debug level������Ϊ0~3��Ĭ��Ϊ0
	AT+WDBG=DRVD,1					��/�ر�driver dump�����ӡ���շ������ݣ�1Ϊ�򿪣�0Ϊ�رգ�Ĭ��Ϊ�ر�
	AT+WDBG=WPAD,1					��/�ر�WPA dump�����ӡ��ĳЩ���ݣ�1Ϊ�򿪣�0Ϊ�رգ�Ĭ��Ϊ�ر�
	AT+WDBG=HUTD,1                  ��/�ر�HUT dump�����ӡ��ĳЩ���ݣ�����ÿ���Զ���ӡһ��RX���Խ����1Ϊ�򿪣�0Ϊ�رգ�Ĭ��Ϊ�ر�
		
2.efuse����
��ʼ��R��ʾRead��W��ʾWrite������E��ʾEfuse�����д���Ĳ���Ϊ����Ϊ16���ƣ�1��byte��
2.1 AT+RE                           ��ȡ����efuse����
	efuse��15��page��ÿ��page2��bytes���û����Զ���page2~15�����ݣ����������ݰ���[page2 byte0] [page2 byte1] [page3 byte0] ... [page15 byte1]���С�
			byte1		        	byte0	
	page0	rda_reserved			
	page1	rda_reserved			
	page2	usb pid			
	page3	usb vid			
	page4	mac address[4]			mac address[5]	
	page5	mac address[2]			mac address[3]	
	page6	mac address[0]			mac address[1]	
	page7	mac address[4]_bak		mac address[5]_bak	
	page8	mac address[2]_bak		mac address[3]_bak	
	page9	mac address[0]_bak		mac address[1]_bak	
	page10	crystal_cal_bak1		crystal_cal	
	page11	crystal_cal_bak3		crystal_cal_bak2	
	page12	rda_reserved:Bit[12~15]	Tx_power: Bit[6~11]:b mode Bit[0~5]:g/n mode		
	page13	rda_reserved:Bit[12~15]	Tx_power_bak1: Bit[6~11]:b mode Bit[0~5]:g/n mode		
	page14	rda_reserved:Bit[12~15]	Tx_power_bak2: Bit[6~11]:b mode Bit[0~5]:g/n mode		
	page15	rda_reserved:Bit[12~15]	Tx_power_bak3: Bit[6~11]:b mode Bit[0~5]:g/n mode		

2.2 AT+WTPE                         дtx power��efuse
	AT+WTPE=n1,n2
	n1Ϊ11g/nģʽ�µ�TX POWER����ΧΪ0x25~0x64��
	n2Ϊ11bģʽ�µ�TX POWER����ΧΪ0x15~0x54��
	���ٿ���д���ĴΡ�
	
2.3 AT+RTPE                         ��efuse��tx power
	���ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	
2.4 AT+WXCE                			д����У׼��efuse
	AT+WXCE=n1
	n1Ϊ1��byte��ȡbit7~bit1��bit0��Ч�����ٿ���д���ĴΡ�

2.5 AT+RXCE                			��efuse������У׼
	���ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	
2.6 AT+WMACE                        дMAC��ַ��efuse
	AT+WTPE=n1,n2,n3,n4,n5,n6
	n1�����λ����Ϊ0��n1~n6����ȫΪ0�����ٿ���д�����Ρ�
	
2.7 AT+RMACE                        ��efuse��MAC��ַ
	���ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��

3.RF�Ĵ���ͨ������
��ʼ��R��ʾRead��W��ʾWrite��AC��ʾ����All Channels��SC��ʾSingle Channel�����еļĴ�����ַ��ֵ����Ϊ16���ƣ�channel����Ϊ10���ơ�
�ڽ���Readʱ��_CUR��ʾ�ӼĴ�����ȡ��_DEF��ʾ��flash��ȡ������Writeʱ��_CUR��ʾֻд��Ĵ�����_DEF��ʾд��Ĵ�����ͬʱд��flash��
3.1 AT+WRF_CUR                      дRF�Ĵ������˼Ĵ�����channel�޹�
	AT+WRF_CUR=n1,n2
	n1,n2��Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2ΪҪд���ֵ��
	AT+WRF_CUR=0xDA,0x80

3.2 AT+WRF_DEF                      дRF�Ĵ������˼Ĵ�����channel�޹�
	AT+WRF_DEF=n1,n2
	n1,n2��Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2ΪҪд���ֵ��
	AT+WRF_DEF=0xDA,0x80	
	
3.3 AT+WRFAC_CUR                    дRF�Ĵ������˼Ĵ�����channel�й�
	AT+WRFAC_CUR=n1,n2,n3,...,n15
	n1~n15��Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2~n15����Ϊchannel1~14��ֵ��
	AT+WRFAC_CUR=0x8A,0x69A0,0x69A0,...,0x6820

3.4 AT+WRFAC_DEF                    дRF�Ĵ������˼Ĵ�����channel�й�
	AT+WRFAC_DEF=n1,n2,n3,...,n15
	n1~n15��Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2~n15����Ϊchannel1~14��ֵ��
	AT+WRFAC_DEF=0x8A,0x69A0,0x69A0,...,0x6820	
	
3.5 AT+WRFSC_CUR			        дRF�Ĵ�����ֻдĳ��channel��ֵ
	AT+WRFSC_CUR=n1,n2,n3
	n1��n3Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2Ϊchannel��n3ΪҪд���ֵ��
	AT+WRFSC_CUR=0x8A,1,0x69A0

3.6 AT+WRFSC_DEF			        дRF�Ĵ�����ֻдĳ��channel��ֵ
	AT+WRFSC_DEF=n1,n2,n3
	n1��n3Ϊhalf word��n1Ϊ�Ĵ�����ַ��n2Ϊchannel��n3ΪҪд���ֵ��
	AT+WRFSC_DEF=0x8A,1,0x69A0	
	
3.7 AT+RRF_CUR                      ��RF�Ĵ������˼Ĵ�����channel�޹�
	AT+RRF_CUR=n1
	n1Ϊ�Ĵ�����ַ��half word�����ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	AT+RRF_CUR=0xDA

3.8 AT+RRF_DEF                      ��RF�Ĵ������˼Ĵ�����channel�޹�
	AT+RRF_DEF=n1
	n1Ϊ�Ĵ�����ַ��half word�����ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	AT+RRF_DEF=0xDA	
	
3.9 AT+RRFAC_CUR                    ��RF�Ĵ������˼Ĵ�����channel�й�
	AT+RRFAC_CUR=n1
	n1Ϊ�Ĵ�����ַ��half word��
	AT+WRFAC_CUR=0x8A

3.10 AT+RRFAC_DEF                   ��RF�Ĵ������˼Ĵ�����channel�й�
	AT+RRFAC_DEF=n1
	n1Ϊ�Ĵ�����ַ��half word��
	AT+WRFAC_DEF=0x8A	
	
3.11 AT+RRFSC_CUR				    ��RF�Ĵ�����ֻ��ĳ��channel��ֵ
	AT+WRFSC_CUR=n1,n2
	n1Ϊ�Ĵ�����ַ��half word��n2Ϊchannel��
	AT+WRFSC_CUR=0x8A,1

3.12 AT+RRFSC_DEF				    ��RF�Ĵ�����ֻ��ĳ��channel��ֵ
	AT+WRFSC_DEF=n1,n2
	n1Ϊ�Ĵ�����ַ��half word��n2Ϊchannel��
	AT+WRFSC_DEF=0x8A,1	

3.13 AT+DRF				            dump flash�б����RF�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�޹�

3.14 AT+DRFAC				        dump flash�б����RF�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�й�

3.15 AT+ERF				    		����flash�б����RF�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�޹�
	AT+ERF=n1
	n1Ϊ�Ĵ�����ַ��half word��
	AT+ERF=0xDA

3.16 AT+ERFAC				        ����flash�б����RF�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�й�
	AT+ERF=n1
	n1Ϊ�Ĵ�����ַ��half word��
	AT+ERFAC=0x8A
	
4. PHY�Ĵ���ͨ������
��ʼ��R��ʾRead��W��ʾWrite��ALL��ʾ����All Channels��SC��ʾSingle Channel�����еļĴ�����ַ��ֵ����Ϊ16���ƣ�channel����Ϊ10���ơ�
�ڽ���Readʱ��_CUR��ʾ�ӼĴ�����ȡ��_DEF��ʾ��flash��ȡ������Writeʱ��_CUR��ʾֻд��Ĵ�����_DEF��ʾд��Ĵ�����ͬʱд��flash��
4.1 AT+WPHY_CUR                     дPHY�Ĵ������˼Ĵ�����channel�޹�
	AT+WPHY_CUR=n1,n2
	n1,n2��Ϊword��n1Ϊ�Ĵ�����ַ��n2ΪҪд���ֵ��
	AT+WPHY_CUR=0x11F,0x45

4.2 AT+WPHY_DEF                     дPHY�Ĵ������˼Ĵ�����channel�޹�
	AT+WPHY_DEF=n1,n2
	n1,n2��Ϊword��n1Ϊ�Ĵ�����ַ��n2ΪҪд���ֵ��
	AT+WPHY_DEF=0x11F,0x45	
	
4.3 AT+WPHYAC_CUR                   дPHY�Ĵ������˼Ĵ�����channel�й�
	AT+WPHYAC_CUR=n1,n2,n3,...,n15
	n1~n15��Ϊword��n1Ϊ�Ĵ�����ַ��n2~n15����Ϊchannel1~14��ֵ��

4.4 AT+WPHYAC_DEF                   дPHY�Ĵ������˼Ĵ�����channel�й�
	AT+WPHYAC_DEF=n1,n2,n3,...,n15
	n1~n15��Ϊword��n1Ϊ�Ĵ�����ַ��n2~n15����Ϊchannel1~14��ֵ��
	
4.5 AT+WPHYSC_CUR			        дPHY�Ĵ�����ֻдĳ��channel��ֵ
	AT+WPHYSC_CUR=n1,n2,n3
	n1��n3Ϊword��n1Ϊ�Ĵ�����ַ��n2Ϊchannel��n3ΪҪд���ֵ��

4.6 AT+WPHYSC_DEF			        дPHY�Ĵ�����ֻдĳ��channel��ֵ
	AT+WPHYSC_DEF=n1,n2,n3
	n1��n3Ϊword��n1Ϊ�Ĵ�����ַ��n2Ϊchannel��n3ΪҪд���ֵ��
	
4.7 AT+RPHY_CUR                     ��PHY�Ĵ������˼Ĵ�����channel�޹�
	AT+RPHY_CUR=n1
	n1Ϊ�Ĵ�����ַ��word�����ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	AT+RPHY_CUR=0x11F

4.8 AT+RPHY_DEF                     ��PHY�Ĵ������˼Ĵ�����channel�޹�
	AT+RPHY_DEF=n1
	n1Ϊ�Ĵ�����ַ��word�����ص����ݸ�ʽ��д������ݸ�ʽ��ͬ��
	AT+RPHY_DEF=0x11F	
	
4.9 AT+RPHYAC_CUR                   ��PHY�Ĵ������˼Ĵ�����channel�й�
	AT+RPHYAC_CUR=n1
	n1Ϊ�Ĵ�����ַ��word��

4.10 AT+RPHYAC_DEF                  ��PHY�Ĵ������˼Ĵ�����channel�й�
	AT+RPHYAC_DEF=n1
	n1Ϊ�Ĵ�����ַ��word��
	
4.11 AT+RPHYSC_CUR				    ��PHY�Ĵ�����ֻ��ĳ��channel��ֵ
	AT+WPHYSC_CUR=n1,n2
	n1Ϊ�Ĵ�����ַ��word��n2Ϊchannel��

4.12 AT+RPHYSC_DEF				    ��PHY�Ĵ�����ֻ��ĳ��channel��ֵ
	AT+WPHYSC_DEF=n1,n2
	n1Ϊ�Ĵ�����ַ��word��n2Ϊchannel��

4.13 AT+DPHY				        dump flash�б����PHY�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�޹�

4.14 AT+DPHYAC				        dump flash�б����PHY�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�й�

4.15 AT+EPHY				        ����flash�б����PHY�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�޹�
	AT+EPHY=n1
	n1Ϊ�Ĵ�����ַ��word��
	AT+EPHY=0x11F

4.16 AT+EPHYAC				        ����flash�б����PHY�Ĵ��������Ӧ��ֵ����Щ�Ĵ�����channel�й�
	AT+EPHYAC=n1
	n1Ϊ�Ĵ�����ַ��word��
	
5. ��дMAC��ַ����
��ʼ��R��ʾRead��W��ʾWrite����дMAC��ַ�Ƚ����⣬_DEFֻд��flash��ֻ��flash��ȡ��
MAC��ַ����Ϊ16���ơ�

5.1 AT+WMAC_DEF                     дMAC��ַ��ֻд��flash
	AT+WMAC_DEF=n1,n2,n3,n4,n5,n6
	n1~n6ΪMAC��ַ����Ϊ1��byte��
	AT+WMAC_DEF=0x64,0x20,0xAB,0xC1,0x1D,0x34
	
5.2 AT+RMAC_DEF					    ��MAC��ַ����flash�ж�ȡ

6. HUTģʽ���շ���������
���еĲ�������10���Ƶ�
6.1 AT+TXSTART						��ʼTX����
	AT+TXSTART=n1,n2,n3,n4,n5,n6
	n1�����ŵ���ȡֵ��Χ1~14��
	n2��ģʽ��0����b/g mode��1����11n green field mode��2����11n mixed mode��
	n3���ŵ�����0����20M��1����40M��
	n4: �źŴ���0����ȫ40M��1�������ŵ�Ϊupper��2����20M��3�������ŵ�Ϊlower��
	n5�����ʣ�11b/gģʽȡֵΪ1 2 5 6 9 11 12 18 24 36 48 54��11nģʽȡֵΪ0~7������mcs0��mcs7��
	n6�����Ͱ�������λΪbyte��
	ע�⣺���ŵ�����Ϊ40mʱ�������ŵ�Ϊ1~4���źŴ���ֻ��ѡ��0����3�������ŵ�Ϊ10~13���źŴ���ֻ��ѡ��0����1�� 
	AT+TXSTART=1,0,0,2,54,1024
	
6.2 AT+TXSTOP						ֹͣTX����

6.3 AT+TXRESTART				    �����ϴε��������¿�ʼTX����
	������һ�β���ΪTX���Բ���Ч
	
6.4 AT+RXSTART						��ʼRX����
	AT+TXSTART=n1,n2,n3,n4
	n1~n4�Ķ�����6.1��ͬ��RX���Բ���Ҫ�������ʺͰ�����
	AT+RXSTART=1,0,0,2

6.5 AT+RXSTOP						ֹͣRX����

6.6 AT+RXRESULT						��ȡRX���Խ��
	�жϴ�ӡ��time:n1 recv:n2 fcs_passed:n3 per:n4
	n1Ϊ���Ե�ʱ�䣬n2Ϊ�ӿ�ʼ���Ե���ȡ����ڼ��յ����ܵ���������n3Ϊn2��fcs pass����������n4Ϊfcs pass�İٷֱȡ�

6.7 AT+RXRESTART				    �����ϴε��������¿�ʼRX����
	������һ�β���ΪRX���Բ���Ч

6.8 AT+WTPOFS_DEF                   дtx power g/nƫ�ã�g > n��д��flash
	AT+WTPOFS_DEF=n1
	n1ȡֵ��Χ0~16

6.9 AT+RTPOFS_DEF                   ��tx power g/nƫ�ã���flash��ȡ
