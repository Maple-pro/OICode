// dfs
#include <bits/stdc++.h>
using namespace std;

const int maxn = 405;
int dist[maxn][maxn];
int n, m, inx, iny;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int step)
{
	if (step >= 500) return;
	dist[x][y] = step;
	for (int i = 0; i < 8; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx >= 0 && newx < n 
			&& newy >= 0 && newy < m
			&& (dist[newx][newy] == -1 || dist[newx][newy] > step+1))
			{
				dfs(newx, newy, step + 1);
			}
	}
}

int main()
{
	cin >> n >> m >> inx >> iny;
	memset(dist, -1, sizeof(dist));
	dfs(inx-1, iny-1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%-5d", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
