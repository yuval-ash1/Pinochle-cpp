
#include "Card.h"
#include <iostream>



/* *********************************************************************
Function Name: Card (this is the default constructor)
Purpose:
	Initializes a card with an empty ('e') type and suit. This is for the trump card to be created
	but not yet initialized.
Parameters:
	None.
Return Value:
	None.
Local Variables:
	None.
Algorithm: 
	No algorithm for this one, just a constructor that initialized the members
Assistance Received: 
	None.
********************************************************************* */
Card::Card() {
	type = 'e';
	suit = 'e';
}


/* *********************************************************************
Function Name: Card (this is another constructor)
Purpose:
	Creates and initializes a card object with the suit and type it gets as parameters
Parameters:
	type1- a character passed by value, holds the designated type of the card
	suit1- a character passed by value, holds the designated suit of the card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	No algorithm for this one, just a constructor that initialized the members
Assistance Received:
	None.
********************************************************************* */
Card::Card(char type1, char suit1) {
	type = type1;
	suit = suit1;
}


/* *********************************************************************
Function Name: get_type
Purpose:
	retrieves the type of the card
Parameters:
	None.
Return Value:
	The type of the card, a character
Local Variables:
	None.
Algorithm:
	Returning the local type of the card
Assistance Received:
	None.
********************************************************************* */
char Card::get_type() const {
	return type;
}

/* *********************************************************************
Function Name: get_suit
Purpose:
	retrieves the suit of the card
Parameters:
	None.
Return Value:
	The suit of the card, a character
Local Variables:
	None.
Algorithm:
	Returning the local suit of the card
Assistance Received:
	None.
********************************************************************* */
char Card::get_suit() const {
	return suit;
}


/* *********************************************************************
Function Name: set_type
Purpose:
	changes the type of the card according to a given parameter- used to update the trump
	type after it is defined
Parameters:
	type1- a character that represents the type of the card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	type gets the value of type1
Assistance Received:
	None.
********************************************************************* */
void Card::set_type(char type1) {
	type = type1;
}


/* *********************************************************************
Function Name: set_suit
Purpose:
	changes the suit of the card according to a given parameter- used to update the trump
	suit after it is defined
Parameters:
	suit1- a character that represents the suit of the card
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	suit gets the value of suit1
Assistance Received:
	None.
********************************************************************* */
void Card::set_suit(char suit1) {
	suit = suit1;
}

/*
This
function prints the card in the right format
*/

/* *********************************************************************
Function Name: print_card
Purpose:
	This function prints a card in upperlevel (type,suit)
Parameters:
	None.
Return Value:
	None.
Local Variables:
	None.
Algorithm:
	print type of card in upperlevel, print suit of card in upperlevel
Assistance Received:
	None.
********************************************************************* */
void Card::print_card() {
	putchar(toupper(type));
	putchar(toupper(suit));
}


/* *********************************************************************
Function Name: operator==
Purpose:
	overloading the == operator for a Card object
Parameters:
	c1- Card type passed by reference
Return Value:
	Boolean. true if the cards are the same, false if not.
Local Variables:
	equal- a boolean to indicate if cards are equal or not
Algorithm:
	If cards' type is equal and the cards' suit is equal- return true
	Else- return false
Assistance Received:
	None.
********************************************************************* */
bool Card::operator==(const Card &c1) {
	bool equal = false;
	if ((this->suit == c1.suit) && (this->type == c1.type))
	{
		equal = true;
	}
	return equal;
}

