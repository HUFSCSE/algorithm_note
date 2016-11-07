#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��������
bool cmp(int a,int b) {
	if (a > b)return true;
	return false;
}

int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> b = { 10,9,8,7,6,5,4,3,2,1 };
	vector<int> c = { 1,3,5 };

	if (binary_search(a, a + 10, 5))cout << "5 ����" << endl; //����Ž������ ���� ã���� true ��ȯ
	sort(b.begin(), b.end()); //�⺻������ ��������, ����Ʈ ������
	if (!binary_search(b.begin(), b.end(), 11))cout << "11 ���� X" << endl;
	cout << *lower_bound(b.begin(), b.end(), 5) << endl; //5���� ���ų� ū ��
	cout << *upper_bound(b.begin(), b.end(), 5) << endl; //5���� ū ��
	if (lower_bound(b.begin(), b.end(), 11) == b.end())cout << "���� X" << endl; //�������� ������, return end()
	cout << *lower_bound(a, a + 10, 5) << endl;
	sort(b.begin(), b.end(), cmp); //��������
	for (int i = 0; i < 10; i++)cout << b[i] << ' ';
	cout << endl;
	for (vector<int>::iterator it = b.begin(); it != b.end(); it++)cout << *it << ' ';//iterator�� �̿��� ����
	cout << endl;
	random_shuffle(b.begin(), b.end());
	nth_element(b.begin(), b.begin() + 5, b.end()); //�迭�� ó������ n��°������ �����Ͽ� �� ã��
	cout << b[5] << endl; //
	//���� ���� ���� ����
	do {
		cout << c[0] << ' ' << c[1] << ' ' << c[2] << endl;
	} while (next_permutation(c.begin(), c.end()));
	for (int i = 0; i < b.size(); ++i)cout << b[i] << ' ';
	cout << endl;
	reverse(b.begin(), b.end()); //����
	for (int i = 0; i < b.size(); ++i)cout << b[i] << ' ';
	cout << endl;
	cout << find(b.begin(), b.end(), 5)-b.begin() << endl; //5�� �ε��� ��ȯ

	return 0;
}
