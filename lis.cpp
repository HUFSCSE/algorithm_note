#include <iostream>
#include<string.h> //memset
#include<algorithm>

using namespace std;

int a[40001];
int n;
int dp[4001];
//���� 1965��
//lis O(n^2)�˰���
// lis[i]=a[i]���� �����ϴ� �ִ� �������� ũ��
int lis(int index) {
	//if (index == n - 1)return 0;
	int &ret = dp[index];
	if (ret != -1)return ret;
	ret = 1;
	for (int next = index + 1; next < n; ++next) {
		if (a[index] < a[next]) ret = max(ret, lis(next) + 1);
	}
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int ret=-1;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)ret = max(ret, lis(i));
	cout << ret;
	return 0;

}