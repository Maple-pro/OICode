#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	ll ans;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		ans = s.length();
		ll sum = 0;
		ll res = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+') sum++;
			else sum--;
			if (sum < res)
			{
				res = sum;
				ans += i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
