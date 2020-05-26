#include "flipHeader.h"

// function for struct card
void card :: printCard(){
	cout << "The suit of the card is: " << suit << endl;
	cout << "The value of the card is: " << value << endl;
}


//functions for deck Class
deck :: deck() {
	first = NULL;
	last  = NULL;

	//create deck with cards in order
	string suits[4] = { "Harts" , "Clubs" , "Spades" , "Diamonds"};
	for( int i = 0; i < 4; i++){ //assign suit
		for( int j = 1; j <= 13; j++){ //assign value
			addCard( suits[i], j); 
		}
	}
	
	//Shuffle Deck
	int numShuffles = 3; //Total number of deck shuffles
	for( int i = 0; i < numShuffles; i++)
		shuffle();
}

void deck :: addCard( string inSuit, int inValue){
	card *tmp = new card; //create new card
	//assign card values
	tmp -> suit  	  = inSuit;
	tmp -> value 	  = inValue;
	tmp -> next 	  = NULL;
	
	//assign pointer values so that 
	if( first == NULL){
		first = tmp;
		last = tmp;
	}
	else{
		last -> next = tmp;
		last = last -> next;
	}
}

void deck :: printDeck(){
	card *tmp;
	tmp = first;
	while( tmp != NULL){
		cout << "Card: " << endl;
		tmp -> printCard();
		tmp = tmp -> next; //move to next card
	}	
}

void deck :: shuffle(){
	card *tmp = first;
	srand(time(NULL));
	int randCard; //random card to be choosen
	
	for( int i = 1; i <= 52; i++){ //52 total swaps
		randCard = rand() % 52; //pick random card
		for( int j = 0; j<= randCard; j++){
			tmp = tmp -> next; //find card
			if ( j == randCard)
				replace(tmp); //move card to bottom
		}
		tmp = first; //start from begining
	}	
}

void deck :: replace(card *ptr){
	//store card info in temporary variables
	string tempSuit = last -> suit;
	int tempValue  = last -> value;
	
	//Assign input values to the last card
	last -> suit  = ptr -> suit;
	last -> value = ptr -> value;
	
	//Assign last temporary values to the input card
	ptr -> suit  = tempSuit;
	ptr -> value = tempValue;
}

//functions for flipGame class
bool flipGame :: getUserInput(){
	string input;
	bool play = false;	
START:
	cout << "Enter 1 if you wish to keep drawing, Enter 2 to stop: ";
	cin >> input;
	
	if( input == "1" ){ //user wants to keep drawing
		play = true;
		currentCard = currentCard -> next; //move to next card
	}	
	else if( input == "2" ){ //user wishes to stop
		play =  false;
	}
	else{
		cout << "ERROR: Invalid input. TRY AGAIN!" << endl;
		goto START;	
	}
	
	return play;
}

void flipGame :: getPoints(){
	string points = "";			//points earned from card
	string harts  = "";			//extra point for harts
	int value     = currentCard -> value;	//current card value
	string suit   = currentCard -> suit;	//current card suit
	
	if( value == 1)
		points = "10 points";
	else if( value == 11 || value == 12 || value == 13)
		points = "5 points";
	else if( value == 8  || value == 9  || value == 10)
		points = "0 points ";
	else if( value == 2  || value == 3  || value == 4 || value == 5 || value == 6)
		points = "All taken away!";
	else if( value == 7)
		points = "Loose half :( ";
	
	if( suit == "harts") 
		harts = " +1 point for Hart"; 
	
	cout << "\nThe outcome is: " << points << harts <<endl; 
}


void flipGame :: playGame(){
	int picks           = 0;	 	//number of cards that have been drawn
	bool keepPlaying    = true; 		//player wants ro keep playing
	
	cout << "Welcome to Flip, Deck has been shuffled, Lets Play!" << endl;
	while( keepPlaying && (picks < 52)){
		keepPlaying = getUserInput();
		picks++;
		if( !keepPlaying ) {
			cout << "You wish to stop, your card is: " << endl;
			currentCard -> printCard();
			getPoints();
		}
	}
}
