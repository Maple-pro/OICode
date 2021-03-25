#include <bits/stdc++.h>
using namespace std;

const int maxn = 12;
int path[maxn][maxn];
int n;
int dp[maxn][maxn][maxn][maxn];

int getmax(int a, int b, int c, int d) {
	return max(a, max(b, max(c, d)));
}

int main()
{
	cin >> n;
	memset(path, 0, sizeof(path));
	int x, y, num;
	while (true) {
		scanf("%d%d%d", &x, &y, &num);
		if (x == 0) break;
		path[x][y] = num;
	}
	
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					dp[i][j][k][l] = getmax(dp[i-1][j][k-1][l], dp[i][j-1][k-1][l], dp[i-1][j][k][l-1], dp[i][j-1][k][l-1]) + path[i][j] + path[k][l];
					if (i == k && j == l) dp[i][j][k][l] -= path[i][j];
				}
			}
		}
	}
	
	cout << dp[n][n][n][n] << endl;
	
	return 0;
}
