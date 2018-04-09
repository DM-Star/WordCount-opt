// Copyright[2018]<Star>
#include<iostream>
#include<fstream>
#include <time.h>

#include"WordState.h"
#include"WordList.h"
using namespace std;

char *inputCheck(char *fileName);
// word frequency statistics
void wordCount(char *buffer, WordList &wordList);
// output results
void outPut(char outFile[], WordList &wordList);

int main(int argc, char **argv) {
	char *buffer = inputCheck(argv[1]);
    if (buffer == nullptr) return 0;

    WordList wordList;
    wordCount(buffer, wordList);
	delete[]buffer;

    outPut("result.txt", wordList);
    return 0;
}

char *inputCheck(char *fileName) {
	char B[MAX_WORD_LEN] = "";
	for (int i = strlen(fileName) - 1; i >= 0; i--) {
		if (fileName[i] == '.') {
			for (int j = i; j < strlen(fileName); j++)
				B[j - i] = fileName[j];
		}
	}
	if (strcmp(".txt", B) != 0) {
		cout << fileName << "not a 'txt' file";
		return nullptr;
	}

	ifstream in(fileName, ios::binary);
	if (!in) {  // Determine if the file exists
		cout << fileName << "file not exists" << endl;
		return nullptr;
	}
	filebuf *pbuf = in.rdbuf();

	// 调用buffer对象方法获取文件大小  
	long size = pbuf->pubseekoff(0, ios::end, ios::in);
	if (size == 0) {
		cout << fileName << "file is empty" << endl;
		in.close();
		return nullptr;
	}
	pbuf->pubseekpos(0, ios::in);

	// 分配内存空间  
	char *ch = new char[size + 1];
	pbuf->sgetn(ch, size);
	ch[size] = '\0';
	in.close();

	return ch;
}

void wordCount(char *buffer, WordList &wordList) {
    char word[MAX_WORD_LEN];
    WordState wordState;
    processType process;

    char c;

    int wordPosition = 0;
    int delta = 'a' - 'A';
    do {
		c = *buffer++;
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
    } while (c != '\0');
}

void outPut(char outFile[], WordList &wordList) {
    ofstream outf(outFile);
    streambuf *default_buf = cout.rdbuf();
    cout.rdbuf(outf.rdbuf());

    wordList.outPut();

    cout.rdbuf(default_buf);
}
