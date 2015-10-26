#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "CartCar.h"
#include "Train.h"
#include "HeroTrain.h"

HeroTrain::HeroTrain() :
		basicTrainProps(30, Vec2(0, PLAYER_RAIL_Y), 8), crew(1) {
	auto holder = std::shared_ptr < Car::Holder > (&basicTrainProps);
	basicTrainProps.cars.push_back(
			std::make_shared < CartCar > (holder, Vec2(0, 0)));
}
