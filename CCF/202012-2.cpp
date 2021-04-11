#include <bits/stdc++.h>
using namespace std;

const int maxm = 1e5 + 5;
struct Node {
	int y;
	int res;
};
Node stus[maxm];
int pre[maxm];
int post[maxm];
int m;

bool comp(Node n1, Node n2)
{
	return n1.y < n2.y;
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &stus[i].y, &stus[i].res);
	}
	sort(stus, stus + m, comp);
	
	memset(pre, 0, sizeof(pre));
	memset(post, 0, sizeof(post));
	for (int i = 1; i < m; i++) {
		if (stus[i - 1].res == 0) pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	if (stus[m - 1].res == 1) post[m - 1]++;
	for (int i = m - 1; i >= 0; i--) {
		if (stus[i].res == 1) post[i] = post[i + 1] + 1;
		else post[i] = post[i + 1];
	}
	
	int result = stus[0].y;
	int sum = pre[0] + post[0];
	for (int i = 1; i < m; i++) {
		if (stus[i].y == stus[i - 1].y) continue;
		if (pre[i] + post[i] >= sum) {
			result = stus[i].y;
			sum = pre[i] + post[i];
		}
	}
	
	printf("%d\n", result);
	
	return 0;
}
