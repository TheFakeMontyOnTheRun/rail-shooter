#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Turret.h"
#include "Character.h"
#include "Drone.h"
#include "Car.h"
#include "CoveredZBorCar.h"
#include "OpenZBorCar.h"
#include "Train.h"
#include "VillainTrain.h"

VillainTrain::VillainTrain() :
		basicTrainProps(30, Vec2(0, ENEMY_RAIL_Y), 8) {

	auto holder = std::shared_ptr < Car::Holder > (&basicTrainProps);

	auto car = std::make_shared < CoveredZBorCar > (holder, Vec2(0, 0));
	auto car2 = std::make_shared < OpenZBorCar > (holder, Vec2(300, 0));

	// auto turret = std::make_shared < Turret > (car2, Vec2(4, 64));
	// auto turret2 = std::make_shared < Turret > (car2, Vec2(75, 64));
	// auto turret3 = std::make_shared < Turret > (car, Vec2(115, 64));

	// car2->elements.push_back(turret);
	// car2->elements.push_back(turret2);
	// car->elements.push_back(turret3);

	basicTrainProps.cars.push_back(car2);
	basicTrainProps.cars.push_back(car);
}
