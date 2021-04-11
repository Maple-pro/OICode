// hdu-1114
// ÍêÈ«±³°ü 
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxv = 10005;
const int maxn = 505;
int p[maxn];
int w[maxn];
int dp[maxv];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int e, f;
		scanf("%d%d", &e, &f);
		int total = f - e;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d", &p[i], &w[i]);
		
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = w[i - 1]; j < maxv; j++) {
				dp[j] = min(dp[j], dp[j - w[i - 1]] + p[i - 1]);
			}
		}
		if (dp[total] >= 0x3f3f3f) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[total]);
	}
	
	return 0;
}
