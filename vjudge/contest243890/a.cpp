// 01교관 
#include <iostream>
// hdu-2602
// 01교관 
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1005;
const int maxv = 1005;
int value[maxn];
int volume[maxn];
ll dp[maxv];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		memset(value, 0, sizeof(value));
		memset(volume, 0, sizeof(volume));
		memset(dp, 0, sizeof(dp));
		int n, v;
		scanf("%d%d", &n, &v);
		for (int i = 0; i < n; i++) scanf("%d", &value[i]);
		for (int i = 0; i < n; i++) scanf("%d", &volume[i]);
		
		for (int i = 1; i <= n; i++) {
			for (int j = v; j >= 0; j--) {
				if (j >= volume[i-1]) dp[j] = max(dp[j], dp[j - volume[i-1]] + value[i-1]);
				else dp[j] = dp[j];
			}
		}
		
		printf("%lld\n", dp[v]);
	}
	
	return 0;
}
