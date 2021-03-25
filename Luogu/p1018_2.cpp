// dfs, 高精度 
// 通过部分数据 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 45;
int nums[maxn];
ll dp[maxn][6];
string tmp;
int n, k;

ll getNum(int l, int r) {
	ll mul = 0;
	for (int i = l; i <= r; i++) {
		mul = mul * 10 + nums[i];
	}
	return mul;
}

int main()
{
	scanf("%d%d", &n, &k);
	cin >> tmp;
	for (int i = 0; i < n; i++) nums[i] = tmp[i] - '0';
	
	for (int i = 0; i < n; i++) dp[i][0] = getNum(0, i);
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			for (int b = j; b <= i; b++) {
				dp[i][j] = max(dp[i][j], dp[b-1][j-1] * getNum(b, i));
			}
		}
	}
	
	cout << dp[n-1][k] << endl;
	return 0;
} 
