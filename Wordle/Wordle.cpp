
#include <iostream>
#include <string>
#include <vector>

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
using namespace std;

void theGame();
string getString();

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

int main()
{

	cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
	cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;

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








}
void theGame()
{
	string input1;
	string input2;
	string input3;
	string input4;
	string input5;

	string correctString = "hallo";
	cout << FOREGROUND(ForegroundColor::DarkBlue,"       Wordle") << endl;
	

	input1 = getString();
	cout << "| "<< input1[0] << " | "<< input1[1] << " | "<< input1[2] << " | "<< input1[3] <<" | "<< input1[4] << " |" << endl;
	

}
string getString()
{
	string inputStr;
	string listOfStrings = "hello";

	while (1)
	{
		cin >> inputStr;
		if (inputStr!=listOfStrings)
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
vector<string> checkForChars(string input)
{
	string correctString = "hello";
	vector< string > charArr;

	
	return charArr;
}




