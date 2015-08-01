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
  video = SDL_SetVideoMode( 255, 192, 32, 0 );
}

void drawBackground(){

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
}

void clearGraphics() {
  SDL_FillRect( video, NULL, 0 );
}

void drawTrain( int carCount, Car *cars, int pos, int line ) {

  SDL_Rect tile;
  int healthIndicator;
  int c;
  int d;

  int acc;


  acc = pos;

  for ( c = 0; c < carCount; ++c ) {

    tile.x = acc + cars[ c ].position;
    tile.w =  cars[ c ].length;
    tile.y = line;
    tile.h = 15;
    healthIndicator = cars[ c ].hull + 255;

    if ( cars[ c ].hit ) {
      healthIndicator = 0;
      cars[ c ].hit = 0;
    }

    SDL_FillRect( video, &tile, 0xFF000000 + (healthIndicator * 0xFFFF ) );
  }

}

void refreshGraphics() {

  drawBackground();


  drawTrain( heroTrain.basicTrainProps.carsCount, heroTrain.basicTrainProps.cars, heroTrain.basicTrainProps.position, 150 );

  drawTrain( villainTrain.basicTrainProps.carsCount, villainTrain.basicTrainProps.cars, villainTrain.basicTrainProps.position, 15 );

  int slot;
  Projectile *bullet;

  SDL_Rect tile;

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
