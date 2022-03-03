
#include <iostream>
using namespace std;

int main()
{
	int input;
	cout << "-- Welcome to the game wordle --";
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
	string correctString = "hallo";


}


