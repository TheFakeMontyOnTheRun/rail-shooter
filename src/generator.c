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

void initCar( Car* car, int position ) {
  car->hull = 255;
  car->hit = 0;
  car->length = 30;
  car->position = 5 + position;
}

void initTrain( Train* train, int cars ) {

  train->position = 0;
  train->speed = 255;
  train->carsCount = cars;
  train->cars = (Car*) malloc( train->carsCount * sizeof( Car ) );

  int car;
  int lastPosition = 0;

  for ( car = 0; car < train->carsCount; ++car ) {
    initCar( &train->cars[ car ], lastPosition );
    lastPosition = train->cars[ car ].position + train->cars[ car ].length;
  }
}

void initTrains() {

  initTrain( & heroTrain.basicTrainProps, 4 );
  heroTrain.crew = 1;
  heroTrain.basicTrainProps.length = 30;
  initTrain( & villainTrain.basicTrainProps, 7 );
  villainTrain.basicTrainProps.length = villainTrain.basicTrainProps.cars[ 2 ].position + villainTrain.basicTrainProps.cars[ 2 ].length;
}	

void fireBullet( int xPos, int yPos, int xSpeed, int ySpeed ) {

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
    bullet->x = xPos;
    bullet->y = yPos;
    bullet->speedY = ySpeed;
    bullet->speedX = xSpeed;
    bullet->kind = 1;
    bullets[ slot ] = bullet;

    return;
  }
}


void shoot() {
  int car;
  for ( car = 0; car < heroTrain.basicTrainProps.carsCount; ++car ) {
    fireBullet( heroTrain.basicTrainProps.position + heroTrain.basicTrainProps.cars[ car ].position, 150, 1, -1 );
  }
}

int isHit( int pos, int line,  Car* car, Projectile *bullet ) {
  
  if ( bullet != NULL ) {
  
    if ( bullet->y > line && bullet->y < ( line + 15 ) && bullet->x > ( car->position + pos ) && bullet->x < ( car->position + car->length + pos ) ) {
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

  int slot;
  Projectile *bullet;
  int car;

  for ( slot = 0; slot < MAX_BULLETS; ++slot ) {
    if ( bullets[ slot ] != NULL ) {  

      bullet = bullets[ slot ];
      bullet->x += bullet->speedX;
      bullet->y += bullet->speedY;

      if ( bullet->y < 0 ) {
	destroyBullet( bullet );
	continue;
      }

      if ( bullet->y >= 192 ) {
	destroyBullet( bullet );
	continue;
      }

      for ( car = 0; car < villainTrain.basicTrainProps.carsCount; ++car ){

	if ( isHit( villainTrain.basicTrainProps.position, 15, &villainTrain.basicTrainProps.cars[ car ], bullet ) ) {
	  villainTrain.basicTrainProps.cars[ car ].hit = 1;
	  villainTrain.basicTrainProps.cars[ car ].hull -= 1;
	  destroyBullet( bullet );
	  fireBullet( villainTrain.basicTrainProps.position + villainTrain.basicTrainProps.cars[ car ].position, 35, -1, 1 );
	  goto nextBullet;
	}      
      }

      for ( car = 0; car < heroTrain.basicTrainProps.carsCount; ++car ){

	if ( isHit( heroTrain.basicTrainProps.position, 150, &heroTrain.basicTrainProps.cars[ car ], bullet ) ) {
	  heroTrain.basicTrainProps.cars[ car ].hit = 1;
	  heroTrain.basicTrainProps.cars[ car ].hull -= 1;
	  destroyBullet( bullet );
	}      
      }
    }    
  nextBullet:
    bullet = bullet; /* noop */
  }


  if (  villainTrain.basicTrainProps.speed == 0 ) {
    villainTrain.basicTrainProps.position--;

    if ( villainTrain.basicTrainProps.position == -villainTrain.basicTrainProps.length ) {
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

    usleep( 500 );
    if ( mapPos > 8 ) {
      refreshGraphics();
    }
  }

  shutdownGraphics();
  return 0;
}
