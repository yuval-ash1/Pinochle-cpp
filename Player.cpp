
#include "Player.h"
#include <iostream>
#include<iterator>
#include <stdio.h>
#include <ctype.h>


/* *********************************************************************
Function Name: Player (constructor)
Purpose:
	The constructor for the Player class- initializing the player's name & scor
Parameters:
	name- string type that represents the name of the Player
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. local name gets name1
	2. local game score gets 0
	3. local round score gets 0
Assistance Received:
	None.
********************************************************************* */
Player::Player(string name1) {
	name = name1;
	game_score = 0;
	round_score = 0;
}


/* *********************************************************************
Function Name: add_to_round_score
Purpose:
	This function adds points to the player's round score
Parameters:
	pts- int type holds the number of points to add
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. add pts to local round_score 
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_round_score(int pts)
{
	round_score += pts;
}


/* *********************************************************************
Function Name: add_to_game_score
Purpose:
	This function adds points to the player's game score
Parameters:
	pts- int type holds the number of points to add
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. add pts to local game_score
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_game_score(int pts)
{
	game_score += pts;
}

/* *********************************************************************
Function Name: initialize_round_score
Purpose:
	This function initialized the player's round score at the end of every round
Parameters:
	None.
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. set local round_score to 0
Assistance Received:
	None.
********************************************************************* */
void Player::initialize_round_score()
{
	round_score = 0;
}


/* *********************************************************************
Function Name: add_to_hand
Purpose:
	This function gets a card as as input and adds it to the player's hand
Parameters:
	c1- Card type which holds a card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. push c1 to hand
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_hand(Card c1) {
	hand.push_back(c1);
}


/* *********************************************************************
Function Name: add_to_previous_melds_cards
Purpose:
	This function gets a string type as as input and adds it to the player's
	previous_melds_cards
Parameters:
	c1- string type which holds a card's type and suit
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. push c1 to previous_melds_cards
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_previous_melds_cards(string c1) {
	previous_melds_cards.push_back(c1);
}


/* *********************************************************************
Function Name: add_to_previous_melds_names
Purpose:
	This function gets a string type as as input and adds it to the player's
	previous_melds_names
Parameters:
	meld_name- string type which holds a meld name
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. push c1 to previous_melds_names
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_previous_melds_names(string meld_name) {
	previous_melds_names.push_back(meld_name);
}
/*
This functions gets 2 cards (lead, chase) and adds it to the winner's capture pile
*/

/* *********************************************************************
Function Name: add_to_capture
Purpose:
	This functions gets 2 cards (lead, chase) and adds it to the winner's capture pile
Parameters:
	lead, chase- Card types which hold the lead and the chase cards of that round
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. push lead to capture_pile
	2. push chase to capture_pile
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_capture(Card lead, Card chase) {
	capture_pile.push_back(lead);
	capture_pile.push_back(chase);
}

/* *********************************************************************
Function Name: add_to_capture
Purpose:
	This functions gets 2 char types (s, t) and adds the cards they
	represent to the winner's capture pile
Parameters:
	t, s- char types which hold the type and the suit (respectively) of a card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. push Card(t,s) to capture_pile
Assistance Received:
	None.
********************************************************************* */
void Player::add_to_capture(char t, char s) {
	capture_pile.push_back(Card(t, s));
}

/*

*/

/* *********************************************************************
Function Name: is_card_valid
Purpose:
	This function get a string (user input), which represents a card from the user's hand
	It returns true if this card exists in the user's hand, false otherwise
Parameters:
	c- string type which represents a card
Return Value:
	boolean type of whether the card is valid or not
Local Variables:
	valid- boolead type which holds true if card valid and false if not
Algorithm:
	1. valid = false
	2. iterate through player's hand:
		-if current card = c
			-valid = true
	3. return valid
Assistance Received:
	None.
********************************************************************* */
bool Player::is_card_valid(string c) {
	bool valid = false;
	vector<Card> hand2 = get_hand();
	for (auto it = hand2.begin(); it < hand2.end(); it++)
	{
		if ((c[0] == (*it).get_type()) && (c[1] == (*it).get_suit()))
		{
			valid = true;
			break;
		}
	}
	return valid;
}


/* *********************************************************************
Function Name: get_round_score
Purpose:
	This function returns the round score of the player
Parameters:
	None.
Return Value:
	a const int type containing the round score of the player
Local Variables:
	None.
Algorithm:
	
Assistance Received:
	None.
********************************************************************* */
int Player::get_round_score() const {
	return round_score;
}


