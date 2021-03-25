/*
	Name: Prime Ring Problem (uva-524)
	Copyright: 
	Author: maples
	Date: 13/03/21 00:39
	Description: traceback, dfs
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;
int n;
const int maxn = 20;
int perm[maxn];
bool vis[maxn];

bool isp(int n)
{
	bool res = true;
	for (int i = 2; i <= sqrt(n) + 1; i++) {
		if (n % i == 0) res = false;
	}
	return res;
}

void dfs(int cnt)
{
	if (cnt == n && isp(perm[0] + perm[cnt - 1])) {
		for (int i = 0; i < n-1; i++) printf("%d ", perm[i]);
		printf("%d\n", perm[n-1]);
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (!vis[i] && isp(perm[cnt-1] + i)) {
				vis[i] = true;
				perm[cnt] = i;
				dfs(cnt+1);
				vis[i] = false;
			}
		}
	}
}

int main()
{
	int num = 1;
	while (cin >> n) {
		memset(perm, 0, sizeof(perm));
		memset(vis, false, sizeof(vis));
		ans = 0;
		if (num >= 2) printf("\n"); 
		printf("Case %d:\n", num);
		perm[0] = 1;
		dfs(1);
		num++;
	}
	
	return 0;
}

