// ¶¯Ì¬¹æ»® 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxm = 10005;
int t[maxm];
int x[maxm];
int y[maxm];
int dp[maxm]; 

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) cin >> t[i] >> x[i] >> y[i];
	
	for (int i = 0; i < m; i++) dp[i] = 1;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < i; j++) {
			if (abs(t[i] - t[j]) >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) ans = max(ans, dp[i]);
	
	cout << ans;
	
	return 0;
}