/* *********************************************************************
Function Name: get_game_score
Purpose:
	This function returns the game score of the player
Parameters:
	None.
Return Value:
	a const int type containing the game score of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
int Player::get_game_score() const {
	return game_score;
}


/* *********************************************************************
Function Name: get_name
Purpose:
	This function returns the name of the player
Parameters:
	None.
Return Value:
	a const string type containing the name of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
string Player::get_name() const{
	return name;
}


/* *********************************************************************
Function Name: get_capture_pile
Purpose:
	This function returns the capture pile vector of the player
Parameters:
	None.
Return Value:
	a const Card vector type containing the capture pile of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
vector<Card>Player::get_capture_pile() const{	//YUVAL: don't think I need that
	return capture_pile;
}


/* *********************************************************************
Function Name: get_hand
Purpose:
	This function returns the hand vector of the player
Parameters:
	None.
Return Value:
	a const Card vector type containing the hand of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
vector<Card> Player::get_hand() const {
	return hand;
}


/* *********************************************************************
Function Name: get_previous_melds_names
Purpose:
	This function returns the previous_melds_names vector of the player
Parameters:
	None.
Return Value:
	a const string vector type containing the previous_melds_names of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
vector<string> Player::get_previous_melds_names() const {
	return previous_melds_names;
}

/* *********************************************************************
Function Name: get_previous_melds_cards
Purpose:
	This function returns the previous_melds_cards vector of the player
Parameters:
	None.
Return Value:
	a const string vector type containing the previous_melds_cards of the player
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
vector<string> Player::get_previous_melds_cards() const {
	return previous_melds_cards;
}


/* *********************************************************************
Function Name: print_hand
Purpose:
	This function prints all the cards in the player's hand in the followng format "TypeSuit"
Parameters:
	None.
Return Value:
	None
Local Variables:
	t,s- char types which hold the type and the suit of a Card object repectively
Algorithm:
	1. iterate through hand
		-print type of card in uppercase
		-print suit of card in uppercase
Assistance Received:
	None.
********************************************************************* */
void Player::print_hand() {
	char t, s;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		t = (*it).get_type();
		s = (*it).get_suit();
		putchar(toupper(t));
		putchar(toupper(s));
		cout << " ";
	}
	cout << endl;
}


/* *********************************************************************
Function Name: print_capture_pile
Purpose:
	This function prints all the cards in the player's capture pile
	in the followng format "TypeSuit"
Parameters:
	None.
Return Value:
	None
Local Variables:
	count- integer type to keep track of the nubmer of cards displayed per line
	t,s- char types which hold the type and the suit of a Card object repectively
Algorithm:
	1. if capture pile is not empty
	2. iterate through capture pile: (print in a nice format)
		-print type of card in uppercase
		-print suit of card in uppercase
Assistance Received:
	None.
********************************************************************* */
void Player::print_capture_pile() {
	int count = 0;
	if (!(this->capture_pile.empty()))
	{
		//vector<Card> = p.get_hand();
		char t, s;
		for (auto it = capture_pile.begin(); it < capture_pile.end(); it++)
		{
			if (count > 0 && count % 15 == 0)
			{
				cout << endl << "\t\t\t";
			}
			t = (*it).get_type();
			s = (*it).get_suit();
			putchar(toupper(t));
			putchar(toupper(s));
			cout << " ";
			count++;
		}
	}
	cout << endl;
}


/* *********************************************************************
Function Name: print_previous_melds_cards
Purpose:
	This function prints all the cards in the player's preious_melds_cards
	in the followng format "TypeSuit"
Parameters:
	None.
Return Value:
	None
Local Variables:
	index- int type loop iterator
	it- a string vector iterator
Algorithm:
	1. if capture pile is not empty
	2. iterate through previous_melds_cards:
		-print content in uppercase
Assistance Received:
	None.
********************************************************************* */
void Player::print_previous_melds_cards()
{
	if (!(this->previous_melds_cards.empty()))
	{
		for (auto it = previous_melds_cards.begin(); it < previous_melds_cards.end(); it++)
		{
			for (size_t index = 0; index < (*it).size(); index++)
			{
				cout << char(toupper((*it)[index]));
			}
			cout << " ";
		}
	}
	cout << endl;
}


/* *********************************************************************
Function Name: clear_for_new_round
Purpose:
	This function resets score and clears melds_names, melds_cards, and
	capture_pile for a new round
Parameters:
	None.
Return Value:
	None
Local Variables:
	None.
Algorithm:
	1. round_score gets 0
	2. clear melds names
	3. clear melds cards
	4. clear capture pile
Assistance Received:
	None.
********************************************************************* */
void Player::clear_for_new_round()
{
	round_score = 0;
	previous_melds_cards.clear();
	previous_melds_names.clear();
	capture_pile.clear();
}


