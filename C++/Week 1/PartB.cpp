#define _CRT_SECURE_NO_WARNINGS

/*
* File: p6.c
* Student: Martyn van Dijke
* Student id: 0887668
*/

#include <iostream>

using namespace std;
char* months[] = { "January", "February" , "March","April","May", "June","July","August","September","October" , "November", "December" };

void reverse_string_array(char* months[], int size) {
	//std::reverse(str, &str[strlen(str)]);
	char* temp;
	for (int i = 0; i < (size / 2); i++) {
		temp = months[i];
		months[i] = months[size - i - 1];
		months[size - i - 1] = temp;

	}


}

int get_value(int* num) {
	return *num;

}

double fourth(int x) {
	double out = x*x*x*x;
	return out;

}

void main(void)
{

	int i = 5; // (2) integer variable i, set to 5
	int* ip = &i;
	int** ipp = &ip;

	char* ber_string = &months[8][6];

	// Reverse the order of the words in string array months
	reverse_string_array(months, 12);
	cout << months[3] << "," << months[2]<< "," << months[1] << " and " << months[0] << " are the months \nthe year that end with " << ber_string << endl;
	cout << "Fourth(" << **ipp << ") " << fourth(get_value(*ipp))  << endl;
	

}