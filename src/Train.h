#ifndef TRAIN_H
#define TRAIN_H

class Train {
 public:
  int speed;
  int position;
  int length;
  std::vector<Car*> cars;

  void update( long step );
  Train( int length, int position, int speed );
};

#endif
