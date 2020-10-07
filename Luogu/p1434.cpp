// 动态规划 , 记忆化搜索, dfs
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int h[maxn][maxn];
int s[maxn][maxn];
int r, c;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
	if (s[x][y] != -1) return s[x][y];
	s[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < r && yy < c && h[xx][yy] < h[x][y])
		{
			dfs(xx, yy);
			s[x][y] = max(s[x][y], s[xx][yy] + 1);
		}
	}
	return s[x][y];
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> h[i][j];
			s[i][j] = -1;
		}
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}
