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
	virtual void update( long ms ) override;
	virtual void shoot() override;
};

#endif /* SRC_PEASANT_H_ */
