#include <vector>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Drone.h"
#include "Car.h"
#include "OpenZBorCar.h"
#include "Video.h"

const int HULL = 40;
const int LENGTH = 30;

OpenZBorCar::OpenZBorCar(const Car::Holder& aTrain, const Vec2& aPosition) :
		Car(aTrain, HULL, LENGTH, aPosition) {

	drone1 = new Drone(*this);
	drone1->position.x = 140;
	occupants.push_back(drone1);
	drone2 = new Drone(*this);
	drone2->position.x = 200;
	occupants.push_back(drone2);
}

void OpenZBorCar::update(long ms,
		const std::vector<Bullet* >& bullets,
		const std::vector<Explosion*>& explosions) {
	Car::update(ms, bullets, explosions);

	acc += ms;

	if (acc >= 1000) {
		acc = 0;
		Car::fire();
	}
}

int OpenZBorCar::getResId() {
	return Image::ZBOR1;
}

OpenZBorCar::~OpenZBorCar() {
	
}
