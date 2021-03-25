#include <bits/stdc++.h>
using namespace std;

int map1[35][35];

int dfs(int x, int y) {
	int sum = 0;
	if (map1[x][y] == 0) {
		return sum;
	}
	sum++;
	map1[x][y] = 0;
	sum += dfs(x+1, y);
	sum += dfs(x-1, y);
	sum += dfs(x, y-1);
	sum += dfs(x, y+1);
	return sum;
}

int main()
{
	int n, x, y;
	while (scanf("%d%d%d", &n, &x, &y) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> map1[i][j];
			}
		}
		memset(map1, 0, sizeof(map1));
		cout << dfs(x, y) << endl;
	}
	return 0;
}
