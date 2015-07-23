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

void initTrain( Train* train ) {
	train->position = 0;
	train->hull = 255;
	train->speed = 255;
	train->hit = 0;
}

void initTrains() {
	initTrain( & heroTrain.basicTrainProps );
	heroTrain.crew = 1;
	heroTrain.basicTrainProps.length = 30;
	initTrain( & villainTrain.basicTrainProps );
	villainTrain.basicTrainProps.length = 1000;
}	

void shoot() {

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
    bullet->x = heroTrain.basicTrainProps.position;
    bullet->y = 150;
    bullet->speedY -= 1;
    bullet->speedX = 1;
    bullet->kind = 1;
    bullets[ slot ] = bullet;
    return;
  }
}


int isHit( Train* train, Projectile *bullet ) {
  
  if ( bullet != NULL ) {
  
    if ( bullet->y > 15 && bullet->y < 30 && bullet->x > villainTrain.basicTrainProps.position && bullet->x < ( villainTrain.basicTrainProps.position + villainTrain.basicTrainProps.length ) ) {
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

  for ( slot = 0; slot < MAX_BULLETS; ++slot ) {
    if ( bullets[ slot ] != NULL ) {  

      bullet = bullets[ slot ];
      bullet->x += bullet->speedX;
      bullet->y += bullet->speedY;

      if ( isHit( &villainTrain.basicTrainProps, bullet ) ) {
	villainTrain.basicTrainProps.hit = 1;
	villainTrain.basicTrainProps.hull -= 1;
	destroyBullet( bullet );
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
