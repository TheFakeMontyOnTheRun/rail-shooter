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
	Drone( std::shared_ptr<Character::Holder> parent );
	virtual ~Drone();
	virtual int getResId() override;
	virtual void update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions ) override;
	virtual void fire() override;
};

#endif /* SRC_DRONE_H_ */
