// dp
#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;
int dp[1205];
int s[4];
int a[4][maxn];

int main()
{
//	ios::sync_with_stdio(false);
	
	int total = 0;
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < s[i]; j++) {
			cin >> a[i][j];
			total += a[i][j];
		}
//		printf("total is %d\n", total);
		for (int k = s[i]-1; k >= 0; k--) {
			for (int m = total / 2; m >= a[i][k]; m--) {
				dp[m] = max(dp[m], dp[m-a[i][k]] + a[i][k]);
			}
		}
		ans += total - dp[total / 2];
//		cout << dp[total / 2] << endl;
		total = 0;
		memset(dp, 0, sizeof(dp));
	}
	
	cout << ans << endl;
	return 0;
}
