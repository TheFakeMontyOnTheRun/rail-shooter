#ifndef TURRET_H
#define TURRET_H

class Turret : public CarElement{
 public:
  virtual int getResId();
  virtual void fire();
  Turret( std::shared_ptr<CarElement::Holder> parent, Vec2 position );
};

#endif
