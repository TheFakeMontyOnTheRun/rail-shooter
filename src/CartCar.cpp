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

CartCar::CartCar(const Car::Holder& train, const Vec2&	 aPosition) :
		Car(train, HULL, LENGTH, aPosition) {

	auto sergei = new Peasant(*this);
	occupants.push_back(sergei);
}

int CartCar::getResId() {
	return Image::PLAYER;
}

CartCar::~CartCar() {
	
}