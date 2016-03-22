#ifndef TURRET_H
#define TURRET_H

#include <array>

#include "drawtools.h"

class Turret {

public: Turret(PointF position,Color color , int range, int health, int upgrade, int type);

	int	Aim();

	PointF Position();

public:
	PointF _position;
private:
	Color _color;
	int _range;
	int _health;
	int _upgrade;
	int _type;

};


#endif
