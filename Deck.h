#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "Card.h"
#include <vector>

using namespace std;

class Deck {
	private:
		vector<char> suits;
		vector<char> ranks;
		vector<Card> myDeck;
	public:
		Deck();
		Card deal();
		void display();
		void shuffle();
};
#endif