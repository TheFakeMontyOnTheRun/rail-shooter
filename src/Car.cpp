#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"

Car::Car(const Car::Holder& aTrain, int aHull, int aLength,
		const Vec2& aRelativePosition) :
		train(&aTrain), hull(aHull), length(aLength), position(aRelativePosition) {
}

void Car::update(long step,
		const std::vector<Bullet*>& bullets,
		const std::vector<Explosion*>& explosions) {
	for (auto &element : elements) {
		if (element->hull > 0) {
			element->update(step, bullets, explosions);
		}
	}

	for (auto& passenger : occupants) {
		if (passenger->health > 0) {
			passenger->update(step, bullets, explosions);
		}
	}
}

Vec2 Car::getPositionForCharacter() const {
	return getPosition();
}

Vec2 Car::getPositionForCarElement() const {
	return getPosition();
}

void Car::fire() {
	for (auto& passenger : occupants) {
		if (passenger->health > 0) {
			passenger->fire();
		}
	}

	for (auto& element : elements) {
		if (element->hull > 0) {
			element->fire();
		}
	}
}

Vec2 Car::getPosition() const {
	Vec2 toReturn = Vec2(position.x, position.y);

	if (train != nullptr) {
		toReturn += train->getPosition();
	}

	return toReturn;
}

Car::~Car() {
	for ( auto& element : elements ) {
		delete element;
	}
	
	for ( auto& character : occupants ) {
		delete character;
	}
	
	elements.clear();
	occupants.clear();
}
