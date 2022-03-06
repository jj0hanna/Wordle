
#include <iostream>
#include <string>
#include <vector>

#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"
using namespace std;

void theGame();
string getString();
string checkString(string input);

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
	//vector<string> stringArr;
	string input;
	int guesses = 0;

	string correctString = "hallo";
	cout << FOREGROUND(ForegroundColor::DarkBlue,"       Wordle") << endl;
	do
	{
		input = getString();
		checkString(input);


		cout << "| " << input[0] << " | " << input[1] << " | " << input[2] << " | " << input[3] << " | " << input[4] << " |" << endl;
		guesses++;

		
		cout << guesses << endl;
		

	} while (input != correctString && guesses != 6); // what way sould i write? input != correctString or input.compare(correctString)

	if (input == correctString )
	{
		cout << "You found the right word: " << correctString << endl;
	}
	else
	{
		cout << "You did not find the right word. The right word was: " << correctString << endl;
	}

	cout << "End of game" << endl;
	
	

}
string getString() // send in list of strings
{
	string inputStr;
	string listOfStrings = "hallo";

	while (1)
	{
		cin >> inputStr;
		if (inputStr!=listOfStrings || inputStr.size() > 5) // check if the input is a real word or not. Checks if the input is more then 5 chars long
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
string checkString(string input) // hlles
{
	string correctString = "hallo"; // how to do if the input have 2 of the same letter
	

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < correctString.size(); j++)
		{
			if (input[i] == correctString[j])
			{
				cout << FOREGROUND(ForegroundColor::DarkBlue, input[i]);
				//check if that input[i] has the same index as correctstring[j]
				//if they have the same index set that input[i] to green backgorund, break
				//else set that input[i] to have yellow background, break
			}
			else if (correctString.size() - 1 == j)
			{
				cout << BACKGROUND(BackgroundColor::Gray, input[i]);
			}
		}
	}
	return input;
}