/* *********************************************************************
Function Name: try_a_meld
Purpose:
	This function tries to see if the input cards are good enough
	to perform the input meld_name 
Parameters:
	meld_vecor- a vector of cards containing the cards of the meld
	meld_name- a string type containing the meld name
	trump- a card type that holds the trump of the current round
Return Value:
	an integer type containing the amount of point a user can get performing
	the meld
Local Variables:
	None.
Algorithm:
	1. if meld_vector is empty
		-return 0
	2. for every meld name:
		-if meld_name = "a meld name"
			-if can earn point for this meld and have not performed that meld
				-push the meld name into previous melds
				-return the number of point getting for that meld
		-else
			-print "no melds"
			-return 0
Assistance Received:
	None.
********************************************************************* */
int Player::try_a_meld(vector<Card> meld_vector, string meld_name, Card trump)
{
	if ((meld_vector.empty()))
	{
		return 0;
	}
	if (meld_name == "flush")
	{
		int flush = flush_meld(meld_vector, trump);
		if (flush > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "flush") == previous_melds_names.end())
		{
			previous_melds_names.push_back("flush");
			add_meld_cards(meld_name, trump.get_suit());
			return 150;
		}
	}
	else if (meld_name == "fourA")
	{
		int fourA = four_aces_meld(meld_vector, trump);
		if (fourA > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourA") == previous_melds_names.end())
		{
			previous_melds_names.push_back("fourA");
			add_meld_cards(meld_name, trump.get_suit());
			return 100;
		}
	}
	else if (meld_name == "fourK")
	{
		int fourK = four_kings_meld(meld_vector, trump);
		if (fourK > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourK") == previous_melds_names.end())
		{
			previous_melds_names.push_back("fourK");
			add_meld_cards(meld_name, trump.get_suit());
			return 80;
		}
	}
	else if (meld_name == "fourQ")
	{
		int fourQ = four_queens_meld(meld_vector, trump);
		if (fourQ > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourQ") == previous_melds_names.end())
		{
			previous_melds_names.push_back("fourQ");
			add_meld_cards(meld_name, trump.get_suit());
			return 60;
		}
	}
	else if (meld_name == "royal_marriage")
	{
		int royal_marriage = royal_marriage_meld(meld_vector, trump);
		if (royal_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end())
		{
			previous_melds_names.push_back("royal_marriage");
			add_meld_cards(meld_name, trump.get_suit());
			return 40;
		}
	}
	else if (meld_name == "fourJ")
	{
		int fourJ = four_jacks_meld(meld_vector, trump);
		if (fourJ > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourJ") == previous_melds_names.end())
		{
			previous_melds_names.push_back("fourJ");
			add_meld_cards(meld_name, trump.get_suit());
			return 40;
		}
	}
	else if (meld_name == "pinochle")
	{
		int pinochle = pinochle_meld(meld_vector, trump);
		if (pinochle > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "pinochle") == previous_melds_names.end())
		{
			previous_melds_names.push_back("pinochle");
			add_meld_cards(meld_name, trump.get_suit());
			return 40;
		}
	}
	else if (meld_name == "spade_marriage")
	{
		int spade_marriage = spade_marriage_meld(meld_vector, trump);
		if (spade_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "spade_marriage") == previous_melds_names.end())
		{
			previous_melds_names.push_back("spade_marriage");
			add_meld_cards(meld_name, trump.get_suit());
			return 20;
		}
	}
	else if (meld_name == "heart_marriage")
	{
		int heart_marriage = heart_marriage_meld(meld_vector, trump);
		if (heart_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "heart_marriage") == previous_melds_names.end())
		{
			previous_melds_names.push_back("heart_marriage");
			add_meld_cards(meld_name, trump.get_suit());
			return 20;
		}
	}
	else if (meld_name == "diamond_marriage")
	{
		int diamond_marriage = diamond_marriage_meld(meld_vector, trump);
		if (diamond_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "diamond_marriage") == previous_melds_names.end())
		{
			previous_melds_names.push_back("diamond_marriage");
			add_meld_cards(meld_name, trump.get_suit());
			return 20;
		}
	}
	else if (meld_name == "club_marriage")
	{
		int club_marriage = club_marriage_meld(meld_vector, trump);
		if (club_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "club_marriage") == previous_melds_names.end())
		{
			previous_melds_names.push_back("club_marriage");
			add_meld_cards(meld_name, trump.get_suit());
			return 20;
		}
	}
	else if (meld_name == "dix")
	{
		int dix = dix_meld(meld_vector, trump);
		if (dix > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "dix") == previous_melds_names.end())
		{
			previous_melds_names.push_back("dix");
			add_meld_cards(meld_name, trump.get_suit());
			return 10;
		}
	}
	else
	{
		cout << "Meld name entered is not valid";
		return 0;
	}
}

/* *********************************************************************
Function Name: add_meld_cards
Purpose:
	This function adds the right cards to previous_melds_cards
Parameters:
	meld_name- a string type containing the meld name
	trumpSuit- a char type that holds the trump suit of the current round
Return Value:
	None.
Local Variables:
	cards- string type vector that holds the cards of the meld
Algorithm:
	1. for every meld name:
		-if meld_mane = "a meld name"
			-push cards the cards of the meld
		-push cards into previous_melds_cards
Assistance Received:
	None.
********************************************************************* */
void Player::add_meld_cards(string meld_name, char trumpSuit)
{
	vector<string> cards;
	trumpSuit = toupper(trumpSuit);
	if (meld_name == "flush")
	{
		string ace = "A", ten = "X", king = "K", queen = "Q", jack = "J";
		cards[0] = ace + trumpSuit;
		cards[1] = ten + trumpSuit;
		cards[2] = king + trumpSuit;
		cards[3] = queen + trumpSuit;
		cards[4] = jack + trumpSuit;

	}
	else if (meld_name == "fourA")
	{
		cards.push_back("AS");
		cards.push_back("AC");
		cards.push_back("AD");
		cards.push_back("AH");
	}
	else if (meld_name == "fourK")
	{
		cards.push_back("KS");
		cards.push_back("KC");
		cards.push_back("KD");
		cards.push_back("KH");
	}
	else if (meld_name == "fourQ")
	{
		cards.push_back("QS");
		cards.push_back("QC");
		cards.push_back("QD");
		cards.push_back("QH");
	}
	else if (meld_name == "royal_marriage")
	{

		string kingT = "K", queenT = "Q";
		kingT += trumpSuit;
		queenT += trumpSuit;
		cards.push_back(kingT);
		cards.push_back(queenT);
	}
	else if (meld_name == "fourJ")
	{
		cards.push_back("JS");
		cards.push_back("JC");
		cards.push_back("JD");
		cards.push_back("JH");
	}
	else if (meld_name == "pinochle")
	{
		cards.push_back("QS");
		cards.push_back("JD");
	}
	else if (meld_name == "spade_marriage")
	{
		cards.push_back("KS");
		cards.push_back("QS");
	}
	else if (meld_name == "heart_marriage")
	{
		cards.push_back("KH");
		cards.push_back("QH");
	}
	else if (meld_name == "diamond_marriage")
	{
		cards.push_back("KD");
		cards.push_back("QD");
	}
	else if (meld_name == "club_marriage")
	{
		cards.push_back("KC");
		cards.push_back("QC");
	}
	else if (meld_name == "dix")
	{
		string card = "9";
		card += trumpSuit;
		cards.push_back(card);
	}
	if (!previous_melds_cards.empty())
	{
		previous_melds_cards.push_back(",");
	}
	for (size_t index = 0; index < cards.size(); index++)
	{
		if (find(previous_melds_cards.begin(), previous_melds_cards.end(), cards[index]) == previous_melds_cards.end())
		{
			previous_melds_cards.push_back(cards[index]);
		}
		else
		{
			cards[index] = cards[index] + "*";
			previous_melds_cards.push_back(cards[index]);
		}
	}
}

