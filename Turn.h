#pragma once

#ifndef _TURN_H
#define _TURN_H

#include "Round.h"
//#include "Player.h"

using namespace std;


class Turn {

public:
	Turn(Player* playerList, int &nextPlayerIndex, Card trump, int round_number, vector<Card> deck);
	~Turn() {}
	bool winner(Card lead, Card chase, Card trump);
	int points(Card lead, Card chase);



private:

	int flush, fourA, fourK, fourQ, royal_marriage, fourJ, pinochle, marriage, dix;

	void save_the_game(Player* playerList, int nextPlayerIndex, Card trump, vector<Card> deck, int round_number);
	
};
#endif