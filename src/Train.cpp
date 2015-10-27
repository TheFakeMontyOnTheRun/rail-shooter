#include <vector>
#include <memory>
#include "Vec2.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Train.h"

Train::Train(int aLength, const Vec2& aRelativePosition, int aSpeed) :
		length(aLength), position(aRelativePosition), speed(aSpeed) {
}

void Train::update(long step,
		const std::vector<Bullet*>& bullets,
		const std::vector<Explosion*>& explosions) {

	position.x += speed;

	for (auto& car : cars) {
		car->update(step, bullets, explosions);
	}
}

Vec2 Train::getPosition() const {
	return Vec2(position.x, position.y);
}

Train::~Train() {
	
}
