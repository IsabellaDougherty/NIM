/* THe game of NIM*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	// ------------------------------ Variable Declarations ------------------------------

	int num_objects;
	int current_player = 1;
	int move;
	srand(time(NULL)); 

	//------------------------------ Explain the rules ------------------------------

	cout << "You have undertaken the game of NIM. NIM utilizes very simple rules. \n1. Generally, 23 objects are placed into a pile." << endl;
	cout << "2. The first player removes any amount of pieces from the pile in any quantity of 1, 2, or 3. \n3. The second player takes any amount of pieces in the same fashion." << endl;
	cout << "4. This continues until the pile is empty. Whoever has taken the final piece is the loser. \nNow, it is time to face your opponent!" << endl;
	
	do {
		cout << "So, how many pieces would you like to play with?" << endl;
		cin >> num_objects;
		if (num_objects < 2) {
			cout << "This isn't an acceptable amount of pieces. Please input an acceptable number." << endl;
		}
	} while (num_objects < 2);
	//------------------------------ Beginning of the main game loop ------------------------------

	do {
		if (current_player == 1) {
			cout << "Challenger, how many pieces do you retrieve? (1-3): ";
			cin >> move;
			while (move < 1 || move > 3 || move > num_objects) 
			{
				cout << "This is unacceptable. Try again. \nEnter a new move: ";
				cin >> move;
			}
			cout << "Challenger has retrieved " << move << " pieces." << endl;
		}
		else {
			do  {
				move = 1 + rand() % 3;
			} while (move < 1 || move > 3 || move > num_objects);
			cout << "Your enemy has removed " << move << endl;
		}
		num_objects = num_objects - move;
		cout << num_objects << " pieces remaining.\n";
		current_player = (current_player + 1) % 2;
		} while (num_objects > 0);
	//------------------------------ end of the game loop ------------------------------

	cout << "Player " << current_player << " has emerged victorious!!!\n";
	cin.ignore();
	cout << "\nPress enter to quit.\n";
	cin.ignore();
	return 0;
}