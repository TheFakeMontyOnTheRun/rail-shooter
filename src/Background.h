#ifndef BACKGROUND_H
#define BACKGROUND_H

const int TILES_X = 11;
const int TILES_Y = 8;

typedef struct {
	GroundType *tiles[ TILES_Y ];
} Column;

extern Column columns[ TILES_X ];
extern GroundType ice;
extern GroundType desert;


void initGroundTypes();
void updateTerrain( int pos );

#endif
