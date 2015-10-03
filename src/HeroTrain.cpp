#include <vector>
#include "CarElement.h"
#include "Car.h"
#include "Train.h"
#include "HeroTrain.h"

HeroTrain::HeroTrain():
  basicTrainProps(30, 0, 8 ), crew( 1 )
{
  basicTrainProps.cars.push_back( Car( 30,20,0 ) );
}  
