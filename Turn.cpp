
#include "Turn.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;


/* *********************************************************************
Function Name: Turn (constructor)
Purpose:
	The constructor of the turn class
	Responsble to prompt the players to play, decide who won the turn, add points accordingly,
	Prompt user to play a meld, and add points accordingly as well
Parameters:
	playerList- A player pointer type list pointing to the 2 playerd
	nextPlayerIndex- int type passed by reference holding the index to the player's list
	trump- a card type holding the trump type and suit for the round
	round_number- an int type holding the round number
	local_deck-a card vector type holding the deck of the current round
Return Value:
	None.
Local Variables:
	want_to_meld- a boolean type holding 1 if player wants to play a meld, 0 if not
	player_choice- an integer value holding the player's choise for the menu
	lead- a card type holding the lead card
	chase- a card type holding the chase card
Algorithm:
	1.get player's choice
	2.act accordingly (if 1 save and uit, if 2 play, if 3 quit, if 4 reccomend card)
	3.define lead
	4.get player's choice
	5.act accordingly (if 1 save and uit, if 2 play, if 3 quit, if 4 reccomend card)
	6.define chase
	7.determine winner
	8. declate winner
	9.change next player accordingly
Assistance Received:
	None.
********************************************************************* */
Turn::Turn(Player* playerList, int &nextPlayerIndex, Card trump, int round_number, vector<Card> local_deck){
	bool want_to_meld;
	int player_choice;

	player_choice = playerList[nextPlayerIndex].player_selection();

	switch (player_choice) {
	case 1:
		save_the_game(playerList, nextPlayerIndex, trump, local_deck, round_number);
		//YUVYUV- I need to end the game here, how do I do that??
		_Exit(132);
		break;
	case 2:
		//This does nothing, I tried putting here the line Card chase= ... but-
		//then the computer does not see its declaration and doesnt know it exists.
		break;
	case 3:
		_Exit(132);
		//YUVYUV- I need to end the game here, how do I do that??
		break;
	case 4:
		string reccomended_card = playerList[nextPlayerIndex].strategy_lead(trump);
		break;
	}
	Card lead = playerList[nextPlayerIndex].play(trump, 'e', 'e');		//Asking first player to play and defining the lead card accordingly


	int player2_index = (nextPlayerIndex + 1) % 2;
	player_choice = playerList[player2_index].player_selection();

	switch (player_choice) {
	case 1:
		save_the_game(playerList, player2_index, trump, local_deck, round_number);
		_Exit(132);
		//YUVYUV- I need to end the game here, how do I do that??
		break;
	case 2:
		//This does nothing, I tried putting here the line Card chase= ... but-
		//then the computer does not see its declaration and doesnt know it exists.
		break;
	case 3:
		//YUVYUV- I need to end the game here, how do I do that??
		_Exit(132);
		break;
	case 4:
		string reccomended_card = playerList[player2_index].strategy_chase(trump, lead.get_type(), lead.get_suit());
		cout << reccomended_card << endl;
		
		break;
	}
	Card chase = playerList[player2_index].play(trump, lead.get_type(), lead.get_suit());		//Asking first player to play and defining the lead card accordingly

	bool did_lead_win = winner(lead, chase, trump);		//Determining who card won
	if (did_lead_win)
	{
		cout << playerList[nextPlayerIndex].get_name() << " won this turn!" << endl;	//Determining the winnign player
		playerList[nextPlayerIndex].add_to_capture(lead, chase);						//Adding cards to winner's capture pile
		playerList[nextPlayerIndex].add_to_round_score(points(lead, chase));					//Adding points to winner's score

	}
	else
	{
		cout << playerList[player2_index].get_name() << " won this turn!" << endl;
		playerList[player2_index].add_to_capture(lead, chase);
		playerList[player2_index].add_to_round_score(points(lead, chase));
		nextPlayerIndex = player2_index;
	}
	playerList[nextPlayerIndex].help_with_meld(trump);
	want_to_meld = playerList[nextPlayerIndex].would_you_meld(trump);

	if (want_to_meld)
	{
		playerList[nextPlayerIndex].perform_a_meld(trump);
	}
}


