
#include "Round.h"
#include <iostream>
#include <time.h>
#include "Human.h"

#include <thread>
#include <chrono>

using namespace std;


/* *********************************************************************
Function Name: Round (constructor)
Purpose:
	This is the round class constructor it is responsible for determining who starts,
	initializing and shuffling the deck, dealing cards, then displaying game info and
	determining and declaring who won the round
Parameters:
	round_number- int type holding the round number
	p1- a Human object
	p2- a computer object
Return Value:
	None.
Local Variables:
	who_starts- a boolean type holding 1 if human starts, 0 if computer
Algorithm:
	-initialize playerList
	-determine who starts
	-shuffle deck
	-deal cards
	-while hands of players are not empty:
		-display game info
		-call Turn
	- display round scores
	- declare winner
Assistance Received:
	None.
********************************************************************* */
Round::Round(int round_number, Human& p1, Computer& p2) {

	//Initializing a list of players:
	playerList[0] = &p1;
	playerList[1] = &p2;
	cout << endl << "Welcome to round number " << round_number << "!" << endl;
	if (round_number == 1)					//If first round- toss a coin
	{
		bool who_starts;
		cout << "Since this is the first round, we'll toss a coin to decide who starts:" << endl;
		who_starts = toss_a_coin(p1.get_name());
		if (who_starts) {
			cout << p1.get_name() << " starts";
			nextPlayerIndex = 0;
		}
		else {
			cout << p2.get_name() << " starts";
			nextPlayerIndex = 1;
		}
	}
	else if (p1.get_game_score() == p2.get_game_score()) {		//If tied score- toss a coin
		cout << "Since there is a tie, we'll toss a coin to decide who starts:" << endl;
		int who_starts;
		who_starts = toss_a_coin(p1.get_name());
		if (who_starts) {
			cout << p1.get_name() << " starts";
			nextPlayerIndex = 0;
		}
		else {
			cout << p2.get_name() << " starts";
			nextPlayerIndex = 1;
		}
	}
	else {												//Otherwise- the player with more points starts first
		if (p1.get_game_score() > p2.get_game_score())
		{
			cout << p1.get_name() << " starts";
			nextPlayerIndex = 0;
		}
		else
		{
			cout << p2.get_name() << " starts";
			nextPlayerIndex = 1;
		}
	}
	Deck deck1;
	cout << endl << "shuffeling deck.." << endl;
	this_thread::sleep_for(chrono::seconds(1));
	deck1.shuffle_deck();
	cout << "Deck is shuffled!" << endl;
	deck1.deal_cards(*playerList, nextPlayerIndex);
	Card trump = deck1.get_trump();					//determining the trump card
	vector<Card> local_deck = deck1.get_deck();
	//save_the_game(*playerList, nextPlayerIndex, trump, local_deck);
	

	while (!(p1.get_hand().empty()) && !(p2.get_hand().empty()))		//Game continues until both player's hands are empty
	{
		cout << "\t\t\t\t Round Number " << round_number << endl;			//Displaying round number, trump, and deck
		cout << "Trump: ";
		deck1.print_trump();
		cout << "Deck: ";
		deck1.print_deck();
		cout << endl;

		cout << p1.get_name() << ":" << endl;						//Displaying first player's name, hand, capture pile, and score
		cout << "\t Hand: ";
		p1.print_hand();
		cout << "\t Capture Pile: ";
		p1.print_capture_pile();
		cout << "\t Melds: ";
		p1.print_previous_melds_cards();
		cout << "\t Score: " << p1.get_round_score() << endl << endl;

		cout << p2.get_name() << ":" << endl;						//Displaying second player's name, hand, capture pile, and score
		cout << "\t Hand: ";
		p2.print_hand();
		cout << "\t Capture Pile: ";
		p2.print_capture_pile();
		cout << "\t Melds: ";
		p2.print_previous_melds_cards();
		cout << "\t Score: " << p2.get_round_score() << endl << endl;

		Turn(*playerList, nextPlayerIndex, trump, round_number, local_deck);					//Starting a turn
		deck1.deal_turn_cards(*playerList, nextPlayerIndex);
	}
	//This if/else statement determined who won the round
	p1.add_to_game_score(p1.get_round_score());
	p2.add_to_game_score(p2.get_round_score());
	if (p1.get_game_score() > p2.get_game_score()) {
		cout << endl << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
		cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl << endl;
		cout << p1.get_name() << " won this round!" << endl;
	}
	else if (p2.get_game_score() > p1.get_game_score()) {
		cout << endl << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
		cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl << endl;
		cout << p2.get_name() << " won this round!" << endl;
	}
	else {
		cout << "It's a tie!" << endl;
	}

	//resetting the players' round score, capture pile, and meld piles for new round
	p1.clear_for_new_round();
	p2.clear_for_new_round();

}


