#include <vector>
#include <memory>
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "CoveredZBorCar.h"
#include "Video.h"

const int HULL = 50;
const int LENGTH = 30;

CoveredZBorCar::CoveredZBorCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {
}

int CoveredZBorCar::getResId() {
  return Image::ZBOR2;
}
