#ifndef OPENZBORCAR_H
#define OPENZBORCAR_H

class OpenZBorCar: public Car {
private:
	std::shared_ptr<Drone> drone1;
	std::shared_ptr<Drone> drone2;
	long acc { 0 };
public:
	virtual int getResId();
	virtual void update(long step,
			const std::vector<std::shared_ptr<Bullet> >& bullets,
			const std::vector<std::shared_ptr<Explosion>>& explosions);
	OpenZBorCar(const std::shared_ptr<Car::Holder>& train, const Vec2& position);
};

#endif
