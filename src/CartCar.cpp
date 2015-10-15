#include <vector>
#include <memory>
#include "CarElement.h"
#include "Character.h"
#include "Peasant.h"
#include "Car.h"
#include "CartCar.h"
#include "Video.h"

const int HULL = 10;
const int LENGTH = 15;

CartCar::CartCar( int aPosition ):
  Car( HULL, LENGTH, aPosition ) {

	auto sergei = std::make_shared<Peasant>();
	occupants.push_back( sergei );
}

int CartCar::getResId() {
  return Image::PLAYER;
}
