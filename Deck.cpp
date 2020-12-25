
#include "Deck.h"
#include <ctime>
#include <algorithm>
#include <iostream>


/* *********************************************************************
Function Name: deck (default constructor)
Purpose:
	initializes the deck- a vector of Card types
Parameters:
	None.
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1.initialize the deck to contain all the neccessary cards
Assistance Received:
	None.
********************************************************************* */
Deck::Deck() {
	deck = { Card('9', 's'), Card('9', 'c'), Card('9', 'd'), Card('9', 'h'),
			Card('9', 's'), Card('9', 'c'), Card('9', 'd'), Card('9', 'h'),
			Card('x', 's'), Card('x', 'c'), Card('x', 'd'), Card('x', 'h'),
			Card('x', 's'), Card('x', 'c'), Card('x', 'd'), Card('x', 'h'),
			Card('j', 's'), Card('j', 'c'), Card('j', 'd'), Card('j', 'h'),
			Card('j', 's'), Card('j', 'c'), Card('j', 'd'), Card('j', 'h'),
			Card('q', 's'), Card('q', 'c'), Card('q', 'd'), Card('q', 'h'),
			Card('q', 's'), Card('q', 'c'), Card('q', 'd'), Card('q', 'h'),
			Card('k', 's'), Card('k', 'c'), Card('k', 'd'), Card('k', 'h'),
			Card('k', 's'), Card('k', 'c'), Card('k', 'd'), Card('k', 'h'),
			Card('a', 's'), Card('a', 'c'), Card('a', 'd'), Card('a', 'h'),
			Card('a', 's'), Card('a', 'c'), Card('a', 'd'), Card('a', 'h')
	};
	
}

/* *********************************************************************
Function Name: deck (constructor)
Purpose:
	creates a deck of cards using an existing deck of strings
Parameters:
	deck1- a vector of string type, contains cards that are represented with strings
		-this is for initialize a deck that was read from a file.
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1.for over deck1 from beginningh to end
	2. push every srting from deck1 as a card to he local deck.
Assistance Received:
	None.
********************************************************************* */
Deck::Deck(vector<string> deck1)
{
	for (auto it = deck1.begin(); it < deck1.end(); it++)
	{
		deck.push_back(Card((*it)[0], (*it)[1]));
	}
}


/* *********************************************************************
Function Name: get_deck
Purpose:
	retrieves the deck of the current round as a constant 
Parameters:
	None.
Return Value:
	The local deck- A vector of Cards (constant)
Local Variables:
	None.
Algorithm:
	Returning the local deck
Assistance Received:
	None.
********************************************************************* */
vector<Card> Deck::get_deck() const {
	return deck;
}


/* *********************************************************************
Function Name: get_trump
Purpose:
	retrieves the trump of the current round as a constant 
Parameters:
	None.
Return Value:
	trump- A card that holds the trump's suit and type
Local Variables:
	None.
Algorithm:
	Returning the trump card
Assistance Received:
	None.
********************************************************************* */
Card Deck::get_trump() const {
	return trump;
}


/* *********************************************************************
Function Name: set_trump
Purpose:
	Defines the local trump  card
		-this is used to set the stump when reading a game from a file
Parameters:
	trump_card- a string type which hold the type and suit of the trump card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. If length of trump = a space	 (this means stoc is empty and trump has been dealt
										to one of the players)
		-trump type=' '
		-trump suit = trump_card
	   Else-
	   -trump type=trump_card[0]
	   -trump suit = trump_card[1]
Assistance Received:
	None.
********************************************************************* */
void Deck::set_trump(string trump_card) {
	if (trump_card.length() == 1)
	{
		trump = Card(' ', trump_card[0]);
	}
	else
	{
		trump = Card(trump_card[0], trump_card[1]);
	}
}

/* *********************************************************************
Function Name: shuffle_deck
Purpose:
	randomly shuffle the local deck
Parameters:
	None.
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. use a built in function to shuffle the local deck vector
Assistance Received:
	None.
********************************************************************* */
void Deck::shuffle_deck() {
	srand(unsigned(std::time(0)));
	random_shuffle(deck.begin(), deck.end());
}


