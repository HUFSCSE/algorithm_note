#include<iostream>
#include<cstdio>
#include<iostream>
using namespace std;
int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
int d[101][101];
int main() {
	//Floyd_Warshall Algorithm
	//모든 V 사이의 최단 경로 구하기, 음수 가능
	//O(V^3)
	//https://www.acmicpc.net/problem/11404
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (d[x][y] == 0) {
			d[x][y] = z;
		}
		else {
			d[x][y] = min(d[x][y], z);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0)
						d[i][j] = d[i][k] + d[k][j];
					else if (d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}