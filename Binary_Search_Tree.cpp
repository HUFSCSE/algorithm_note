#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	//Binary Search Tree
	//STL set 사용
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
	//역순
	for (auto it = s.rbegin(); it != s.rend(); it++) {
		cout << *it << '\n';
	}
	return 0;
}