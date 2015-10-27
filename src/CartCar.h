#ifndef CARTCAR_H
#define CARTCAR_H

class CartCar: public Car {
public:
	virtual int getResId() override;
	CartCar(const Car::Holder& train, const Vec2& position);
	virtual ~CartCar();
};

#endif
