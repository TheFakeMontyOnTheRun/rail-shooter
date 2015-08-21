#ifndef TRAIN_H
#define TRAIN_H

class Car {
public:

	int hull;
	int length;
	bool hit;
	int position;
};

class Train {
public:
	int speed;
	int position;
	int length;
	std::vector<Car> cars;
};

#endif
