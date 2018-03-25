#pragma once

#define		MAX_WORD_LEN	20

//这个结构体用于存储单词和词频 
struct Word {
	char word[MAX_WORD_LEN];
	int num;
	//根据最终确定的数据结构类型，还可以继续扩充该结构体 
	//根据最终确定的数据结构类型，修改构造函数 
	Word() {
		word[0] = 0;
		num = 0;
	}
	//如果使用了指针，在析构函数中释放 
	~Word() {
		;
	}
};

//这个类用于操作所有单词的词频
//需要实现：可以快速地按顺序取出最高词频的100个词
//以及：可以根据给出的单词名称（码），立即找到该单词的存储单元。
class WordList
{
public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void outPut();
};