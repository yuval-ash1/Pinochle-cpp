#pragma once
#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "Player.h"

using namespace std;


class Computer :public Player {

public:
	Computer(string name="Computer") :Player(name) {};

	~Computer() {};

	virtual Card play(Card trump, char lead_type, char lead_suit);
	virtual bool would_you_meld(Card trump);
	virtual void perform_a_meld(Card trump);
	virtual int player_selection();
	virtual void help_with_meld(Card trump);

private:



};
#endif