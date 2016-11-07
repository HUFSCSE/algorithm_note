#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	stack<pair<int, int>> s;
	s.push(make_pair(node, 0));
	check[node] = true;
	printf("%d ", node);
	while (!s.empty()) {
		int node = s.top().first;
		int start = s.top().second;
		s.pop();
		for (int i = start; i<a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				printf("%d ", next);
				check[next] = true;
				s.push(make_pair(node, i + 1));
				s.push(make_pair(next, 0));
				break;
			}
		}
	}
}
void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i<a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	//DFS and BFS( List ver. )
	//O( V + E )
	//https://www.acmicpc.net/problem/1260
	int v, e, start;
	scanf("%d %d %d", &v, &e, &start);
	for (int i = 0; i<e; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= v; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	printf("\n");
	bfs(start);
	printf("\n");
	return 0;
}