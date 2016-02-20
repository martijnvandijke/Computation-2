// Name: Martyn van Dijke
// Student number: 0887668

#include <iostream>

#include "list.h"
#include "item.h"
#include <time.h>

using namespace std;

List::List()
    : _head(nullptr)
{ }

List::~List()
{
    clear();
}

Node* List::head()
{
    return _head;
}

void List::clear()
{
    // To be implemented
}

// function will add new item's to the list
void List::push_back(Item* item) {
	Node* nodetoadd = new Node();
	nodetoadd->item = item;

	if (_head == nullptr) {
		nodetoadd->next = nodetoadd;
		nodetoadd->prev = nodetoadd;
		_head = nodetoadd;
	}
	else 
	{
		Node* currentNode =	_head->prev;
		currentNode->next = nodetoadd;
		nodetoadd->prev = currentNode;
		nodetoadd->next = _head;
		_head->prev = nodetoadd;
	}
}

//function will
void List::push_front(Item* item) {
	Node* nodetoadd = new Node();
	nodetoadd->item = item;

	if (_head == nullptr) {
		nodetoadd->next = nodetoadd;
		nodetoadd->prev = nodetoadd;
		_head = nodetoadd;
	}
	else
	{
		Node* currentNode = _head->prev;
		currentNode->next = nodetoadd;
		nodetoadd->prev = currentNode;
		nodetoadd->next = _head;
		_head->prev = nodetoadd;
	}

}

void List::print() {
	if (_head == nullptr) {
		cout << "There is nothing to print"<< endl;
		return;
	}
	int order = 0;
	Node* node = _head;
	//if there is a next item on the list
	do {
		order++;
		cout	<< "Printing the order of the List : "
				<< order ;
		node->item->print(); //<< endl;
				//<<end1;
	} while ((node = node->next) != _head);

}