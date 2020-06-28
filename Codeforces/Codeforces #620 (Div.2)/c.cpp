#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 105;
ll t[maxn];
ll l[maxn];
ll h[maxn];

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		ll m;
		cin >> n >> m;
		for (int i=1; i<=n; i++)
			cin >> t[i] >> l[i] >> h[i];

		ll big = m;
		ll small = m;
		ll pre_time = 0;
		bool flag = true;
		for (int i=1; i<=n; i++)
		{
			big = big + t[i] - pre_time;
			small = small - (t[i] - pre_time);
			if(big < l[i] || small > h[i])
			{
				flag = false;
				break;
			}
			pre_time = t[i];
			if (big > h[i]) big = h[i];
			if (small < l[i]) small = l[i]; 
		}

		if (flag == false) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}