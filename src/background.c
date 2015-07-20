#include "GroundType.h" 
#include "background.h"

void initGroundTypes() {
  ice.representation = 'O';
  ice.colour = 0xFF55FF55;
  
  desert.representation = '.';
  desert.colour = 0xFF555555;
}

void updateTerrain( int mapPos ) {
  int stripPos = 0;
  int stripWidth = 6;
		
  for ( stripPos = 0; stripPos < stripWidth; ++stripPos ){
     columns[ mapPos % 8 ].tiles[ stripPos ] = ( mapPos % 8 ) > stripPos ? &ice : &desert;
  }
}
