#include "Enemy.h"
#include <iostream>


using namespace std;

Enemy::Enemy(const PointF& begin,float speed, int health)
	: _begin{begin},
	_health{health},
	_speed { speed}
{

}

PointF Enemy::Move()
{
	PointF speed = { _speed, 10 };
	return  speed;
}
