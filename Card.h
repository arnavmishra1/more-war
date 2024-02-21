#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <map>

using namespace std;

class Card {
	private:
		char rank;
		char suit;
		map<char,int> dictionary;
	public:
		Card(char, char);
		void display();
		int compare(Card);
};
#endif