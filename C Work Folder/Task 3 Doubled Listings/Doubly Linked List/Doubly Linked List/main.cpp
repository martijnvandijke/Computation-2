// Name: Martyn van Dijke
// Student number: 0887668

#include <iostream>

#include "list.h"
#include "item.h"

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

    cout << "-------- Ring-style linked list base class by Martyn van Dijke. --------" << endl << endl;

    char command;
    while ((command = get_command()) != 'q') {
        switch (command) {
        case 'a': // append
            // Add your code here
            break;
        case 'i': // insert
            break;
        case 'd': // delete
            break;
        case 'f': // put first
            break;
        case 'p': // print
            break;
        case 's': // sort
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
