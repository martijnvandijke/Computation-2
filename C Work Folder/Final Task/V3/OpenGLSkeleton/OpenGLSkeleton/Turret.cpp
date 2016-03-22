#include "Turret.h"

Turret::Turret(PointF position,Color color ,int range, int health, int upgrade, int type)
	: _position{ position },
	_range{ range },
	_health{ health },
	_color{color},
	_upgrade{ upgrade },
	_type{type}
{

}

int Turret::Aim()
{
	//if it is a machine gun
	if (_type == 0) {
		

	}


	return 0;

}

PointF Turret::Position() {
	return _position;
}