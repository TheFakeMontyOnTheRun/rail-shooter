#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "video.h"
#include "background.h" 
#include "generator.h"
 
HeroTrain heroTrain;
VillainTrain villainTrain;
int mapPos = 0;
int quit = 0;

void initTrain( Train* train ) {
	train->position = 0;
	train->hull = 255;
	train->speed = 255;
}

void initTrains() {
	initTrain( & heroTrain.basicTrainProps );
	heroTrain.crew = 1;
	heroTrain.basicTrainProps.length = 30;
	initTrain( & villainTrain.basicTrainProps );
	villainTrain.basicTrainProps.length = 1000;
}	

updateGame() {
  if (  villainTrain.basicTrainProps.speed == 0 ) {
    villainTrain.basicTrainProps.position--;

    if ( villainTrain.basicTrainProps.position == -255 -villainTrain.basicTrainProps.length ) {
      villainTrain.basicTrainProps.speed = 8;
    }
  } else {
    villainTrain.basicTrainProps.position++;

    if ( villainTrain.basicTrainProps.position == 255 ) {
      villainTrain.basicTrainProps.speed = 0;
    } 
  }
}


int main( int argc, char **argv ) {

	initGraphics();
	initGroundTypes();
	initTrains();

	quit = 0;

	while( !quit ) {

		handleEvents();
		
		++mapPos;
		updateTerrain( mapPos );
		updateGame();

		if ( mapPos > 8 ) {
			refreshGraphics();
		}
	}

	shutdownGraphics();
	return 0;
}
