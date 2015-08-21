#ifndef TRAIN_H
#define TRAIN_H

typedef struct {
	int hull;
	int length;
	int hit;
	int position;
} Car;

typedef struct {
	int speed;
	int position;
	int length;
	std::vector<Car> cars;
} Train;

#endif
