#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "CoveredZBorCar.h"

const int HULL = 50;
const int LENGTH = 30;

CoveredZBorCar::CoveredZBorCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {
}

int CoveredZBorCar::getResId() {
  return 2;
}
