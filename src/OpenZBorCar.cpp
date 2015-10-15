#include <vector>
#include <memory>
#include "CarElement.h"
#include "Character.h"
#include "Drone.h"
#include "Car.h"
#include "OpenZBorCar.h"
#include "Video.h"

const int HULL = 40;
const int LENGTH = 30;

OpenZBorCar::OpenZBorCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {

	{
		auto drone = std::make_shared<Drone>();
		drone->position = 140;
		occupants.push_back( drone );
	}

	{
		auto drone = std::make_shared<Drone>();
		drone->position = 200;
		occupants.push_back( drone );
	}
}

int OpenZBorCar::getResId() {
  return Image::ZBOR1;
}
