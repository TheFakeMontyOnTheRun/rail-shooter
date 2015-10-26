#include <memory>
#include <vector>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"
#include "Character.h"
#include "Car.h"
#include "Video.h"
#include "Train.h"
#include "HeroTrain.h"
#include "VillainTrain.h"
#include "RailShooter.h"
#include "Turret.h"

const int HULL = 10;
const int SIZE = 10;

Turret::Turret(std::shared_ptr<CarElement::Holder> parent, Vec2 aPosition) :
		CarElement(parent, HULL, SIZE, aPosition,
				Area(Vec2(0, 0), Vec2(55, 55))) {
}

int Turret::getResId() {
	return Image::TURRET;
}

void Turret::fire() {
	Vec2 pos = parent->getPositionForCarElement();
	pos += Vec2(position.x, 0);

	fireBullet(pos.x, pos.y + 5, 0, 5);
}
