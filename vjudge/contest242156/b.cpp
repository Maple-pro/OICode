#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int grid[maxn][maxn];
int idx[maxn][maxn];
int m, n;

void dfs(int i, int j, int cnt)
{
	if (i < 0 || i >= m || j < 0 || j >= n) return;
	if (idx[i][j] != -1 || !grid[i][j]) return;
	idx[i][j] = cnt;
	for (int k = -1; k <= 1; k++) {
		for (int t = -1; t <= 1; t++) {
			dfs(i + k, j + t, cnt);
		}
	}
}

int main()
{
	while (true) {
		cin >> m >> n;
		if (m == 0) break;
		for (int i = 0; i < m; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < n; j++) {
				if (tmp[j] == '*') grid[i][j] = 0;
				else grid[i][j] = 1;
			}
		}
		memset(idx, -1, sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] && idx[i][j] == -1) {
					dfs(i, j, cnt);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
} 
