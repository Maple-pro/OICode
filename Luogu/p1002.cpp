#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int maxn = 25;
ll dp[maxn][maxn];

int main()
{
	int xb, yb, xh, yh;
	cin >> xb >> yb >> xh >> yh;
	memset(dp, -1, sizeof(dp));
	dp[xh][yh] = 0;
	dp[xh + 1][yh + 2] = 0;
	dp[xh + 2][yh + 1] = 0;
	if (yh >= 2) dp[xh + 1][yh - 2] = 0;
	if (yh >= 1) dp[xh + 2][yh - 1] = 0;
	if (xh >= 1) dp[xh - 1][yh + 2] = 0;
	if (xh >= 2) dp[xh - 2][yh + 1] = 0;
	if (xh >= 1 && yh >= 2) dp[xh - 1][yh - 2] = 0;
	if (xh >= 2 && yh >= 1) dp[xh - 2][yh - 1] = 0;
	
	dp[0][0] = 1;
	for (int i = 1; i <= xb; i++) if (dp[i][0] == -1) dp[i][0] = dp[i-1][0];
	for (int j = 1; j <= yb; j++) if (dp[0][j] == -1) dp[0][j] = dp[0][j-1];
		
	for (int i = 1; i <= xb; i++)
	{
		for (int j = 1; j <= yb; j++)
		{
			if (dp[i][j] == -1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[xb][yb] << endl;
	
	return 0;
}