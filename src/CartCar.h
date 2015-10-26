#ifndef CARTCAR_H
#define CARTCAR_H

class CartCar: public Car {
public:
	virtual int getResId() override;
	CartCar(const std::shared_ptr<Car::Holder>& train, const Vec2& position);
};

#endif
