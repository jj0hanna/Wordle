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
Node* makeTreeBalanced(vector<string>& wordsInVector, int left, int right);
void loadWordTree();

Node* createNode(string Strdata, int number)
{
	Node* temp = new Node;
	temp -> Strdata = Strdata;
	temp->Left = nullptr;
	temp->Right = nullptr;
	temp->nr = number;

	return temp;
}
Node* insert(Node* node, string key, int number)
{
	Node* prev = nullptr;
	bool left = false;
	while (node != nullptr)
	{
		if (key < node->Strdata)
		{
			prev = node;
			node = node->Left;
			left = true;
		}
		else if (key > node->Strdata)
		{
			prev = node;
			node = node->Right;
			left = false;
		}
	}
	Node* newNode = createNode(key, number);
	if (prev != nullptr) {
		if (left) {
			prev->Left = newNode;
		}
		else {
			prev->Right = newNode;
		}
	}
	return newNode;
	
//	 return node; // recursive functions does not work i got stack overflow
// 	if (node == nullptr)
// 	{
// 		return createNode(key, number); 
// 	}
// 	if (key < node->Strdata)
// 	{
// 		node->Left = insert(node ->Left, key, number);
// 	}
// 	else if (key > node->Strdata)
// 	{
// 		node->Right = insert(node ->Right, key, number);
// 	}
//	return node;
 }
 Node* getNode(Node* node, int randomNumber)
 {
	 while (randomNumber!= node->nr)
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

	// if ( randomNumber == node->nr) // recursive functions does not work i got stack overflow
	// {
	//	 return node;
	// }
	// if (randomNumber < node->nr) // will never be cause a linear tree
	// {
	//	 node = getNode(node->Left, randomNumber); 
	// }
	// else if (randomNumber > node->nr)
	// {
	//	 node = getNode(node->Right, randomNumber);
	// }
	//
	// return node;
 }
 string getRandomNode()
 {
	 //srand(time(NULL));
	 
	 int randomNumber = rand() % totalNodes;
	 return getNode(rootNode, randomNumber)->Strdata;
 }


int main()
{
	//loadWordMap();
	loadWordTree();
	int input;
	srand(time(NULL)); // do this in the start once to get a better random number insted of inside getRandom

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


Node* makeTreeBalanced(vector<string>& wordsInVector, int left, int right)
{
	
	Node* output = insert(rootNode, wordsInVector[left + ((right - left) / 2)], left + ((right - left) / 2));
	cout << output->Strdata << endl;
	cout << output->nr << endl;

	if (left != right)
	{
		int left1 = left + ((right - left) / 2) + 1;
		int right1 = left + ((right - left) / 2);

		makeTreeBalanced(wordsInVector, left , right1);
		makeTreeBalanced(wordsInVector, left1, right);
	}
	
	// insert node at new index[left+((right-left) / 2)] // make sure its ints // save result in a varible
	// if left=!right do this{
	// recurse the funcion with left , right = left+((right-left) / 2)
    // recurse the funcion with left = left + ((right - left) / 2) +1, right
	//}
	
	return output;// return rootnode if i need it
}
void loadWordTree()
{
	fstream wordFile;
	wordFile.open("words.txt");

	string word;
	vector<string> wordsInVector = vector<string>();

	if (wordFile)
	{
		// Add all nodes or only words? to wordsInVector
		// next for loop, insert nodes. Start to insert the node that is at position wordsInvector.size/2 (math.round) to not get desimal.
		for (int i = 0; getline(wordFile, word); i++)
		{
			wordsInVector.push_back(word);
			totalNodes++;
		}
		wordFile.close();

		rootNode = makeTreeBalanced(wordsInVector, 0, wordsInVector.size()); // -1 här?


	}
	else
	{
		cout << "file not found!" << endl;
	}

}



//void loadWordTree()
//{
//	fstream wordFile;
//	wordFile.open("words.txt");
//	string word;
//	vector<string> wordsInVector = vector<string>();
//
//	if (wordFile)
//	{
//		getline(wordFile, word);
//		rootNode = insert(rootNode, word, 0);
//
//		// Add all nodes or only words? to wordsInVector
//		// next for loop, insert nodes. Start to insert the node that is at position wordsInvector.size/2 (math.round) to not get desimal.
//
//
//		for (int i = 1; getline(wordFile, word); i++)
//		{
//			insert(rootNode, word, i);
//			totalNodes++;
//		}
//
//		wordFile.close();
//	}
//	else
//	{
//		cout << "file not found!" << endl;
//	}
//}
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
//		for (int i = 0; getline(wordFile, word); i++) // get lenght of the list in txt
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

