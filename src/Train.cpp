#include <vector>
#include <memory>
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Train.h"

Train::Train( int aLength, int aRelativePosition, int aSpeed ):
  length( aLength ), position( aRelativePosition ), speed( aSpeed ) {
}

void Train::update( long step ) {

  position += speed;
  
  for ( auto& car : cars ) {
    car->update( step );
  }
}
