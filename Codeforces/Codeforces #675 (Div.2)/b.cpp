#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 105;
ll a[maxn][maxn];

int cal(int x, int y, int z, int u)
{
	int a[4] = {x, y, z, u};
	sort(a, a + 4);
	int target = a[1];
	int res = a[2] + a[3] -a[0] - a[1];
	return res;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
			}
		}
		ll res = 0;
		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < m/2; j++)
			{
				res += cal(a[i][j], a[i][m-1-j], a[n-1-i][j], a[n-1-i][m-1-j]);
			}
		}
		
		if (m % 2 != 0)
		{
			for (int i = 0; i < n/2; i++)
			{
				res += abs(a[i][m/2] - a[n-1-i][m/2]);
			}
		}
		if (n % 2 != 0)
		{
			for (int i = 0; i < m/2; i++)
			{
				res += abs(a[n/2][i] - a[n/2][m-1-i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
