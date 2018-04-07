// Copyright[2018]<Star>
#include "WordList.h"

WordList::WordList() {
    pWordHead = new Word();
    pWordTail = new Word();
    pWordHead->next = pWordTail;
    pWordTail->previous = pWordHead;
    for (int i = 0; i < 128; i++) index[i] = nullptr;
}


WordList::~WordList() {
	Word *p = pWordHead;
	while (p != nullptr) {
		pWordHead = p->next;
		delete p;
		p = pWordHead;
	}
	
    for (int i = 0; i < 128; i++) {
		if (index[i] != nullptr)
        delete index[i];
        index[i] = nullptr;
    }
}

void WordList::addWord(char word[]) {
    // Add the word to the WordList (or word frequency +1)
    int  p_index = Hash(word);
    WordIndex* pIndex = index[p_index];
    while (pIndex != nullptr) {
        Word *pWord = pIndex->pWord;
        if (!strcmp(word, pWord->word)) {
            pWord->num++;

            Word *qWord = pWord->previous;
            while (qWord->num < pWord->num) {
                if (qWord == pWordHead)
                    return;

                shiftWord(pWord);

                qWord = pWord->previous;
            }
            while (strcmp(qWord->word, pWord->word) > 0) {
                if (qWord->num > pWord->num) return;
                shiftWord(pWord);
                qWord = pWord->previous;
            }
            return;
        }
        pIndex = pIndex->next;
    }

    Word *pWord = new Word(word, 1);
    pWord->previous = pWordTail->previous;
    pWord->next = pWordTail;

    pWordTail->previous->next = pWord;
    pWordTail->previous = pWord;

    pIndex = new WordIndex(pWord, index[p_index]);
    index[p_index] = pIndex;

    Word *qWord = pWord->previous;
    while (strcmp(qWord->word, pWord->word) > 0) {
        if (qWord->num > pWord->num) return;
        shiftWord(pWord);
        qWord = pWord->previous;
    }
}

void WordList::outPut() {
    // 100 words are all output via cout
    Word *p = pWordHead->next;
    if (p != pWordTail) cout << p->word << ' ' << p->num;
    else
        return;
    p = p->next;

    for (int i = 0; i < 99; i++) {
        if (p != pWordTail) cout << endl << p->word << ' ' << p->num;
        else
            return;

        p = p->next;
    }
}

Word * WordList::getHead()
{
	return pWordHead;
}

Word * WordList::getTail()
{
	return pWordTail;
}

int WordList::Hash(char* word) {
    int HashVal = 0;

    while (*word != '\0')
        HashVal += *word++;

    return HashVal & 127;
}

void WordList::shiftWord(Word *pWord) {
    if (pWord == pWordHead) return;
    Word *qWord = pWord->previous;
    if (qWord == pWordHead) return;

    pWord->next->previous = qWord;
    qWord->previous->next = pWord;

    qWord->next = pWord->next;
    pWord->previous = qWord->previous;

    pWord->next = qWord;
    qWord->previous = pWord;
}
