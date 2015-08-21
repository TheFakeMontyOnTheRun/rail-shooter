#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "projectile.h"

#include "video.h"
#include "background.h" 
#include "generator.h"

HeroTrain heroTrain;
VillainTrain villainTrain;
std::vector<Projectile*> bullets;

int mapPos = 0;
bool quit = false;

void initCar(Car* car, int position) {
	car->hull = 32;
	car->hit = 0;
	car->length = 30;
	car->position = 5 + position;
}

void initTrain(Train* train, int cars) {

	train->position = 0;
	train->speed = 255;

	int car;
	int lastPosition = 0;

	for (car = 0; car < cars; ++car) {
		Car *newCar = (Car*) malloc(sizeof(Car));
		initCar(newCar, lastPosition);
		train->cars.push_back(*newCar);
		lastPosition = train->cars[car].position + train->cars[car].length;
	}
}

void initTrains() {

	initTrain(&heroTrain.basicTrainProps, 1);
	heroTrain.crew = 1;
	heroTrain.basicTrainProps.length = 30;
	initTrain(&villainTrain.basicTrainProps, 1);
	villainTrain.basicTrainProps.length =
			villainTrain.basicTrainProps.cars[0].position
					+ villainTrain.basicTrainProps.cars[0].length;
}

void fireBullet(int xPos, int yPos, int xSpeed, int ySpeed) {

	Projectile *bullet;

	bullet = (Projectile*) malloc(sizeof(Projectile));
	bullet->x = xPos;
	bullet->y = yPos;
	bullet->speedY = ySpeed;
	bullet->speedX = xSpeed;
	bullet->kind = 1;

	bullets.push_back(bullet);
}

void shoot() {
	for (auto& car : heroTrain.basicTrainProps.cars) {
		fireBullet(heroTrain.basicTrainProps.position + car.position, 150, 1,
				-1);
	}
}

int isHit(int pos, int line, Car* car, Projectile *bullet) {

	if (bullet != NULL) {

		if (bullet->y > line && bullet->y < (line + 15)
				&& bullet->x > (car->position + pos)
				&& bullet->x < (car->position + car->length + pos)) {
			return 1;
		}
	}

	return 0;
}

void destroyBullet(Projectile *bullet) {
	bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet),
			bullets.end());
	free(bullet);
}

void updateGame() {

	std::vector<Projectile*> toDestroy;

	for (auto& bullet : bullets) {
		bullet->x += bullet->speedX;
		bullet->y += bullet->speedY;

		if (bullet->y < 0) {
			destroyBullet(bullet);
			continue;
		}

		if (bullet->y >= 192) {
			destroyBullet(bullet);
			continue;
		}

		for (auto& car : villainTrain.basicTrainProps.cars) {

			if (car.hull <= 0) {
				continue;
			}

			if (isHit(villainTrain.basicTrainProps.position, 15, &car,
					bullet)) {
				car.hit = 1;
				car.hull -= 1;
				toDestroy.push_back(bullet);
				fireBullet(villainTrain.basicTrainProps.position + car.position,
						35, -1, 1);
				continue;
			}
		}

		for (auto& car : heroTrain.basicTrainProps.cars) {

			if (car.hull <= 0) {
				continue;
			}

			if (isHit(heroTrain.basicTrainProps.position, 150, &car, bullet)) {
				car.hit = 1;
				car.hull -= 1;
				destroyBullet(bullet);
			}
		}
	}

	if (villainTrain.basicTrainProps.speed == 0) {
		villainTrain.basicTrainProps.position--;

		if (villainTrain.basicTrainProps.position
				== -villainTrain.basicTrainProps.length) {
			villainTrain.basicTrainProps.speed = 8;
		}
	} else {
		villainTrain.basicTrainProps.position++;

		if (villainTrain.basicTrainProps.position == 255) {
			villainTrain.basicTrainProps.speed = 0;
		}
	}

	for (auto &bullet : toDestroy) {
		destroyBullet(bullet);
	}
}

int main(int argc, char **argv) {

	initGraphics();
	initGroundTypes();
	initTrains();

	quit = false;

	struct timeval timeBefore;
	struct timeval timeAfter;
	int slept = 0;
	long delta;

	while (!quit) {
		gettimeofday(&timeBefore, NULL);

		handleEvents();

		mapPos += 8;
		updateTerrain(mapPos);
		updateGame();

		if (mapPos > 8) {
			refreshGraphics();
		}

		gettimeofday(&timeAfter, NULL);
		delta = (timeAfter.tv_usec - timeBefore.tv_usec) / 100;

		if (delta < 0) {
			delta = -delta;
		}

		if (delta < 50) {
			sleepForMS(50 - delta);
			slept++;
		}
	}

	printf("slept for %d frames", slept);
	shutdownGraphics();
	return 0;
}
