#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <vector>
#include "Card.h"

using namespace std;

class Player {

public:
	Player(string name);

	~Player() { };

	virtual Card play(Card trump, char lead_type, char lead_suit) = 0;

	void add_to_round_score(int pts);
	void add_to_game_score(int pts);
	void initialize_round_score();
	void add_to_hand(Card c1);
	void add_to_previous_melds_cards(string c1);
	void add_to_previous_melds_names(string meld_name);

	//void add_to_capture(Card c1);
	void add_to_capture(Card lead, Card chase);
	void add_to_capture(char t, char s);
	bool is_card_valid(string c);
	
	int get_round_score() const;
	int get_game_score() const;
	string get_name() const;
	vector<Card> get_capture_pile() const;
	vector<Card> get_hand() const;
	vector<string> get_previous_melds_names() const;
	vector<string> get_previous_melds_cards() const;
	
	void print_hand();
	void print_capture_pile();
	void print_previous_melds_cards();
	void clear_for_new_round();

	int try_a_meld(vector<Card> meld_vector, string meld_name, Card trump);
	void add_meld_cards(string meld_name, char trumpSuit);
	string best_meld(vector<Card> meld_vector, Card trump);
	virtual bool would_you_meld(Card trump) = 0;
	virtual void perform_a_meld(Card trump) = 0;
	virtual int player_selection() = 0;
	virtual void help_with_meld(Card trump) = 0;
	string strategy_lead(Card trump);
	string strategy_chase(Card trump, char lead_type, char lead_suit);

	void set_game_score(int gameS);
	void set_round_score(int roundS);
	
protected:
	string name;
	int round_score, game_score;

	vector<Card> hand;
	vector<Card> capture_pile;
	vector<string> previous_melds_names;
	vector<string> previous_melds_cards;



	//Private functions to check melds
	int flush_meld(vector<Card> hand, Card trump);
	int four_aces_meld(vector<Card> hand, Card trump);
	int four_kings_meld(vector<Card> hand, Card trump);
	int four_queens_meld(vector<Card> hand, Card trump);
	int royal_marriage_meld(vector<Card> hand, Card trump);
	int four_jacks_meld(vector<Card> hand, Card trump);
	int pinochle_meld(vector<Card> hand, Card trump);
	int spade_marriage_meld(vector<Card> hand, Card trump);
	int heart_marriage_meld(vector<Card> hand, Card trump);
	int diamond_marriage_meld(vector<Card> hand, Card trump);
	int club_marriage_meld(vector<Card> hand, Card trump);
	int dix_meld(vector<Card> hand, Card trump);
	
	vector<Card> remove_meld_cards(Card trump);
	
	int find_card_index(char card_type);


};
#endif