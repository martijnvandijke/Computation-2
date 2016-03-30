#include "Turret.h"

//Turret file

Turret::Turret(PointF position,Color color ,int range, int health, int upgrade, int type,int time)
	: _position{ position },
	_range{ range },
	_health{ health },
	_color{color},
	_upgrade{ upgrade },
	_type{type},
	_lastTime{time}
{
	//define bullet speeds for the turret
	if (_type == 0) {
		_bulletSpeed = 3;
	}
}
void Turret::TimeUpdate(int CurTime) {
	_lastTime = CurTime;

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

	}


	return 0;

}

PointF Turret::Position() {
	return _position;
}
