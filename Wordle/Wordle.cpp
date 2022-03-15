#include <iostream>
#include <string>
#include <vector>
#include "theGame.h"
#include <fstream>
#include <map>
#include <time.h>
#include <stdlib.h>
#include <set>
using namespace std;

set<string> *words;
vector<string> *vecWords;

void loadWordMap();
struct Node
{
	string Strdata;
	Node* Left;
	Node* Right;

};

Node* createNode(string Strdata)
{
	Node* temp = new Node; // using new, do i have to do someting more
	temp -> Strdata;
	temp->Left = nullptr;
	temp->Right = nullptr;

	return temp;
}
Node* insert(Node* node, string key)
{
	// if the current node already have 2 chil

	if (node == nullptr)
	{
		return createNode(key);
	}
	if (key < node->Strdata)
	{
		node->Left = insert(node ->Left, key);
	}
	else if (key > node->Strdata)
	{
		node->Right = insert(node ->Right, key);
	}
}
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
			case 1: theGame(); break;
			case 2: cout << "Quit the game"; break;
			default: cout << "Not a valid input, try again." << endl; break;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		} while (input != 2);

	return 0;
}
void loadWordTree()
{
	fstream wordFile;
	wordFile.open("words.txt");


	if (wordFile)
	{
		

		for (int i = 0; wordFile.eof(); i++) // get lenght of the list in txt
		{
			
		}

		wordFile.close();
	}
	else
	{
		cout << "file not found!" << endl;
	}
}
void loadWordMap()
{
	words = new set<string>;
	vecWords = new vector<string>;

	fstream wordFile;
	wordFile.open("words.txt");

	if (wordFile)
	{
		string word;
		string vecWord;
		
		for (int i = 0; getline(wordFile, word); i++) // get lenght of the list in txt
		{
			words->insert({word});
			vecWords->push_back(word);
		}

		wordFile.close();
	}
	else
	{
		cout << "file not found!" << endl;
	}
}


