
// void remove( ){
//if ( node->item->id() == nullptr	) {
//cout << "That id is not possible" << endl;
//}

//Node* before = node->next ;
//Node* after = node->prev ;
//node->item->print();
//before->item->print();
//after->item->print();

//if (after == before) {
//	_head = nullptr;
//	cout << "Nothing to delete" << endl;
//	return;
//}

////delete node;

//before->next = after;
//after->prev = before;
//
////delete node->item;
//cout << "Ik kom tot hiero" << endl;
//int delId = node->item->id();
//cout << delId << endl;
//node->item->id()
//delete &delId;
//delete node->item = nullptr;
//delete node; 

//remove node;
//idcounter--;
//delete node;}




//list->print();
//listhead->
//Node* node = listhead;

//cout << listhead << endl;
//cout << listhead->item->id() << endl;

//while ((listhead->next) != listhead)
//{
//	nextlist:
//	if (listhead->item->id() == id) {
//		int returnid = listhead->item->id();
//		cout << "Founded the item" << endl;
//		//listhead = listhead->next;
//		return* &listhead;


//	}

//	//if (listhead->next->item->id() == id) {
//	//	int returnid = listhead->item->id();
//	//	cout << "Founded the item 2" << endl;
//	//	listhead = listhead->next;
//	//	return* &listhead;

//	//}

//	//hiero klopt de logica niet 
//	else
//	{
//		listhead = listhead->next;
//		if(	listhead->prev->item->id() != id	)
//			{
//				cout << "Nothing Found for real" << endl;
//				return nullptr;
//			}
//		
//		goto nextlist;
//		//cout << "Nothing Found" << endl;
//		//return nullptr;
//	}
//	//listhead = listhead->next;

//} 

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