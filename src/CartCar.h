#ifndef CARTCAR_H
#define CARTCAR_H

class CartCar : public Car {
 public:
  virtual int getResId() override;
  CartCar( int position );
};

#endif
