#ifndef CAR_H
#define CAR_H

class Car {
 public:
  std::vector<CarElement*> elements;
  int hull;
  int length;
  bool hit;
  int position;
  virtual int getResId() = 0;
  virtual void update( long step );
  Car( int hull, int length, int position );
};
#endif