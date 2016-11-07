#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<string.h>
#include<iostream>

using namespace std;
int main() {
	char *a = "xyzzy";
	string b = "shift";
	int c = 999;
	char *d = "1234";
	string e = to_string(7654); //integer to string
	string f = "hufs";

	cout << e << endl;
	cout << string(a) << endl; //char to string
	cout << b.c_str() << endl; //string to char
	cout << atoi(a) << endl; //char to integer;
	cout << stoi("9999") << endl; //string to integer
	cout << b+f << endl; // string + operation
	cout <<b[0]<<' '<< b.at(0) << endl;// b[0]==b.at(0)
	cout << strstr(d, "23") << endl; //index of 2, 못찾으면 NULL
	cout << b.substr(0, 3) << endl; //index, size
	cout << b.substr(3) << endl; //index~
	cout << b.size() << endl; //string length
	cout << b.find("ift") << endl; //index of 'i',못찾으면 쓰레기값
	
	return 0;
}