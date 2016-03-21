#include "Enemy.h"
#include <iostream>


using namespace std;

//int Enemy::increase()
//{
//	_idNumber++;
//	_id = _idNumber;
//	return _id;
//}

Enemy::Enemy(const PointF& begin,float speed, int health)
	: _begin{begin},
	_health{health},
	_speed { speed}
{

}

PointF Enemy::Value() {
	return  _begin;
}

PointF Enemy::Move()
{
	cout << "moving the enemy" << endl;
	//PointF speed2 = { (_begin[0] + 50) , (_begin[1] + 50)};
	_begin = { (_begin[0] + 50) , (_begin[1] + 50) };
	return  _begin;
}
