#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> a; //����Ž��Ʈ���� ������
	a.insert(1);
	a.insert(2); //O(logn)
	a.insert(3);
	a.insert(3); //������ ������ �� ������ ��ȭ����
	for (set<int>::iterator it = a.begin(); it != a.end(); it++)cout << *it << ' '; //������������ ���ĵ�
	cout << endl;
	a.erase(3);//O(logn)
	for (set<int>::iterator it = a.begin(); it != a.end(); ++it)cout << *it << ' ';
	cout << endl;
	cout << *a.lower_bound(2) << endl;
	cout << *a.upper_bound(1) << endl;
	

	multiset<int>b = { 1,1,1,2 };
	for (auto it = b.begin(); it != b.end(); ++it)cout << *it << ' ';
	return 0;
}