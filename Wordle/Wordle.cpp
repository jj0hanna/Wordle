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

//set<string> *words;
//vector<string> *vecWords;
//void loadWordMap();

struct Node
{
	string Strdata;
	int nr;
	Node* Left;
	Node* Right;
};

Node* rootNode = nullptr;
int totalNodes = 0;

Node* insert(Node* node, string key, int number);
Node* createNode(string Strdata, int number);
Node* getNode(Node* node, int randomNumber);
string getRandomNode();
void makeTreeBalanced(vector<string>& wordsInVector, size_t left, size_t right);
bool Contains(string input);
void loadWordTree();

int main()
{
	//loadWordMap();

	loadWordTree();
	srand(time(NULL)); // do this in the start once to get a better random number insted of inside getRandom
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

Node* insert(Node* node, string key, int number)
{
	Node* prev = nullptr;
	bool left = false;

	while (node != nullptr)
	{
		if (number == node->nr) // added this to check if node already exist // i know that for some reason i get dublicates on words so we wont create a new node when that happens
		{
			return node;
		}
		else if (number < node->nr)
		{
			prev = node;
			node = node->Left;
			left = true;
		}
		else if (number > node->nr)
		{
			prev = node;
			node = node->Right;
			left = false;
		}
	}

	Node* newNode = createNode(key, number);
	if (prev != nullptr) {
		if (left)
		{
			prev->Left = newNode;
		}
		else {
			prev->Right = newNode;
		}
	}
	if (rootNode == nullptr)
	{
		rootNode = newNode;
	}
	//cout << newNode->Strdata << " " << newNode->nr << endl;
	return newNode;
}

Node* createNode(string Strdata, int number)
{
	Node* temp = new Node;
	temp->Strdata = Strdata;
	temp->Left = nullptr;
	temp->Right = nullptr;
	temp->nr = number;

	return temp;
}

Node* getNode(Node* node, int randomNumber)
{
	while (randomNumber != node->nr)
	{
		if (randomNumber < node->nr)
		{
			node = node->Left;
		}
		else if (randomNumber > node->nr)
		{
			node = node->Right;
		}
	}
	return node;
}

string getRandomNode()
{
	int randomNumber = rand() % totalNodes;
	return getNode(rootNode, randomNumber)->Strdata;
}

void makeTreeBalanced(vector<string>& wordsInVector, size_t left, size_t right)
{
	Node* output = insert(rootNode, wordsInVector[left + ((right - left) / 2)], left + ((right - left) / 2));

	size_t left1 = left + ((right - left) / 2);
	size_t right1 = left + ((right - left) / 2) + 1;

	if (left != right && left < right)
	{
		if (left1 < right1 && left1 != right1)
		{
			if (left != left1 && right != right1)
			{
				makeTreeBalanced(wordsInVector, left, right1);
				makeTreeBalanced(wordsInVector, left1, right);
			}
		}
	}
}

bool Contains(string input)
{
	Node* tempNode = rootNode;
	while (tempNode != nullptr)
	{
		if (input == tempNode->Strdata)
		{
			return true;
		}
		else if (input < tempNode->Strdata)
		{
			tempNode = tempNode->Left;
		}
		else if (input > tempNode->Strdata)
		{
			tempNode = tempNode->Right;
		}
	}
	return false;
}

void loadWordTree()
{
	fstream wordFile;
	wordFile.open("words.txt");

	string word;
	vector<string> wordsInVector = vector<string>();

	if (wordFile)
	{
		for (int i = 0; getline(wordFile, word); i++)
		{
			wordsInVector.push_back(word);
			totalNodes++;
		}
		wordFile.close();

		makeTreeBalanced(wordsInVector, (size_t)0, wordsInVector.size());
	}
	else
	{
		cout << "file not found!" << endl;
	}
}

//-------------------------------------------------------------------------------------------
// - Using STL to take care of the words.
// - 2 containers, one set to later use to easy look up if the input exist in the container
// -  And vector to easy get a random number = random word
//-------------------------------------------------------------------------------------------
//void loadWordMap()
//{
//	words = new set<string>;
//	vecWords = new vector<string>;
//
//	fstream wordFile;
//	wordFile.open("words.txt");
//
//	if (wordFile)
//	{
//		string word;
//		string vecWord;
//		
//		for (int i = 0; getline(wordFile, word); i++)
//		{
//			words->insert({word});
//			vecWords->push_back(word);
//		}
//
//		wordFile.close();
//	}
//	else
//	{
//		cout << "file not found!" << endl;
//	}
//}
//

