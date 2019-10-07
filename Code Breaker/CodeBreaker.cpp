#include<iostream>
#include<string>
#include <random>
#include<ctime>

using namespace std;

int main() 
{
	srand(time(0));

	const int WORD_COUNT = 3;

	string words[WORD_COUNT][2] = { 
		{ "HELLO", "What you say when you greet someone." },
		{ "GOODBYE", "" },
		{ "WOW", "" }
	};

	char playAgain = 'y';

	do
	{
		int randWord = rand() % WORD_COUNT;

		string word = words[randWord][0];
		string hint = words[randWord][1];

		string scrambledWord = word;

		cout << "HINT: " << hint << endl;

		for (int i = 0; i < scrambledWord.length(); i++)
		{
			int randIndex = rand() % scrambledWord.length();

			char temp = scrambledWord[i];
			scrambledWord[i] = scrambledWord[randIndex];
			scrambledWord[randIndex] = temp;
		}

		cout << "INITIAL WORD: " << word << endl;
		cout << "SCRAMBLED WORD: " << scrambledWord << endl;

		cout << "Play again?: ";
		cin >> playAgain;
	} while (playAgain == 'y');
}

