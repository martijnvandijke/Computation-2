// Name: Martyn van Dijke
// Student number: 0887668
#include <iostream>
#include "item.h"

using namespace std;

Item::Item()
{ 
	_idNumber++;
	_id = _idNumber;
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

	cout	<< "-> item id : "
			<< _id 
			<< endl;

}

