#ifndef BULLET_H
#define BULLET_H

class Bullet {
	bool valid { true };
public:
	Vec2 position;
	Vec2 speed;

	bool isValid();
	void hit();

	void update(long step);
	Bullet(const Vec2& position, const Vec2& speed);
};
#endif
