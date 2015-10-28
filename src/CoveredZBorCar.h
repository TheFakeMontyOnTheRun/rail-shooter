#ifndef COVEREDZBORCAR_H
#define COVEREDZBORCAR_H

class CoveredZBorCar: public Car {
public:
	virtual int getResId();
	CoveredZBorCar(const Car::Holder& train, const Vec2& position);
	virtual ~CoveredZBorCar();
};

#endif
