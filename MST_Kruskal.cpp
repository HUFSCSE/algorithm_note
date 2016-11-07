#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < (const Edge &other) const {
		return cost < other.cost;
	}
};
int p[10001];
int Find(int x) {
	if (x == p[x]) {
		return x;
	}
	else {
		return p[x] = Find(p[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	p[x] = y;
}
int main() {
	//MST Kruskal algo
	//E 가 적을 때 사용한다. E 가 이미 정렬되어있을 때 사용한다.
	//O( E * log V )
	//Worst( E * log E )
	//https://www.acmicpc.net/problem/1197
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		p[i] = i;
	}
	vector<Edge> a(e);
	for (int i = 0; i<e; i++) {
		scanf("%d %d %d", &a[i].start, &a[i].end, &a[i].cost);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i<e; i++) {
		Edge e = a[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y) {
			Union(e.start, e.end);
			ans += e.cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}