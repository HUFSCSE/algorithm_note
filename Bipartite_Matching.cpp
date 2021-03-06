#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
* matching::v1 = XX; matching::v2 = XX; // 정점 개수
* matching::graph[x].push_back(y); // 정점 x와 y가 연결됨
* result = matching::hopcroft(); // 매칭 수
* y = matching::mx[x]; // 정점 x와 연결된 정점 번호
* x = matching::my[y]; // 정점 y와 연결된 정점 번호
*/
namespace Hopcroft_Karp
{
	typedef int val_t;
	const int SIZE = 1000;
	int v1, v2;
	vector<int> graph[SIZE];
	int mx[SIZE], my[SIZE];
	int total_matching;
	int dist[SIZE];
	int inf_dist;
	bool bfs() {
		int x, y;
		queue<int> q;
		for (x = 0; x < v1; x++) {
			if (mx[x] == -1) {
				dist[x] = 0;
				q.push(x);
			}
			else
				dist[x] = -1;
		}
		bool flg = false;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (int i = 0; i < graph[x].size(); i++) {
				y = graph[x][i];
				if (my[y] == -1) {
					inf_dist = dist[x] + 1;
					flg = true;
				}
				else if (dist[my[y]] == -1) {
					dist[my[y]] = dist[x] + 1;
					q.push(my[y]);
				}
			}
		}
		return flg;
	}
	bool dfs(int x) {
		if (x == -1) return true;
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
			if (tmp == dist[x] + 1 && dfs(my[y])) {
				mx[x] = y;
				my[y] = x;
				return true;
			}
		}
		dist[x] = -1;
		return false;
	}
	int matching() {
		memset(mx, -1, sizeof(mx));
		memset(my, -1, sizeof(my));
		total_matching = 0;
		while (bfs()) {
			for (int x = 0; x < v1; x++)
				if (mx[x] == -1 && dfs(x))
					total_matching++;
		}
		return total_matching;
	}
} // namespace Hopcroft_Karp Algorithm