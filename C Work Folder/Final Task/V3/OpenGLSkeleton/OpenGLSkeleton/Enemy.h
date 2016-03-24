#ifndef ENEMY_H
#define ENEMY_H
//Enemy header file

#include <array>

#include "drawtools.h"

class Enemy {
public :
//	int increase();
	Enemy(const PointF& begin, PointF current,float speed, int health);

	void Health(int i);

	virtual PointF Move(int i, int j);
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
float _speed;

private :
	


//int _id;

PointF Move();

};

#endif
