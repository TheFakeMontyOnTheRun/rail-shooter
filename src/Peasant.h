/*
 * Peasant.h
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */

#ifndef SRC_PEASANT_H_
#define SRC_PEASANT_H_

#include "Character.h"

class Peasant: public Character {
public:
	Peasant();
	virtual ~Peasant();
	virtual int getResId();
};

#endif /* SRC_PEASANT_H_ */
