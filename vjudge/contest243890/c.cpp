// Codeforces-366C
// 01±³°ü 
#include <bits/stdc++.h>
using namespace std;

const int INF = -(1 << 30);

const int maxn = 105;
const int maxc = 1e5 + 5;
const int minc = -1e5 - 5;
int a[maxn];
int b[maxn];
int c[maxn];
int dp1[maxc];
int dp2[maxc];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int j = 0; j < n; j++) {
		scanf("%d", &b[j]);
	}
	for (int i = 0; i < n; i++) c[i] = a[i] - k * b[i]; 
	
	memset(dp1, -0x3f, sizeof(dp1));
	memset(dp2, -0x3f, sizeof(dp2));
	
	dp1[0] = 0; dp2[0] = 0;

	for (int i = 1; i <= n; i++) {
		if (c[i-1] >= 0) {
			for (int j = 1e5; j >= c[i-1]; j--) {
				dp1[j] = max(dp1[j], dp1[j - c[i-1]] + a[i - 1]);
			}
		}
		else if (c[i-1] < 0) {
			c[i - 1] = -c[i - 1];
			for (int j = 1e5; j >= c[i-1]; j--) {
				dp2[j] = max(dp2[j], dp2[j - c[i-1]] + a[i - 1]);
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= 1e5; i++) {
		if (dp1[i] == 0 && dp2[i] == 0) continue;
		ans = max(dp1[i] + dp2[i], ans);
	}
	
	printf("%d\n", ans);
	
	return 0;
}
