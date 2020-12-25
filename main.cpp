/*
************************************************************
* Name:  Yuval Ashkenazi                                   *
* Project : Pinochle project C++ (1)                       *
* Class : CMPS666- Organization of Programming Languages   *
* Date : 09/29/2020                                        *
************************************************************
*/
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"

using namespace std;

int validateInput();

int main() {
	srand(time(NULL));
	string name1, name2;
	cout << "Hello welcome to the Pinochle game" << endl << endl;
	cout << "To Start a game please press 1" << endl << endl;
	cout << "To load a game please press 2" << endl << endl;
	short user_selection = validateInput();
	if (user_selection == 1) {

		Human p1("Human");
		Computer p2("Computer");

		Game(p1, p2);

	}
	if (user_selection == 2) {

		string fileName;
		cout << "Please enter a file name: ";
		cin >> fileName; //reading the fileName

		fstream gameFile;

		Human p1("Human");
		Computer p2("Computer");

		Game(p1, p2, fileName);

	}
	else {
		cout << "Ok, Bye!";
	}

	return 0;
}

/* *********************************************************************
Function Name: validateInput
Purpose:
	This funtion is used validate the user's choice (new game or loaded
		game)
Parameters:
	none.
Return Value:
	num_choice- a short representing the validated user's choice
Local Variables:
	user_input- a character representing the read user's choice
	num_choice- a short representing the validated user's choice
Algorithm:
	1. read user choice
		-if choice is not '1' and not '2'
			reread uesr's choice until it is either '1' or '2'
			convert user's choice from a chararter to a short
Assistance Received:
	None.
********************************************************************* */
int validateInput() {
	char user_input;
	//user_input is read as a character to avoid runtime errors when inputting chars
	cin >> user_input;
	while (user_input != '1' && user_input != '2') {
		cout << "Invalid input, please try again:" << endl;
		cout << "To Start a game please press 1" << endl << endl;
		cout << "To load a game please press 2" << endl << endl;
		cin >> user_input;
	}
	//converting user_input back to int after validation
	short num_choice = user_input - '0';
	return num_choice;
}