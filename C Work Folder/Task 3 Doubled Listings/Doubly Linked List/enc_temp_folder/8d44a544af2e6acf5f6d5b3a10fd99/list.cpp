// Name: Martyn van Dijke
// Student number: 0887668

#include <iostream>

#include "list.h"
#include "item.h"


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
    
}

void sortListById(List* list) {

}

void List::remove(Node* node) {
	
	//if ( (node->item->id()) == nullptr) {
		//cout << "That id is not possible" << endl;
	//}

	node = node->next ;
	node = node->prev ;
	node->item->print();
}

void List::put_first(Node* node) {

}

Node* findItemById(List* list, int id) {
	cout << list << " test " <<id << endl ;

	//cout << list->head() << endl;
	Node* listhead = list->head();
	//listhead->
	//Node* node = listhead;
	cout << listhead << endl;
	cout << listhead->item->id() << endl;
	do {
		if(listhead->item->id() == id) {
			int returnid = listhead->item->id();
			cout << "Founded the item" << endl;
			return  listhead ;
	}
		else {
			//item is not in the list
			cout << "Nothing is found" << endl;
			return nullptr;
	}

	} while( (listhead = listhead->next) != listhead);

	//return 0;
}



//Node* findItemById(List* list, int id) {
	
	//if ( _head == nullptr) {
		//return nullptr;
	//}

	//Node* node = list->head;
	//do the next function while there is no next item on the list
	//do {

		//if (node->item->id() == id) {
			//int returnid = &id();
			//cout << "Founded the item" << endl;
			//return ; 
		//}
		//else {
			//item is not in the list
			//return nullptr;
		//}
		
	//} while ((node = node->next) != _head);
	
//}



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
	//do the nxt function while there is no next item on the list
	do{
		order++;
		cout	<< "Printing the order of the List : "
				<< order ;
		node->item->print(); //<< endl;
				//<<end1;
	} while ((node = node->next) != _head);

}