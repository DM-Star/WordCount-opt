#pragma once

#define		MAX_WORD_LEN	20

//����ṹ�����ڴ洢���ʺʹ�Ƶ 
struct Word {
	char word[MAX_WORD_LEN];
	int num;
	//��������ȷ�������ݽṹ���ͣ������Լ�������ýṹ�� 
	//��������ȷ�������ݽṹ���ͣ��޸Ĺ��캯�� 
	Word() {
		word[0] = 0;
		num = 0;
	}
	//���ʹ����ָ�룬�������������ͷ� 
	~Word() {
		;
	}
};

//��������ڲ������е��ʵĴ�Ƶ
//��Ҫʵ�֣����Կ��ٵذ�˳��ȡ����ߴ�Ƶ��100����
//�Լ������Ը��ݸ����ĵ������ƣ��룩�������ҵ��õ��ʵĴ洢��Ԫ��
class WordList
{
public:
	WordList();
	~WordList();
	void addWord(char word[]);
	void outPut();
};