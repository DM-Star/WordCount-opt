#include "stdafx.h"
#include "CppUnitTest.h"
#include "../wcPro/WordList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("apple");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("apple", p->word);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("apple");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("apple");
			wordlist.addWord("boy");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("apple", p->word);
			Assert::AreEqual(1, p->num);
			p = p->next;
			Assert::AreEqual("boy", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("boy");
			wordlist.addWord("apple");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("apple", p->word);
			Assert::AreEqual(1, p->num);
			p = p->next;
			Assert::AreEqual("boy", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("apple");
			wordlist.addWord("apple");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("apple", p->word);
			Assert::AreEqual(2, p->num);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("boy");
			wordlist.addWord("apple");
			wordlist.addWord("boy");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("boy", p->word);
			Assert::AreEqual(2, p->num);
			p = p->next;
			Assert::AreEqual("apple", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("congratulations");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("congratulations", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: Your test code here
			WordList wordlist;
			wordlist.addWord("electroencephalography");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("electroencephalography", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: Your test code here
			WordList wordlist;
			for (int i = 0; i < 10000; i++) wordlist.addWord("is");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("is", p->word);
			Assert::AreEqual(10000, p->num);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: Your test code here
			WordList wordlist;
			for (int i = 0; i < 100000; i++) wordlist.addWord("is");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("is", p->word);
			Assert::AreEqual(100000, p->num);
		}
		TEST_METHOD(TestMethod11)
		{
			// TODO: Your test code here
			WordList wordlist;
			for (int i = 0; i < 10000; i++) wordlist.addWord("congratulations");
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("congratulations", p->word);
			Assert::AreEqual(10000, p->num);
		}
		TEST_METHOD(TestMethod12)
		{
			// TODO: Your test code here
			WordList wordlist;
			char word[4] = "aaa";
			for (int i = 0; i < 26;i++) {
				word[1] = 'a';
				for (int j = 0; j < 26; j++) {
					word[2] = 'a';
					for (int k = 0; k < 26; k++) {
						wordlist.addWord(word);
						word[2]++;
					}
					word[1]++;
				}
				word[0]++;
			}
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("aaa", p->word);
			Assert::AreEqual(1, p->num);
			p = wordlist.getTail()->previous;
			Assert::AreEqual("zzz", p->word);
			Assert::AreEqual(1, p->num);
		}
		TEST_METHOD(TestMethod13)
		{
			// TODO: Your test code here
			WordList wordlist;
			char word[4] = "zzz";
			for (int i = 0; i < 26; i++) {
				word[1] = 'z';
				for (int j = 0; j < 26; j++) {
					word[2] = 'z';
					for (int k = 0; k < 26; k++) {
						wordlist.addWord(word);
						word[2]--;
					}
					word[1]--;
				}
				word[0]--;
			}
			Word *p = wordlist.getHead()->next;
			Assert::AreEqual("aaa", p->word);
			Assert::AreEqual(1, p->num);
			p = wordlist.getTail()->previous;
			Assert::AreEqual("zzz", p->word);
			Assert::AreEqual(1, p->num);
		}

	};
}