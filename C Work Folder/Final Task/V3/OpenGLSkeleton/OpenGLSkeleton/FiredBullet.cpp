#include "FiredBullet.h"
#include <iostream>
#include <string>

//Bullet file

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
	//_current = { _begin[0], _begin[1]	};
	cout << "Made a bullet in the Bullet class:" << endl;
	cout << "begin x:"<< _begin[0] << " begin y:" << _begin[1] << " destination x:" << _destination[0] << "   destination y:" << _destination[1] << endl;
}

FiredBullet::~FiredBullet()
{
	
	//delete FiredBullet;

}

//update the poistion of the bullet
PointF FiredBullet::Move()
{
	float dx = _current[0] - _destination[0];
	float dy = _current[1] - _destination[1];
	// if the x position is to the right
	if (dx > 0) {
		if (dy > 0) {
			PointF speed = { (_begin[0] - _speed)	, (_begin[1] - _speed) };
			cout << speed[0] << " : :::" << speed[1] << endl;
			return speed;
		}
		else {
			PointF speed = { (_begin[0] - _speed)	, (_begin[1] + _speed) };
			cout << speed[0] << " : :::" << speed[1] << endl;
			return speed;
		}
	}
	// if x poistion is to the left
	else {
		if (dy > 0) {
			PointF speed = { (_begin[0] + _speed)	, (_begin[1] - _speed) };
			cout << speed[0] << " : :::" << speed[1] << endl;
			return speed;
		}
		else {
			PointF speed = { (_begin[0] + _speed)	, (_begin[1] + _speed) };
			cout << speed[0] << " : :::" << speed[1] << endl;
			return speed;
		}
	}
}


void FiredBullet::Update(PointF begin) {
	_begin = begin;
}

void FiredBullet::Update2(PointF current) {
	_current = current;
}


PointF FiredBullet::Move2() {
	PointF _current = { (_current[0] ), (_current[1] +_speed) };

	return _current;
}