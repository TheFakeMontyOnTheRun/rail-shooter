#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>

#include "GroundType.h"
#include "CarElement.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "Vec2.h"
#include  "Bullet.h"

#include "Video.h"

#include "Background.h"
#include "RailShooter.h"

SDL_Surface *video;
SDL_Surface *shot;
SDL_Surface *player;
SDL_Surface *zbor;
SDL_Surface *bg1;
SDL_Surface *bg2;
SDL_Surface *turret;

void initGraphics() {

	if (SDL_Init( SDL_INIT_VIDEO) != 0) {
		printf("Erro de SDL...");
		exit(-1);
	}
	video = SDL_SetVideoMode(XRES, YRES, 0, SDL_HWSURFACE);
	shot = IMG_Load("res/misc/shot.png");
	player = IMG_Load("res/player/wagon.png");
	zbor = IMG_Load("res/foes/zbor1.png");
	bg1 = IMG_Load("res/scenary/stage1-floor_all.png");
	bg2 = IMG_Load("res/scenary/stage1-floor_grass.png");
	turret = IMG_Load( "res/foes/turret.png" );
}

void sleepForMS(long ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds( ms ));
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
			SDL_BlitSurface( ( columns[ (c + mapPos ) % TILES_X ].tiles[ d ] == &ice ) ? bg1 : bg1, nullptr, video, &tile);
		}
	}
}

void clearGraphics() {
	SDL_FillRect(video, NULL, 0);
}

void drawTrain( Train &train, int pos, int line, SDL_Surface*asset) {
  
  SDL_Rect tile;
    
  for (auto& car : train.cars) {
    
    tile.x = pos + car.position;
    tile.w = car.length;
    tile.y = line;
    tile.h = 15;
    car.hit = false;
    
    SDL_BlitSurface(asset, nullptr, video, &tile);
    
    for ( auto& carElement : car.elements ) {
      tile.x = pos + car.position + carElement.position;
      tile.w = 30;
      tile.y = line;
      tile.h = 15;
      SDL_BlitSurface( turret, nullptr, video, &tile);
    }
  }
}

void refreshGraphics() {

	drawBackground();

	drawTrain(villainTrain.basicTrainProps, villainTrain.basicTrainProps.position - mapPos, ENEMY_RAIL_Y, zbor);

	drawTrain(heroTrain.basicTrainProps, heroTrain.basicTrainProps.position -  mapPos, PLAYER_RAIL_Y, player);

	SDL_Rect tile;

	for (auto& bullet : bullets) {

		if (bullet != NULL) {
			tile.x = bullet->position.x - mapPos;
			tile.y = bullet->position.y;
			tile.w = 8;
			tile.h = 8;

			SDL_BlitSurface(shot, NULL, video, &tile);
		}
	}

	SDL_UpdateRect(video, 0, 0, 0, 0);
}

void handleEvents() {
	SDL_Event events;

	memset( &events, 0, sizeof( events ) );

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
	SDL_Quit();
}
