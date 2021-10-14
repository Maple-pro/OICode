// constructive algorithms
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("data.in", "r", stdin);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		for (int i = 1; i <= a - c + 1; i++) printf("1");
		for (int i = 1; i <= c - 1; i++) printf("0");
		printf(" ");
		printf("1");
		for (int i = 1; i <= b - 1; i++) printf("0");
		printf("\n");
	}
	
	return 0;
}
