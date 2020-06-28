#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll x1 = -1;
		ll x2 = -1;
		if (a < c)
		{
			x1 = 1;
		}
		if (a * b > c)
		{
			x2 = b;
		}
		cout << x1 << " " << x2 << endl;
	}
	return 0;
}