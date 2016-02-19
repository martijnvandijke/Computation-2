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

private:
    Node* _head;
};

#endif // _LIST_H_ 
