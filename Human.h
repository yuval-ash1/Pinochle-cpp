#pragma once

#ifndef _HUMAN_H
#define _HUMAN_H

#include "Player.h"


using namespace std;


class Human:public Player{

public:
	
	Human(string name) :Player(name) {};

	~Human() { };

	virtual Card play(Card trump, char lead_type, char lead_suit);
	virtual bool would_you_meld(Card trump);
	virtual void perform_a_meld(Card trump);
	virtual int player_selection();
	virtual void help_with_meld(Card trump);

private:



};
#endif