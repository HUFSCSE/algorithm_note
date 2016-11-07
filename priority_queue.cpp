#include<iostream>
#include<queue>

using namespace std;

int main() {
	priority_queue<int> a;
	priority_queue<pair<int, int> > b;
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.top() << endl; // 3
	a.pop(); //delete 3
	cout << a.size() << endl; //2
	b.push(make_pair(0, 0));
	b.push(make_pair(1, -1));
	b.push(make_pair(2, 9999));
	b.push(make_pair(3, 2));
	cout << b.top().first << ' ' << b.top().second << endl; //3 2 first값으로 정렬됨
	return 0;

}