#ifndef ENEMY_H
#define ENEMY_H

#include <array>

#include "drawtools.h"

class Enemy {
public :
	Enemy(const PointF& begin,float speed, int health);

	PointF Move();


private :
PointF _begin;
float _speed;
int	_health;
//int _id;

};

#endif