/* *********************************************************************
Function Name: winner
Purpose:
	This function is responsible to determine the winner of the turn
Parameters:
	lead- a card type holding the lead card of the turn
	chase- a card type holding the chase card of the turn
	trump- a card type holding the trump type and suit for the round
Return Value:
	boolean- true if lead won, false if chase won
Local Variables:
	typeOrder[]- char type array that holds the type in their order of presedence
	index- int type, loop iterator
	leadIdx, chaseIdx- short, holds the index (presedence) of lead and chace respectively
Algorithm:
	1.find leadIdx
	2.find chaseIdx
	3.if lead is trump
		if chase is trump
			if chaseIdx > leadIdx
				return false
			else
				return true
		else
			return ture
	else
		if chase suit = lead suit
			if chaseIdx > leadIdx
				return fasle
			else
				return true
		else if chaseIdx = leadIdx
			return false
		else
			return true
Assistance Received:
	None.
********************************************************************* */
bool Turn::winner(Card lead, Card chase, Card trump) {
	short leadIdx, chaseIdx;
	char typeOrder[] = { '9', 'j', 'q', 'k', 'x', 'a' };
	for (short index = 0; index < 6; index++)
	{
		if (lead.get_type() == typeOrder[index]) {
			leadIdx = index;
		}
		if (chase.get_type() == typeOrder[index]) {
			chaseIdx = index;
		}
	}
	if (lead.get_suit() == trump.get_suit()) {
		if (chase.get_suit() == trump.get_suit()) {
			if (chaseIdx > leadIdx)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else {
			return true;
		}
	}
	else
	{
		if (chase.get_suit() == lead.get_suit())
		{
			if (chaseIdx > leadIdx)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if (chase.get_suit() == trump.get_suit())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}


/* *********************************************************************
Function Name: points
Purpose:
	This function determined how many points the winner gets from the lead and chase
Parameters:
	lead- a card type holding the lead card of the turn
	chase- a card type holding the chase card of the turn
Return Value:
	int- the number of point the winner is getting for lead and chase cards
Local Variables:
	turnPts- int type represents the number of point winner will get for lead and chase cards
Algorithm:
	1.turnPts = 0
	2.for each card (lead and chase)
		-find # of point user is getting and add it to turnPts
	3.return turnPts
Assistance Received:
	None.
********************************************************************* */
int Turn::points(Card lead, Card chase) {
	int turnPts = 0;
	switch (lead.get_type())
	{
	case 'j':
		turnPts += 2;
		break;
	case 'q':
		turnPts += 3;
		break;
	case 'k':
		turnPts += 4;
		break;
	case 'x':
		turnPts += 10;
		break;
	case 'a':
		turnPts += 11;
		break;
	default:
		//type is 9, no points for 9
		break;
	}
	switch (chase.get_type())
	{
	case 'j':
		turnPts += 2;
		break;
	case 'q':
		turnPts += 3;
		break;
	case 'k':
		turnPts += 4;
		break;
	case 'x':
		turnPts += 10;
		break;
	case 'a':
		turnPts += 11;
		break;
	default:
		//type is 9, no points for 9
		break;
	}
	return turnPts;
}


/* *********************************************************************
Function Name: save_the_game
Purpose:
	This function writes to a file the neccessary information about
	the current game
Parameters:
	playerList- A player pointer type list pointing to the 2 playerd
	nextPlayerIndex- int type passed by reference holding the index to the player's list
	trump- a card type holding the trump type and suit for the round
	round_number- an int type holding the round number
	deck-a card vector type holding the deck of the current round
Return Value:
	None.
Local Variables:
	filename- string type holding a name of the file
	t, s- char types holding the type and suit of the card respectively
	gameFile- ofstream type used to write to the file
Algorithm:
	1.open the file
	2. write round nubmer
	3. write empty line
	4. write computer:
	5. write computer's game score / round score
	6. write computer's hand
	7. write computer's capture pile
	8. write computer's melds
	9. write empty line
	10. write human:
	11. write human's game score / round score
	12. write human's hand
	12. write human's capture pile
	14. write human's melds
	15. write empty line
	16. write  trump card
	17. write deck
Assistance Received:
	None.
********************************************************************* */
void Turn::save_the_game(Player* playerList, int nextPlayerIndex, Card trump, vector<Card> deck, int round_number)
{
	char s, t;
	string fileName;
	cout << "Please enter a file name (without an extention): ";
	cin >> fileName;  //reading the file name
	fileName += ".txt";
	ofstream gameFile(fileName);

	gameFile << "Round: " << round_number << endl << endl;
	gameFile << "Computer:" << endl;
	gameFile << "\tScore: " << playerList[1].get_game_score() << " / " << playerList[1].get_round_score() << endl;
	gameFile << "\tHand: ";
	if (!(playerList[1].get_hand()).empty())
	{
		vector<Card> hand_copy = playerList[1].get_hand();
		for (auto it = hand_copy.begin(); it < hand_copy.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			gameFile << char(toupper(t)) << char(toupper(s)) << " ";
		}
	}
	gameFile << endl;

	gameFile << "\tCapture Pile: ";
	if (!playerList[1].get_capture_pile().empty())
	{
		vector<Card> capture_pile_copy = playerList[1].get_capture_pile();
		for (auto it = capture_pile_copy.begin(); it < capture_pile_copy.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			gameFile << char(toupper(t)) << char(toupper(s)) << " ";
		}
	}
	gameFile << endl;

	gameFile << "\tMelds: ";
	if (!playerList[1].get_previous_melds_cards().empty())
	{
		vector<string> previous_meld_cards_copy = playerList[1].get_previous_melds_cards();
		for (auto it = previous_meld_cards_copy.begin(); it < previous_meld_cards_copy.end(); it++)
		{
			for (size_t index = 0; index < (*it).size(); index++)
			{
				(*it)[index] = char(toupper((*it)[index]));
			}
		}
		for (auto it = previous_meld_cards_copy.begin(); it < previous_meld_cards_copy.end(); it++)
		{
			gameFile << (*it) << " ";
		}
	}
	gameFile << endl << endl;


	gameFile << "Human:" << endl;
	gameFile << "\tScore: " << playerList[0].get_game_score() << " / " << playerList[0].get_round_score() << endl;
	gameFile << "\tHand: ";
	if (!(playerList[0].get_hand()).empty())
	{
		vector<Card> hand_copy = playerList[0].get_hand();
		for (auto it = hand_copy.begin(); it < hand_copy.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			gameFile << char(toupper(t)) << char(toupper(s)) << " ";
		}
	}
	gameFile << endl;

	gameFile << "\tCapture Pile: ";
	if (!(playerList[0].get_capture_pile()).empty())
	{
		vector<Card> capture_pile_copy = playerList[0].get_capture_pile();
		for (auto it = capture_pile_copy.begin(); it < capture_pile_copy.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			gameFile << char(toupper(t)) << char(toupper(s)) << " ";
		}
	}
	gameFile << endl;

	gameFile << "\tMelds: ";
	if (!playerList[0].get_previous_melds_cards().empty())
	{
		vector<string> previous_meld_cards_copy = playerList[0].get_previous_melds_cards();
		for (auto it = previous_meld_cards_copy.begin(); it < previous_meld_cards_copy.end(); it++)
		{
			for (size_t index = 0; index < (*it).size(); index++)
			{
				(*it)[index] = char(toupper((*it)[index]));
			}
		}
		for (auto it = previous_meld_cards_copy.begin(); it < previous_meld_cards_copy.end(); it++)
		{
			gameFile << (*it) << " ";
		}
	}
	gameFile << endl << endl;

	if (trump.get_type() == ' ')
	{
		gameFile << "Trump Card: " << char(toupper(trump.get_suit())) << endl;
	}
	else
	{
		gameFile << "Trump Card: " << char(toupper(trump.get_type())) << char(toupper(trump.get_suit())) << endl;
	}	
	gameFile << "Stock: ";
	if (!deck.empty())
	{
		for (auto it = deck.begin(); it < deck.end(); it++)
		{
			t = (*it).get_type();
			s = (*it).get_suit();
			gameFile << char(toupper(t)) << char(toupper(s)) << " ";
		}
	}
	gameFile << endl << endl;

	gameFile << "Next Player: " << playerList[nextPlayerIndex].get_name();

	gameFile.close();
}