/* *********************************************************************
Function Name: best_meld
Purpose:
	This function finds the best meld to perform
Parameters:
	meld_vector- Card type holding the vector of cards to perform the meld with
	trump- Card type that holds the trump of the round
Return Value:
	string holding the best meld's name.
Local Variables:

	flush, fourA, fourK, fourQ, royal_marriage,
	fourJ, 	pinochle, spade_marriage, heart_marriage,
	diamond_marriage, club_marriage, dix -integer type that hold the # of points
	user can recieve from each meld
Algorithm:
	1. if meld_vector is not empty:
		-for each meld:
			-meld name variable > 0 and meld has not been performed yet
			-return that meld's name
		-if nothing found:
			-return "No possible melds"
Assistance Received:
	None.
********************************************************************* */
string Player::best_meld(vector<Card> meld_vector, Card trump)
{
	if ((meld_vector.empty()))
	{
		return "No possible melds";
	}
	int flush = flush_meld(meld_vector, trump);
	int fourA = four_aces_meld(meld_vector, trump);
	int fourK = four_kings_meld(meld_vector, trump);
	int fourQ = four_queens_meld(meld_vector, trump);
	int royal_marriage = royal_marriage_meld(meld_vector, trump);
	int fourJ = four_jacks_meld(meld_vector, trump);
	int pinochle = pinochle_meld(meld_vector, trump);
	int spade_marriage = spade_marriage_meld(meld_vector, trump);
	int heart_marriage = heart_marriage_meld(meld_vector, trump);
	int diamond_marriage = diamond_marriage_meld(meld_vector, trump);
	int club_marriage = club_marriage_meld(meld_vector, trump);
	int dix = dix_meld(meld_vector, trump);

	if (flush > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "flush") == previous_melds_names.end())
	{
		return "flush";
	}
	else if (fourA > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourA") == previous_melds_names.end())
	{
		return "fourA";
	}
	else if (fourK > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourK") == previous_melds_names.end())
	{
		return "fourK";
	}
	else if (fourQ > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourQ") == previous_melds_names.end())
	{
		return "fourQ";
	}
	else if (royal_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end())
	{
		return "royal_marriage";
	}
	else if (fourJ > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "fourJ") == previous_melds_names.end())
	{
		return "fourJ";
	}
	else if (pinochle > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "pinochle") == previous_melds_names.end())
	{
		return "pinochle";
	}
	else if (spade_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "spade_marriage") == previous_melds_names.end())
	{
		if ((trump.get_suit() == 's'))
		{
			if ((find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end()))
			{
				return "royal_marriage";
			}
			else
			{
				return "No possible melds";
			}
		}
		return "spade_marriage";
	}
	else if (heart_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "heart_marriage") == previous_melds_names.end())
	{
		if (trump.get_suit() == 'h')
		{
			if ((find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end()))
			{
				return "royal_marriage";
			}
			else
			{
				return "No possible melds";
			}
		}
		return "heart_marriage";
	}
	else if (diamond_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "diamond_marriage") == previous_melds_names.end())
	{
		if (trump.get_suit() == 'd')
		{
			if ((find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end()))
			{
				return "royal_marriage";
			}
			else
			{
				return "No possible melds";
			}
		}
		return "diamond_marriage";
	}
	else if (club_marriage > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "club_marriage") == previous_melds_names.end())
	{
		if (trump.get_suit() == 'c')
		{
			if ((find(previous_melds_names.begin(), previous_melds_names.end(), "royal_marriage") == previous_melds_names.end()))
			{
				return "royal_marriage";
			}
			else
			{
				return "No possible melds";
			};
		}
		return "club_marriage";
	}
	else if (dix > 0 && find(previous_melds_names.begin(), previous_melds_names.end(), "dix") == previous_melds_names.end())
	{
		return "dix";
	}
	else
	{
		return "No possible melds";
	}
}





/**
	 This function finds the best meld to perform and crerates a clone of the player's hand, with
		the meld cards removed. This way, computer takes into account all the melds and wouldn't
		reccoment to play a card that can be used in a meld.
	 @param trump- Card type that holds the trump of the round.
	 @return the hand of the player with the best meld cards removed. If not possible melds- the
		original hand of the player.
	 */

