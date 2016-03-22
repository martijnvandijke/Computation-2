#include "Enemy.h"
#include <iostream>


using namespace std;

//int Enemy::increase()
//{
//	_idNumber++;
//	_id = _idNumber;
//	return _id;
//}
int Count = 1;
Enemy::Enemy(const PointF& begin,PointF current ,float speed, int health)
	: _begin{begin},
	_current{current},
	_health{health},
	_speed { speed}
{
	Count++;
	_id = Count;
}

PointF Enemy::Value() {
	return  _begin;
}

PointF Enemy::Move()
{


	cout << "moving the enemy" << endl;
	//PointF speed2 = { (_begin[0] + 50) , (_begin[1] + 50)};
	PointF speed2 = { (_current[0] + _speed) , (_current[1] + _speed) };
	return  speed2;
}

int Enemy::Update(PointF current) {
	_current = current;

	return 0;
}