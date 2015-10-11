#ifndef OPENZBORCAR_H
#define OPENZBORCAR_H

class OpenZBorCar : public Car {

 public:
  virtual int getResId();
  OpenZBorCar( int position );
};

#endif
