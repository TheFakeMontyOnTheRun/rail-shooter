#include "CarElement.h"

CarElement::CarElement( int aHull, int aLength, int aRelativePosition ):
  hull( aHull ), length( aLength ), position( aRelativePosition ), hit( false ) {
}

void CarElement::update( long step ) {
}
