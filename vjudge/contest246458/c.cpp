// uva-548
// tree, dfs, stringstream
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int inorder[maxn];
int postorder[maxn];
int ltree[maxn];
int rtree[maxn];
int n;
int best, best_sum;

bool readline(int *a)
{
	string line;
	if (!getline(cin, line)) return false;
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x) a[n++] = x;
	return n > 0;
}

// inorder[l1...r1] and postorder[l2, r2]
int build(int l1, int r1, int l2, int r2)
{
	if (l1 > r1) return 0;
	int root = postorder[r2];
	int p = l1;
	while (inorder[p] != root) p++;
	int cnt = p - l1;
	ltree[root] = build(l1, p - 1, l2, l2 + cnt - 1);
	rtree[root] = build(p + 1, r1, l2 + cnt, r2 - 1);
	return root;
}

void dfs(int now, int sum)
{
	sum += now;
	if (!ltree[now] && !rtree[now]) {
		if (sum < best_sum || (sum == best_sum && now < best)) {
			best = now;
			best_sum = sum;
		}
	}
	if (ltree[now]) {
		dfs(ltree[now], sum);
	}
	if (rtree[now]) {
		dfs(rtree[now], sum);
	}
}

int main()
{
	while (readline(inorder)) {
		readline(postorder);
		memset(ltree, 0, sizeof(ltree));
		memset(rtree, 0, sizeof(rtree));
		build(0, n - 1, 0, n - 1);
		best_sum = 0x3f3f3f;
		dfs(postorder[n - 1], 0);
		cout << best << endl;
	}
	
	return 0;
}
