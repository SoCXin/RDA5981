����˫console��˵����

1�� Ŀǰ������Ĭ��UART0Ϊlog�Ĵ�ӡ���ڣ����ڸ����û�����Ĳ�ͬ����Ҫ�û��ֶ��޸��ļ�\hal\targets\hal\target_rda\target_uno_91h\PeripheralNames.h��
    STDIO_UART_TX �� UART0_TX �ĳ� UART1_TX
    STDIO_UART_RX �� UART0_RX �ĳ� UART1_RX
    STDIO_UART    �� UART_0   �ĳ� UART_1

2���������ڶ�������ӦAT���AT����ο�AT_readme.txt;

3������1�����޸ģ��û�ʹ��printf������ӡ�ڴ���1���û�����ʹ��console_uart0_printf�Ӵ���0��ӡ;

4) ����case�ο�ָ�
   mbed compile -t ARM -m UNO_91H --source TESTS/TARGET_RDA/dual_console/ --source ./
   
5) Ĭ��RDA_AT_DEBUG�ĺ�򿪣�����û�����Ҫ�������йرա