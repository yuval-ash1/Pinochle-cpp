
#include "Game.h"
#include "Round.h"
#include "Deck.h"
#include <iostream>
#include <sstream>


/* *********************************************************************
Function Name: Game (constructor)
Purpose:
	This is a constructor of the game glass
	It is responsible to start another round if the player wants to
	and declares the winner of the game otherwise
Parameters:
	p1- a Human object
	p2- a computer object
Return Value:
	None.
Local Variables:
	user_input- a character type that takes in the users selestion
Algorithm:
	1. call the round constructor
	2. ask the user if wants another game
		- if yes-	
			- increment round number
			-call the round constructor
			-repeat as long as user wants to keep playing
		-if no-
			-print both player's score
			-determine and print the winner of the game
Assistance Received:
	None.
********************************************************************* */
Game::Game(Human p1, Computer p2) {
	char user_input = 'y';
	round_number = 1;
	Round(round_number, p1, p2);
	cout << "If you want to play another round please press y, otherwise, press n: ";
	//reading the user's decision (another round or not)
	user_input = another_round_validation();
	while (user_input == 'y')
	{
		round_number++;
		Round(round_number, p1, p2);
		cout << "If you want to play another round please press y, otherwise, press any other key: ";
		//reading the user's decision (another round or not)
		user_input = another_round_validation();
		
	}
	cout << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
	cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl;
	if (p1.get_game_score() > p2.get_game_score())
	{
		cout << p1.get_name() << " won this game!" << endl;
	}
	else if (p2.get_game_score() > p1.get_game_score())
	{
		cout << p2.get_name() << " won this game!" << endl;
	}
	else
	{
		cout << "It's a tie!" << endl;
	}
	cout << "Thank you for playing Pinochle";
}

