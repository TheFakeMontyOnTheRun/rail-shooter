#include <vector>
#include "CarElement.h"
#include "Turret.h"
#include "Video.h"

const int HULL = 10;
const int SIZE = 10;

Turret::Turret( int aPosition ):
  CarElement( HULL, SIZE, aPosition ) {
}

int Turret::getResId() {
  return Image::TURRET;
}
