#ifndef OPENZBORCAR_H
#define OPENZBORCAR_H

class OpenZBorCar: public Car {
private:
	Drone* drone1{nullptr};
	Drone* drone2{nullptr};
	long acc { 0 };
public:
	virtual int getResId();
	virtual void update(long step,
			const std::vector<Bullet*>& bullets,
			const std::vector<Explosion*>& explosions);
	OpenZBorCar(const Car::Holder& train, const Vec2& position);
	~OpenZBorCar();
};

#endif
