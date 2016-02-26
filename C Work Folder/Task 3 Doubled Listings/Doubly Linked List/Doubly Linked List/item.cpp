// Name: Martyn van Dijke
// Student number: 0887668
#include <iostream>
#include "item.h"

using namespace std;

Item::Item()
{ 
	_idNumber++;
	_id = _idNumber;
	//= _idcounter;
	//_id++;
}

Item::~Item()
{ }

int Item::id()
{
    return _id;
}

int Item::_idNumber = 0;

void Item::print()
{ 
	cout	<< " id of the item is : "
			<< _id 
			<< endl;

}

