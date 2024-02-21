// Author: Arnav Mishra
// CECS 325-02 Prog 1
// Due 02/15/2024

#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Card class
class Card {
	char rank;
	char suit;
	map<char,int> dictionary;

	public:
		Card() {
			rank = '0';
			suit = '0';
		}

		Card(char r, char s) {
			rank = r;
			suit = s;
			dictionary = {{'A',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}, {'T',10}, {'J',11}, {'Q',12}, {'K',13}};
		}

		void display() {
			if (rank != 'T') {
				cout << rank << suit;
			} else {
				cout << 10 << suit;
			}
		}

		int compare(Card other) {
			if (dictionary[rank] > dictionary[other.rank]) {
				return 1;
			} else if (dictionary[rank] == dictionary[other.rank]) {
				return 0;
			} else {
				return -1;
			}
		}
};

// Deck class
class Deck {
	vector<char> suits;
	vector<char> ranks;
	Card myDeck[52];
	int index = 0;

	public:
		Deck() {

			suits = {'C','S','D','H'};
			ranks = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
			
			for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 13; j++)
					{
						myDeck[i*13 + j] = Card(ranks[j], suits[i]);
					}
				}
		}

		Card deal() {
			if (isEmpty()) {
				throw runtime_error("Error - Deck is empty");
			}
			Card temp = myDeck[index];
			index++;
			return temp;
		}

		void display()
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

		void shuffle() {
			srand(time(NULL));

			for (int i = 0; i < 52; i++) {
				int random = rand() % 52;
				swap(myDeck[i],myDeck[random]);
			}
		}

		bool isEmpty() {
			return (index >= 52) ? true : false;
		}
};

int main() {
	Deck myDeck;

	string p1;
	string p2;
	int games;

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
	cout << "How many games will they play? ";
	cin >> games;
	cout << endl;

	cout << "Original Deck" << endl;
	myDeck.display();
	cout << endl;

	cout << "Shuffled Deck" << endl;
	myDeck.shuffle();
	myDeck.display();
	cout << endl;

	while(counter < games) {
		Card card1;
		Card card2;

		try {
			card1 = myDeck.deal();
			card2 = myDeck.deal();
		}
		catch (runtime_error) {
			break;
		}

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
