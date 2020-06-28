#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int maxm = 2 * 1e5 + 5;
ll arr[maxm];
int n, m;

void before()
{
	arr[0] = 1;
	for (int i=1; i<=maxm; i++)
		arr[i] = (arr[i-1] * i) % MOD;
}


ll fac(int m)
{
	return arr[m];
}

ll cau(int mid, int i)
{
	ll part = (fac(mid-1)/(fac(mid-n+1) * fac(n-i-1) * fac(i-2))) % MOD;
	return part;
}

int main()
{
	before();
	ll ans = 0;
	cin >> n >> m;
	for (int i = 2; i <= n-1; i++)
	{
		for (int mid = n-1; mid <= m; mid++)
		{
			ans = ans + cau(mid, i) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}