/* *********************************************************************
Function Name: Game (constructor)
Purpose:
	This is a constructor of the game glass that starts a game read from a file.
	It is responsible to start another round if the player wants to
	and declares the winner of the game otherwise
Parameters:
	p1- a Human object
	p2- a computer object
	fileName- a string type which holds the name of the file where the game is stored
Return Value:
	None.
Local Variables:
	line- s tring type used to store lines read from the file one by one
	gameFile- fstream type used to open the file
	input1- istringstream type used to read a line word by word
	word- a string type to store words from a line
	round_num- int type to hold the round number
	gameS, roundS- int types, used to store the round score and game score from the file
					for each player 
	slash- character type, used to store the slash in the score line (score: # / #)
	cutLoc- int type used to store the location of where we want to sut a certain string
			(determined after finding a , or a space in the string.
	i, index- indexes for loops
	temp_hand, temp_capture- string type vectors, used to store the hand and capture pile (respectively)
							of the player (as a string)
	prev_melds_computer, prev_melds_human- string types used to hold the previous meld line from the file
	one_meld- a string type, used to hold one meld at a time
Algorithm:
	1.open the file
	2. read file line by line, using the information from each line to set the right variables
		in the program
	3. close the fil
Assistance Received:
	None.
********************************************************************* */
Game::Game(Human p1, Computer p2, string fileName)
{
	string line;
	fstream gameFile;
	string word;
	int round_num;
	int gameS, roundS; //scores;
	char slash;
	gameFile.open(fileName);
	if (!gameFile) {
		cerr << "Could not open this file" << endl;
		return;
	}

	//Defining round_number
	getline(gameFile, line);//This line contains round: #
	istringstream input1 (line);
	input1 >> word >> round_num;
	round_number = round_num;

	getline(gameFile, line); // empty line
	getline(gameFile, line); // line only contains "Computer:"
	getline(gameFile, line); //this line contains score: # / #
	istringstream input2 (line);
	input2 >> word >> gameS >> slash >> roundS; //gameS and roundS now contain the game and round score of the player respectively
	p2.set_game_score(gameS);
	p2.set_round_score(roundS);
	
	
	int cutLoc;
	getline(gameFile, line); //this line should contain hand: hand cards
	if (!(line.length() <= 9)) //making sure hand is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
	}
	vector<string> temp_hand;
	if (line.size() > 0) {
		for (size_t i = 0; i < line.size() - 1; i = i + 3)
		{
			temp_hand.push_back(line.substr(i, 2));
		}
	}
	if (!temp_hand.empty())
	{
		for (auto it = temp_hand.begin(); it < temp_hand.end(); it++)
		{
			p2.add_to_hand(Card((*it)[0], (*it)[1]));
		}
	}

	getline(gameFile, line); //this line should contain capture pile: capture cards
	vector<string> temp_capture;
	if (!(line.length() <= 17)) //making sure capture pille is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
		if (line.size() > 0) {
			for (size_t i = 0; i < line.size() - 1; i = i + 3)
			{	
				temp_capture.push_back(line.substr(i, 2));
			}
		}
	}
	if (!temp_capture.empty())
	{
		for (auto it = temp_capture.begin(); it < temp_capture.end(); it++)
		{
			p2.add_to_capture((*it)[0], (*it)[1]);
		}
	}

	//Another note- change characters to lower case!!!!
	//I stopped here- not sure how to insert the melds+meld names yet:

	string prev_melds_computer = "";
	int num_commas;
	getline(gameFile, line); //this line should contain melds: prev melds
	if (!(line.length() <= 10)) //making sure player has melds to work with is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
		prev_melds_computer = line;			//Saving this line to use is later to update previous_melds_names vector

		num_commas = number_of_commas(line);
		for (int index = 0; index < num_commas; index++)
		{
			string one_meld = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 2);
			adding_melds(one_meld, p2);
			p2.add_to_previous_melds_cards(",");
		}
		adding_melds(line, p2);
	}
	



	getline(gameFile, line); // this should be empty
	getline(gameFile, line);// this should only say "Human:"

	getline(gameFile, line); //this line contains score: # / #
	istringstream input3(line);
	input3 >> word >> gameS >> slash >> roundS; //gameS and roundS now contain the game and round score of the player respectively
	p1.set_game_score(gameS);
	p1.set_round_score(roundS);



	getline(gameFile, line); //this line should contain hand: hand cards
	if (!(line.length() <= 9)) //making sure hand is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		temp_hand.clear();
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
	}
	if (line.size() > 0) {
		for (size_t i = 0; i < line.size() - 1; i = i + 3)
		{
			temp_hand.push_back(line.substr(i, 2));
		}
	}
	if (!temp_hand.empty())
	{
		for (auto it = temp_hand.begin(); it < temp_hand.end(); it++)
		{
			p1.add_to_hand(Card((*it)[0], (*it)[1]));
		}
	}

	getline(gameFile, line); //this line should contain capture pile: capture cards
	if (!(line.length() <= 17)) //making sure capture pille is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
		temp_capture.clear();
		if (line.size() > 0) {
			for (size_t i = 0; i < line.size() - 1; i = i + 3)
			{
				temp_capture.push_back(line.substr(i, 2));
			}
		}
	}
	if (!temp_capture.empty())
	{
		for (auto it = temp_capture.begin(); it < temp_capture.end(); it++)
		{
			p1.add_to_capture((*it)[0], (*it)[1]);
		}
	}

	string prev_melds_human = "";
	getline(gameFile, line); //this line should contain melds: prev melds
	if (!(line.length() <= 10)) //making sure player has melds to work with is not empty
	{
		cutLoc = line.find(':');
		line = line.substr(cutLoc + 2);
		get_rid_of_end_space(line);		//getting read of space at end of line if exists
		for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
		{
			line[i] = tolower(line[i]);
		}
		prev_melds_human = line;

		//Saving this line to use is later to update previous_melds_names vector
		num_commas = number_of_commas(line);
		for (int index = 0; index < num_commas; index++)
		{
			string one_meld = line.substr(0, line.find(','));
			line = line.substr(line.find(',') + 2);
			adding_melds(one_meld, p1);
			p1.add_to_previous_melds_cards(",");
		}
		adding_melds(line, p1);
	}



	getline(gameFile, line);	//this line should be empty
	getline(gameFile, line);// this line should be trump card: __
	cutLoc = line.find(':');
	line = line.substr(cutLoc + 2);
	string temp_trump = line;


	getline(gameFile, line);	//this line should contain stock: ___
	cutLoc = line.find(':');
	line = line.substr(cutLoc + 2);
	vector<string> temp_deck;
	for (size_t i = 0; i < line.length(); ++i)			//converting line to lower case
	{
		line[i] = tolower(line[i]);
	}
	if (line.size() > 0) {					//created a vector of string cards
		for (size_t i = 0; i < line.size() - 1; i = i + 3)
		{
			temp_deck.push_back(line.substr(i, 2));
		}
	}
	Deck help_deck(temp_deck);			//creating the deck
	help_deck.set_trump(temp_trump);	//defining the trump card



	
	if (prev_melds_human.size() > 0)
	{
		num_commas = number_of_commas(prev_melds_human);
		for (int index = 0; index < num_commas; index++)
		{
			string one_meld = prev_melds_human.substr(0, prev_melds_human.find(','));
			prev_melds_human = prev_melds_human.substr(prev_melds_human.find(',') + 2);
			adding_melds_names(one_meld, p1, help_deck.get_trump());
		}
		adding_melds_names(prev_melds_human, p1, help_deck.get_trump());
	}

	if (prev_melds_computer.size() > 0)
	{
		num_commas = number_of_commas(prev_melds_computer);
		for (int index = 0; index < num_commas; index++)
		{
			string one_meld = prev_melds_computer.substr(0, prev_melds_computer.find(','));
			prev_melds_computer = prev_melds_computer.substr(prev_melds_computer.find(',') + 2);
			adding_melds_names(one_meld, p2, help_deck.get_trump());
		}
		adding_melds_names(prev_melds_computer, p2, help_deck.get_trump());
	}
	string nextPlayer;
	getline(gameFile, line);// this line should be empty
	getline(gameFile, nextPlayer);
	nextPlayer = nextPlayer.substr(13); // cutting off the beginning of the line to be left only with the player's name
	cout << "Game is loaded" << endl;
	   	  

	char user_input = 'y';

	Round(round_number, p1, p2, help_deck, nextPlayer); //here is should have a different round call, no need to initiallize deck again!
	cout << "If you want to play another round please press y, otherwise, press any other key: ";
	//reading the user's decision (another round or not)
	user_input = another_round_validation();
	while (user_input == 'y')
	{
		round_number++;
		Round(round_number, p1, p2);
		cout << "If you want to play another round please press y, otherwise, press any other key: ";
		//reading the user's decision (another round or not)
		user_input = another_round_validation();

	}
	cout << p1.get_name() << "'s score: " << p1.get_game_score() << endl;
	cout << p2.get_name() << "'s score: " << p2.get_game_score() << endl;
	if (p1.get_game_score() > p2.get_game_score())
	{
		cout << p1.get_name() << " won this game!" << endl;
	}
	else if (p2.get_game_score() > p1.get_game_score())
	{
		cout << p2.get_name() << " won this game!" << endl;
	}
	else
	{
		cout << "It's a tie!" << endl;
	}
	cout << "Thank you for playing Pinochle";


}

