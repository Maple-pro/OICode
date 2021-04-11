#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int sum[maxn];

void build(int p)
{
	int now;
	scanf("%d", &now);
	if (now == -1) return;
	sum[p] += now;
	build(p - 1);
	build(p + 1);
}

bool init()
{
	int root;
	scanf("%d", &root);
	if (root == -1) return false;
	memset(sum, 0, sizeof(sum));
	int position = maxn / 2;
	sum[position] = root;
	build(position - 1);
	build(position + 1);
	return true;
}

int main()
{
//	freopen("./data/e/1.in", "r", stdin);
	
	int cnt = 1;
	while (init()) {
		int i = 0;
		while (!sum[i]) i++;
		printf("Case %d:\n%d", cnt, sum[i]);
		for (i = i + 1 ; ; i++) {
			if (!sum[i]) break;
			printf(" %d", sum[i]);
		}
		printf("\n\n");
		cnt++;
	}
	
	return 0;
}
