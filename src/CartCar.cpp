#include <vector>
#include "CarElement.h"
#include "Character.h"
#include "Peasant.h"
#include "Car.h"
#include "CartCar.h"

const int HULL = 10;
const int LENGTH = 15;

CartCar::CartCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {

	Character* sergei = new Peasant();
	occupants.push_back( sergei );
}

int CartCar::getResId() {
  return 1;
}
