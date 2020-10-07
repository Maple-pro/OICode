// wrong answer

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	ll res = 0;
	int dig0 = s[len - 1] - '0';
	res += dig0 * (len - 1) * len / 2;
	// cout << res << endl;
	
	for (int i = 1; i < len; i++)
	{
		int dig = s[len - i -1] - '0';
		res += dig * pow(10, i) * (len - 1) * (len - 1 - i) / 2 + dig * ((9 * i - 1) * pow(10, i) + 1) / 81;
		// cout << res << endl;
		res = res % mod;
	}
	// res += s[len - 1] - '0';
	cout << res << endl;
	return 0;
}
