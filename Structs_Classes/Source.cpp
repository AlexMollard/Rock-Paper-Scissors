#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
using namespace std;

																							// Font formatting
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"

																							// Macros

#define B << (char)205																		// ═
#define Border B B B B B B B B B B B B B B B B B B B B B B B B B							// ═══════════════════


int ComputerChoice()																		// Generate random number function.
{
	int randomNum = rand() % 3;																// Get random number from 0 to 2.
	return randomNum;																		// Returns number between 0 and 2.
}


string RPS(int num1)																		// Rock Paper Scissors.
{
	switch (num1)																			// Test num1 and compares to cases to return a string.
	{
	case 0:																					// if 0
		return "Rock";																		// Rock
		break;
	case 1:																					// if 1
		return "Paper";																		// Paper
		break;
	case 2:																					// if 2
		return "Scissors";																	// Scissors
		break;
	}
}

int Game(int comp, int user)																// Checks who the winner is.
{
	if (comp == user) { cout << "It's a Tie \n"; return 0; }

	if (comp == 0 && user == 1) { cout << "Player wins! \n"; return 1;}								// Player win checks.
	if (comp == 1 && user == 2) { cout << "Player wins! \n"; return 1;}
	if (comp == 2 && user == 0) { cout << "Player wins! \n"; return 1;}

	if (comp == 1 && user == 0) { cout << "Computer wins! \n"; return 2;}								// Computer win checks.
	if (comp == 2 && user == 1) { cout << "Computer wins! \n"; return 2;}
	if (comp == 0 && user == 2) { cout << "Computer wins! \n"; return 2;}
}


int main()
{
	
	srand(time(NULL));																		// Get new seed.

																							// Declaring varibles
	int input = 0;
	int playInput = 0;
	int winner = 0;
	int score[2] = {0,0};
	bool play = true;

	do
	{

		cout << "	" << (char)201 Border << (char)187 << "\n";								                        // ╔═════════════════════╗
		cout << "	" << (char)186 << GREEN << BOLD << "  Rock  Paper  Scissors  " << RESET << (char)186 << "\n";	// ║ Rock Paper Scissors ║
		cout << "	" << (char)200 Border << (char)188 << "\n" ;								                    // ╚═════════════════════╝
	
	
		cout << "Score's: " << "Player: " << score[0] << " | Computer: " << score[1] << "\n\n";	// Display Scores
	
	
	
	
	
		cout << "0. Rock \n";																	// Choice: 0
		cout << "1. Paper \n";																	// Choice: 1
		cout << "2. Scissors \n";																// Choice: 2
		cout << "Choose your move: " << YELLOW << BOLD;											// Asking player to make a choice.
	
	
	
		do {																					// Looping the player if input is invaild.
			cin >> input;																		// Getting the players choice.
		} while (input > 2 || input < 0);														
	
	
		cout << RESET;																	        // Resetting the console font.
	
	
	
	
		int computer = ComputerChoice();														// Gives computer value of computerChoice function.
	
		winner = Game(computer, input);															// Making winner = (0 || 1 || 2) for (Tie || Player || Computer)
	
	
		switch (winner)																			// Add score to winner
		{
		case 0:
			break;
		case 1:
			score[0]++;
			break;
		case 2:
			score[1]++;
			break;
		}
	

			

		cout << "Would you like to play again? \n 0. No \n 1. Yes \n";							// Ask player if they wopuld like to play again

		do {																					// Loop if input is invalid
			cin >> playInput;																	// Get input from player
		} while (playInput > 1 || playInput < 0);

		switch (playInput)																		// Change value of play
		{
		case 0:
			play = false;
			break;
		case 1:
			play = true;
			break;
		}



		system("cls");																		   // Clear Console
	
	} while (play);
	return 0;																				   // Returns 0
}