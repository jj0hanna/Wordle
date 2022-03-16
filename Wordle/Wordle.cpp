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
int totalNodes = 0;

struct Node
{
	string Strdata;
	int nr;
	Node* Left;
	Node* Right;

};

Node* rootNode = nullptr;

//void loadWordMap();
void loadWordTree();

Node* createNode(string Strdata, int number)
{
	Node* temp = new Node; // using new, do i have to do someting more
	temp -> Strdata = Strdata;
	temp->Left = nullptr;
	temp->Right = nullptr;
	temp->nr = number;

	return temp;
}
 Node* insert(Node* node, string key, int number)
 {
 	
 	if (node == nullptr)
 	{
 		return createNode(key, number); 
 	}
 	if (key < node->Strdata)
 	{
 		node->Left = insert(node ->Left, key, number);
 	}
 	else if (key > node->Strdata)
 	{
 		node->Right = insert(node ->Right, key, number);
 	}
	return node;
 }
 Node* getNode(Node* node, int randomNumber)
 {
	 cout << node->nr << endl;
	 cout << node->Strdata << endl;
	 
	 if ( randomNumber == node->nr)
	 {
		 return node;
	 }
	 if (randomNumber < node->nr) // will never be cause a linear tree
	 {
		 node = getNode(node->Left, randomNumber); 
	 }
	 else if (randomNumber > node->nr)
	 {
		 node = getNode(node->Right, randomNumber);
	 }

	 return node;
 }
 string getRandomNode()
 {
	 srand(time(NULL));
	 
	 int randomNumber = rand() % totalNodes;
	 return getNode(rootNode, randomNumber)->Strdata;
 }


int main()
{
	//loadWordMap();
	loadWordTree();
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
	string word;

	if (wordFile)
	{
		for (int i = 0; totalNodes < 1000 && getline(wordFile, word); i++) // fråga samuel om stack overflow om vi har mer än 1400 ish ord. quick fix nu har vi bara 1000
		{
			rootNode = insert(rootNode, word, i);
			totalNodes++;
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


