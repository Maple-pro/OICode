// 深度优先搜索 ,回溯算法 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 13;
int n;
int sum = 0;
int ans[maxn];
int b[maxn];
int c[2 * maxn + 2];
int d[2 * maxn + 2];

void search(int i)
{
	if (i >= n) {
		sum++;
		if (sum <= 3)
		{
			for (int k = 0; k < n; k++) cout << ans[k] + 1 << " ";
			cout << endl;
		}
		return;
	}
	else {
		for (int j = 0; j < n; j++) {
			if ((!b[j]) && (!c[i+j]) && (!d[n+i-j])) {
				ans[i] = j;
				b[j] = 1;
				c[i+j] = 1;
				d[n+i-j] = 1;
				search(i+1);
				b[j] = 0;
				c[i+j] = 0;
				d[n+i-j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n;
	search(0);
	cout << sum << endl;
	return 0;
}
