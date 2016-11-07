#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.front() << endl; //1
	a.pop(); //delete 1
	cout << a.size() << endl; //2
	return 0;
}