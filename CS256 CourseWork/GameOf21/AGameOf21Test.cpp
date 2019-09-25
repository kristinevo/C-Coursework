#include "stdafx.h"
#include "AGameOf21.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char cont = 'y';
	int rollTotal, roll1, roll2;
	cout << "Welcome to a Game of Blackjack...with DIE!" << endl;
	AGameOf21 b;
	while (cont == 'y') {
		roll1 = b.rollDie();
		roll2 = b.rollDie();
		rollTotal = roll1 + roll2;
		b.setComputerScore(rollTotal);

		roll1 = 0;
		roll2 = 0;
		roll1 = b.rollDie();
		roll2 = b.rollDie();
		rollTotal = roll1 + roll2;
		b.setPlayerScore(rollTotal);
		if (b.getPlayerScore() < 21) {
			cout << "Your current score is " << b.getPlayerScore() << endl;
			cout << "Would you like to roll the die again? y or n" << endl;
			cin >> cont;
		}
		else if (b.getPlayerScore() > 21) {
			cont = 'n';
		}
		
	}
	cout << "Your final score is " << b.getPlayerScore() << endl;
	cout << "Your opponent's final score is " << b.getComputerScore() << endl;
	if ((b.getComputerScore() == b.getPlayerScore())){
		cout << "it's a tie." << endl;
	}

	else if (b.getComputerScore() <= 21 && b.getPlayerScore() <= 21) {
		if ((b.getComputerScore() > b.getPlayerScore())) {
			cout << "You have lost! Better luck next time! :)" << endl;
		}
		else if ((b.getComputerScore() < b.getPlayerScore())) {
			cout << "Congrats! You have won!" << endl;
		}
	}

	else if (b.getComputerScore() > 21 || b.getPlayerScore() > 21) {
		if (b.getComputerScore() > 21 && b.getPlayerScore() <= 21) {
			cout << "Congrats! You have won!" << endl;
		}

		else if (b.getComputerScore() <= 21 && b.getPlayerScore() > 21) {
			cout << "You have lost! Better luck next time! :)" << endl;
		}
		else if ((b.getComputerScore() > 21 && b.getPlayerScore() > 21)) {
			cout << "it's a tie." << endl;
		}
	}
	return 0;

}

