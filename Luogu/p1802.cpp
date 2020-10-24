#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxx = 1005;
int lose[maxn];
int win[maxn];
int use[maxn];
int n, x;
long long dp[maxx];

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> lose[i] >> win[i] >> use[i];
	}
	memset(dp, 0, sizeof(dp));
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = x; j >= 0; --j)
		{
			if (j >= use[i-1]) dp[j] = max(dp[j - use[i-1]] + win[i-1], dp[j] + lose[i-1]);
			else dp[j] = dp[j] + lose[i-1];
		}
	}
	cout << dp[x] * 5 << endl;
	return 0;
}
