// dfs
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxk = 100005;
int cells[maxn][maxn];
int visits[maxn][maxn];
int dp[maxk];
int n, m, k;

void dfs(int x, int y, int &cnt, int num)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (!cells[x][y]) {
		cnt++;
		return;
	}
	if (visits[x][y] != -1) {
		if (visits[x][y] != num) {
			cnt = dp[visits[x][y]];
		}
		return;
	}
	visits[x][y] = num;
	dfs(x + 1, y, cnt, num);
	dfs(x, y - 1, cnt, num);
	dfs(x - 1, y, cnt, num);
	dfs(x, y + 1, cnt, num);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '.') cells[i][j] = 1;
			else cells[i][j] = 0;
		}
	}
	memset(dp, -1, sizeof(dp));
	memset(visits, -1, sizeof(visits));
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		int cnt = 0;
		dfs(x, y, cnt, i);
		dp[i] = cnt;
		printf("%d\n", cnt);
	}
	return 0;
}
