// 贪心，优先队列 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<int, vector<int>, greater<int> > q(a, a+n);
	ll res = 0;
	while (!q.empty())
	{
		int a1 = q.top();
		q.pop();
		int a2 = 0;
		if (!q.empty()) {
			a2 = q.top();
			q.pop();
			int sum = a1 + a2;
			q.push(sum);
			res += sum;
		}
		else {
			break;
		}
	}
	printf("%lld", res);
	return 0;
} 
