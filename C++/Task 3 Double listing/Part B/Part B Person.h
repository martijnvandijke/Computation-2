#ifndef _PERSON_H_
#define _PERSON_H_

#include "list.h"
#include "item.h"

class Person : public Item
{
public:
	Person(std::string name);
	virtual ~Person();
	virtual void print();

private:
	std::string _name;
};

#endif