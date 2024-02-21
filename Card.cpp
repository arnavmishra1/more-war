#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(char r, char s) {
	rank = r;
	suit = s;
	dictionary = {{'A',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}, {'T',10}, {'J',11}, {'Q',12}, {'K',13}};
}

void Card::display() {
	if (rank != 'T') {
		cout << rank << suit;
	} else {
		cout << 10 << suit;
	}
}

int Card::compare(Card other) {
	if (dictionary[rank] > dictionary[other.rank]) {
		return 1;
	} else if (dictionary[rank] == dictionary[other.rank]) {
		return 0;
	} else {
		return -1;
	}
}
