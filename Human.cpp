
#include "Human.h"
#include <iostream>

using namespace std;


/* *********************************************************************
Function Name: play
Purpose:
	To play a turn in the pinochle game
Parameters:
	trump- Card type that hold's the trump card's suit and type
	lead_type- char type that represents the type of lead card
	lead_suit- char type that represents the suit of lead card
Return Value:
	Card- the card played by the Human
Local Variables:
	c1- string type holds the card the human chose
	t, s- char types hold the type and suit of the card the huamn chose
	card_to_remove- iterator of a card vector, points to the  the card we are trying
		to remove from the huamn's hand after it was played
	userCard- card type that holds the card that the human chose
Algorithm:
	1.prompt user to play a card
	2.while card is not valid (found in hand):
		-ask user for card
		- check if card valid (found in hand)
	3. convert the string input into a card type
	4. return that card.
Assistance Received:
	None.
********************************************************************* */
Card Human::play(Card trump, char lead_type, char lead_suit) {
	cout << this->get_name() << " please play a card: ";
	string c1;
	cin >> c1; //reading the user's selection
	char t, s;
	if (!is_card_valid(c1)) {
		do {
			cout << "The card you entered is not valid, please enter a valid card: ";
			cin >> c1; //reading the user's selection

		} while (!is_card_valid(c1));
	}
	t = char(c1[0]);
	s = char(c1[1]);
	Card userCard(t, s);
	vector<Card>::iterator card_to_remove = find(this->hand.begin(), this->hand.end(), userCard);
	this->hand.erase(card_to_remove);
	return userCard;
}


