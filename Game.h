#pragma once

#ifndef _GAME_H
#define _GAME_H

#include <fstream>

#include "Player.h"
#include "Human.h"
#include "Computer.h"

using namespace std;


class Game {

public:
	Game(Human p1, Computer p2);
	Game(Human p1, Computer p2, string fileName);

	~Game() { };

private:
	int number_of_spaces(string one_meld);
	int number_of_commas(string line);
	void adding_melds(string one_meld, Player& one_player);
	void adding_melds_names(string one_meld, Player& one_player, Card trump);
	void get_rid_of_end_space(string& str);
	char another_round_validation();
	int round_number;

};
#endif