/* *********************************************************************
 Function Name: remove_meld_cards
 Purpose:
	 This function finds the best meld to perform and crerates a clone of the player's hand, with
		the meld cards removed. This way, computer takes into account all the melds and wouldn't
		recommend to play a card that can be used in a meld.
 Parameters:
	 trump- Card type that holds the trump of the round
 Return Value:
	 The hand of the player with the best meld cards removed. If not possible melds- the
	 	original hand of the player.
 Local Variables:
	 aceT, tenT, kingT, queenT, jackT, nineT, kingS, queenS, kingH, queenH,
	 kingC, queenC, kingD, queenD, aceS, aceH, aceC, aceD, jackS, jackH,
	 jackC, jackD,-Card types that hold the card in which we are trying
	 to remove.
 Algorithm:
	 1. check the best meld
		 -remove the cards of the best meld from hand (if any)
			 -if hand is now empty- return original hand
			 -else- return updated hand
 Assistance Received:
	 None.
	********************************************************************* */
vector<Card> Player::remove_meld_cards(Card trump) {
	int index;
	Card aceT('a', trump.get_suit());
	Card tenT('x', trump.get_suit());
	Card kingT('k', trump.get_suit());
	Card queenT('q', trump.get_suit());
	Card jackT('j', trump.get_suit());
	Card nineT('9', trump.get_suit());
	Card kingS('k', 's');
	Card queenS('q', 's');
	Card kingH('k', 'h');
	Card queenH('q', 'h');
	Card kingC('k', 'c');
	Card queenC('q', 'c');
	Card kingD('k', 'd');
	Card queenD('q', 'd');
	Card aceS('a', 's');
	Card aceH('a', 'h');
	Card aceC('a', 'c');
	Card aceD('a', 'd');
	Card jackS('j', 's');
	Card jackH('j', 'h');
	Card jackC('j', 'c');
	Card jackD('j', 'd');


	vector<Card> newHand = hand;

	string best_m = best_meld(hand, trump);
	if (best_m == "No possible melds") {
		return hand;
	}
	else {
		if (best_m == "flush") {
			newHand.erase(find(newHand.begin(), newHand.end(), aceT));
			newHand.erase(find(newHand.begin(), newHand.end(), tenT));
			newHand.erase(find(newHand.begin(), newHand.end(), kingT));
			newHand.erase(find(newHand.begin(), newHand.end(), queenT));
			newHand.erase(find(newHand.begin(), newHand.end(), jackT));
		}
		else if (best_m == "fourA") {
			newHand.erase(find(newHand.begin(), newHand.end(), aceS));
			newHand.erase(find(newHand.begin(), newHand.end(), aceH));
			newHand.erase(find(newHand.begin(), newHand.end(), aceC));
			newHand.erase(find(newHand.begin(), newHand.end(), aceD));
		}
		else if (best_m == "fourK") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingS));
			newHand.erase(find(newHand.begin(), newHand.end(), kingH));
			newHand.erase(find(newHand.begin(), newHand.end(), kingC));
			newHand.erase(find(newHand.begin(), newHand.end(), kingD));
		}
		else if (best_m == "fourQ") {
			newHand.erase(find(newHand.begin(), newHand.end(), queenS));
			newHand.erase(find(newHand.begin(), newHand.end(), queenH));
			newHand.erase(find(newHand.begin(), newHand.end(), queenC));
			newHand.erase(find(newHand.begin(), newHand.end(), queenD));
		}
		else if (best_m == "royal_marriage") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingT));
			newHand.erase(find(newHand.begin(), newHand.end(), queenT));
		}
		else if (best_m == "fourJ") {
			newHand.erase(find(newHand.begin(), newHand.end(), jackS));
			newHand.erase(find(newHand.begin(), newHand.end(), jackH));
			newHand.erase(find(newHand.begin(), newHand.end(), jackC));
			newHand.erase(find(newHand.begin(), newHand.end(), jackD));
		}
		else if (best_m == "pinochle") {
			newHand.erase(find(newHand.begin(), newHand.end(), queenS));
			newHand.erase(find(newHand.begin(), newHand.end(), jackD));
		}
		else if (best_m == "spade_marriage") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingS));
			newHand.erase(find(newHand.begin(), newHand.end(), queenS));
		}
		else if (best_m == "heart_marriage") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingH));
			newHand.erase(find(newHand.begin(), newHand.end(), queenH));
		}
		else if (best_m == "diamond_marriage") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingD));
			newHand.erase(find(newHand.begin(), newHand.end(), queenD));
		}
		else if (best_m == "club_marriage") {
			newHand.erase(find(newHand.begin(), newHand.end(), kingC));
			newHand.erase(find(newHand.begin(), newHand.end(), queenC));
		}
		else { //else- this is a dix meld
			newHand.erase(find(newHand.begin(), newHand.end(), nineT));
		}
		if (newHand.size() > 0) {
			return newHand;
		}
		else {
			return hand;
		}
	}
}



/* *********************************************************************
Function Name: all of the meld functions
Purpose:
	The following functions are each checking for a specific type of meld
Parameters:
	hand- card type vector hold the cards for the meld
	trump- Card type that holds the trump of the round
Return Value:
	number of points getting from that meld (if possible to do this meld)
	0 otherwise
Local Variables:
	for each function- boolean variables with the names of the cards for that specific meld
Algorithm:
	1.all  meld vard variables get false
	2. iterate hand:
		- if current hand card = one of the neccessary meld cards
			-turn that meld vard variable into true
	3. if all meld variables are true:
		-return the amount of point getting for that meld
	4. else
		-return 0
Assistance Received:
	Professor Kumar's advice on how to approach best meld detection.
********************************************************************* */
int Player::flush_meld(vector<Card> hand, Card trump)
{
	bool trumpA = false, trumpT = false, trumpK = false, trumpQ = false, trumpJ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'a')
		{
			trumpA = true;
		}
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'x')
		{
			trumpT = true;
		}
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'k')
		{
			trumpK = true;
		}
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'q')
		{
			trumpQ = true;
		}
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'j')
		{
			trumpJ = true;
		}
	}
	if (trumpA && trumpT && trumpK && trumpQ && trumpJ)
	{
		return 150;
	}
	else
	{
		return 0;
	}
}