/* *********************************************************************
Function Name: would_you_meld
Purpose:
	determine whether or not the huaman wants to play a meld
Parameters:
	trump- Card type that hold's the trump card's suit and type
Return Value:
	boolean- true if computer wants to play a meld
			 false if computer doesn't want to play a meld
Local Variables:
	would_you_meld- char type holding the user's input
Algorithm:
	1. prompt user for input
	2. if input = '1' return true
	   else return fasle
Assistance Received:
	None.
********************************************************************* */
bool Human::would_you_meld(Card trump)
{
	char would_you_meld;
	//Asking player if they want to play a meld
	cout << name << ", press 1 to play a meld, press 2 otherwise: ";
	cin >> would_you_meld; //reading the user's selection
	while (would_you_meld != '1' && would_you_meld != '2') {
		cout << "Invalid input, please try again: " << endl;
		//Asking player if they want to play a meld
		cout << "Press 1 to play a meld, press 2 otherwise: ";
		cin >> would_you_meld;
	}
	if (would_you_meld == '1')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* *********************************************************************
Function Name: perform_a_meld
Purpose:
	play a meld- vlidate meld, then add points to the humans's score, and
		push the right cards into the meld_cards vector, and right names into the meld_names
		into the right vector
Parameters:
	trump- Card type that hold's the trump card's suit and type
Return Value:
	None.
Local Variables:
	trump_suit- char to hold the of the suit of the trump card
	meld_vector- a Card type vector to hold the cards needed to perform a meld
	meld_name- to hold the name of the meld that is being preformed
	input- holds the user's input/s
Algorithm:
	1. read the meld's name into meld_name
	2. read cards from user and store them into meld_vector
	3.get the number of points for this meld
		-if not 0:
			-add meld points to player
		-else:
			-tell user meld has been used already
Assistance Received:
	None.
********************************************************************* */
void Human::perform_a_meld(Card trump)
{
	vector<Card> meld_vector;
	string input, meld_name, meld_num;
	cout << "Please enter the number associated with the meld name: " << endl;
	cout << "1 - Flush Meld" << endl;
	cout << "2 - Four Aces Meld" << endl;
	cout << "3 - Four Kings Meld" << endl;
	cout << "4 - Four Queens Meld" << endl;
	cout << "5 - Royal Marriage Meld" << endl;
	cout << "6 - Four Jacks Meld" << endl;
	cout << "7 - Pinochle Meld" << endl;
	cout << "8 - Spade Marriage Meld" << endl;
	cout << "9 - Heart Marriage Meld" << endl;
	cout << "10 - Diamond Marriage Meld" << endl;
	cout << "11 - Club Marriage Meld" << endl;
	cout << "12 - Dix Meld" << endl;
	cin >> meld_num; //reading the user's selection

	if (meld_num == "1")
		meld_name = "flush";
	else if (meld_num == "2")
		meld_name = "fourA";
	else if (meld_num == "3")
		meld_name = "fourK";
	else if (meld_num == "4")
		meld_name = "fourQ";
	else if (meld_num == "5")
		meld_name = "royal_marriage";
	else if (meld_num == "6")
		meld_name = "fourJ";
	else if (meld_num == "7")
		meld_name = "pinochle";
	else if (meld_num == "8")
		meld_name = "spade_marriage";
	else if (meld_num == "9")
		meld_name = "heart_marriage";
	else if (meld_num == "10")
		meld_name = "diamond_marriage";
	else if (meld_num == "11")
		meld_name = "club_marriage";
	else if (meld_num == "12")
		meld_name = "dix";
	else
		meld_name == "";

	cout << "Please enter a many cards as you would like,\nEnter \'m' when you are done:" << endl;
	do
	{ 
		cin >> input; //reading the user's selection
		if (input != "m") {
			meld_vector.push_back(Card(input[0], input[1]));
		}
	} while (input != "m");


	int meld_points = try_a_meld(meld_vector, meld_name, trump);

	if (meld_points != 0)
	{
		add_to_round_score(meld_points);
	}
	else
	{
		cout << "you have already performed this specific meld" << endl;
	}
}


/* *********************************************************************
Function Name: player_selection
Purpose:
	displays the human's menu and takes in it's choice (the User's choice)
Parameters:
	None.
Return Value:
	An integer representing the selection made
Local Variables:
	input- char type that takes in what has been inputted to the console
Algorithm:
	1. display the menu
	2. read in char type
	3. validate input
		-if not valid
			-display menu
			-read char type
			-repeat until valid
		-if valid- cast into integer
		-return value
Assistance Received:
	None.
********************************************************************* */
int Human::player_selection()
{
	char input;
	int numerical_input;
	cout << "1. Save the game" << endl;
	cout << "2. Make a move" << endl;
	cout << "3. Quit the game" << endl;
	cout << "4. Ask for help" << endl;

	cin >> input; //reading the user's menu selection
	while (input != '1' && input != '2' && input != '3' && input != '4')
	{
		cout << "Input is not valid, please try again:" << endl;
		cout << "1. Save the game" << endl;
		cout << "2. Make a move" << endl;
		cout << "3. Quit the game" << endl;
		cout << "4. Ask for help" << endl;

		cin >> input; //reading the user's menu selection
	}
	numerical_input = input - 48;
	return numerical_input;
}

/* *********************************************************************
Function Name: help_with_meld
Purpose:
	asks the human player if they need help with performing the meld
Parameters:
	trump- Card type that hold's the trump card's suit and type
Return Value:
	An integer representing the selection made
Local Variables:
	None.
Algorithm:
	1. ask the user if the want help
	2.if yes:
		-call best_meld with human's hand
		-print out the name if the best meld (or "no possible..." if there aren't any)
	3.else: do nothing

Assistance Received:
	None.
********************************************************************* */
void Human::help_with_meld(Card trump)
{
	char input;
	cout << "To recieve help with performing a meld press 1, press 2 otherwise: ";
	//reading the user's selection
	cin >> input;
	//validating user's input
	while (input != '1' && input != '2') {
		cout << "Invalid input, please try again:" << endl;
		cout << "To recieve help with performing a meld press 1, press 2 otherwise: ";
		//reading the user's selection
		cin >> input;
	}
	if (input == '1')
	{
		string meld = best_meld(hand, trump);
		if (meld == "No possible melds")
		{
			cout << "No possible melds at this point" << endl;
			
		}
		else
		{
			cout << "The Best meld you can make is: " << meld << endl;
		}
	}
}