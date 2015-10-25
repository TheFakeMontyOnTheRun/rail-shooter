#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Peasant.h"
#include "Car.h"
#include "CartCar.h"
#include "Video.h"

const int HULL = 10;
const int LENGTH = 15;

CartCar::CartCar( std::shared_ptr<Car::ICarHolder> train, Vec2 aPosition ):
  Car( train, HULL, LENGTH, aPosition ) {

	auto holder = std::shared_ptr<Character::ICharacterHolder>( this);
	auto sergei = std::make_shared<Peasant>( holder );
	occupants.push_back( sergei );
}

int CartCar::getResId() {
  return Image::PLAYER;
}
