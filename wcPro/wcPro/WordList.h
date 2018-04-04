// Copyright[2018]<Star>
#ifndef WCPRO_WORDLIST_H_
#define WCPRO_WORDLIST_H_

#pragma once
#include<iostream>
#include <cstring>
using namespace std;

#define    MAX_WORD_LEN    20

// This structure is used to store words and word frequencies
struct Word {
    char word[MAX_WORD_LEN];
    int num;
    Word *next;
    Word *previous;

    // According to the finalized data structure type
    // you can also continue to expand the structure
    // Modify the constructor according to the finalized data structure type
    Word() {
        word[0] = 0;
        num = 0;
        next = nullptr;
        previous = nullptr;
    }
    Word(char* theWord, int theNum) {
        strcpy_s(word, theWord);
        num = theNum;
        next = nullptr;
        previous = nullptr;
    }
    // If a pointer is used, it is released in the destructor
    ~Word() {
        delete next;
        next = nullptr;
    }
};


struct WordIndex {
    Word* pWord;
    WordIndex* next;
    WordIndex(Word* theWord, WordIndex* theNext) {
        pWord = theWord;
        next = theNext;
    }
    ~WordIndex() {
        delete next;
        next = nullptr;
    }
};

// This class is used to manipulate the frequency of all words
// You can quickly retrieve the 100 words
// with the highest word frequency in order
// The storage unit of the word can be found immediately
// based on the given word name
class WordList {
 private:
    int Hash(char *word);  // hash funtion
    void shiftWord(Word * pWord);  // Advance word by one
    Word* pWordHead;  // Pointer to Word
    Word* pWordTail;

    WordIndex* index[128];  // hash index

 public:
    WordList();
    ~WordList();
    void addWord(char word[]);
    void outPut();
};

#endif  // WCPRO_WORDLIST_H_
