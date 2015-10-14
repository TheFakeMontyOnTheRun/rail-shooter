/*
 * Drone.h
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */

#ifndef SRC_DRONE_H_
#define SRC_DRONE_H_

#include "Character.h"

class Drone: public Character {
public:
	Drone();
	virtual ~Drone();
	virtual int getResId();
};

#endif /* SRC_DRONE_H_ */
