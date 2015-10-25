#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"

Car::Car( std::shared_ptr<Car::ICarHolder> aTrain, int aHull, int aLength, Vec2 aRelativePosition ):
  train( aTrain ), hull( aHull ), length( aLength ), position( aRelativePosition )
{}

void Car::update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions ) {
  for ( auto &element : elements ) {
	  if ( element->hull > 0 ) {  
    	element->update( step, bullets, explosions );
	  }
  }

  for ( auto& passenger : occupants ) {
	  if ( passenger->health > 0 ) {
		  passenger->update( step, bullets, explosions );
	  }
  }
}

Vec2 Car::getPositionForCharacter() {
	return getPosition();
}

Vec2 Car::getPositionForCarElement() {
	return getPosition();
}

void Car::fire() {
	for ( auto& passenger: occupants ) {
		if ( passenger->health > 0 ) {
			passenger->fire();
	  	}
	}

	for ( auto& element : elements ) {
	  if ( element->hull > 0 ) {		
			element->fire();
		}
	}
}


Vec2 Car::getPosition() {
	Vec2 toReturn = Vec2(position.x, position.y );

	if ( train != nullptr ) {
		toReturn += train->getPosition();
	}

	return toReturn;
}
