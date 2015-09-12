#include "GroundType.h"
#include "Background.h"

Column columns[TILES_X];
GroundType ice;
GroundType desert;

void initGroundTypes() {
	ice.resId = 1;
	desert.resId = 2;
}

void updateTerrain(int mapPos) {
	int stripPos = 0;
	int stripWidth = TILES_Y;

	for (stripPos = 0; stripPos < stripWidth; ++stripPos) {
		columns[mapPos % TILES_X].tiles[stripPos] =
				(mapPos % TILES_X) > stripPos ? &ice : &desert;
	}
}
