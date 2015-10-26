#ifndef VEC2_H
#define VEC2_H

class Vec2 {

public:
	int x;
	int y;

	void operator+=(const Vec2& other);

	Vec2(const Vec2& other);
	Vec2(int x, int y);
};
#endif
