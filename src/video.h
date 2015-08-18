#ifndef VIDEO_H
#define VIDEO_H

const int XRES = 255;
const int YRES = 192;

void initGraphics();
void refreshGraphics();
void handleEvents();
void shutdownGraphics();
void sleepForMS( long ms );
#endif