/* *********************************************************************
Function Name: deal_cards
Purpose:
	This function deals the cards at the beginning on the round
	4 cards a player at a time (x3)
	then it sets the trump card to be the next card in the stock
Parameters:
	playerList- a Pointer of player type to a plater array- holds the
				two players of the game
	nextPlayerIndex- an int type passed by value which serves as the index to the playerList
Return Value:
	None.
Local Variables:
	i, j- iterators of the for loops
Algorithm:
	1. repeat 3 times:
		-repeat 4 times:
			-deal card to player 1
			-erase card from deck
		-repeat 4 times:
			-deal card to player 2
			-erase card from deck
	2.set trump to be next card from deck
	3. delete that card from the deck
Assistance Received:
	None.
********************************************************************* */
void Deck::deal_cards(Player* playerList, int nextPlayerIndex){
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			playerList[nextPlayerIndex].add_to_hand(deck[0]);
			deck.erase(deck.begin());
		}
		nextPlayerIndex = (nextPlayerIndex + 1) % 2;

		for (size_t j = 0; j < 4; j++)
		{
			playerList[nextPlayerIndex].add_to_hand(deck[0]);
			deck.erase(deck.begin());
		}
		nextPlayerIndex = (nextPlayerIndex + 1) % 2;
	}
	trump.set_type(deck[0].get_type());
	trump.set_suit(deck[0].get_suit());
	deck.erase(deck.begin());
}


/* *********************************************************************
Function Name: deal_turn_cards
Purpose:
	This function deals cards to the players after each turn:
	Winner of the last turn gets a card first
	If no cards left for the second player- the trump card is dealt
Parameters:
	playerList- a Pointer of player type to a plater array- holds the
				two players of the game
	nextPlayerIndex- an int type passed by value which serves as the index to the playerList
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	1. if deck is not empty-
		-add first card from deck to first player
		-erase first card from deck
		-if deck is still not empty
			-add first card from deck to second player
			-erase first card from deck
		-else-
			-add trump card to second player
			-change trump type to ' '
	2. else- dekc is empty- do nothing
Assistance Received:
	None.
********************************************************************* */
void Deck::deal_turn_cards(Player* playerList, int nextPlayerIndex) {
	if (!(this->deck.empty())) {							//If the deck is not empty
		playerList[nextPlayerIndex].add_to_hand(deck[0]);	//Giving a card to the winner
		deck.erase(deck.begin());							//Erasing that card from the deck
		int player2Idx = (nextPlayerIndex + 1) % 2;
		if (!(this->deck.empty()))							//If the deck is still not empty
		{
			playerList[player2Idx].add_to_hand(deck[0]);	//Second player gets the next card in the deck
			deck.erase(deck.begin());
		}
		else
		{
			playerList[player2Idx].add_to_hand(trump);		//If deck is now empty- second player gets the trump
			trump.set_type(' ');
		}
	}
	//Else- do nothing
}


/* *********************************************************************
Function Name: print_deck
Purpose:
	This function prints all the cards in the stock pile
	All cards are presented in upper-level
Parameters:
	None.
Return Value:
	None.
Local Variables:
	t, s- char types hold the type and suit of the current card in the deck
Algorithm:
	1. if deck is not empty-
		-iterate the deck vector and do:
			-print card's type in uppercase
			-print card's suit in uppercase
		-go down one line
Assistance Received:
	None.
********************************************************************* */
void Deck::print_deck() {
	if (!(this->deck.empty()))
	{
		char t, s;
		for (auto it = deck.begin(); it < deck.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			putchar(toupper(t));
			putchar(toupper(s));
			cout << " ";
		}
	}
	cout << endl;
}


/* *********************************************************************
Function Name: print_trump
Purpose:
	This function prints the trump card in upper-level
Parameters:
	None.
Return Value:
	None.
Local Variables:
	t, s- char types hold the type and suit of the trump card
Algorithm:
	1. if trump's type = ' '-
		-print trump's suit in upperlever
	2. else-
	-print trump's type in upperlever
	-print trump's suit in upperlever
Assistance Received:
	None.
********************************************************************* */
void Deck::print_trump() {
	char t, s;
	t = trump.get_type();
	s = trump.get_suit();
	if (t == ' ')
	{
		putchar(toupper(s));
		cout << endl;
	}
	else
	{
		putchar(toupper(t));
		putchar(toupper(s));
		cout << endl;
	}
}