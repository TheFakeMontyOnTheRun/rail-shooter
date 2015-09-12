#ifndef VIDEO_H
#define VIDEO_H

const int XRES = 640;
const int YRES = 480;

const int ENEMY_RAIL_Y = 10;
const int PLAYER_RAIL_Y = 350;

void initGraphics();
void refreshGraphics();
void handleEvents();
void shutdownGraphics();
void sleepForMS( long ms );
#endif
