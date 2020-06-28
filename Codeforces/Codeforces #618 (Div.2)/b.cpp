#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int data[2*maxn];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i=1; i<=2*n; i++){
			scanf("%d", &data[i]);
		}

		sort(data+1, data+n+1);
		int result = data[n+1] - data[n];

		printf("%d\n", result);
	}

	return 0;
}
