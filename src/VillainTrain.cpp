#include <vector>
#include <memory>
#include "CarElement.h"
#include "Turret.h"
#include "Character.h"
#include "Car.h"
#include "CoveredZBorCar.h"
#include "OpenZBorCar.h"
#include "Train.h"
#include "VillainTrain.h"

VillainTrain::VillainTrain():
basicTrainProps( 30, 0, 8 ) {

  auto car = std::make_shared<CoveredZBorCar>( 0 );
  auto car2 = std::make_shared<OpenZBorCar>( 300 );


  auto turret = std::make_shared<Turret>( 4 );
  auto turret2 = std::make_shared<Turret>( 75 );
  auto turret3 = std::make_shared<Turret>( 115 );
 

  car2->elements.push_back( turret );
  car2->elements.push_back( turret2 );
  car->elements.push_back( turret3 );

  basicTrainProps.cars.push_back( car2 );
  basicTrainProps.cars.push_back( car );
}
