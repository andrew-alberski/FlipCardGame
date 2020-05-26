#ifndef flipHeader
#define flipHeader

#include <string> 
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Card struct, I choose a struct over a class b/c values are defaluted to public
struct card{
	string suit;
	int value; 
	card *next; //pointer to next node

	void printCard(); //prints card info	
};


class deck{
public:
	card *first;
	card *last;
	card *tmp;
	deck(); //Constructor that creates deck with cards in order
	~deck(); //deConstructor to free memory 
	void addCard(string, int); 	//add card to deck (for constructor) 
	
	void printDeck();		//prints cards in deck
	void replace();		 	//card(parameter by value), put at bottom of deck
	void shuffle();			//shuffles cards in the deck
};

class flipGame{
public:
	deck cardDeck; //Create deck object
	card *currentCard = cardDeck.first; //establish first card

	bool getUserInput(); 	//Prompts user for action DRAW / STOP
	void getPoints();	//retuurns the number of points earned
	void playGame(); 	//play flip card game
	
};
#endif
