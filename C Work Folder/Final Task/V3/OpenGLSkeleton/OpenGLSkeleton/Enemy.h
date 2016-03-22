#ifndef ENEMY_H
#define ENEMY_H

#include <array>

#include "drawtools.h"

class Enemy {
public :
//	int increase();
	Enemy(const PointF& begin, PointF current,float speed, int health);

	void Health(int i);

	virtual PointF Move();
	int	Update(PointF current);
	PointF Value();

//protected:
//	int _id;
//
//private:
//	static int _idNumber;
public:
PointF _begin;
PointF _current;
int	_health;
int _id;

private :
	
float _speed;

//int _id;

};

#endif
