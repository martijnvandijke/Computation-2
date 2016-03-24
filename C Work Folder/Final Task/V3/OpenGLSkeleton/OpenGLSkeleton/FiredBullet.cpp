#include "FiredBullet.h"
#include <iostream>
#include <string>

using namespace std;
int Count2 = 0;
//desitnation pointF m begin PointF and speed
FiredBullet::FiredBullet(PointF destination, PointF begin, PointF current, int speed)
	: _begin{begin},
	_current{current},
	_destination{destination},
	_speed{speed}
{
	Count2++;
	_id = Count2;
	cout << " made a bullet" << endl;
	cout << _begin[0] << " " << _begin[1] << " destination :" << _destination[0] << "   : " << _destination[1] << endl;
}

PointF FiredBullet::Move()
{
	PointF speed = { (_begin[0] + _speed)	, ( _begin[1])	 };
	cout << speed[0] << " : :::" << speed[1] << endl;
	return speed;
}

void FiredBullet::Update(PointF begin) {
	_begin = begin;
}

void FiredBullet::Update2(PointF current) {
	_current = current;
}


PointF FiredBullet::Move2() {
	PointF _current = { (_current[0] + _speed), _current[1]  };

	return _current;
}