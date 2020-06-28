#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, x, y;
		cin >> n >> x >> y;
		ll small, big;

		if((x+y)>(2*n-1))
		{
			small = big =n;
		}
		else if(x + y > n && x+y<=(2*n-1)) 
		{
			small = x+y-n+1;
			big = n;
		}
		else {
			small = 1;
			big = x+y-1;
		}
		cout << small << " " << big << endl;
	}
	return 0;
}