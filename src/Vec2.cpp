#include "Vec2.h"

void Vec2::operator+=(const Vec2& other) {
	x += other.x;
	y += other.y;
}

Vec2::Vec2(const Vec2& other) :
		x(other.x), y(other.y) {
}

Vec2::Vec2(int aX, int aY) :
		x(aX), y(aY) {
}
