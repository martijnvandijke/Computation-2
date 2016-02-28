// Name: Martyn van Dijke
// Student number: 0887668

#include <iostream>
#include <string>

#include "list.h"
#include "item.h"
#include "Person.h"

using namespace std;

char get_command()
{
    char c;
    cout << "Type command: ";
    cin >> c;
    return c;
}

void main()
{
    // Define your my_list here

	List* my_list = new List();
	//int id = 1;
	int input;
	string string_input;
    cout << "-------- Ring-style linked list base class by Martyn van Dijke. --------" << endl;
	cout << "Command [Add(a)|Insert(i)|Delete(d)|First(f)|Print(p)|Sort(s)|Destroy(x)|Find(t)|Quit(q)] \n \n" ;

    char command;
    while ((command = get_command()) != 'q') {
        switch (command) {
        case 'a': // append
			cout << "-> Type character name: ";
			cin >> string_input;
			my_list->push_back(new Person( string_input) );

            // Add your code here
            break;
        case 'i': // insert
			cout << "-> Type character name: " << endl;
			cin >> string_input;
			my_list->push_front(new Person( string_input) );
            break;
		case 't':
			cout << "Please input the string of the item you want to find :" << endl;
			cin >> input;
			findItemById(my_list,input);
			break;
        case 'd': // delete
			cout << "Please input the id of the item :" << endl;
			cin >> input;
			findItemById(my_list, input);
			my_list->remove(findItemById(my_list, input));
            break;
        case 'f': // put first
			cout << "Please input the id of the item :" << endl;
			cin >> input;
			my_list->put_first(findItemById(my_list, input));
            break;
        case 'p': // print
			my_list->print();
            break;
        case 's': // sort
			sortListById( my_list );
            break;
        case 'x': // destroy list
            break;
        case 'q':
            break;
        default:
            cout << "Command unknown!" << endl;
            break;
        }
    }

    cout << "Bye bye!" << endl;
}
