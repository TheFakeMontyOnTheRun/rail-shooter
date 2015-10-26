#include <vector>
#include <memory>
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

OpenZBorCar::OpenZBorCar(const std::shared_ptr<Car::Holder>& aTrain, const Vec2& aPosition) :
		Car(aTrain, HULL, LENGTH, aPosition) {

	std::shared_ptr<Character::Holder> holder = std::shared_ptr
			< Character::Holder > (this);

	drone1 = std::make_shared < Drone > (holder);
	drone1->position.x = 140;
	occupants.push_back(drone1);
	drone2 = std::make_shared < Drone > (holder);
	drone2->position.x = 200;
	occupants.push_back(drone2);
}

void OpenZBorCar::update(long ms,
		const std::vector<std::shared_ptr<Bullet> >& bullets,
		const std::vector<std::shared_ptr<Explosion>>& explosions) {
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