int Player::four_aces_meld(vector<Card> hand, Card trump)
{
	bool spadeA = false, clubA = false, diamondA = false, heartA = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'a')
		{
			spadeA = true;
		}
		else if ((*it).get_suit() == 'c' && (*it).get_type() == 'a')
		{
			clubA = true;
		}
		else if ((*it).get_suit() == 'd' && (*it).get_type() == 'a')
		{
			diamondA = true;
		}
		else if ((*it).get_suit() == 'h' && (*it).get_type() == 'a')
		{
			heartA = true;
		}
	}
	if (spadeA && clubA && diamondA && heartA)
	{
		return 100;
	}
	else
	{
		return 0;
	}
}

int Player::four_kings_meld(vector<Card> hand, Card trump)
{
	bool spadeK = false, clubK = false, diamondK = false, heartK = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'k')
		{
			spadeK = true;
		}
		else if ((*it).get_suit() == 'c' && (*it).get_type() == 'K')
		{
			clubK = true;
		}
		else if ((*it).get_suit() == 'd' && (*it).get_type() == 'K')
		{
			diamondK = true;
		}
		else if ((*it).get_suit() == 'h' && (*it).get_type() == 'K')
		{
			heartK = true;
		}
	}
	if (spadeK && clubK && diamondK && heartK)
	{
		return 80;
	}
	else
	{
		return 0;
	}
}
int Player::four_queens_meld(vector<Card> hand, Card trump)
{
	bool spadeQ = false, clubQ = false, diamondQ = false, heartQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'q')
		{
			spadeQ = true;
		}
		else if ((*it).get_suit() == 'c' && (*it).get_type() == 'q')
		{
			clubQ = true;
		}
		else if ((*it).get_suit() == 'd' && (*it).get_type() == 'q')
		{
			diamondQ = true;
		}
		else if ((*it).get_suit() == 'h' && (*it).get_type() == 'q')
		{
			heartQ = true;
		}
	}
	if (spadeQ && clubQ && diamondQ && heartQ)
	{
		return 60;
	}
	else
	{
		return 0;
	}
}
int Player::royal_marriage_meld(vector<Card> hand, Card trump)
{
	bool trumpK = false, trumpQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'k')
		{
			trumpK = true;
		}
		else if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == 'q')
		{
			trumpQ = true;
		}
	}
	if (trumpK && trumpQ)
	{
		return 40;
	}
	else
	{
		return 0;
	}
}
int Player::four_jacks_meld(vector<Card> hand, Card trump)
{
	bool spadeJ = false, clubJ = false, diamondJ = false, heartJ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'j')
		{
			spadeJ = true;
		}
		else if ((*it).get_suit() == 'c' && (*it).get_type() == 'j')
		{
			clubJ = true;
		}
		else if ((*it).get_suit() == 'd' && (*it).get_type() == 'j')
		{
			diamondJ = true;
		}
		else if ((*it).get_suit() == 'h' && (*it).get_type() == 'j')
		{
			heartJ = true;
		}
	}
	if (spadeJ && clubJ && diamondJ && heartJ)
	{
		return 40;
	}
	else
	{
		return 0;
	}
}

int Player::pinochle_meld(vector<Card> hand, Card trump)
{
	bool spadeQ = false, diamondJ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'q')
		{
			spadeQ = true;
		}
		if ((*it).get_suit() == 'd' && (*it).get_type() == 'j')
		{
			diamondJ = true;
		}
	}
	if (spadeQ && diamondJ)
	{
		return 40;
	}
	else
	{
		return 0;
	}
}
int Player::spade_marriage_meld(vector<Card> hand, Card trump)
{
	bool spadeK = false, spadeQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 's' && (*it).get_type() == 'k')
		{
			spadeK = true;
		}
		else if ((*it).get_suit() == 's' && (*it).get_type() == 'q')
		{
			spadeQ = true;
		}
	}
	if (spadeK && spadeQ)
	{
		return 20;
	}
	else
	{
		return 0;
	}
}

int Player::heart_marriage_meld(vector<Card> hand, Card trump)
{
	bool heartK = false, heartQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 'h' && (*it).get_type() == 'k')
		{
			heartK = true;
		}
		else if ((*it).get_suit() == 'h' && (*it).get_type() == 'q')
		{
			heartQ = true;
		}
	}
	if (heartK && heartQ)
	{
		return 20;
	}
	else
	{
		return 0;
	}
}
int Player::diamond_marriage_meld(vector<Card> hand, Card trump)
{
	bool diamondK = false, diamondQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 'd' && (*it).get_type() == 'k')
		{
			diamondK = true;
		}
		else if ((*it).get_suit() == 'd' && (*it).get_type() == 'q')
		{
			diamondQ = true;
		}
	}
	if (diamondK && diamondQ)
	{
		return 20;
	}
	else
	{
		return 0;
	}
}
int Player::club_marriage_meld(vector<Card> hand, Card trump)
{
	bool clubK = false, clubQ = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == 'c' && (*it).get_type() == 'k')
		{
			clubK = true;
		}
		else if ((*it).get_suit() == 'c' && (*it).get_type() == 'q')
		{
			clubQ = true;
		}
	}
	if (clubK && clubQ)
	{
		return 20;
	}
	else
	{
		return 0;
	}
}

