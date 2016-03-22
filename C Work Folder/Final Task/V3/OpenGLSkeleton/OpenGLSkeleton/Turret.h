#ifndef TURRET_H
#define TURRET_H

#include <array>

#include "drawtools.h"

class Turret {

public: Turret(PointF position,Color color , int range, int health, int upgrade, int type);

	int	Aim(int i);

	PointF Position();

public:
	PointF _position;
	int _upgrade;
	int _type;
	int _range;
	int _health;
	int _bulletSpeed;
	int _aiming = 0;
private:
	Color _color;
	
	

};



#endif
