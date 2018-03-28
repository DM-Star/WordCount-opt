#pragma once
#include<iostream>
#include <cstring>
using namespace std;

#define		MAX_WORD_LEN	20

//����ṹ�����ڴ洢���ʺʹ�Ƶ 
struct Word {
	char word[MAX_WORD_LEN];
	int num;
	Word *next;
	Word *previous;
	
	//��������ȷ�������ݽṹ���ͣ������Լ�������ýṹ�� 
	//��������ȷ�������ݽṹ���ͣ��޸Ĺ��캯�� 
	Word() {
		word[0] = 0;
		num = 0;
		next = nullptr;
		previous = nullptr;
	}
	Word(char* theWord,int theNum) {
		strcpy_s(word, theWord);
		num = theNum;
		next = nullptr;
		previous = nullptr;
	}
	//���ʹ����ָ�룬�������������ͷ� 
	~Word() {
		delete next;
		next = nullptr;
	}
};


struct WordIndex{
	Word* pWord;
	WordIndex* next;
	WordIndex(Word* theWord,WordIndex* theNext)
	{
		pWord = theWord;
		next = theNext;
	}
	~WordIndex(){
		delete next;
		next = nullptr;
	}
};

//��������ڲ������е��ʵĴ�Ƶ
//��Ҫʵ�֣����Կ��ٵذ�˳��ȡ����ߴ�Ƶ��100����
//�Լ������Ը��ݸ����ĵ������ƣ��룩�������ҵ��õ��ʵĴ洢��Ԫ��
class WordList
{


private:
	int Hash(char *word);			//��ϣ����
	void shiftWord(Word * pWord);	//ʹwordǰ��һ��
	Word* pWordHead;				//ָ��Word��ָ��
	Word* pWordTail;
	
	WordIndex* index[128];			//��ϣ����

public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void outPut();

};