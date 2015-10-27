/*
 * Drone.h
 *
 *  Created on: Oct 13, 2015
 *      Author: monty
 */

#ifndef SRC_DRONE_H_
#define SRC_DRONE_H_

class Drone: public Character {
public:
	Drone(const Character::Holder& parent);
	virtual ~Drone();
	virtual int getResId() override;
	virtual void update(long step,
			const std::vector<Bullet* >& bullets,
			const std::vector<Explosion*>& explosions) override;
	virtual void fire() override;
};

#endif /* SRC_DRONE_H_ */
