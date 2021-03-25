#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
//	printf("%d %d\n", i, j);
    int sum = 0;
    if (i == -1 || j == -1 || i >= m || j >= n || grid[i][j] == 0) return sum;
    sum = 1;
	grid[i][j] = 0;
    sum += dfs(i-1, j, grid, m, n);
    sum += dfs(i+1, j, grid, m, n);
    sum += dfs(i, j-1, grid, m, n);
    sum += dfs(i, j+1, grid, m, n);
//    printf("%d %d %d\n", i, j, sum);
    return sum;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int maxn = 55;
    int m = grid.size();
    int n = grid[0].size();
    
    int res = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]){
                int tmp = dfs(i, j, grid, m, n);
                res = max(tmp, res);
            }
        }
    }
    return res;
}

int main()
{
	vector<vector<int>> grid = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}
	};
	
	cout << maxAreaOfIsland(grid) << endl;
	
	return 0;
}