/* *********************************************************************
Function Name: number_of_spaces
Purpose:
	This funtion is used to calcualte the number of spaces in a string
	in order to know how many melds are in the line (to be able to parse 
	it correctly)
Parameters:
	one_meld- a string line that contains the one meld from the line of melds
Return Value:
	an integer value that indicates how many spaces are in a specific line
Local Variables:
	count- an integer type used to count the number of spaces in a string
Algorithm:
	-iterate through the string
		-if current location of the string = ' '
			-increment count
	-return count
Assistance Received:
	None.
********************************************************************* */
int Game::number_of_spaces(string one_meld)
{
	int count = 0;
	for (int index = 0; index < one_meld.size(); index++)
	{
		if (one_meld[index] == ' ')
		{
			count++;
		}
	}
	return count;
}


/* *********************************************************************
Function Name: number_of_commas
Purpose:
	This funtion is used to calcualte the number of commas in a string
	in order to know how many cards are in the meld (to be able to parse
	it correctly)
Parameters:
	line- a string line that contains the previous melds line from the file.
Return Value:
	an integer value that indicates how many commas are in a specific line
Local Variables:
	count- an integer type used to count the number of commas in the string
Algorithm:
	-iterate through the string
		-if current location of the string = ','
			-increment count
	-return count
Assistance Received:
	None.
********************************************************************* */
int Game::number_of_commas(string line)
{
	int count = 0;
	for (int index = 0; index < line.size(); index++)
	{
		if (line[index] == ',')
		{
			count++;
		}
	}
	return count;
}


