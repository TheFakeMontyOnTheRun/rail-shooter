/*
 * Character.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */
#include <vector>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "Character.h"

Character::Character(const Character::Holder& aPlace,
		const Area& aHitArea) :
		place(&aPlace), hitArea(aHitArea) {
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

void Character::update(long ms,
		const std::vector<Bullet* >& bullets,
		const std::vector<Explosion*>& explosions) {

	if (health <= 0) {
		return;
	}

	Vec2 parentPosition = place->getPositionForCharacter();

	hitArea.pos.x = parentPosition.x + position.x;
	hitArea.pos.y = parentPosition.y + position.y;

	for (auto& bullet : bullets) {
		if (bullet->isValid() && hitArea.contains(bullet->position)) {
			bullet->hit();

			const Vec2 pos = bullet->position;
			auto explosion = new Explosion(150, pos);
			::explosions.push_back(explosion);

			--health;
		}
	}
}

void Character::fire() {

}
