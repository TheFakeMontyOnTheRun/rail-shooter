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

	auto car = new CoveredZBorCar(basicTrainProps, Vec2(0, 0));
	auto car2 = new OpenZBorCar(basicTrainProps, Vec2(300, 0));
	auto car3 = new OpenZBorCar(basicTrainProps, Vec2(600, 0));
	auto car4 = new OpenZBorCar(basicTrainProps, Vec2(900, 0));
	auto car5 = new CoveredZBorCar(basicTrainProps, Vec2(1200, 0));

	auto turret = new Turret(*car2, Vec2(4, 64));
	auto turret2 = new Turret( *car2, Vec2(75, 64));
	auto turret3 = new Turret(*car, Vec2(115, 64));
	auto turret4 = new Turret( *car2, Vec2(75, 64));
	auto turret5 = new Turret(*car, Vec2(115, 64));

	car2->elements.push_back(turret);
	car2->elements.push_back(turret2);
	car->elements.push_back(turret3);
	
	car3->elements.push_back(turret4);
	car4->elements.push_back(turret5);

	basicTrainProps.cars.push_back(car5);
	basicTrainProps.cars.push_back(car4);
	basicTrainProps.cars.push_back(car3);
	basicTrainProps.cars.push_back(car2);
	basicTrainProps.cars.push_back(car);
}
