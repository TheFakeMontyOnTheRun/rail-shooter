#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "GroundType.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "Background.h"
#include "Video.h"
#include "RailShooter.h"

HeroTrain heroTrain;
VillainTrain villainTrain;
std::vector<Bullet*> bullets;
std::vector<Explosion*> explosions;
int mapPos = 0;
bool quit = false;

void fireBullet(int xPos, int yPos, int xSpeed, int ySpeed) {
	bullets.push_back( new Bullet(Vec2(xPos, yPos), Vec2(xSpeed, ySpeed)));
}

void shoot() {
	for (auto& car : heroTrain.basicTrainProps.cars) {
		fireBullet(heroTrain.basicTrainProps.position.x + car->position.x,
				PLAYER_RAIL_Y - 5, 1 + heroTrain.basicTrainProps.speed, -7);
	}
}

void destroyBullet(const Bullet* bullet) {
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet),
			bullets.end());
			
	delete bullet;
}

void destroyExplosion( const Explosion* explosion ) {
	explosions.erase(std::remove(explosions.begin(), explosions.end(), explosion),
			explosions.end());
			
	delete explosion;	
}

void updateGame(long sleptFor) {

	std::vector<Bullet*> toDestroy;
	std::vector<Explosion*> expiredExplosion;

	for (auto& bullet : bullets) {
		bullet->update(sleptFor);

		if (bullet->position.y < 0) {
			toDestroy.push_back(bullet);
			continue;
		}

		if (bullet->position.y >= YRES) {
			toDestroy.push_back(bullet);
			continue;
		}
	}
	
	for (auto& explosion : explosions) {
		explosion->update(sleptFor);
	}
	
	for ( auto& explosion : explosions ) {
		if ( !explosion->isValid() ) {
			expiredExplosion.push_back( explosion );
		}
	}

	for (auto &bullet : toDestroy) {
		destroyBullet(bullet);
	}

	for ( auto& explosion : expiredExplosion ) {
		destroyExplosion( explosion );	
	}
	
	heroTrain.basicTrainProps.update(sleptFor, bullets, explosions);
	villainTrain.basicTrainProps.update(sleptFor, bullets, explosions);

}

int main(int argc, char **argv) {

	initGraphics();
	initGroundTypes();

	quit = false;

	timeval timeBefore;
	timeval timeAfter;
	long delta;
	long sleptFor = 0;

	while (!quit) {
		gettimeofday(&timeBefore, nullptr);

		handleEvents();

		mapPos += 8;
		updateTerrain(mapPos);

		if (mapPos > TILES_X) {
			refreshGraphics();
		}

		gettimeofday(&timeAfter, nullptr);
		delta = (timeAfter.tv_usec - timeBefore.tv_usec) / 1000;

		if (delta < 0) {
			delta = -delta;
		}

		if (delta < 20) {
			sleptFor = 20 - delta;
			sleepForMS(sleptFor);
		} else {
			sleptFor = 0;
		}

		updateGame(delta);
	}
	
	for ( auto& bullet : bullets ) {
		delete bullet;
	}
	
	for ( auto& explosion : explosions ) {
		delete explosion;
	}
	
	

	shutdownGraphics();
	return 0;
}
