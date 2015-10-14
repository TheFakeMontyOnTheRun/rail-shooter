#include <vector>
#include "CarElement.h"
#include "Character.h"
#include "Drone.h"
#include "Car.h"
#include "OpenZBorCar.h"

const int HULL = 40;
const int LENGTH = 30;

OpenZBorCar::OpenZBorCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {

	Character* drone;

	drone = new Drone();
	drone->position = 140;
	occupants.push_back( drone );

	drone = new Drone();
	drone->position = 200;
	occupants.push_back( drone );
}

int OpenZBorCar::getResId() {
  return 3;
}
