#define _CRT_SECURE_NO_WARNINGS

/*
* File: p6.c
* Student: Martyn van Dijke
* Student id: 0887668
*/

#include <iostream>
#include <string>

using namespace std;


void main(void)
{
	std:: string input1, input2; 
	cout	<< "Welcome to Part C \n"
			<< "This program will ask you to input two stings \n" 
			<< "Enter the first word:"
			<< endl;
	cin >> input1;
	cout	<< "Enter the second word:" << endl;
	cin >> input2;

	if (input1 == input2) {
		cout	<<input1
				<<" and "
				<< input2
				<< " are eqaul."
				<< endl;
	}

	else {
		cout << "Concatenated: "
			<< input1 + input2
			<< " or "
			<< input2 +input1
			<< endl;
	}

}