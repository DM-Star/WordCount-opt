#include<iostream>
#include<fstream>

#include"WordState.h"
#include"WordList.h"
using namespace std;

void wordCount(char *fileName, WordList &wordList);		//用于词频统计
void outPut(char outFile[], WordList &wordList);		//用于输出结果

int main(int argc, char **argv) {
	WordList wordList;

	wordCount("wcPro.cpp", wordList);
	outPut("result.txt", wordList);

	return 0;
}

void wordCount(char *fileName, WordList &wordList) {
	char word[MAX_WORD_LEN];
	WordState wordState;
	processType process;

	ifstream in;
	in.open(fileName);

	int wordPosition = 0;
	bool flag = true;
	do {
		flag = (word[wordPosition] = in.get()) != EOF;

		process = wordState.stateTransfer(word[wordPosition]);
		switch (process) {
			//根据不同状态做出不同的响应 
		case PROCESS_23:
			//删去最后一个字符以及前一个连词符，单词数++ 
			word[wordPosition - 1] = 0;
			wordList.addWord(word);
			wordPosition = 0;
			break;
		case PROCESS_13:
			//删去最后一个字符，单词数++ 
			word[wordPosition] = 0;
			wordList.addWord(word);
			wordPosition = 0;
			break;
		case PROCESS_33:
			//单词外部-单词外部，wordPosition不变 
			break;
		default:
			wordPosition++;
		}
	} while (flag);

	in.close();
}

void outPut(char outFile[], WordList &wordList) {
	ofstream outf(outFile);
	streambuf *default_buf = cout.rdbuf();
	cout.rdbuf(outf.rdbuf());

	wordList.outPut();

	cout.rdbuf(default_buf);
}