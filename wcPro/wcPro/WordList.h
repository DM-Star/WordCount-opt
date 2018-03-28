#pragma once
#include<iostream>
#include <cstring>
using namespace std;

#define		MAX_WORD_LEN	20

//这个结构体用于存储单词和词频 
struct Word {
	char word[MAX_WORD_LEN];
	int num;
	Word *next;
	Word *previous;
	
	//根据最终确定的数据结构类型，还可以继续扩充该结构体 
	//根据最终确定的数据结构类型，修改构造函数 
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
	//如果使用了指针，在析构函数中释放 
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

//这个类用于操作所有单词的词频
//需要实现：可以快速地按顺序取出最高词频的100个词
//以及：可以根据给出的单词名称（码），立即找到该单词的存储单元。
class WordList
{


private:
	int Hash(char *word);			//哈希函数
	void shiftWord(Word * pWord);	//使word前移一格
	Word* pWordHead;				//指向Word的指针
	Word* pWordTail;
	
	WordIndex* index[128];			//哈希索引

public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void outPut();

};