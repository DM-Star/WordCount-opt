#include "WordState.h"



WordState::WordState()
{
	state = OUTERWORD;
}


processType WordState::stateTransfer(char c) {
	//传进一个字符，根据这个字符和当前状态计算下一个状态，并返回一个process，指明状态是如何迁移的。 
	processType process = state << 4;

	//在下方添加状态迁移的代码


	//在上方添加状态迁移的代码，其他代码不要动

	process = process | state;
	return process;
}