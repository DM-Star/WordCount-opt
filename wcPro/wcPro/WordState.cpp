#include "WordState.h"



WordState::WordState()
{
	state = OUTERWORD;
}


processType WordState::stateTransfer(char c) {
	//����һ���ַ�����������ַ��͵�ǰ״̬������һ��״̬��������һ��process��ָ��״̬�����Ǩ�Ƶġ� 
	processType process = state << 4;

	//���·����״̬Ǩ�ƵĴ���


	//���Ϸ����״̬Ǩ�ƵĴ��룬�������벻Ҫ��

	process = process | state;
	return process;
}