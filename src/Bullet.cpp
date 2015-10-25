#include "Vec2.h"
#include "Bullet.h"

void Bullet::update( long step ) {
  position += speed;
}

Bullet::Bullet( const Vec2& aPosition, const Vec2& aSpeed ):
  position( aPosition ), speed( aSpeed ) {
}

bool Bullet::isValid() {
  return valid;
}

void Bullet::hit() {
  valid = false;
}