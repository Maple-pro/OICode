#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int datas[2*maxn];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i=1; i<=2*n; i++){
			scanf("%d", &datas[i]);
		}

		sort(datas+1, datas+n+1);
		int result = datas[n+1] - datas[n];

		printf("%d\n", result);
	}

	return 0;
}
