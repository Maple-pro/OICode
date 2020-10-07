#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c;
		ll x = a + b;
		if (x >= c) d = x - c + 1;
		else d = c - x + 1;
		cout << d << endl;
	}

	return 0;
}
