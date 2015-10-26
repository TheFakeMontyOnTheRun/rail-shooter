#ifndef TURRET_H
#define TURRET_H

class Turret: public CarElement {
public:
	virtual int getResId();
	virtual void fire();
	Turret(const std::shared_ptr<CarElement::Holder>& parent, const Vec2& position);
	virtual ~Turret();
};

#endif
