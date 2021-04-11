// Unfinished
// Ë«ÏòÁ´±í 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int left[maxn];
int right[maxn];

int n, m;
int kase = 1;
bool revert = false;

void op1(int l, int r)
{
	
}

void op2(int l, int r)
{
	
}

void op3(int l, int r)
{
	
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2) {
		memset(left, 0, sizeof(left));
		memset(right, 0, sizeof(right));
		revert = false;
		for (int i = 1; i <= n; i++) {
			left[i] = i - 1;
			right[i] = (i + 1) % (n + 1);
		}
		right[0] = 1;
		left[n + 1] = n;
		
		int op, l, r;
		while (m--) {
			scanf("%d", &op);
			if (op == 4) {
				revert = !revert;
				continue;
			}
			scanf("%d%d", &l, &r);
			if (op == 1) op1(l, r);
			else if (op == 2) op2(l, r);
			else op3(l, r);
		}
	}
}
