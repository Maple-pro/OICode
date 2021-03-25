#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 20;
int s[maxn];
int n;
ll dp[maxn][maxn];

int main()
{
	int num = 1;
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> s[i];
		
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (i == j) {
					dp[i][j] = s[i];
					ans = max(ans, dp[i][j]);
				}
				else {
					dp[i][j] = dp[i][j-1] * s[j];
					ans = max(ans, dp[i][j]);
				}
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", num, ans);
		num++;
	}
	return 0;
}