int Player::dix_meld(vector<Card> hand, Card trump)
{
	bool trumpN = false;
	for (auto it = hand.begin(); it < hand.end(); it++)
	{
		if ((*it).get_suit() == trump.get_suit() && (*it).get_type() == '9')
		{
			trumpN = true;
		}
	}
	if (trumpN)
	{
		return 10;
	}
	else
	{
		return 0;
	}
}





/* *********************************************************************
Function Name: find_card_index
Purpose:
	This function is supposed to find the index of the card type (to know its priority)
Parameters:
	card_type- character type containing the card's type
Return Value:
	the index of this cards type in the local array
	(0 for 9, 1 for j, 2 for q, etc.)
Local Variables:
	index- loop iterator
Algorithm:
	1. initialize array of types
	2. iterate through array to types:
		-if card_type = array[index]
			-return index
Assistance Received:
	None.
********************************************************************* */
int Player::find_card_index(char card_type)
{
	char card_order[] = { '9', 'j', 'q', 'k', 'x', 'a' };
	for (size_t index = 0; index < 6; index++)
	{
		if (card_type == card_order[index])
		{
			return index;
		}
	}
	//This is just to make sure all paths of function return a value.
	//technically the function should never return -1 because all cards are validated
	//befre being sent to this function.
	return -1;	
}


/* *********************************************************************
Function Name: strategy_lead
Purpose:
	This function is contains the logic of the computer's strategy as lead player
Parameters:
	trump- Card type that holds the trump of the round
Return Value:
	a string type containing the the best card to play
Local Variables:
	best_card- a string type to gold the best card
	trump_cards- a char type vector to hold the card types that are of trump suit
Algorithm:
	1. Put the highest non-trump suit in hand (b/c it is the hardest to beat)
	2. If no non-trumps in hand-
		-Put the lowest trump from hand.
Assistance Received:
	None.
********************************************************************* */
string Player::strategy_lead(Card trump)
{
	string best_card;
	string strCard = "";
	vector<Card> newHand;
	newHand = remove_meld_cards(trump);

	vector<Card> non_trump_cards;
	for (auto it = newHand.begin(); it < newHand.end(); it++)
	{
		//pushing all non-trumps to a vector
		if ((*it).get_suit() != trump.get_suit())
		{
			non_trump_cards.push_back((*it));
		}
	}
	//if there are non trumps in my newHand
	if (!non_trump_cards.empty())
	{
		best_card = non_trump_cards[0].get_type();
		best_card += non_trump_cards[0].get_suit();
		for (auto it = non_trump_cards.begin(); it < non_trump_cards.end(); it++)
		{
			//if a non-trump with higher precedence is found-
			if ((find_card_index((*it).get_type())) < find_card_index(best_card[0]))
			{
				//this is the new best card.
				best_card = (*it).get_type();
				best_card += (*it).get_suit();
			}
		}
		cout << "Strategy: playing the highest non trump card in hand: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << " to win the round" << endl;
		return best_card;
	}
	else
	{
		//Setting best card to be first card in newHand (should be trump b/c no non-trumps)
		best_card = newHand[0].get_type() + newHand[0].get_suit();
		//Iterating through newHand
		for (auto it = newHand.begin(); it < newHand.end(); it++)
		{
			//If card's type is of lower precedence:
			if (find_card_index(best_card[0]) > find_card_index((*it).get_type()))
			{
				//Best card will now contain the better card.
				best_card = (*it).get_type() + (*it).get_suit();
			}
		}
		best_card += trump.get_suit();
		cout << "Strategy: playing the highest trump card in hand: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << endl;
		return best_card;
	}
}


