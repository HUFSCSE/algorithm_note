#include<iostream>
#include<map>
using namespace std;
int main() {
	map<int, int> a;
	a.insert(make_pair(1, 2)); //key,value ... key값 순으로 오름차순
	a.insert(make_pair(2, 2));
	a.insert(make_pair(2,5));//영향 x
	a[9] = 3; // ==insert
	for (auto it = a.begin(); it != a.end(); it++)cout << (*it).first << ' ' << it->second << endl;
	cout <<a[6]<<a.at(9)<<endl;
	a.erase(9);
	a[6] = a[2];
	for (auto it = a.begin(); it != a.end(); it++)cout << (*it).first << ' ' << it->second << endl;
	cout << a.find(6)->second;
	a.clear();

	return 0;
	

}