/* *********************************************************************
Function Name: adding_melds
Purpose:
	This funtion is used to add the meld cards into the previous_melds_cards
	vector
Parameters:
	one_meld- a string line that contains the one meld from the line of melds
	one_player- player type that contains the player to which the cards belong
Return Value:
	None
Local Variables:
	num_space- an integer type to hold the number of spaces in one_meld
	temp- a string type vector to hold cards from the meld
	iss- istringstream to read from a string word by word (card by card)
Algorithm:
	1. get num_spaces
	2. if num_spaces = 0	//there is only one meld in string
		-add one meld to previous_melds_cards
	3. else-
		-iterate through one meld- read card by card into temp

Assistance Received:
	None.
********************************************************************* */
void Game::adding_melds(string one_meld, Player& one_player)
{
	int num_spaces = number_of_spaces(one_meld);
	if (num_spaces == 0)
	{
		one_player.add_to_previous_melds_cards(one_meld);

	}
	else
	{
		vector<string> temp;
		istringstream iss(one_meld);
		string card;
		for (int index = 0; index < num_spaces+1; index++)
		{
			iss >> card;
			one_player.add_to_previous_melds_cards(card);
		}

	}

}


/* *********************************************************************
Function Name: adding_melds_names
Purpose:
	This funtion is used to add the meld names into the previous_melds_names
	vector
Parameters:
	one_meld- a string line that contains the one meld from the line of melds
	one_player- player type that contains the player to which the cards belong
	trump- Card type that hold's the trump card's suit and type
Return Value:
	None
Local Variables:
	meld_cards- a Card type vector to store the cards of the meld
	card- a string type to store one card from one_meld
	spaces- an integer type to hold the number of spaces in one_meld
Algorithm:
	1. get rid of space in the beginning of the string if exists
	2. spaces <- number of spaces in the meld
	3. iterate through one_meld (using num of spaces)
		-check for card's length 
		-if 3:
			-get rid of last char in string (get rid of *)
			-push card into meld_cards
		-find the name of each meld using best_beld
		-push it to previous_melds_names
Assistance Received:
	None.
********************************************************************* */
void Game::adding_melds_names(string one_meld, Player& one_player, Card trump)
{
	vector<Card> meld_cards;
	string card;
	if (one_meld[0] == ' ')
	{
		one_meld = one_meld.substr(1);	// getting rid of spaces at beginning of string if exist
	}
	int spaces = number_of_spaces(one_meld);
	for (size_t i = 0; i < spaces + 1; i++)
	{
		card = one_meld.substr(0, one_meld.find(' '));
		if (card.size() == 3)		//this means card has * at the end
		{
			card = card.substr(0, 2);		//cutting the * off the card.
		}
		meld_cards.push_back(Card(card[0], card[1]));
		one_meld = one_meld.substr(one_meld.find(' ') + 1);
	}
	if (one_meld.size() == 3)		//this means card has * at the end
	{
		one_meld = one_meld.substr(0, 2);		//cutting the * off the card.
		meld_cards.push_back(Card(one_meld[0], one_meld[1]));
	}

	string current_meld_name = one_player.best_meld(meld_cards, trump);
	one_player.add_to_previous_melds_names(current_meld_name);
}

/* *********************************************************************
Function Name: get_rid_of_end_space
Purpose:
	This funtion is used get rid of unneccessary spaces in a string
Parameters:
	str- string type passed by reference
Return Value:
	None
Local Variables:
	None.
Algorithm:
	1. if str is not an empty string:
		-if str[size -1] = ' '
			get rid of that space using substring
Assistance Received:
	None.
********************************************************************* */
void Game::get_rid_of_end_space(string& str)
{
	if (str.size() > 0)
	{
		if (str[str.size() - 1] == ' ')
		{
			str = str.substr(0, str.size() - 1);
		}
	}
}

/* *********************************************************************
Function Name: another_round_validation
Purpose:
	This funtion is used validate the user's choice (another round or not)
Parameters:
	none.
Return Value:
	u_choice- a character representing the validated user's choice
Local Variables:
	u_choice- a character representing the validated user's choice
Algorithm:
	1. read user choice
		-if choice is not 'y' and not 'n'
			reread uesr's choice until it is either 'y' or 'n'
Assistance Received:
	None.
********************************************************************* */
char Game::another_round_validation() {
	char u_choice;
	cin >> u_choice;
	u_choice = tolower(u_choice);
	while (u_choice != 'y' && u_choice != 'n') {
		cout << "Invalid input, please try again:" << endl;
		cout << "To play another round please press y, otherwise, press n: ";
		cin >> u_choice;
	}
	return u_choice;
}
