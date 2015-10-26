#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "CoveredZBorCar.h"
#include "Video.h"

const int HULL = 50;
const int LENGTH = 30;

CoveredZBorCar::CoveredZBorCar(std::shared_ptr<Car::Holder> aTrain,
		Vec2 aPosition) :
		Car(aTrain, HULL, LENGTH, aPosition) {
}

int CoveredZBorCar::getResId() {
	return Image::ZBOR2;
}
