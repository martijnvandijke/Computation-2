// Name: Martyn van Dijke
// Student number: 0887668

#ifndef _ITEM_H_
#define _ITEM_H_

#include "list.h"

Node* findItemById(List* list, int id); // To be implemented
void sortListById(List* list);          // To be implemented

class Item
{
public:
    Item();
    virtual ~Item();

    int id();

    virtual void print();

protected:
    int _id;

private:
	static int _idNumber;

};

#endif // _ITEM_H_ 
