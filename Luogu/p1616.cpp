#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxm = 10005;
const int maxt = 1e7 + 5;
int costtime[maxm];
int value[maxm];
ll dp[maxt];

int main()
{
	int T, M;
	cin >> T >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> costtime[i] >> value[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= M; i++)
	{
		for (int j = costtime[i-1]; j <= T; j++)
		{
			dp[j] = max(dp[j], dp[j-costtime[i-1]]+value[i-1]);
		}
	}
	cout << dp[T] << endl;
	return 0;
}
