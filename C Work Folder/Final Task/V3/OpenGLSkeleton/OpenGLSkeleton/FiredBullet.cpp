#include "FiredBullet.h"

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
}

PointF FiredBullet::Move()
{
	PointF _begin = { (_begin[0] + 30)	, ( _begin[1] + 30)	 };

	return _begin;
}

PointF FiredBullet::Move2() {
	PointF _current = { _current[0] + 40, _current[1] + 40 };
	return _current;
}