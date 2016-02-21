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
	//there is nothing to clear
	if (!_head) {
		return;
	}

	Node* nextNode = _head;
	do {
		Node* currentNode = nextNode;
		nextNode = currentNode->next;
		delete currentNode;
	} while (nextNode != _head);
	_head = nullptr;

}
int List::highest_id(){
	int highestId = 0;
	Node* node = _head;
	do
	{
		if (node->item->id() > highestId)
		{
			highestId = node->item->id();
		}
	} while ((node = node->next) != _head);
	return highestId;
}


void sortListById(List* list) {
	int highestId = list->highest_id();
	//int highestid = highest_id();
	cout << highestId << endl;

	for (int i = highestId; i > 0; i--)
	{
		list->put_first(findItemById(list, i));

		//if (it._node != nullptr)
		//{
			//put_first(it);
		//}

	}


}

void List::remove(Node* node) {
	cout << "\n \n \n Going to remove a node" << endl;
	//if ( node->item->id() == nullptr	) {
		//cout << "That id is not possible" << endl;
	//}

	Node* before = node->next ;
	Node* after = node->prev ;
	node->item->print();
	before->item->print();
	after->item->print();

	if (after == before) {
		_head = nullptr;
		cout << "Nothing to delete" << endl;
		return;
	}

	//delete node;

	before->next = after;
	after->prev = before;
	
	//delete node->item;
	cout << "Ik kom tot hiero" << endl;
	int delId = node->item->id();
	cout << delId << endl;
	//node->item->id()
	//delete &delId;
	//delete node->item = nullptr;
	//delete node; 

	//remove node;
	//idcounter--;
	//delete node;
}

void List::put_first(Node* node) {

	Node* before = node->prev;
	Node* after = node->next;

	// node is at the head of the list
	if ( node == _head)
	{
		return;
	}

	if (before == after)
	{
		_head->prev = node;
		_head->next = node;
		_head = node;
		return;
	}

	before->next = after;
	after->prev = before;

	_head->prev->next = node;
	node->prev = _head->prev;
	_head->prev = node;
	node->next = _head;

	_head = node;

	cout	<< "Node with id " 
			<< node->item->id() 
			<< " has been put in the front" 
			<< endl;
}

Node* findItemById(List* list, int id) {
	cout << list << " test " <<id << endl ;

	//cout << list->head() << endl;
	Node* listhead = list->head();

	//list->print();
	//listhead->
	//Node* node = listhead;
	
	cout << listhead << endl;
	cout << listhead->item->id() << endl;

	while ((listhead->next) != listhead)
	{
		nextlist:
		if (listhead->item->id() == id) {
			int returnid = listhead->item->id();
			cout << "Founded the item" << endl;
			//listhead = listhead->next;
			return* &listhead;
		}

		//if (listhead->next->item->id() == id) {
		//	int returnid = listhead->item->id();
		//	cout << "Founded the item 2" << endl;
		//	listhead = listhead->next;
		//	return* &listhead;

		//}

		else
		{
			listhead = listhead->next;
			goto nextlist;
			cout << "Nothing Found" << endl;
			return nullptr;
		}
		//listhead = listhead->next;

	} 
	if((listhead->next) == listhead)
	{
		cout << "Nothing Found for real" << endl;
		return nullptr;
	}
	//while ( (listhead->next) != listhead );




	//do {
	//	if(	listhead->item->id() == id) {
	//		int returnid = listhead->item->id();
	//		cout << "Founded the item" << endl;
	//		return*  &listhead ;
	//}
	//	if (listhead->next->item->id() == id) {

	//		int returnid = listhead->item->id();
	//		cout << "Founded the item 2" << endl;
	//		return*&listhead;

	//	}

	//	else {
	//		//item is not in the list
	//		cout << "Nothing is found" << endl;
	//		return nullptr;
	//}
	//	
	//} while( (listhead = listhead->next ) != listhead );

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