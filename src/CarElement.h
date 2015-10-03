#ifndef CARELEMENT_H
#define CARELEMENT_H

class CarElement {
 public:

  int hull;
  int length;
  bool hit;
  int position;

  CarElement( int hull, int length, int relativePosition );
};
#endif
