#include<algorithm>
#include<iostream>
using namespace std;
int a[40001];
int b[40001];
int n;
int main() {
	int ret = 1;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> a[i];
	b[0] = a[0];
	for (int i = 1; i < n; ++i) {
		if (b[ret - 1] < a[i]) {
			b[ret ] = a[i];
			ret++;
			continue;
		}
		else 
			*lower_bound(b, b + ret,a[i]) = a[i];
	}
	cout << ret;
	return 0;

}