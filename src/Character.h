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

	class Holder {
	public:
		virtual Vec2 getPositionForCharacter() const = 0;
	};

	const Character::Holder* place{nullptr};

	enum class State {
		AIMING, SHOOTING, WALKING_LEFT, WALKING_RIGHT
	};
	Area hitArea { Vec2 { 0, 0 }, Vec2 { 0, 0 } };
	virtual int getResId() = 0;
	virtual void update(long step,
			const std::vector<Bullet*>& bullets,
			const std::vector<Explosion*>& explosions) = 0;
	State currentState = { State::AIMING };
	Vec2 position { 0, 0 };
	int health { 25 };
	int power { 10 };
	Character(const Holder& place, const Area& hitArea);
	virtual void fire();
	virtual ~Character();
};

#endif /* SRC_CHARACTER_H_ */