/* *********************************************************************
Function Name: strategy_chase
Purpose:
	This function is contains the logic of the computer's strategy as chase player
Parameters:
	trump- Card type that holds the trump of the round
	lead_type, lead_suit- char types containing the type and suit of the lead card
Return Value:
	a string type containing the the best card to play
Local Variables:
	best_card- a string type to gold the best card
	trump_cards- a char type vector to hold the card types that are of trump suit
	non_trump_cards- a char type vector to hold the card types that are of non-trump suit
Algorithm:
	-If lead is of trump suit:
		-Put lowest trump in hand that is higher than lead type
		-If no such card- turn is lost anyways- put lowest card in pile (non-trump suit)
	-If lead is not of trump suit:
		-Put lowest lead_suit card in hand that is higher than lead type
		-If no such card:
			-Put the lowest trump suit card in hand
		-If no trump suited cards in hand:
			-Turn is lost anyway, put the lowest card in the pile (non-trump suit)
Assistance Received:
	None.
********************************************************************* */
string Player::strategy_chase(Card trump, char lead_type, char lead_suit)
{
	string best_card;
	vector<Card> newHand;
	newHand = remove_meld_cards(trump);
	//If lead is of trump suit
	if (lead_suit == trump.get_suit())
	{
		vector<char> trump_cards;
		for (auto it = newHand.begin(); it < newHand.end(); it++)
		{
			if ((*it).get_suit() == trump.get_suit())
			{
				if (find_card_index((*it).get_type()) > find_card_index(lead_type))
				{
					//Pushing to the vector all the trump cards in newHand
					//With higher presedence than the lead
					trump_cards.push_back((*it).get_type());

				}
			}
		}
		//If there are trump cards with higher presedence than lead- find the lowest one.
		if (!trump_cards.empty())
		{
			//At this point we know all of these cards can beat the lead, we are trying to find the least "valuable" option to win the turn
			best_card = trump_cards[0];
			for (auto it = trump_cards.begin(); it < trump_cards.end(); it++)
			{
				if ((find_card_index(*it) < find_card_index(best_card[0])))
				{
					best_card = (*it);
				}
			}
			//Which is trump. Using this vaiable to save the function call trump.get_suit()
			best_card += lead_suit;
			cout << "Strategy: playing the lowest possible trump card in hand to win round: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << endl;
		}
		//If I dont have any trump card that can beat the lead-turn is lost case- put the least valuable card- lowest non trump
		else
		{
			vector<Card> non_trump_cards;
			for (auto it = newHand.begin(); it < newHand.end(); it++)
			{
				//pushing all non-trumps to a vector
				if ((*it).get_suit() != trump.get_suit())
				{
					non_trump_cards.push_back((*it));

				}
			}
			//if there are non trumps in my newHand- use lowest trump
			if (!non_trump_cards.empty())
			{
				best_card = non_trump_cards[0].get_type();
				best_card += non_trump_cards[0].get_suit();
				for (auto it = non_trump_cards.begin(); it < non_trump_cards.end(); it++)
				{
					if ((find_card_index((*it).get_type())) < find_card_index(best_card[0]))
					{
						best_card = (*it).get_type();
						best_card += (*it).get_suit();

					}
				}
				cout << "Strategy: cannot win this round, playing the least valuable card from newHand: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << " to win the round" << endl;
			}
			//if I dont have any non trump- find the trump with the lowest presedence
			else
			{
				best_card = newHand[0].get_type();
				best_card += newHand[0].get_suit();
				for (auto it = newHand.begin(); it < newHand.end(); it++)
				{
					if (find_card_index((*it).get_type()) < find_card_index(best_card[0]))
					{
						best_card = (*it).get_type();
						best_card += (*it).get_suit();
					}
				}
				cout << "Strategy: cannot win this round but only have trump cards in hand, playing the weakest one: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << endl;
			}
		}
	}
	//If lead is not of trump suit
	else
	{
		vector<char> lead_cards;
		for (auto it = newHand.begin(); it < newHand.end(); it++)
		{
			if ((*it).get_suit() == lead_suit)
			{
				if (find_card_index((*it).get_type()) > find_card_index(lead_type))
				{
					//Pushing to the vector all the lead_suit-cards in newHand
					//With higher presedence than the lead_type
					lead_cards.push_back((*it).get_type());
				}
			}
		}
		//If there are lead_type cards with higher presedence than lead-find the lowest one.
		if (!lead_cards.empty())
		{
			//At this point we know all of these cards can beat the lead, we are trying to find the least "valuable" option to win the turn
			best_card = lead_cards[0];
			for (auto it = lead_cards.begin(); it < lead_cards.end(); it++)
			{
				if ((find_card_index(*it) < find_card_index(best_card[0])))
				{
					best_card = (*it);
				}
			}
			//Which is trump. Using this vaiable to save the function call trump.get_suit()
			best_card += lead_suit;
			cout << "Strategy: playing the lowest possible card of suit " << lead_suit << " which is: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << " to win the round" << endl;
		}
		//There are no lead_suit cards that can beat lead- therefore- find lowesr trump suited card in newHand
		else
		{
			for (auto it = newHand.begin(); it < newHand.end(); it++)
			{
				if ((*it).get_suit() == trump.get_suit())
				{
					lead_cards.push_back((*it).get_type());	//Pushing to the vector all the trump_suit-cards in newHand
				}
			}
			if (!lead_cards.empty()) //if we there are trump cards in newHand
			{
				best_card = lead_cards[0];
				for (auto it = lead_cards.begin(); it < lead_cards.end(); it++)
				{
					if ((find_card_index(*it) < find_card_index(best_card[0])))
					{
						best_card = (*it);
					}
				}
				best_card += trump.get_suit();
				cout << "Strategy: no cards with higher presedence than lead suit, playing the weakest trump to win: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << endl;
			}
			//if no lead-suited cards nor trump cards in newHand- lost case- put weakest card
			else
			{
				best_card = newHand[0].get_type();
				best_card += newHand[0].get_suit();
				for (auto it = newHand.begin(); it < newHand.end(); it++)
				{
					if (find_card_index((*it).get_type()) < find_card_index(best_card[0]))
					{
						best_card = (*it).get_type();
						best_card += (*it).get_suit();
					}
				}
				cout << "Strategy: cannot win this round, playing the least valuable card from newHand: " << char(toupper(best_card[0])) << char(toupper(best_card[1])) << " to win the round" << endl;
			}
		}
	}
	return best_card;
}

/* *********************************************************************
Function Name: set_game_score
Purpose:
	This function sets the game score of a player to a given valuse
	(used when loading a game from a file)
Parameters:
	gameS- an int type that holds the player's game score
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	
Assistance Received:
	None.
********************************************************************* */
void Player::set_game_score(int gameS)
{
	game_score = gameS;
}

/* *********************************************************************
Function Name: set_round_score
Purpose:
	This function sets the round score of a player to a given valuse
	(used when loading a game from a file)
Parameters:
	roundS- an int type that holds the player's round score
Return Value:
	None.
Local Variables:
	None.
Algorithm:

Assistance Received:
	None.
********************************************************************* */
void Player::set_round_score(int roundS)
{
	round_score = roundS;
}