#pragma once

//这是一个有限状态机的类，这个类如果很大可以单独写成一个文件 
//将不同状态进行宏定义 
#define		INNERWORD		1			//状态一：单词内部 
#define		CRITICAL		2			//状态二：临界（收到一个连词符） 
#define		OUTERWORD		3			//状态三：单词外部 
typedef	int stateType;

#define		PROCESS_11		0x11			//过程：状态一  到  状态一 
#define		PROCESS_12		0x12			//过程：状态一  到  状态二 
#define		PROCESS_13		0x13			//过程：状态一  到  状态三 
#define		PROCESS_21		0x21			//过程：状态二  到  状态一 
#define		PROCESS_23		0x23			//过程：状态二  到  状态三 
#define		PROCESS_31		0x31			//过程：状态三  到  状态一 
#define		PROCESS_33		0x33			//过程：状态三  到  状态三
typedef int processType;

class WordState {
private:
	stateType state;
public:
	WordState();
	processType  stateTransfer(char c);
};
