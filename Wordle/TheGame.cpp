#include <iostream>
#include <string>
#include <vector>
#include "theGame.h"
#include <fstream>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"



string getString();
void printWord(string input, string correctWord);
string forceWordToUppercase(string input);
string getTheCorrectWord();
extern map<int, string>* words;

enum class ForegroundColor : int {
	Red = 31,
	Green = 32,
	Yellow = 33,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93,
	DarkBlue = 34
};

enum class BackgroundColor : int {
	Red = 41,
	Green = 42,
	Yellow = 43,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103,
	Gray = 100
};

void theGame()
{
	string input;
	int guesses = 0;
	string correctString = getTheCorrectWord(); // get correct string
	
	cout << FOREGROUND(ForegroundColor::DarkBlue, "       Wordle") << endl;
	do
	{
		input = getString();
		
		printWord(input, correctString);

		guesses++;

	} while (input != correctString && guesses != 6);

	if (input == correctString)
	{
		cout << "You found the right word: " << correctString << endl;
	}
	else
	{
		cout << "You did not find the right word. The right word was: " << correctString << endl;
	}

	cout << "End of game" << endl;
}

string getTheCorrectWord()
{
	map<int, string>::iterator it;
	string correctword;

	srand(time(NULL));

	int randomKeyNumber = rand() % words->size() + 0;
	
	it = words->find(randomKeyNumber); // use random number to decide wich word
	correctword = words->find(randomKeyNumber)->second;
	
	return correctword;
}
string getString() // send in list of strings
{
	string inputStr;
	
	while (1)
	{
		getline(cin, inputStr);
		inputStr = forceWordToUppercase(inputStr);

		if (inputStr.size() > 5) // check if the input is a real word or not(fix). Checks if the input is more then 5 chars long
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Not valid, try again!" << endl;
		}
		else
		{
			break;
		}


	}
	return inputStr;
}

void printWord(string input, string correctWord) 
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == correctWord[i])
		{
			cout << BACKGROUND(BackgroundColor::Green, input[i]);
		}
		else
		{
			bool letterIsYellow = false;
			for (int j = 0; j < input.length(); j++)
			{
				if (input[i] == correctWord[j])
				{
					letterIsYellow = true;
					break;
				}
			}

			if (letterIsYellow)
			{
				cout << BACKGROUND(BackgroundColor::Yellow, input[i]);
			}
			else
			{
				cout << BACKGROUND(BackgroundColor::Gray, input[i]);
			}
		}
	}
	cout << endl;
}
string forceWordToUppercase(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]); // force to uppercase
	}
	return input;
}

