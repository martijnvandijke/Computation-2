#ifndef FIREDBULLET_h
#define FIREDBULLET_H

#include "drawtools.h"

class FiredBullet {
public: FiredBullet(PointF destination, PointF begin, PointF current, int speed);

		PointF Move();
		PointF Move2();
public:
	PointF _begin;
	PointF _destination;
	PointF _current;
	int _speed;
	int _id;
};

#endif
