#include <memory>
#include <vector>
#include "Vec2.h"
#include "Explosion.h"

Explosion::Explosion( long aTimeToExpire, const Vec2& aPosition ):
timeToExpire( aTimeToExpire ), position( aPosition ) {
	
}

void Explosion::update( long ms ) {
	timeToExpire -= ms;	
}

bool Explosion::isValid() {
	return timeToExpire >= 0;
}