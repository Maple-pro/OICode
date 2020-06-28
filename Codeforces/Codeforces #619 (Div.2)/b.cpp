#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn];
ll k[maxn];
ll m[maxn];

int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(k, 0, sizeof(k));
		memset(m, 0, sizeof(m));
		int n;
		scanf ("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf ("%I64d", &a[i]);
		}

		int k_num = 1;
		for (int i=1; i<=n; i++)
		{
			if (a[i] == -1)
			{
				int front;
				for (front=i; front<=n; front++)
				{
					if (a[front] != -1) break;
				}
				
				int behind;
				for (behind=i; behind>=1; behind--)
				{
					if (a[behind] != -1) break;
				}
				if (behind == 0) continue;

				if(front == n+1)
				{
					if(behind !=0)
					{
						k[k_num] = a[behind];
						k_num++;
						break;
					}
					else
					{
						k[k_num] = 1;
						k_num++;
						break;
					}
				}
				else
				{
					if(behind == 0)
					{
						k[k_num] = a[front];
						k_num++;
						continue;
					}
					else
					{
						k[k_num] = (a[behind] + a[front]) / 2;
						k_num++;
						continue;
					}
				}
			}
		}

		ll temp_m = 0;
		for (int i=1; i<k_num; i++)
		{
			if (a[1] == -1) a[1] = k[i];
			for (int j=2; j<=n; j++)
			{
				if (a[j] == -1) a[j] = k[i];
				if (abs(a[j] - a[j-1]) > temp_m) temp_m = abs(a[j] - a[j-1]);
			}
			m[i] = temp_m;
		}

		ll result_num = 1;
		for (int i=1; (i+1)<k_num; i++)
		{
			if (m[i+1] < m[result_num]) result_num = i+1;
		}

		cout << m[result_num] << " " << k[result_num] << endl;
	}
	return 0;
}