#include "GroundType.h" 
#include "background.h"

Column columns[8];
GroundType ice;
GroundType desert;

void initGroundTypes() {
	ice.resId = 1;
	desert.resId = 2;
}

void updateTerrain(int mapPos) {
	int stripPos = 0;
	int stripWidth = 6;

	for (stripPos = 0; stripPos < stripWidth; ++stripPos) {
		columns[mapPos % 8].tiles[stripPos] =
				(mapPos % 8) > stripPos ? &ice : &desert;
	}
}
