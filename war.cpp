// Author: Arnav Mishra
// CECS 325-02 Prog 1
// Due 02/15/2024

#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

int main() {
	Deck myDeck;

	string p1;
	string p2;

	int counter = 0;

	int p1wins = 0;
	int p2wins = 0;
	int p1losses = 0;
	int p2losses = 0;
	int ties = 0;

	cout << "Enter the name of the first player: ";
	getline(cin, p1);
	cout << "Enter the name of the second player: ";
	getline(cin, p2);
	cout << endl;

	cout << "Original Deck" << endl;
	myDeck.display();
	cout << endl;

	cout << "Shuffled Deck" << endl;
	myDeck.shuffle();
	myDeck.display();
	cout << endl;

	while(counter < 26) {
		Card card1 = myDeck.deal();
		Card card2 = myDeck.deal();

		cout << "Game " << counter+1 << endl;
		cout << "--------" << endl;

		cout << "	" << p1 << "=>";
		card1.display();
		cout << endl;

		cout << "	" << p2 << "=>";
		card2.display();
		cout << endl;

		int winner = card1.compare(card2);
		if (winner == 1) {
			cout << p1 << "=>Winner";
			p1wins++;
			p2losses++;
		} else if (winner == (-1)) {
			cout << p2 << "=>Winner";
			p2wins++;
			p1losses++;
		} else {
			cout << "Tie!";
			ties++;
		}
		cout << "\n" << endl;

		counter++;
	}

	cout << "------Final Stats------" << endl;
	cout << "	" << p1 << "	vs.	" << p2 << endl;
	cout << "Wins	" << p1wins << "		" << p2wins << endl;
	cout << "Losses	" << p1losses << "		" << p2losses << endl;
	cout << "Ties	" << ties << "		" << ties << endl;

	return 0;
}
