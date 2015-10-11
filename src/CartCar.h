#ifndef CARTCAR_H
#define CARTCAR_H

class CartCar : public Car {
 public:
  virtual int getResId();
  CartCar( int position );
};

#endif
