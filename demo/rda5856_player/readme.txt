RDA5856����˾��һ��BT��֧��BLE��+CODECоƬ��Ŀǰ֧��mp3��aac��m4a��wav��ts���Ĳ��ţ�8K��16K������¼����

1��rda58xx.h��rda58xx.cpp�ṩֱ�Ӳ���RDA5856�Ľӿڣ�class rda58xx����player.h��player.cpp�ṩ��Ӳ���RDA5856�Ľӿڣ�class Player����
2������Ĭ�Ͻ���CODECģʽ�����ȵ���Player::isReady����rda58xx::isReady��ֱ������true�ſ��Զ�RDA5856���в�����
3������player::begin��ɨ��SD����Ŀ¼�����Ƶ�ļ������ļ��������list�У�Ĭ����ౣ��16�ף��ļ����32���ֽڣ������и��ġ�
4������player::playFile������Ƶ�ļ�������Ĳ���Ϊ�ļ���·������"a.mp3"��
5������player::recordFile��ʼ¼��������Ĳ���Ϊ�ļ���·������"a.wav"��

�������̣�
1������rda58xx::bufferReq(mci_type_enum ftype, uint16_t size, uint16_t threshold)��ʼ���š�
����ftypeΪ��Ƶ���ͣ�sizeΪ��RDA5856�����buffer��С��Ŀǰ���Ϊ8K�ֽڡ�
thresholdΪRDA5856��ʼ����ǰ���յ�������������������Ϊ4K����RDA5856�ڽ��յ�>4K���ݺ�ſ�ʼ���š�
2��ѭ������rda58xx::sendRawData(uint8_t *databuf, uint16_t n)��RDA5856������Ƶ���ݡ�
����*databufΪ����ָ�룬nΪ����������Ŀǰn���Ϊ2K��
3��������Ϻ󣬵���rda58xx::stopPlay(rda58xx_stop_type stype)ֹͣ���š�
stypeΪֹͣ���ŵ�ģʽ��Ŀǰ��WITH_ENDING��WITTOUT_ENDING���֡�
WITH_ENDINGģʽ��RDA5856�Ὣ��buffer�ڻ�������ݲ�����ϡ�
����ͨ������rda58xx::getCodecStatus��ȷ����״̬�������״̬һֱδPLAY����˵����δ������ϡ�
WITHOUT_ENDINGģʽ��RDA5856��ֱ��ֹͣ���ţ���buffer�ڻ�������ݻᱻ������
ע�⣺m4a��װ��aac����Ҫ��ת����ADTS��ʽ���ٷ��͸�RDA5856��Player::m4aPlay�ṩ��ת��������

¼�����̣�
1������rda58xx::startRecord(mci_type_enum ftype, uint16_t size, uint16_t sampleRate)��ʼ¼����
����ftypeΪ��Ƶ���ͣ�Ĭ��Ϊwav��sizeΪ����buffer��С��Ĭ��640�ֽڣ�sampleRateΪ�����ʣ���������8K����16K��Ĭ��Ϊ8K��
2��������buffer״̬ΪFULLʱ��ȡ��buffer�ڵ����ݣ�������buffer״̬ΪEMPTY��
if (FULL == rda5856.getBufferStatus()) {
	rda5856.clearBufferStatus();
    fp->write(rda5856.getBufferAddr(), rda5856.getBufferSize());
	fileSize += rda5856.getBufferSize();
}
3������rda58xx::stopRecord(void)ֹͣ¼����
ע�⣺���Ҫ����MIC���棬�ڿ�ʼ¼��ǰ����rda58xx::setMicGain(uint8_t gain)������gainΪ¼�����棬���ֵΪ12��

