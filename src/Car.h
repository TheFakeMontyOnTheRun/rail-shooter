#ifndef CAR_H
#define CAR_H

class Car : public CarElement::ICarElementHolder, public Character::ICharacterHolder {
private:
	Vec2 getPosition();
public:

	class ICarHolder {
	public:
		virtual Vec2 getPosition() = 0;
	};

	std::shared_ptr<ICarHolder> train;
  std::vector<std::shared_ptr<CarElement>> elements;
  std::vector<std::shared_ptr<Character>> occupants;
  int hull;
  int length;
  Vec2 position{ 0, 0 };
  virtual void fire();
  virtual int getResId() = 0;
  virtual void update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions );
  virtual Vec2 getPositionForCharacter() override;
  virtual Vec2 getPositionForCarElement() override;
  Car( std::shared_ptr<ICarHolder> train, int hull, int length, Vec2 position );
};
#endif
