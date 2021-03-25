// dfs, 高精度 
// 部分通过 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 45;
int num[maxn];
int n, k;
ll ans = INT_MIN;

void dfs(int has, ll res, int pre)
{
	if (has == k) {
		ll mul = 0;
		for (int j = pre; j < n; j++) {
			mul = mul * 10 + num[j];
		}
		ans = max(ans, res * mul);
		return;
	}
	else {
		ll mul = 0;
		for (int i = pre + 1; i <= n-k+has; i++) {
			mul = mul * 10 + num[i-1];
			dfs(has + 1, res * mul, i);
		}
	}
	
}

int main()
{
	cin >> n >> k;
	string tmp;
	cin >> tmp;
	
	for (int i = 0; i < n; i++) num[i] = tmp[i] - '0';
	
	dfs(0, 1, 0);
	cout << ans << endl;
	return 0;
} 
