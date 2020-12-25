#pragma once

#ifndef _ROUND_H
#define _ROUND_H

#include "Player.h"
#include "Card.h"
#include "Turn.h"
#include "Human.h"
#include "Computer.h"
#include "Deck.h"

using namespace std;


class Round {

public:
	Round(int round_number, Human& p1, Computer& p2);
	Round(int round_number, Human& p1, Computer& p2, Deck help_deck, string nextPlayer);

	~Round() { };

	bool toss_a_coin(string p_name);


private:
	Player* playerList[2];
	int nextPlayerIndex;

};
#endif