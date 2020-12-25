
#include "Computer.h"

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
	Card- the card played by the computer
Local Variables:
	c1- string type holds the card the computer chose
	t, s- char types hold the type and suit of the card the computer chose
	card_to_remove- iterator of a card vector, points to the  the card we are trying
		to remove from the computer's hand after it was played
	computerCard- card type that holds the card that the computer chose
Algorithm:
	1. call thr right strategy function
	2. convert the string into a card
	3. print that card
	4. return that card.
Assistance Received:
	None.
********************************************************************* */
Card Computer::play(Card trump, char lead_type, char lead_suit) {
	string c1;
	char t, s;
	if (lead_type == 'e' && lead_suit == 'e')
	{
		c1 = strategy_lead(trump);
	}
	else
	{
		c1 = strategy_chase(trump, lead_type, lead_suit);
	}
	t = char(c1[0]);
	s = char(c1[1]);
	Card computerCard(t, s);
	vector<Card>::iterator card_to_remove = find(this->hand.begin(), this->hand.end(), computerCard);
	this->hand.erase(card_to_remove);
	cout << this->get_name() << "'s choice: ";
	computerCard.print_card();
	cout << endl << endl;

	return computerCard;
}

/* *********************************************************************
Function Name: would_you_meld
Purpose:
	determine whether or not the computer wants to play a meld
Parameters:
	trump- Card type that hold's the trump card's suit and type
Return Value:
	boolean- true if computer wants to play a meld
			 false if computer doesn't want to play a meld
Local Variables:
	meld- string type holding the name of the best meld the computer can play
Algorithm:
	1. best_meld function to see if computer can play a med
	2. if meld = "No possible melds" return false
	   else return true
Assistance Received:
	None.
********************************************************************* */
bool Computer::would_you_meld(Card trump)
{
	cout << name << ", press 1 to play a meld: ";		//Asking player if they want to play a meld
	string meld = best_meld(hand, trump);
	if (meld == "No possible melds")
	{
		cout << "0" << endl;
		return 0;
	}
	else
	{
		cout << "1" << endl;
		return 1;
	}
}

/* *********************************************************************
Function Name: perform_a_meld
Purpose:
	play a meld- vlidate meld, then add points to the computer's score, and
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
Algorithm:
	1. get the best meld's name using best_meld function
	2. set up the meld_vectr according the the meld's name
	3.get the number of points for this meld (which also pushed the cards
		into the right vector
	4. add meld points to player
Assistance Received:
	None.
********************************************************************* */
void Computer::perform_a_meld(Card trump)
{
	char trump_suit = trump.get_suit();
	vector<Card> meld_vector;
	string meld_name;
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
	meld_name = best_meld(hand, trump);
	
	if (meld_name == "flush")
		cout << "1" << endl;
	if (meld_name == "fourA")
		cout << "2" << endl;
	if (meld_name == "fourK")
		cout << "3" << endl;
	if (meld_name == "fourQ")
		cout << "4" << endl;
	if (meld_name == "royal_marriage")
		cout << "5" << endl;
	if (meld_name == "fourJ")
		cout << "6" << endl;
	if (meld_name == "pinochle")
		cout << "7" << endl;
	if (meld_name == "spade_marriage")
		cout << "8" << endl;
	if (meld_name == "heart_marriage")
		cout << "9" << endl;
	if (meld_name == "diamond_marriage")
		cout << "10" << endl;
	if (meld_name == "club_marriage")
		cout << "11" << endl;
	if (meld_name == "dix")
		cout << "12" << endl;

	cout << "Please enter a many cards as you would like,\nEnter \'m' when you are done:" << endl;
	if (meld_name == "flush")
	{
		cout << "a" << trump_suit << endl;
		cout << "x" << trump_suit << endl;
		cout << "k" << trump_suit << endl;
		cout << "q" << trump_suit << endl;
		cout << "j" << trump_suit << endl;
		cout << "m" << endl;
	}
	else if (meld_name == "fourA")
	{
		cout << "as\nac\nad\nah\nm\n";
	}
	else if (meld_name == "fourK")
	{
		cout << "ks\nkc\nkd\nkh\nm\n";
	}
	else if (meld_name == "fourQ")
	{
		cout << "qs\nqc\nqd\nqh\nm\n";
	}
	else if (meld_name == "royal_marriage")
	{
		cout << "k" << trump_suit << endl;
		cout << "q" << trump_suit << endl;
		cout << "x" << endl;
	}
	else if (meld_name == "fourJ")
	{
		cout << "js\njc\njd\njh\nm\n";
	}
	else if (meld_name == "pinochle")
	{
		cout << "qs\njd\nm\n";
	}
	else if (meld_name == "spade_marriage")
	{
		cout << "ks\nqs\nm\n";
	}
	else if (meld_name == "heart_marriage")
	{
		cout << "kh\nqh\nm\n";
	}
	else if (meld_name == "diamond_marriage")
	{
		cout << "kd\nqd\nm\n";
	}
	else if (meld_name == "club_marriage")
	{
		cout << "kc\nqc\nm\n";
	}
	//Else- this has to be a dix (because we already validated a possible meld exists)
	else
	{
		cout << "9" << trump_suit << endl;
		cout << "m" << endl;
	}


	int meld_points = try_a_meld(hand, meld_name, trump);

	//Calling this function w/out making sure points are > 0 because:
	//this is the computer player, if it is in this function, it already
	//validated a meld is possible here and points would always be more than 0
	add_to_round_score(meld_points);	
}


/* *********************************************************************
Function Name: player_selection
Purpose:
	displays the computer's menu and takes in it's choice (the User's choice)
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
int Computer::player_selection()
{
	char input;
	int numerical_input;
	cout << "1. Save the game" << endl;
	cout << "2. Make a move" << endl;
	cout << "3. Quit the game" << endl;

	cin >> input; //reading the user's selection
	while (input != '1' && input != '2' && input != '3')
	{
		cout << "Input is not valid, please try again:" << endl;
		cout << "1. Save the game" << endl;
		cout << "2. Make a move" << endl;
		cout << "3. Quit the game" << endl;

		cin >> input; //reading the user's selection
	}
	numerical_input = input - 48;
	return numerical_input;
}

void Computer::help_with_meld(Card trump)
{
	//Nothing to do here, only human can get help with melds
}