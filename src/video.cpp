#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>

#include "GroundType.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include  "projectile.h"

#include "video.h"
#include "generator.h"
#include "background.h" 

SDL_Surface *video;
SDL_Surface *shot;
SDL_Surface *player;
SDL_Surface *zbor;
SDL_Surface *bg1;
SDL_Surface *bg2;

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
}

void sleepForMS(long ms) {
	SDL_Delay(ms);
}

void drawBackground() {

	SDL_Rect tile;

	int c;
	int d;

	for (c = 0; c < 5; ++c) {
		for (d = 0; d < 3; ++d) {

			tile.x = (c * 64) - (mapPos % 64);
			tile.y = d * 64;
			tile.w = 64;
			tile.h = 64;

			SDL_BlitSurface(bg1, NULL, video, &tile);
			/*      SDL_FillRect( video, &tile, columns[ (c + mapPos ) % 8 ].tiles[ d ]->colour );*/
		}
	}
}

void clearGraphics() {
	SDL_FillRect(video, NULL, 0);
}

void drawTrain(std::vector<Car> &cars, int pos, int line, SDL_Surface*asset) {

	SDL_Rect tile;
	int acc;
	acc = pos;

	for (auto car : cars) {

		tile.x = acc + car.position;
		tile.w = car.length;
		tile.y = line;
		tile.h = 15;

		if (car.hit) {
			car.hit = 0;
		}

		SDL_BlitSurface(asset, NULL, video, &tile);
	}
}

void refreshGraphics() {

	drawBackground();

	drawTrain(villainTrain.basicTrainProps.cars,
			villainTrain.basicTrainProps.position, -30, zbor);

	drawTrain(heroTrain.basicTrainProps.cars,
			heroTrain.basicTrainProps.position, 100, player);

	SDL_Rect tile;

	for (auto bullet : bullets) {

		if (bullet != NULL) {
			tile.x = bullet->x;
			tile.y = bullet->y;
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

		if (events.key.keysym.sym == SDLK_LEFT) {
			heroTrain.basicTrainProps.position -= 16;
		}

		if (events.key.keysym.sym == SDLK_SPACE) {
			shoot();
		}

		if (events.key.keysym.sym == SDLK_RIGHT) {
			heroTrain.basicTrainProps.position += 16;
		}

		if (events.key.keysym.sym == SDLK_SPACE) {
		}
	}
}

void shutdownGraphics() {
	SDL_Quit();
}
