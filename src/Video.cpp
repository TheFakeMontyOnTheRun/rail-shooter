#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "Vec2.h"
#include  "Bullet.h"
#include "Explosion.h"
#include "Area.h"
#include "GroundType.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "Explosion.h"
#include "Video.h"

#include "Background.h"
#include "RailShooter.h"

SDL_Surface *video;
SDL_Surface *shot;
SDL_Surface *player;
SDL_Surface *zbor1;
SDL_Surface *zbor2;
SDL_Surface *bg1;
SDL_Surface *bg2;
SDL_Surface *turret;
SDL_Surface *hero;
SDL_Surface *drone;
SDL_Surface *hit;

SDL_Surface *res[9];

void initGraphics() {

	if (SDL_Init( SDL_INIT_VIDEO) != 0) {
		printf("Erro de SDL...");
		exit(-1);
	}

	video = SDL_SetVideoMode(XRES, YRES, 0, SDL_HWSURFACE);
	shot = IMG_Load("res/misc/shot.png");
	player = IMG_Load("res/player/wagon.png");
	zbor1 = IMG_Load("res/foes/zbor1.png");
	zbor2 = IMG_Load("res/foes/zbor2.png");
	bg1 = IMG_Load("res/scenary/stage1-floor_all.png");
	bg2 = IMG_Load("res/scenary/stage1-floor_grass.png");
	turret = IMG_Load("res/foes/turret.png");
	hero = IMG_Load("res/player/character1.png");
	drone = IMG_Load("res/foes/enemy.png");
	hit = IMG_Load("res/misc/hit.png");

	res[Image::NOTHING] = nullptr;
	res[Image::PLAYER] = player;
	res[Image::ZBOR2] = zbor2;
	res[Image::ZBOR1] = zbor1;
	res[Image::TURRET] = turret;
	res[Image::PLAYER2] = player;
	res[Image::HERO] = hero;
	res[Image::DRONE] = drone;
	res[Image::HIT] = hit;
}

void sleepForMS(long ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void drawBackground() {

	SDL_Rect tile;

	int c;
	int d;

	tile.w = 64;
	tile.h = 64;

	for (c = 0; c < TILES_X; ++c) {
		for (d = 0; d < TILES_Y; ++d) {
			tile.x = (c * 64) - (mapPos % 64);
			tile.y = d * 64;
			SDL_BlitSurface(
					(columns[(c + mapPos) % TILES_X].tiles[d] == &ice) ?
							bg1 : bg1, nullptr, video, &tile);
		}
	}
}

void drawTrain(const Train &train, int pos, int line) {

	SDL_Rect tile;

	for (auto& car : train.cars) {
		SDL_Surface *asset = res[car->getResId()];

		tile.x = pos + car->position.x;
		tile.w = car->length;
		tile.y = line;
		tile.h = 15;
		SDL_BlitSurface(asset, nullptr, video, &tile);

		for (auto& character : car->occupants) {

			if (character->health <= 0) {
				continue;
			}

			asset = res[character->getResId()];
			tile.x = pos + car->position.x + character->position.x;
			tile.w = 30;
			tile.y = line;
			tile.h = 15;
			SDL_BlitSurface(asset, nullptr, video, &tile);
		}

		for (auto& carElement : car->elements) {

			if (carElement->hull <= 0) {
				continue;
			}

			asset = res[carElement->getResId()];
			tile.x = pos + car->position.x + carElement->position.x;
			tile.w = 30;
			tile.y = line + 64;
			tile.h = 15;
			SDL_BlitSurface(asset, nullptr, video, &tile);
		}
	}
}

void drawMiniMap() {
	
	SDL_Rect tile;
	int basePos = villainTrain.basicTrainProps.position.x;
	int offsetPos = heroTrain.basicTrainProps.position.x;
	int acc = 0;
	for ( auto& car : villainTrain.basicTrainProps.cars ) {
		tile.x = ( XRES / 2 ) +  ( acc ) + ( basePos - offsetPos ) / 100;
		tile.w = car->length;
		tile.y = 5;
		tile.h = 10;
		acc += car->length + 5;

		bool hasElementsToDestroy = false;
		
		for ( auto& carElement : car->elements ) {
			if ( carElement->hull > 0 ) {
				hasElementsToDestroy = true;
			}
		}
		
		for ( auto& passanger : car->occupants ) {
			if ( passanger->health > 0 ) {
				hasElementsToDestroy = true;
			}
		}

		SDL_FillRect( video, &tile, hasElementsToDestroy ? 0xFF00FF00 : 0xFF0000FF );
	}
} 

void refreshGraphics() {

	drawBackground();

	drawTrain(villainTrain.basicTrainProps,
			villainTrain.basicTrainProps.position.x - mapPos, ENEMY_RAIL_Y);

	drawTrain(heroTrain.basicTrainProps,
			heroTrain.basicTrainProps.position.x - mapPos, PLAYER_RAIL_Y);

	SDL_Rect tile;

	for (auto& bullet : bullets) {

		if (!bullet->isValid()) {
			continue;
		}

		tile.x = bullet->position.x - mapPos;
		tile.y = bullet->position.y;
		tile.w = 8;
		tile.h = 8;

		SDL_BlitSurface(shot, nullptr, video, &tile);
	}

	for (auto& explosion : explosions) {

		if (!explosion->isValid()) {
			continue;
		}

		tile.x = explosion->position.x - mapPos;
		tile.y = explosion->position.y;
		tile.w = 8;
		tile.h = 8;

		SDL_BlitSurface(hit, nullptr, video, &tile);
	}
	
	drawMiniMap();

	SDL_UpdateRect(video, 0, 0, 0, 0);
}

void handleEvents() {
	SDL_Event events;

	memset(&events, 0, sizeof(events));

	SDL_PollEvent(&events);

	if (events.type == SDL_KEYDOWN) {
		if (events.key.keysym.sym == SDLK_q) {
			quit = true;
		}

		if (events.key.keysym.sym == SDLK_a) {
			villainTrain.basicTrainProps.speed -= 1;
		}

		if (events.key.keysym.sym == SDLK_s) {
			villainTrain.basicTrainProps.speed += 1;
		}

		if (events.key.keysym.sym == SDLK_LEFT) {
			heroTrain.basicTrainProps.speed -= 1;
		}

		if (events.key.keysym.sym == SDLK_SPACE) {
			shoot();
		}

		if (events.key.keysym.sym == SDLK_RIGHT) {
			heroTrain.basicTrainProps.speed += 1;
		}

		if (events.key.keysym.sym == SDLK_SPACE) {
		}
	}
}

void shutdownGraphics() {
	
	SDL_FreeSurface( video );
	SDL_FreeSurface( shot );
	SDL_FreeSurface( player );
	SDL_FreeSurface( zbor1 );
	SDL_FreeSurface( zbor2 );
	SDL_FreeSurface( bg1 );
	SDL_FreeSurface( bg2 );
	SDL_FreeSurface( turret );
	SDL_FreeSurface( hero );
	SDL_FreeSurface( drone );
	SDL_FreeSurface( hit );

	SDL_Quit();
}
