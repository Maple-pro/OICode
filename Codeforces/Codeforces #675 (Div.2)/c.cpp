// 公式推导 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	ll len = s.length();
	ll res = 0;
	ll sum = 0;
	ll p = 1;
	
	for (ll i = len - 1; i >= 0; i--)
	{
		int dig = s[i] - '0';
		ll k = (i * (i + 1) / 2 % mod * p % mod + sum) % mod;
		sum = (p * (len - i) % mod + sum) % mod;
		p = p * 10 % mod;
		res = (res + dig * k % mod) % mod;
	}
	
	cout << res << endl;
	return 0;
}
