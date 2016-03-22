#include "Bullet.h"


int Count = 0;

Bullet::Bullet(Line* bulletline)
	:_bulletline{ bulletline }
{
	Count++;
	_id = Count;
}
