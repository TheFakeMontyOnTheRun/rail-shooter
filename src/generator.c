#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "projectile.h"

#include <stdio.h>
#include <stdlib.h>

#include "video.h"
#include "background.h" 
#include "generator.h"
 
HeroTrain heroTrain;
VillainTrain villainTrain;
Projectile *bullets[ MAX_BULLETS ];

int availableBullets = MAX_BULLETS;
int mapPos = 0;
int quit = 0;


int ccl;

void initCar( Car* car ) {
  car->hull = 255;
  car->hit = 0;
  car->length = 30;
  car->position = 5 + ccl;
  ccl = car->position + car->length;
}

void initTrain( Train* train ) {

  ccl = 0;

	train->position = 0;
	train->hull = 255;
	train->speed = 255;
	train->hit = 0;
	train->carsCount = 3;
	train->cars = (Car*) malloc( train->carsCount * sizeof( Car ) );

	int car;
	for ( car = 0; car < train->carsCount; ++car ) {
	  initCar( &train->cars[ car ] );
	}
}

void initTrains() {
	initTrain( & heroTrain.basicTrainProps );
	heroTrain.crew = 1;
	heroTrain.basicTrainProps.length = 30;
	initTrain( & villainTrain.basicTrainProps );
	villainTrain.basicTrainProps.length = 1000;
}	

void fireBullet( int car ) {

  int slot;
  Projectile *bullet;

  if ( availableBullets == 0 ) {
    return;
  }

  for ( slot = 0; slot < MAX_BULLETS; ++slot ) {
    
    if( bullets[ slot ] != NULL ) {
      continue;
    }

    availableBullets--;
    bullet = (Projectile*)malloc(  sizeof( Projectile ) );
    bullet->x = heroTrain.basicTrainProps.position + heroTrain.basicTrainProps.cars[ car ].position;
    bullet->y = 150;
    bullet->speedY -= 1;
    bullet->speedX = 1;
    bullet->kind = 1;
    bullets[ slot ] = bullet;
    return;
  }
}


void shoot() {
  fireBullet( 0 );
  fireBullet( 1 );
  fireBullet( 2 );
}

int isHit( int pos, Car* car, Projectile *bullet ) {
  
  if ( bullet != NULL ) {
  
    if ( bullet->y > 15 && bullet->y < 30 && bullet->x > ( car->position + pos ) && bullet->x < ( car->position + car->length + pos ) ) {
      return 1;
    }
  }

  return 0;
}

void destroyBullet( Projectile *bullet ) {
  int slot;
  for ( slot = 0; slot < MAX_BULLETS; ++slot ) {
    if ( bullets[ slot ] == bullet ) {
      bullets[ slot ] = NULL;
      free( bullet );
      availableBullets++;
      return;
    }
  }
}

updateGame() {

  villainTrain.basicTrainProps.hit = 0;

  if ( villainTrain.basicTrainProps.hull <= 0 ) {
    quit = 1;
  }

  int slot;
  Projectile *bullet;
  int car;

  for ( slot = 0; slot < MAX_BULLETS; ++slot ) {
    if ( bullets[ slot ] != NULL ) {  

      bullet = bullets[ slot ];
      bullet->x += bullet->speedX;
      bullet->y += bullet->speedY;

      for ( car = 0; car < villainTrain.basicTrainProps.carsCount; ++car ){

	if ( isHit( villainTrain.basicTrainProps.position, &villainTrain.basicTrainProps.cars[ car ], bullet ) ) {
	  villainTrain.basicTrainProps.cars[ car ].hit = 1;
	  villainTrain.basicTrainProps.cars[ car ].hull -= 1;
	  destroyBullet( bullet );
      }      

      }

    }    
  }

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
