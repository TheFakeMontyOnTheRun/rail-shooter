#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "OpenZBorCar.h"

const int HULL = 40;
const int LENGTH = 30;

OpenZBorCar::OpenZBorCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {
}

int OpenZBorCar::getResId() {
  return 3;
}
