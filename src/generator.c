#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"

#include <stdio.h>
#include <SDL/SDL.h>

SDL_Surface *video;
int quit;
HeroTrain heroTrain;
VillainTrain villainTrain;
int mapPos = 0;

typedef struct {
	GroundType *tiles[ 6 ];
} Column;

Column columns[ 8 ];

void initGraphics() {
  if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
    printf( "Erro de SDL..." );
    exit( -1 );
  }

	video = SDL_SetVideoMode( 255, 192, 16, 0 );
}

void initGroundTypes() {
}

void refreshGraphics() {

	SDL_FillRect( video, NULL, 0 );
	SDL_Rect tile;

	int c;
	int d;

	for ( c = 0; c < 8; ++c ) {
		for ( d = 0; d < 6; ++d ) {
	
			tile.x = c * 32;
			tile.y = d * 32;
			tile.w = 32;
			tile.h = 32;
			
			SDL_FillRect( video, &tile, columns[ (c + mapPos ) % 8 ].tiles[ d ]->colour );			
		}
	}
	
	int healthIndicator;

	tile.x = heroTrain.basicTrainProps.position;
	tile.w = heroTrain.basicTrainProps.length;
	tile.y = 150;
	tile.h = 15;

	healthIndicator = heroTrain.basicTrainProps.hull;

	SDL_FillRect( video, &tile, 0xFF000000 + healthIndicator );

	tile.x = villainTrain.basicTrainProps.position;
	tile.w = villainTrain.basicTrainProps.length;
	tile.y = 15;
	tile.h = 15;

	healthIndicator = villainTrain.basicTrainProps.hull;

	SDL_FillRect( video, &tile, 0xFF000000 + (healthIndicator * 0xFFFF ) );

	SDL_Flip( video );
}

void handleEvents() {
	SDL_Event events;

	SDL_PollEvent( &events );
	
	if (events.type == SDL_KEYDOWN ) {
		if ( events.key.keysym.sym == SDLK_q ) {
			quit = 1;
		}

		if ( events.key.keysym.sym == SDLK_LEFT ) {
			heroTrain.basicTrainProps.position -= 16;
		}

		if ( events.key.keysym.sym == SDLK_RIGHT ) {
			heroTrain.basicTrainProps.position += 16;
		}

		if ( events.key.keysym.sym == SDLK_SPACE ) {
		}
	}
}

void shutdownGraphics() {
	SDL_Quit();
}

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

	GroundType ice;
	GroundType desert;

	ice.representation = 'O';
	ice.colour = 0xFF55FF55;

	desert.representation = '.';
	desert.colour = 0xFF555555;

	int stripPos = 0;
	int stripWidth = 6;

	quit = 0;

	while( !quit ) {

		handleEvents();
		
		for ( stripPos = 0; stripPos < stripWidth; ++stripPos ){
		  //printf( "%c", ( mapPos % 8 ) > stripPos ? ice.representation : desert.representation );	
			columns[ mapPos % 8 ].tiles[ stripPos ] = ( mapPos % 8 ) > stripPos ? &ice : &desert;
		}
		//printf( "\n" );
		++mapPos;

		updateGame();

		if ( mapPos > 8 ) {
			refreshGraphics();
		}
	}

	shutdownGraphics();
	return 0;
}
