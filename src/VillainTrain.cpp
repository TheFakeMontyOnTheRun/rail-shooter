#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "CoveredZBorCar.h"
#include "OpenZBorCar.h"
#include "Train.h"
#include "VillainTrain.h"

VillainTrain::VillainTrain():
basicTrainProps( 30, 0, 8 ) {

  CoveredZBorCar *car = new CoveredZBorCar( 0 );
  OpenZBorCar *car2 = new OpenZBorCar( 300 );


  CarElement *turret = new CarElement( 10, 5, 4 );
  CarElement *turret2 = new CarElement( 10, 5, 50 );
  CarElement *turret3 = new CarElement( 10, 5, 25 );
 

  car2->elements.push_back( turret );
  car2->elements.push_back( turret2 );

  car->elements.push_back( turret3 );

  basicTrainProps.cars.push_back( car );
  basicTrainProps.cars.push_back( car2 );
}
