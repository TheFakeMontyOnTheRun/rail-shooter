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
	Peasant(const Character::Holder& place);
	virtual ~Peasant();
	virtual int getResId();
	virtual void update(long step,
			const std::vector<Bullet*>& bullets,
			const std::vector<Explosion*>& explosions) override;
	virtual void fire() override;
};

#endif /* SRC_PEASANT_H_ */
