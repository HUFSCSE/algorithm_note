#include<iostream>    
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[32001];
int cnt[32001];
int main() {
	//Directed Acyclic Graph
	//Topological Sort
	//O( V+E )
	//https://www.acmicpc.net/problem/2252
	int n, e;
	queue<int> que;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		cnt[b] += 1;
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0)
			que.push(i);
	while (!que.empty()) {
		int now = que.front();
		cout << now << " ";
		que.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int t = v[now][i];
			cnt[t] -= 1;
			if (cnt[t] == 0)
				que.push(t);
		}
	}
	cout << "\n";
	return 0;
}