/* *********************************************************************
Function Name: Round (constructor)
Purpose:
	This is the round class constructor for a round that starts in the middle
	(when reading a game from a file)
	it is responsible for displaying the game info and determining and
	declaring who won the round
Parameters:
	round_number- int type holding the round number
	p1- a Human object
	p2- a computer object
	help_deck- Deck type- the deck of the game
	nextPlayer string type- the name of the next player
Return Value:
	None.
Local Variables:
	local_deck- Card type vector which holds a local deck
	trump- Card type which holds a trump
Algorithm:
	-determine fist player using nextPlayer
	-while hands of players are not empty:
		-display game info
		-call Turn
	- display round scores
	- declare winner
Assistance Received:
	None.
********************************************************************* */
Round::Round(int round_number, Human& p1, Computer& p2, Deck help_deck, string nextPlayer)
{
	playerList[0] = &p1;
	playerList[1] = &p2;
 
	if (nextPlayer == playerList[0]->get_name())
	{
		nextPlayerIndex = 0;
	}
	else
	{
		nextPlayerIndex = 1;
	}

	vector<Card> local_deck = help_deck.get_deck();
	Card trump = help_deck.get_trump();

	while (!(p1.get_hand().empty()) && !(p2.get_hand().empty()))		//Game continues until both player's hands are empty
	{
		cout << "\t\t\t\t Round Number " << round_number << endl;			//Displaying round number, trump, and deck
		cout << "Trump: ";
		help_deck.print_trump();
		cout << "Deck: ";
		help_deck.print_deck();
		cout << endl;

		cout << p1.get_name() << ":" << endl;						//Displaying first player's name, hand, capture pile, and score
		cout << "\t Hand: ";
		p1.print_hand();
		cout << "\t Capture Pile: ";
		p1.print_capture_pile();
		cout << "\t Melds: ";
		p1.print_previous_melds_cards();
		cout << "\t Score: " << p1.get_round_score() << endl << endl;

		cout << p2.get_name() << ":" << endl;						//Displaying second player's name, hand, capture pile, and score
		cout << "\t Hand: ";
		p2.print_hand();
		cout << "\t Capture Pile: ";
		p2.print_capture_pile();
		cout << "\t Melds: ";
		p2.print_previous_melds_cards();
		cout << "\t Score: " << p2.get_round_score() << endl << endl;

		Turn(*playerList, nextPlayerIndex, trump, round_number, local_deck);					//Starting a turn
		help_deck.deal_turn_cards(*playerList, nextPlayerIndex);
	}
	//This if/else statement determined who won the round
	p1.add_to_game_score(p1.get_round_score());
	p2.add_to_game_score(p2.get_round_score());
	if (p1.get_game_score() > p2.get_game_score()) {
		cout << endl << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
		cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl << endl;
		cout << p1.get_name() << " won this round!" << endl;
	}
	else if (p2.get_game_score() > p1.get_game_score()) {
		cout << endl << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
		cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl << endl;
		cout << p2.get_name() << " won this round!" << endl;
	}
	else {
		cout << "It's a tie!" << endl;
	}

	//resetting the players' round score, capture pile, and meld piles for new round
	p1.clear_for_new_round();
	p2.clear_for_new_round();

}


/* *********************************************************************
Function Name: toss_a_coin
Purpose:
	This function is responsible of tossing a coin to determine who starts the round
Parameters:
	p_name- string type golds name of human player
Return Value:
	boolead type- true if human starts, false if computer starts
Local Variables:
	p_choice- char type to hold human's choice
	coin- short to hold a rand number between 0 and 1
Algorithm:
	-get user input
	-get rand num
	-if rand num = user impnut
		-return true
	-else
		-return false
Assistance Received:
	None.
********************************************************************* */
bool Round::toss_a_coin(string p_name)
{
	char p_choice;
	short coin;
	cout << p_name << " Please enter 0 for heads or 1 for tails: ";
	cin >> p_choice; //reading the user's coin choice
	//validating coin choice
	while (p_choice != '0' && p_choice != '1')
	{
		cout << "Invalid number entered, please try again: ";
		cin >> p_choice; //reading the user's coin choice
	}
	//Generating a random number between 0 and 1
	coin = rand() % 2;
	cout << "Coin shows " << coin << "! ";
	short num_choice = p_choice - '0';
	if (coin == num_choice)
	{
		return true;
	}
	else
	{
		return false;
	}
}


















