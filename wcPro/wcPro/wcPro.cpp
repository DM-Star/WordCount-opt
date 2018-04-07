// Copyright[2018]<Star>
#include<iostream>
#include<fstream>

#include"WordState.h"
#include"WordList.h"
using namespace std;

bool inputCheck(char *fileName, fstream &in);
// word frequency statistics
void wordCount(fstream &in, WordList &wordList);
// output results
void outPut(char outFile[], WordList &wordList);

int main(int argc, char **argv) {
    fstream in;
    if (!inputCheck(argv[1], in)) {
        in.close();
        return 0;
    }

    WordList wordList;
    wordCount(in, wordList);
    outPut("result.txt", wordList);

    in.close();
    return 0;
}

bool inputCheck(char *fileName, fstream &in) {
    char *A = ".txt";
    char B[MAX_WORD_LEN] = "";
    int i = strlen(fileName) - 1;
    int j = 0;
    for (i = strlen(fileName) - 1; i >= 0; i--) {
        if (fileName[i] == '.') {
            for (j = i; j < strlen(fileName); j++)
            B[j - i] = fileName[j];
        }
    }
    if (strcmp(A, B) != 0) {
        cout << fileName << "not a 'txt' file";
        return false;
    }

    in.open(fileName);
    if (!in) {  // Determine if the file exists
        cout << fileName << "file not exists" << endl;
        return false;
    }

    char ch;
    ch = in.get();
    if (ch == EOF) {  // Determine if the file is empty
        cout << fileName << "file is empty!" << endl;
        return false;
    }

    return true;
}

void wordCount(fstream &in, WordList &wordList) {
    char word[MAX_WORD_LEN];
    WordState wordState;
    processType process;

	in.seekg(0);
    char c;

    int wordPosition = 0;
    int delta = 'a' - 'A';
    do {
        c = in.get();
        if (c <= 'Z'&&c >= 'A') c += delta;
        process = wordState.stateTransfer(c);

        switch (process) {
            // Different responses according to different states
        case PROCESS_23:
            // Delete the previous "-", increase the number of words
            word[wordPosition - 1] = 0;
            wordList.addWord(word);
            wordPosition = 0;
            break;
        case PROCESS_13:
            word[wordPosition] = '\0';
            wordList.addWord(word);
            wordPosition = 0;
            break;
        case PROCESS_33:
            // Word outside - word outside, wordPosition unchanged
            break;
        default:
            word[wordPosition] = c;
            wordPosition++;
        }
    } while (c != EOF);
}

void outPut(char outFile[], WordList &wordList) {
    ofstream outf(outFile);
    streambuf *default_buf = cout.rdbuf();
    cout.rdbuf(outf.rdbuf());

    wordList.outPut();

    cout.rdbuf(default_buf);
}
