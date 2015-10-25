#ifndef TRAIN_H
#define TRAIN_H

const int ENEMY_RAIL_Y = 10;
const int PLAYER_RAIL_Y = 350;

class Train : public Car::ICarHolder {
 public:
  int speed;
  Vec2 position{ 0, 0 };
  int length;
  std::vector<std::shared_ptr<Car> > cars;
  virtual Vec2 getPosition() override;
  void update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions );
  Train( int length, Vec2 position, int speed );
};

#endif
