/*
 * Character.h
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */

#ifndef SRC_CHARACTER_H_
#define SRC_CHARACTER_H_

class Character {
public:
	enum class State{ AIMING, SHOOTING, WALKING_LEFT, WALKING_RIGHT };
	virtual int getResId() = 0;
	virtual void update( long ms ) = 0;
	State currentState = { State::AIMING };
	int position{ 0 };
	int health{ 25 };
	int power{ 10 };
	Character();
	virtual void shoot() = 0;
	virtual ~Character();
};

#endif /* SRC_CHARACTER_H_ */
