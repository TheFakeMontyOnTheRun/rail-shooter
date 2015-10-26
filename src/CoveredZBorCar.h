#ifndef COVEREDZBORCAR_H
#define COVEREDZBORCAR_H

class CoveredZBorCar: public Car {
public:
	virtual int getResId();
	CoveredZBorCar(std::shared_ptr<Car::Holder> train, Vec2 position);
};

#endif
