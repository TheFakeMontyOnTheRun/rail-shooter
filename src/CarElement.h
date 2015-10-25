#ifndef CARELEMENT_H
#define CARELEMENT_H

class CarElement {
 public:

	class ICarElementHolder {
	public:
		virtual Vec2 getPositionForCarElement() = 0;
	};

	Area hitArea;
  int hull;
  int length;
  bool hit;
  Vec2 position{ 0, 0 };
  std::shared_ptr<ICarElementHolder> parent;
  virtual int getResId() = 0;
  virtual void fire();
  virtual void update( long step, const std::vector< std::shared_ptr<Bullet> >& bullets, const std::vector< std::shared_ptr<Explosion>>& explosions );
  CarElement( std::shared_ptr<CarElement::ICarElementHolder> parent, int hull, int length, Vec2 relativePosition, const Area& hitArea );
};
#endif
