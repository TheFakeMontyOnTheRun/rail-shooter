#ifndef TRAIN_H
#define TRAIN_H

const int ENEMY_RAIL_Y = 10;
const int PLAYER_RAIL_Y = 350;

class Train: public Car::Holder {
public:
	int length;
	Vec2 position { 0, 0 };
	int speed;

	std::vector<Car*> cars;
	virtual Vec2 getPosition() const override;
	void update(long step, const std::vector<Bullet*>& bullets,
			const std::vector<Explosion*>& explosions);
	Train(int length, const Vec2& position, int speed);
	virtual ~Train();
};

#endif
