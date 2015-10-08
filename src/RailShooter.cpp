#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#include "GroundType.h"
#include "CarElement.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "Vec2.h"
#include "Bullet.h"
#include "RailShooter.h"
#include "Background.h"
#include "Video.h"

HeroTrain heroTrain;
VillainTrain villainTrain;
std::vector<Bullet*> bullets;

int mapPos = 0;
bool quit = false;


void fireBullet(int xPos, int yPos, int xSpeed, int ySpeed) {
	bullets.push_back(new Bullet( Vec2(xPos, yPos), Vec2(xSpeed, ySpeed)));
}

void shoot() {
	for (auto& car : heroTrain.basicTrainProps.cars) {
		fireBullet(heroTrain.basicTrainProps.position + car->position, PLAYER_RAIL_Y - 5, 1 + heroTrain.basicTrainProps.speed,
				-7);
	}
}

bool isHit(int pos, int line, Car* car, const Bullet *bullet) {

  if (bullet->position.y > line && bullet->position.y < (line + 15)
      && bullet->position.x > (car->position + pos)
      && bullet->position.x < (car->position + car->length + pos)) {
    return true;
  }

  return false;
}

void destroyBullet(const Bullet *bullet) {
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet),
			bullets.end());
	delete bullet;
}

void updateGame() {
  
  std::vector<Bullet*> toDestroy;
  
  for (auto& bullet : bullets) {
    bullet->update( 100 );
    
    if (bullet->position.y < 0) {
      destroyBullet(bullet);
      continue;
    }
    
    if (bullet->position.y >= YRES) {
      destroyBullet(bullet);
      continue;
    }
    
    for (auto& car : villainTrain.basicTrainProps.cars) {
      
      if (car->hull <= 0) {
	continue;
      }
      
      if (isHit(villainTrain.basicTrainProps.position, ENEMY_RAIL_Y, car,
		bullet)) {
	car->hit = true;
	car->hull -= 1;
	toDestroy.push_back(bullet);
	fireBullet(villainTrain.basicTrainProps.position + car->position,
		   ENEMY_RAIL_Y + 5, -1, 1);
	continue;
      }
    }
    
    for (auto& car : heroTrain.basicTrainProps.cars) {
      
      if (car->hull <= 0) {
	continue;
      }
      
      if (isHit(heroTrain.basicTrainProps.position, PLAYER_RAIL_Y, car, bullet)) {
	car->hit = true;
	car->hull -= 1;
	destroyBullet(bullet);
      }
    }
  }
  
  heroTrain.basicTrainProps.update( 100 );
  villainTrain.basicTrainProps.update( 100 );
  
  for (auto &bullet : toDestroy) {
    destroyBullet(bullet);
  }
}

int main(int argc, char **argv) {

	initGraphics();
	initGroundTypes();

	quit = false;

	struct timeval timeBefore;
	struct timeval timeAfter;
	int slept = 0;
	long delta;

	while (!quit) {
		gettimeofday(&timeBefore, nullptr);

		handleEvents();

		mapPos += 8;
		updateTerrain(mapPos);
		updateGame();

		if (mapPos > TILES_X) {
			refreshGraphics();
		}

		gettimeofday(&timeAfter, nullptr);
		delta = (timeAfter.tv_usec - timeBefore.tv_usec) / 100;

		if (delta < 0) {
			delta = -delta;
		}

		if (delta < 50) {
			sleepForMS(50 - delta);
			slept++;
		}
	}

	shutdownGraphics();
	return 0;
}
