/*
 * Drone.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */
#include "Character.h"
#include "Drone.h"

int Drone::getResId() {
	return 7;
}

Drone::Drone() {
	// TODO Auto-generated constructor stub

}

Drone::~Drone() {
	// TODO Auto-generated destructor stub
}

void Drone::update( long ms ) {

	if ( position == 0 && currentState == State::WALKING_LEFT ) {
		currentState = State::AIMING;
	} else if ( position >= 200 ) {
		currentState = State::WALKING_LEFT;
	}

	switch ( currentState ) {
		case State::WALKING_LEFT:
			position -= 1;
			break;
		case State::WALKING_RIGHT:
			position += 1;
			break;
		case State::AIMING:
			currentState = State::SHOOTING;
			break;
		case State::SHOOTING:
			shoot();
			currentState = State::WALKING_RIGHT;
			break;
		default:
			currentState = State::WALKING_RIGHT;
			break;
	}
}

void Drone::shoot() {

}
