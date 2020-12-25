#pragma once

#ifndef _CARD_H
#define _CARD_H

using namespace std;


class Card {

public:
	Card();
	Card(char type1, char suit1);

	~Card() { };
	
	char get_type() const;
	char get_suit() const;

	void set_type(char type1);
	void set_suit(char suit1);

	void print_card();

	bool operator==(const Card &c1);

private:
	char type;
	char suit;



};
#endif