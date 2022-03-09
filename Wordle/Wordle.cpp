#include <iostream>
#include <string>
#include <vector>
#include "theGame.h"
#include <fstream>
#include <map>
#include <time.h>
#include <stdlib.h>
using namespace std;

map<int, string>* words = nullptr;
void loadWordMap();

int main()
{
	
	loadWordMap();
	int input;
	cout << "-- Welcome to the game wordle --" << endl;
		do
		{
			cout << "[1] Start the game" << endl;
			cout << "[2] Quit" << endl;
			cin >> input;

			switch (input)
			{
			case 1: theGame(); break; // how to call thegame function in the game class. sould i use header like emil did somehow in his lécture? 
			case 2: cout << "Quit the game"; break;
			default: cout << "Not a valid input, try again." << endl; break;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} while (input != 2);

	return 0;
}
void loadWordMap()
{
	words = new map<int, string>;

	fstream wordFile;
	wordFile.open("words.txt");

	if (wordFile)
	{
		string word;
		int count = 0;

		for (int i = 0; getline(wordFile, word); i++) // get lenght of the list in txt
		{
			words->insert({ i, word });
			count++;
		}

		wordFile.close();
	}
	else
	{
		cout << "file not found!" << endl;
	}
}


