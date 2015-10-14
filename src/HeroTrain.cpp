#include <vector>
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "CartCar.h"
#include "Train.h"
#include "HeroTrain.h"

HeroTrain::HeroTrain():
  basicTrainProps(30, 0, 8 ), crew( 1 )
{
  CartCar*  car = new CartCar( 0 );
  basicTrainProps.cars.push_back( car );
} 
