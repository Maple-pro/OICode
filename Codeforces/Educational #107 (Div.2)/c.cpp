#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
const int maxa = 55;
int n, q;
int a[maxn]; // 记录源数据 
int p[maxa]; // 记录每个颜色出现位置的最小值 

int main()
{
//	freopen("data.in", "r", stdin);
	
	scanf("%d%d", &n, &q);
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--) p[a[i]] = i;
	
	for (int i = 0; i < q; i++) {
		int query;
		scanf("%d", &query);
		printf("%d", p[query]);
		if (i < q - 1) printf(" ");
		else printf("\n");
		for (int j = 1; j <= maxa; j++) {
			if (p[j] != -1 && p[j] < p[query]) p[j]++;
		}
		p[query] = 1;
	}
	
	return 0;
}
