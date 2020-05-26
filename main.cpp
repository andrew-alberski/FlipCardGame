#include "flipHeader.h"
int main(){
	flipGame *flip = new flipGame;
	flip->playGame();
	delete flip;
}
