#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include  "projectile.h"

#include <stdio.h>
#include <SDL/SDL.h>

#include "video.h"
#include "generator.h"
#include "background.h" 

SDL_Surface *video;

void initGraphics() {
  if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) {
    printf( "Erro de SDL..." );
    exit( -1 );
  }
  video = SDL_SetVideoMode( 255, 192, 16, 0 );
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

	if ( villainTrain.basicTrainProps.hit) {
	  healthIndicator = 0;
	}

	SDL_FillRect( video, &tile, 0xFF000000 + (healthIndicator * 0xFFFF ) );

	int slot;
	Projectile *bullet;

	for ( slot = 0; slot < MAX_BULLETS; ++slot ){ 
	  
	  bullet = bullets[ slot ];

	  if ( bullet != NULL ) {
	    tile.x = bullet->x;
	    tile.y = bullet->y;
	    tile.w = 5;
	    tile.h = 5;
	    
	    SDL_FillRect( video, &tile, 0 );
	  }
	}

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

		if ( events.key.keysym.sym == SDLK_SPACE ) {
		  shoot();
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
