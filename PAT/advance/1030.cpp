#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 505;
int d[maxn][maxn];
int c[maxn][maxn];
vector<int> pre[maxn];
int dist[maxn];
int vis[maxn] = {0};
int N, M, S, D;
int optValue = INF;
vector<int> path;
vector<int> tmpPath;

void Dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0;
	for (int i = 0; i < N; i++) {
		int now = -1;
		int MIN = INF;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && dist[j] < MIN) {
				now = j;
				MIN = dist[j];
			}
		}
		if (now == -1) return;
		vis[now] = 1;
		for (int j = 0; j < N; j++) {
			if (!vis[j]) {
				if (dist[now] + d[now][j] < dist[j]) {
					dist[j] = dist[now] + d[now][j];
					pre[j].clear();
					pre[j].push_back(now);
				}
				else if (dist[now] + d[now][j] == dist[j]) {
					pre[j].push_back(now);
				}
			}
		}
	}
}

void DFS(int now)
{
	if (now == S) {
		tmpPath.push_back(now);
		int value = 0;
		for (int i = tmpPath.size() - 1; i > 0; i--) {
			int id = tmpPath[i];
			int next = tmpPath[i - 1];
			value += c[id][next];
		}
		if (value < optValue) {
			path = tmpPath;
			optValue = value;
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(now);
	for (int i = 0; i < pre[now].size(); i++) {
		DFS(pre[now][i]);
	}
	tmpPath.pop_back();
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	memset(d, 0x3f, sizeof(d));
	memset(c, 0x3f, sizeof(c));
	scanf("%d%d%d%d", &N, &M, &S, &D);
	for (int i = 0; i < M; i++) {
		int c1, c2, distance, cost;
		scanf("%d%d%d%d", &c1, &c2, &distance, &cost);
		d[c1][c2] = distance;
		d[c2][c1] = distance;
		c[c1][c2] = cost;
		c[c2][c1] = cost;
	}
	
	Dijkstra();
	DFS(D);
	
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d\n", dist[D], optValue);
	
	return 0;
}
