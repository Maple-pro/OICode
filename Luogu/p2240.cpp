// Ì°ÐÄ 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
typedef struct {
	int m;
	int v;
} coin;

coin coins[maxn];

bool comp(coin x, coin y)
{
	return x.v * y.m >= y.v * x.m;
}

int main()
{
	int n, t;
	double result = 0;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i].m >> coins[i].v;
	}
	sort(coins, coins + n, comp);
	
	for (int i = 0; i < n; i++)
	{
		if (coins[i].m <= t) 
		{
			result += coins[i].v;
			t -= coins[i].m;
		}
		else
		{
			result += coins[i].v * t * 1.0 / (coins[i].m * 1.0);
			break;
		}
		// cout << result << endl;
	}
	printf("%.2f\n", result);
	return 0;
}
