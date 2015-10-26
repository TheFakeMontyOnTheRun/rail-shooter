#ifndef VIDEO_H
#define VIDEO_H

const int XRES = 640;
const int YRES = 480;

enum Image {
	NOTHING, PLAYER, ZBOR1, ZBOR2, TURRET, PLAYER2, HERO, DRONE, HIT
};

void initGraphics();
void refreshGraphics();
void handleEvents();
void shutdownGraphics();
void sleepForMS(long ms);
#endif
