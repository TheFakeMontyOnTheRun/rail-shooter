/*
 * Peasant.cpp
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
#include "Peasant.h"
#include "Video.h"

Peasant::Peasant(const Character::Holder& aPlace) :
		Character(aPlace, Area(Vec2(0, 0), Vec2(25, 50))) {
}

Peasant::~Peasant() {
}

int Peasant::getResId() {
	return Image::HERO;
}

void Peasant::update(long step,
		const std::vector<Bullet*>& bullets,
		const std::vector<Explosion*>& explosions) {
			
	Character::update( step, bullets, explosions );
}

void Peasant::fire() {

}

