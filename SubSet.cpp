#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[20];
int main() {
	//�κ� ���� ���ϱ�
	//��Ʈ �÷��׷� �����ϰ� ���� �� �ִ�.
	//https://www.acmicpc.net/problem/1182
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int count = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int t = 0; t < n; t++) {
			if (i&(1 << t)) {
				sum += a[t];
			}
		}
		if (sum == s)
			count++;
	}
	cout << count << endl;
	return 0;
}