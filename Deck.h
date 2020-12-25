#pragma once

#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include "Card.h"
#include "Player.h"

using namespace std;


class Deck {

public:
	Deck();
	Deck(vector<string> deck1);

	~Deck() { };

	vector<Card> get_deck() const;
	Card get_trump() const;
	void set_trump(string trump_card);

	void shuffle_deck();
	void deal_cards(Player* playerList, int nextPlayerIndex);
	void deal_turn_cards(Player* playerList, int nextPlayerIndex);

	void print_deck();
	void print_trump();
	


private:
	vector<Card> deck;
	Card trump;
};
#endif