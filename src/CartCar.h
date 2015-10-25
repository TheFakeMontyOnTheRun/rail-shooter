#ifndef CARTCAR_H
#define CARTCAR_H

class CartCar : public Car {
 public:
  virtual int getResId() override;
  CartCar( std::shared_ptr<Car::ICarHolder> train, Vec2 position );
};

#endif
