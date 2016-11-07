#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> a = { 1,2,3,4,5 };
	vector<int> b(a.begin(), a.end()); //a 카피
	vector<int> c(5, 1); // size=5, c[i]=1
	vector<int> d(5); //size=5 d[i]=???
	vector<int>::iterator it = a.begin();
	for (int i = 0; i < a.size(); ++i)cout << b[i] << ' ';
	cout << endl;
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)cout << *it << ' ';
	cout << endl;
	a.insert(it+3, -1); //a[3]=-1;
	for (int i = 0; i < a.size(); ++i)cout << a[i] << ' ';
	cout << endl;
	a.erase(a.begin() + 3); //delete a[3]
	for (int i = 0; i < a.size(); ++i)cout << a[i] << ' ';
	cout << endl;
	a.clear(); // make empty
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.

}