#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main()
{
//	freopen("data.in", "r", stdin);
	
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int w, s;
		scanf("%d%d", &w, &s);
		sum += w * s;
	}
	if (sum < 0) sum = 0;
	printf("%d\n", sum);
	
	return 0;
}
