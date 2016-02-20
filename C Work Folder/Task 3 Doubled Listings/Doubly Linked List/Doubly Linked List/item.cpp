// Name: Martyn van Dijke
// Student number: 0887668
#include <iostream>
#include "item.h"

using namespace std;

Item::Item()
{ 
	_idcounter++;
	_id = _idcounter;
	//_id++;
}

Item::~Item()
{ }

int Item::id()
{
    return _id;
}

int Item::_idcounter = 0;

void Item::print()
{ 
	cout	<< " id of the item is : "
			<< _id 
			<< endl;

}

