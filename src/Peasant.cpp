/*
 * Peasant.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */
#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "Character.h"
#include "Peasant.h"
#include "Video.h"

Peasant::Peasant( std::shared_ptr<Character::ICharacterHolder> aPlace ) :
	Character( aPlace, Area( Vec2(0,0), Vec2(25, 50) ) ) {
}

Peasant::~Peasant() {
}

int Peasant::getResId() {
	return Image::HERO;
}

void Peasant::update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions ) {
}

void Peasant::fire() {

}

