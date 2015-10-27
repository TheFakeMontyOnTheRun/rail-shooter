#include <vector>
#include <memory>
#include "Vec2.h"
#include "Explosion.h"
#include "Bullet.h"
#include "Area.h"
#include "CarElement.h"

CarElement::CarElement(const CarElement::Holder& aParent, int aHull,
		int aLength, const Vec2& aRelativePosition, const Area& aHitArea) :
		hit(false), parent(&aParent), hull(aHull), length(aLength), position(
				aRelativePosition), hitArea(aHitArea) {
}

void CarElement::update(long step,
		const std::vector<Bullet* >& bullets,
		const std::vector<Explosion*>& explosions) {

	if (hull <= 0) {
		return;
	}

	Vec2 parentPosition = parent->getPositionForCarElement();

	hitArea.pos.x = parentPosition.x + position.x;
	hitArea.pos.y = parentPosition.y + position.y;

	for (auto& bullet : bullets) {
		if (bullet->isValid() && hitArea.contains(bullet->position)) {
			bullet->hit();
			const Vec2 pos = bullet->position;
			auto explosion = new Explosion(150, pos);
			::explosions.push_back(explosion);
			--hull;
		}
	}
}

void CarElement::fire() {
}

CarElement::~CarElement() {
}