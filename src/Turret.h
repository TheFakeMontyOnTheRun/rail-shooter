#ifndef TURRET_H
#define TURRET_H

class Turret : public CarElement{
 public:
  virtual int getResId();
  Turret( int position );
};

#endif
