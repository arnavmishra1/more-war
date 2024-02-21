#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>

#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck() {

	suits = {'C','S','D','H'};
	ranks = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				myDeck.push_back(Card(ranks[j], suits[i]));
			}
		}
}

Card Deck::deal() {
	Card temp = myDeck[0];
	myDeck.erase(myDeck.begin());
	return temp;
}

void Deck::display()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (j < 12) {
				myDeck[(i*13 + j)].display();
				cout << ", ";
			} else {
				myDeck[(i*13 + j)].display();
				cout  << "\n";
			}
		}
	}
}

void Deck::shuffle() {
	vector<Card> temp;
	srand(time(NULL));

	for (int i = 0; i < 52; i++) {
		srand(time(NULL));
		int random = rand() % myDeck.size();

		temp.push_back(myDeck[random]);
		swap(myDeck[random], myDeck[0]);
		myDeck.erase(myDeck.begin());
	}

	myDeck = temp;
}