#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};
vector<Edge> a[20001];
int dist[20001];
bool check[20001];
int inf = 1000000000;
int main() {
	//Dijkstra Algorithm
	//시작점에서 i 로 가는 최단 거리 구하기, 음수 불가
	//음수 -> 벨만 포드
	//Array O(V^2)
	//list O(V^2 + E )
	//priority queue O( (E + V) * logV )
	//fibonacci heap O( E + V*log V )
	//https://www.acmicpc.net/problem/1753
	int v, e;
	scanf("%d %d", &v, &e);
	int start;
	scanf("%d", &start);
	for (int i = 0; i<e; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(Edge(y, z));
	}
	for (int i = 1; i <= v; i++) {
		dist[i] = inf;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		int x = p.second;
		if (check[x]) {
			continue;
		}
		check[x] = true;
		for (int i = 0; i<a[x].size(); i++) {
			int y = a[x][i].to;
			if (dist[y] > dist[x] + a[x][i].cost) {
				dist[y] = dist[x] + a[x][i].cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] >= inf) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}