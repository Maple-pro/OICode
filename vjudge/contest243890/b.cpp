// hdu-2955
// 01±³°ü 
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 105;
int m[maxn];
double P[maxn];
double dp[10005];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		double p; cin >> p;
		int n; cin >> n;
		int sum = 0; 
		for (int i = 0; i < n; i++) {
			cin >> m[i];
			cin >> P[i];
			sum += m[i];
		}
		
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = sum; j >= 0; j--) {
				dp[j] = max(dp[j], dp[j - m[i - 1]] * (1 - P[i - 1])); 
			}
		}
		for (int i = sum; i >= 0; i--) {
			if (dp[i] >= (1 - p)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}
