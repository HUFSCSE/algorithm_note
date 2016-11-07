#include <cstdio>
#include <vector>
using namespace std;
struct Edge {
	int from;
	int to;
	int cost;
};
int dist[501];
int inf = 100000000;
int main() {
	//BellmanFord Algorithm
	//시작점에서 i 로 가는 최단 거리 구하기, 음수 가능
	//Upgrade -> SPFA
	//O(V*E)
	//https://www.acmicpc.net/problem/11657
	int t;
	int v, e;
	scanf("%d %d", &v, &e);
	vector<Edge> a(e);
	for (int i = 0; i<e; i++) {
		scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
	}
	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	dist[1] = 0;
	bool negative_cycle = false;
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j<e; j++) {
			int x = a[j].from;
			int y = a[j].to;
			int z = a[j].cost;
			if (dist[x] != inf && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				if (i == v) {
					negative_cycle = true;
				}
			}
		}
	}
	if (negative_cycle) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= v; i++) {
			if (dist[i] == inf) dist[i] = -1;
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}