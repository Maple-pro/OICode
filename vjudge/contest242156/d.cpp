// bfs, æ≠µ‰√‘π¨Œ Ã‚ 
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
int maze[5][5];
int dist[5][5];
int sx = 0, sy = 0;
int ex = 4, ey = 4;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
P path[5][5];

int bfs()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dist[i][j] = -1;
		}
	}
	queue<P> que;
	que.push(P(sx, sy));
	dist[sx][sy] = 0;
	
	while (!que.empty()) {
		P now = que.front();
		que.pop();
		if (now.first == ex && now.second == ey) break;
		
		for (int i = 0; i < 4; i++) {
			P next = P(now.first + dx[i], now.second + dy[i]);
			if (next.first >= 0 && next.first < 5 && next.second >= 0 && next.second < 5 && !maze[next.first][next.second] && dist[next.first][next.second] == -1) {
				que.push(next);
				dist[next.first][next.second] = dist[now.first][now.second] + 1;
				path[next.first][next.second] = P(now.first, now.second);
			}
		}
	}
	return dist[ex][ey];
}

void outputPath(P now)
{
	if (now.first == -1 && now.second == -1) return;
	if (now.first == sx && now.second == sy) {
		printf("(%d, %d)\n", now.first, now.second);
	}
	else {
		outputPath(path[now.first][now.second]);
		printf("(%d, %d)\n", now.first, now.second);
	}
}

int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &maze[i][j]);
			path[i][j] = P(-1, -1);
		}
	}
	
	int ans = bfs();
	outputPath(P(ex, ey));
//	printf("%d\b", ans);
	return 0;
}
