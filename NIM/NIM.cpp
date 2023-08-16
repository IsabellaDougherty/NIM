/* The game of NIM*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	// ------------------------------ Variable Declarations ------------------------------
	int num_objects;
	int current_player = 1;
	int player = 0;
	int computer = 0;
	int move;
	int saying;
	string objects_remaining;
	string exit = "0";
	srand(time(NULL)); 
	//------------------------------ Explain the rules ------------------------------
	cout << "You have undertaken the game of NIM. NIM utilizes very simple rules. \n1. Generally, 23 objects are placed into a pile." << endl;
	cout << "2. The first player removes any amount of pieces from the pile in any quantity of 1, 2, or 3. \n3. The second player takes any amount of pieces in the same fashion." << endl;
	cout << "4. This continues until the pile is empty. Whoever has taken the final piece is the loser. \nNow, it is time to face your opponent!" << endl;
	//------------------------------ Beginning of the main game loop ------------------------------
	do {
		current_player = 1;
		do {
			cout << "So, how many pieces would you like to play with?" << endl;
			cin >> num_objects;
			if (num_objects < 2) {
				cout << "This isn't an acceptable amount of pieces. Please input an acceptable number." << endl;
			}
		} while (num_objects < 2);
		do {
			objects_remaining = "";
			for (int i = 1; i <= num_objects; ++i) {
				objects_remaining += " ~0~ ";
			}
			cout << objects_remaining << endl;
			if (current_player == 1) {
				cout << "Challenger, how many pieces do you retrieve? (1-3): ";
				cin >> move;
				while (move < 1 || move > 3 || move > num_objects) {
					cout << "This is unacceptable. Try again. \nEnter a new move: ";
					cin >> move;
				}
				cout << "Challenger has retrieved " << move << " pieces." << endl;
			}
			else {
				do {
					if (num_objects == 2) {
						move = 1;
					}
					else if (num_objects == 3) {
						move = 2;
					}
					else if (num_objects == 4) {
						move = 3;
					}
					else {
						move = 1 + rand() % 3;
					}
				} while (move < 1 || move > 3 || move > num_objects);
				cout << "Your enemy has removed " << move << endl;
			}
			num_objects = num_objects - move;

			cout << "\n" << num_objects << " pieces remaining.\n";
			if (num_objects > 8) {
				saying = rand() % 5;
				if (saying == 1) {
					cout << "\nIt's still anyone's game!\n" << endl;
				}
				if (saying == 2) {
					cout << "\nInteresting move by player " << current_player << "\n" << endl;
				}
				if (saying == 3) {
					cout << "\nThe tensions heating up!\n" << endl;
				}
				if (saying == 4) {
					cout << "\nNot what I would have done but to each their own.\n" << endl;
				}
				if (saying == 5) {
					cout << "\nWOW! Can you believe that!\n" << endl;
				}
			}
			else if (num_objects <= 8 && num_objects > 5) {
				saying = rand() % 2;
				if (saying == 1) {
					cout << "\nThis move may decide it all!\n" << endl;
				}
				if (saying == 2) {
					cout << "\nThe game might as well be over!\n" << endl;
				}
			}
			else if (num_objects <= 5) {
				saying = rand() % 3;
				if (saying == 1) {
					cout << "\nIt all comes down to this!\n" << endl;
				}
				if (saying == 2) {
					cout << "\nPlayer " << player << " may pull through!\n" << endl;
				}
				if (saying == 3) {
					cout << "\nI can't believe it! This move decides it all!!!\n" << endl;
				}
			}

			current_player = (current_player + 1) % 2;
		} while (num_objects > 0);
		//------------------------------ end of the game loop ------------------------------
		cout << "Player " << current_player << " has emerged victorious!!!" << endl;
		if (current_player == 1) {
			player += 1;
		}
		else {
			computer += 1;
		}
		cout << "The current score is:\n Challenger: " << player << "\n Enemy: " << computer << endl;
		cout << "Would you like to play again?\nEnter '0' for 'Yes' and '1' for 'No'." << endl;
		cin >> exit;
	} while (exit == "0");
	cout << "\nPress enter to quit.\n";
	cin.ignore();
	return 0;
}