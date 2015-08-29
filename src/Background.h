#ifndef BACKGROUND_H
#define BACKGROUND_H

typedef struct {
	GroundType *tiles[ 6 ];
} Column;

extern Column columns[ 8 ];
extern GroundType ice;
extern GroundType desert;


void initGroundTypes();
void updateTerrain( int pos );

#endif
