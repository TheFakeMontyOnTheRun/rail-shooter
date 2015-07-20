#ifndef BACKGROUND_H
#define BACKGROUND_H

typedef struct {
	GroundType *tiles[ 6 ];
} Column;

Column columns[ 8 ];

GroundType ice;
GroundType desert;


void initGroundTypes();
void updateTerrain( int pos );

#endif
