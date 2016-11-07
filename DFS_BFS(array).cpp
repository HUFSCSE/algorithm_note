#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
int arr[1001][1001];
bool c_dfs[1001];
bool c_bfs[1001];
int main() {
	//DFS and BFS( Array ver. )
	//O( V^2 )
	//https://www.acmicpc.net/problem/1260
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	//DFS
	int top;
	stack<int> st;
	queue<int> q;
	st.push(s);
	while (!st.empty()) {
		top = st.top();
		if (c_dfs[top] == false)
			q.push(top);
		c_dfs[top] = true;
		bool c = false;
		for (int i = 0; i <= n; i++)
			if (c_dfs[i] == false && arr[top][i] == 1) {
				st.push(i);
				c = true;
				break;
			}
		if (!c) st.pop();
	}
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	printf("\n");
	//BFS
	q.push(s);
	while (!q.empty()) {
		top = q.front();
		q.pop();
		if (c_bfs[top] == false) {
			printf("%d ", top);
			c_bfs[top] = true;
			for (int i = 0; i <= n; i++)
				if (c_bfs[i] == false && arr[top][i] == 1) {
					q.push(i);
				}
		}
	}
	printf("\n");
	return 0;
}