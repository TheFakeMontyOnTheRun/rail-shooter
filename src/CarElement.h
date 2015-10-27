#ifndef CARELEMENT_H
#define CARELEMENT_H

class CarElement {
private:
	bool hit;
public:

	class Holder {
	public:
		virtual Vec2 getPositionForCarElement() const = 0;
	};

	const Holder* parent{nullptr};
	int hull;
	int length;
	Vec2 position { 0, 0 };
	Area hitArea;

	virtual int getResId() = 0;
	virtual void fire();
	virtual void update(long step,
			const std::vector<Bullet*>& bullets,
			const std::vector<Explosion*>& explosions);

	CarElement(const CarElement::Holder& parent, int hull, int length,
			const Vec2& relativePosition, const Area& hitArea);
			
	virtual ~CarElement();
};
#endif
