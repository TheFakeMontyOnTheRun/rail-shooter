#include <vector>
#include "CarElement.h"
#include "Car.h"

Car::Car( int aHull, int aLength, int aRelativePosition ):
  hull( aHull ), length( aLength ), position( aRelativePosition ), hit( false )
{}

void Car::update( long step ) {
  for ( auto &element : elements ) {
    element->update( step );
  }
}
