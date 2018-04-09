// Copyright[2018]<Star>
#ifndef WCPRO_WORDLIST_H_
#define WCPRO_WORDLIST_H_

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define    MAX_WORD_LEN    40
#define    MAX_INDEX_NUM   512

// This structure is used to store words and word frequencies
struct Word {
    char word[MAX_WORD_LEN];
    int num;
    Word *next;

    // According to the finalized data structure type
    // you can also continue to expand the structure
    // Modify the constructor according to the finalized data structure type
    Word() {
        word[0] = 0;
        num = 0;
        next = nullptr;
    }
    Word(char* theWord, int theNum, Word *theNext) {
        strcpy_s(word, theWord);
        num = theNum;
		next = theNext;
    }
	int equal(Word *theWord) {
		if (theWord == nullptr) return -1;
		if (num > theWord->num) return 1;
		if (num < theWord->num) return -1;
		if (strcmp(word, theWord->word) > 0) return -1;
		if (strcmp(word, theWord->word) < 0) return 1;
		return 0;
	}
    // If a pointer is used, it is released in the destructor
    ~Word() {}
};


// This class is used to manipulate the frequency of all words
// You can quickly retrieve the 100 words
// with the highest word frequency in order
// The storage unit of the word can be found immediately
// based on the given word name
class WordList {
 private:
    int Hash(char *word);  // hash funtion
	int wordNum;
    Word* index[MAX_INDEX_NUM];  // hash index
	void heapSort(Word* word[], int wordNum);
	void downFilter(Word* word[], int middleNode);
	void upFilter(Word* word[], int downNode);

 public:
    WordList();
    ~WordList();
    void addWord(char word[]);
    void outPut();
};

#endif  // WCPRO_WORDLIST_H_
