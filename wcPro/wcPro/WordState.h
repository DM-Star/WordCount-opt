#pragma once

//����һ������״̬�����࣬���������ܴ���Ե���д��һ���ļ� 
//����ͬ״̬���к궨�� 
#define		INNERWORD		1			//״̬һ�������ڲ� 
#define		CRITICAL		2			//״̬�����ٽ磨�յ�һ�����ʷ��� 
#define		OUTERWORD		3			//״̬���������ⲿ 
typedef	int stateType;

#define		PROCESS_11		0x11			//���̣�״̬һ  ��  ״̬һ 
#define		PROCESS_12		0x12			//���̣�״̬һ  ��  ״̬�� 
#define		PROCESS_13		0x13			//���̣�״̬һ  ��  ״̬�� 
#define		PROCESS_21		0x21			//���̣�״̬��  ��  ״̬һ 
#define		PROCESS_23		0x23			//���̣�״̬��  ��  ״̬�� 
#define		PROCESS_31		0x31			//���̣�״̬��  ��  ״̬һ 
#define		PROCESS_33		0x33			//���̣�״̬��  ��  ״̬��
typedef int processType;

class WordState {
private:
	stateType state;
public:
	WordState();
	processType  stateTransfer(char c);
};
