#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "CartCar.h"

const int HULL = 10;
const int LENGTH = 15;

CartCar::CartCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {
}

int CartCar::getResId() {
  return 1;
}
