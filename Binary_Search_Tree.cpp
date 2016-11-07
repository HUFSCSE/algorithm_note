#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	//Binary Search Tree
	//STL set ���
	//https://www.acmicpc.net/problem/7785
	int n;
	cin >> n;
	set<string> s;
	while (n--) {
		string name, what;
		cin >> name >> what;
		if (what == "enter") {
			s.insert(name);
		}
		else {
			s.erase(s.find(name));
		}
	}
	//����
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << '\n';
	}
	return 0;
}