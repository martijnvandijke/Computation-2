#include "Turret.h"

Turret::Turret(PointF position,Color color ,int range, int health, int upgrade, int type)
	: _position{ position },
	_range{ range },
	_health{ health },
	_color{color},
	_upgrade{ upgrade },
	_type{type}
{
	//define bullet speeds for the turret
	if (_type == 0) {
		_bulletSpeed = 20;
	}
}

int Turret::Aim(int i)
{
	//if it is a machine gun
	if (_type == 0) {
		//if set bit is 1 and it is not aiming 
		if (i == 1 && _aiming == 0) {
			_aiming = 1;
			//return 1;
		}
		//else
		//{
		//	return 0;
		//}
	}


	return 0;

}

PointF Turret::Position() {
	return _position;
}
