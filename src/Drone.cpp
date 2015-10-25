/*
 * Drone.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */
#include <memory>
#include <vector>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "Character.h"
#include "Drone.h"
#include "Video.h"

#include "GroundType.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "RailShooter.h"

int Drone::getResId() {
	return Image::DRONE;
}

Drone::Drone( std::shared_ptr<Character::ICharacterHolder> aPlace ): 
Character(aPlace, Area( Vec2(0,0), Vec2(50, 60) )) {
}

Drone::~Drone() {
}

void Drone::update( long ms, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions ) {
	Character::update( ms, bullets, explosions );
	
	if ( health <= 0 ) {
		return;
	}


	if ( position.x == 0 && currentState == State::WALKING_LEFT ) {
		currentState = State::AIMING;
	} else if ( position.x >= 200 ) {
		currentState = State::WALKING_LEFT;
	}

	switch ( currentState ) {
		case State::WALKING_LEFT:
			position.x -= 1;
			break;
		case State::WALKING_RIGHT:
			position.x += 1;
			break;
		case State::AIMING:
			currentState = State::SHOOTING;
			break;
		case State::SHOOTING:
			fire();
			currentState = State::WALKING_RIGHT;
			break;
		default:
			currentState = State::WALKING_RIGHT;
			break;
	}
}

void Drone::fire() {
	Vec2 pos = place->getPositionForCharacter();
	pos += Vec2( position.x, 0 );

	fireBullet( pos.x, pos.y +5, 0, 5 );
}
