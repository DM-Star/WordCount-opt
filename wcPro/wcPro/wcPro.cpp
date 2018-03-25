#include<iostream>
#include<fstream>

#include"WordState.h"
#include"WordList.h"
using namespace std;

void wordCount(char *fileName, WordList &wordList);		//���ڴ�Ƶͳ��
void outPut(char outFile[], WordList &wordList);		//����������

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
			//���ݲ�ͬ״̬������ͬ����Ӧ 
		case PROCESS_23:
			//ɾȥ���һ���ַ��Լ�ǰһ�����ʷ���������++ 
			word[wordPosition - 2] = 0;
			wordList.addWord(word);
			wordPosition = 0;
			break;
		case PROCESS_13:
			//ɾȥ���һ���ַ���������++ 
			word[wordPosition - 1] = 0;
			wordList.addWord(word);
			wordPosition = 0;
			break;
		case PROCESS_33:
			//�����ⲿ-�����ⲿ��wordPosition���� 
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