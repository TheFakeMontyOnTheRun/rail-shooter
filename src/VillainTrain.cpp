#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "Train.h"
#include "VillainTrain.h"

VillainTrain::VillainTrain():
basicTrainProps( 30, 0, 8 ) {

  Car car( 30, 20, 0 );
  CarElement turret( 10, 5, 4 );
  car.elements.push_back( turret );
  basicTrainProps.cars.push_back( car );
}
