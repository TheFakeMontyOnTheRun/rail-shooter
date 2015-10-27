#ifndef EXPLOSION_H
#define EXPLOSION_H

class Explosion {
public:

	long timeToExpire;
	Vec2 position;
	void update(long ms);
	bool isValid();
	Explosion(long timeToExpire, const Vec2& position);
};
//ugly hack
extern std::vector<Explosion* > explosions;
#endif
