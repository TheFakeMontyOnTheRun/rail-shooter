#ifndef CAR_H
#define CAR_H

class Car: public CarElement::Holder, public Character::Holder {

private:
	Vec2 getPosition() const;
public:

	class Holder {
	public:
		virtual Vec2 getPosition() const = 0;
	};

	const Holder* train{nullptr};
	std::vector<CarElement*> elements;
	std::vector<Character*> occupants;
	int hull;
	int length;
	Vec2 position { 0, 0 };
	virtual void fire();
	virtual int getResId() = 0;
	virtual void update(long step,
			const std::vector<Bullet* >& bullets,
			const std::vector<Explosion*>& explosions);
	virtual Vec2 getPositionForCharacter() const override;
	virtual Vec2 getPositionForCarElement() const override;
	Car(const Holder& train, int hull, int length, const Vec2& position);
	virtual ~Car();
};
#endif
