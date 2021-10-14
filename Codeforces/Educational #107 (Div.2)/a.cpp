#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("data.in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		int sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int r;
			scanf("%d", &r);
			if (r == 1 || r == 3) sum++;
		}
		printf("%d\n", sum);
	}
}
