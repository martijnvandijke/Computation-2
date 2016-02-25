#include <iostream>
#include "person.h"
#include <sstream>

using namespace std;

Person::Person(string name)
{
	_name = name;
}

Person::~Person()
{

}

void Person::print()
{
	cout << " '" << _name << "' (id " << _id << ")" << endl;
}