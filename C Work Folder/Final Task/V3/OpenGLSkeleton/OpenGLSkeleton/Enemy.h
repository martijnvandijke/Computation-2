#ifndef ENEMY_H
#define ENEMY_H

#include <array>

#include "drawtools.h"

class Enemy {
public :
//	int increase();
	Enemy(const PointF& begin,float speed, int health);

	virtual PointF Move();
	PointF Value();

//protected:
//	int _id;
//
//private:
//	static int _idNumber;
public:
PointF _begin;
private :
float _speed;
int	_health;
//int _id;

};

#endif
