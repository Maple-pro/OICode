#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		if (a != 0) 
		{
			ans++;
			a--;
		}
		if (b != 0) 
		{
			ans++;
			b--;
		}
		if (c != 0) 
		{
			ans++;
			c--;
		}

		if(a>b)
		{
			int temp = a;
			a=b; b=temp;
		}
		if(c>b)
		{
			int temp = c;
			c=b; b=temp;
		}

		if (a*b != 0)
		{
			ans++;
			a -= 1;
			b -= 1;
		}
		if (b*c != 0)
		{
			ans++;
			b -= 1;
			c -= 1;
		}
		if (a*c != 0)
		{
			ans++;
			a -= 1;
			c -= 1;
		}
		if (a>=1 && b>=1 && c>=1)
		{
			ans++;
			a -= 1;
			b -= 1;
			c -= 1;
		}
		
		cout << ans << endl;
	}

	return 0;
}