#ifndef BULLET_H
#define BULLET_H

#include <array>

#include "drawtools.h"


class Bullet
{
public: Bullet(Line* bulletline);

public:
	int _id;
	Line* _bulletline;
};

#endif