#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll x, y, a, b;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%I64d %I64d %I64d %I64d", &x, &y, &a, &b);
		if((y-x) % (a+b) == 0)
		{
			ll round = (y-x) / (a+b);
			printf("%I64d\n", round);
		} 
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}