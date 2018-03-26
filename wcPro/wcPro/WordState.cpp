#include "WordState.h"



WordState::WordState()
{
	state = OUTERWORD;
}


processType WordState::stateTransfer(char c) {
	//����һ���ַ�����������ַ��͵�ǰ״̬������һ��״̬��������һ��process��ָ��״̬�����Ǩ�Ƶġ� 
	processType process = state << 4;

	//���·����״̬Ǩ�ƵĴ���
	if ((c >= 'a') && (c <= 'z')) state = INNERWORD;
	else if (c == '-'){
		if (state == INNERWORD) state = CRITICAL;
		else state = OUTERWORD;
	}
	else state = OUTERWORD;
	//���Ϸ����״̬Ǩ�ƵĴ��룬�������벻Ҫ��

	process = process | state;
	return process;
}