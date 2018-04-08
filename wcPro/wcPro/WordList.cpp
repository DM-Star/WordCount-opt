// Copyright[2018]<Star>
#include "WordList.h"

WordList::WordList() {
    for (int i = 0; i < 128; i++) index[i] = nullptr;
	wordNum = 0;
}


WordList::~WordList() {
	Word *temp;
    for (int i = 0; i < 128; i++) {
		for (Word *p = index[i]; p != nullptr;) {
			temp = p;
			p = p->next;
			delete temp;
		}
    }
}

void WordList::addWord(char word[]) {
    // Add the word to the WordList (or word frequency +1)
    int  p_index = Hash(word);
    Word* pWord = index[p_index];

    while (pWord != nullptr) {
        if (!strcmp(word, pWord->word)) {
            pWord->num++;
			return;
        }
		pWord = pWord->next;
    }

    pWord = new Word(word, 1, index[p_index]);
	index[p_index] = pWord;
	wordNum++;
	
}

void WordList::outPut() {
    // 100 words are all output via cout
	if (wordNum <= 0) return;

	if (wordNum > 100) wordNum = 100;
	//开辟一片连续的空间以排序（使用最小堆）
	Word **word = new Word*[wordNum + 2];
	word[0] = word[wordNum + 1] = nullptr;

	int iIndex = 0;
	Word *pWord;
	for (int iWord=1; iIndex < 128; iIndex++) {
		//将索引中的所有结点放入开辟的空间中准备排序
		pWord = index[iIndex];
		while (pWord != nullptr) {
			word[iWord] = pWord;	//上滤
			upFilter(word, iWord);
			pWord = pWord->next;
			//如果有一百个以上结点，可以进行取舍，因为总共只需要输出100个结点
			if (++iWord > 100) break;
		}
		if (iWord > 100) break;
	}
	for (; iIndex < 128; iIndex++) {
		if(pWord==nullptr) pWord = index[iIndex];
		while (pWord != nullptr) {
			if (word[1]->equal(pWord) == -1) {
				word[1] = pWord;
				downFilter(word, 50);	//下滤
			}
			pWord = pWord->next;
		}
	}
	heapSort(word, wordNum);	//堆排序

	//输出那个
	cout << word[2]->word << ' ' << word[2]->num;
	for (int i = 3; i < wordNum + 2; i++) cout << endl << word[i]->word << ' ' << word[i]->num;

	delete[]word;
}


int WordList::Hash(char* word) {
    int HashVal = 0;

    while (*word != '\0')
        HashVal += *word++;

    return HashVal & 127;
}

void WordList::heapSort(Word * word[], int wordNum)
{
	//排序
	int iWord;
	for (iWord = wordNum; iWord >= 1;) {
		word[iWord + 1] = word[1];
		word[1] = word[iWord];
		word[iWord] = nullptr;
		iWord--;
		downFilter(word, iWord >> 1);
	}
}

void WordList::downFilter(Word * word[], int middleNode)
{
	//下滤
	int iHeap = 1;
	Word *left, *right, *pWord = word[1];
	while (iHeap <= middleNode) {
		left = word[iHeap << 1];
		right = word[(iHeap << 1) + 1];
		if (word[iHeap]->equal(left) == 1) {
			if (word[iHeap]->equal(right) == 1) {
				if (left->equal(right) == 1) {
					word[(iHeap << 1) + 1] = pWord;
					word[iHeap] = right;
					iHeap = (iHeap << 1) + 1;
					continue;
				}
			}
			word[iHeap << 1] = pWord;
			word[iHeap] = left;
			iHeap = iHeap << 1;
			continue;
		}
		if (word[iHeap]->equal(right) == 1) {
			word[(iHeap << 1) + 1] = pWord;
			word[iHeap] = right;
			iHeap = (iHeap << 1) + 1;
			continue;
		}
		break;
	}
}

void WordList::upFilter(Word * word[], int downNode)
{
	//上滤
	int iHeap = downNode;
	while (iHeap > 1) {
		if (word[iHeap]->equal(word[iHeap >> 1]) == -1) {
			Word *temp = word[iHeap];
			word[iHeap] = word[iHeap >> 1];
			word[iHeap >> 1] = temp;
		}
		else return;
		iHeap = iHeap >> 1;
	}
}
