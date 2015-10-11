#ifndef CARELEMENT_H
#define CARELEMENT_H

class CarElement {
 public:

  int hull;
  int length;
  bool hit;
  int position;
  virtual int getResId() = 0;
  virtual void update( long step );
  CarElement( int hull, int length, int relativePosition );
};
#endif
