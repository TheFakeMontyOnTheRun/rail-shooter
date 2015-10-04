#ifndef BULLET_H
#define BULLET_H

class Bullet {
 public:
  Vec2 speed;
  Vec2 position;

  void update( long step );
  Bullet( const Vec2& position, const Vec2& speed );
};
#endif
