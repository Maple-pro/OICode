// 记忆化搜索, dfs, 动态规划 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;
int mine[maxn];
int way[maxn][maxn];
int sum[maxn];
int next[maxn];

int N;

int dfs(int x)
{
	if (sum[x] != 0) return sum[x];
	sum[x] = mine[x];
	for (int i = x + 1; i < N; i++)
	{
		if (way[x][i] == 1)
		{
			dfs(i);
			if (sum[i] + mine[x] > sum[x])
			{
				sum[x] = sum[i] + mine[x];
				next[x] = i;
			}
		}
	}
	return sum[x];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> mine[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j <N; j++) cin >> way[i][j];
	}
	memset(sum, 0, sizeof(sum));
	memset(next, -1, sizeof(next));
	
	int res = 0;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (dfs(i) > res)
		{
			res = dfs(i);
			index = i;
		}
	}
	while (index != -1)
	{
		cout << index + 1 << " ";
		index = next[index];
	}
	cout << endl;
	cout << res;
	
	return 0;
}
