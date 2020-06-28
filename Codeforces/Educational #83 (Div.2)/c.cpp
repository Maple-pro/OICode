#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
typedef long long ll;
ll a[maxn];

ll sum()
{
	ll temp = 0;
	for (int i=0; i<maxn; i++) temp += a[i];
	return temp;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		
		int n, k;
		cin >> n >> k;
		for (int i=1; i<=n; i++) cin >> a[i];

		int flag = false;
		int flag1 = false;
		while (sum() != 0)
		{
			flag = false;
			for(int i=1; i<=n; i++)
			{
				if (a[i] % k == 0) a[i] = a[i] / k;
				else if((a[i] - 1) % k == 0) 
				{
					if(flag == false)
					{
						a[i] = (a[i]-1) / k;
						flag = true;
					}
					else
					{
						flag1 = true;
						break;
					}
				}
				else 
				{
					flag1 = true;
					break;
				}
			}
			if (flag1) break;
		}

		if (flag1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}