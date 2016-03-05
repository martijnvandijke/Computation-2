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


	Node* nextNode = _head;
	do {
		Node* currentNode = nextNode;
		nextNode = currentNode->next;
		delete currentNode;
	} while (nextNode != _head);
	_head = nullptr;

}


void List::remove(Node* node) {
	cout	<< "-> Deleted item with id " 
			<< node->item->id()
			<< endl;

	Node* next = node->next;
	Node* previous = node->prev;
	node->prev->next = next;
	node->next->prev = previous;
	delete node;
	//delete node;
}

//function will put a node first
void List::put_first(Node* node) {
	//definition of the previous and next node's
	Node* next = node->next;
	Node* previous = node->prev;

	//if node is already the head exit the function
	if (node == _head) {
		return;
	}

	if (next == previous) {
		_head->prev = node;
		_head->next = node;
		_head = node;
		return;
	}


	previous->next = next;
	next->prev = previous;

	_head->prev->next = node;
	node->prev = _head->prev;
	_head->prev = node;
	node->next = _head;

	_head = node; //place the head of the list at the new beginning

	cout << "-> Moved id "
		<< node->item->id()
		<< " to the first spot of the list"
		<< endl;
}

int List::highest_id() {
	int highest_id = 0;
	Node* node = _head;
	do
	{
		if (node->item->id() > highest_id)
		{
			highest_id = node->item->id();
		}
	} while ((node = node->next) != _head);
	return highest_id;
}


void sortListById(List* list) {
	int high_id = list->highest_id();
	int store_i;
	//int i = high_id;
	//cout << "The highest id is :"
		//<< high_id << endl;

	for (int i = high_id; i > 0; i--)
	{
		//cout << " i is "
			//<< i << endl;

		// if the id of the item is not in the list
		if ((findItemById(list, i)) == nullptr)
		{
			//cout << "ik ben hiero "
				//<< i
				//<< endl;
			//contine with  the loop)
			continue;
		}

		list->put_first(findItemById(list, i));

	}

	cout << "-> Sorted the list" << endl;
}

Node* findItemById(List* list, int id) {
	//cout << list << " the id you are looking for is " <<id << endl ;
	//cout << list << endl;
	//cout << list->head() << endl;
	Node* list_needed = list->head();
	Node* store_list = list_needed;
	//cout << listh << endl;
	//cout << listhead->item->id() << endl;
	if (id > list->highest_id()) {
		cout << "That id is to large it is not even the id is in the list possible" << endl;
		return nullptr;
	}
	//if the next of listhead is not eqaul to the listhead (meaning it has not reached 1 )
	while ((list_needed->next) != list_needed) {
		//if the listhead item id is the id you are looking for
		if (list_needed->item->id() == id) {
			//cout << "I have foudnd id " << list_needed->item->id() << endl;
			// return the pointer to the head of the list
			return*&list_needed;
		}
		//increment the list head with the 
		list_needed = list_needed->next;
		//if the list is the list to begin with (meaning it has looped around and has founded nothing)
		if (list_needed == store_list) {
			cout << "That id is not possible , it must have been deleted" << endl;
			// i have found completly nothing 
			return nullptr;
		}


	}

	return nullptr;

}


// function will add new item's to the list
void List::push_back(Item* item) {
	//cout << "-> Append " << item->id() << endl;
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

//function will push a item to the front of the list
void List::push_front(Item* item) {
	cout	<< "-> Inserted item id " 
			<< item->id() 
			<< endl;
	Node* nodetoAdd = new Node();
	nodetoAdd->item = item;

	//is there are no other node's
	if (_head == nullptr) {
		nodetoAdd->next = nodetoAdd;
		nodetoAdd->prev = nodetoAdd;
		_head = nodetoAdd;
	}
	else
	{
		Node* currentNode = _head->prev;
		currentNode->next = nodetoAdd;
		_head->prev = nodetoAdd;
		nodetoAdd->next = _head;
		nodetoAdd->prev = currentNode;
		_head = nodetoAdd;
	}

}
// function will print out the list
void List::print() {
	//if there is no head
	if ( _head == nullptr) {
		cout << "-> List contains no items"<< endl;
		return;
	}
	Node* node = _head;
	//do the next function while there is no next item on the list
	do{
		//cout << node->item->id() << endl;
		//cout << "-> item id  " << endl;
		node->item->print(); //<< endl;
				//<<end1;
	} while ((node = node->next) != _head);
	//while the next node is not the head node excute this code
}

