#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int to, cost;
	Edge() {
	}
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};
int dist[501];
int inf = 100000000;
bool c[501];
int cnt[501];
vector<Edge> a[501];
int main() {
	//SPFA Algorithm
	//BellmanFord Upgrade 
	//시작점에서 i 로 가는 최단 거리 구하기, 음수 가능
	//O(E)
	//https://www.acmicpc.net/problem/11657
	int t;
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 0; i<e; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		a[from].push_back(Edge(to, cost));
	}
	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	c[1] = true;
	while (!q.empty()) {
		int from = q.front();
		c[from] = false;
		q.pop();
		for (Edge &e : a[from]) {
			int to = e.to;
			int cost = e.cost;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if (c[to] == false) {
					q.push(to);
					c[to] = true;
					cnt[to] += 1;
					if (cnt[to] >= v) {
						printf("-1\n");
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= v; i++) {
		if (dist[i] == inf) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}