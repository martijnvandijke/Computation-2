// Name: Martyn van Dijke
// Student number: 0887668

#ifndef _LIST_H_
#define _LIST_H_

class Item; // Forward declaration

// A simple data structure that forms the core of List
struct Node
{
    Node* next;
    Node* prev;
    Item* item;
};

// This is what it's all about
// A double-linked circular list of nodes containing pointers to items.
class List
{
public:
    List();
    ~List();

    Node* head();

    void clear();

	//own functions
	
	//added void List::print() to the class
	void print();

	//added void List::push_back(Item* item) to the class
	void push_back(Item*);

	//added void List::push_front(Item* item) to the class
	void push_front(Item*);

	//added void List::remove(Node* node) to the class
	void remove(Node* node);

	//added void List::put_first(Node* node) to  the class
	void put_first(Node* node);

	int highest_id();

private:
    Node* _head;
	//int highest_id();
};

#endif // _LIST_H_ 
