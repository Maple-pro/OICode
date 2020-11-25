/**
 * priority queue 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const ll maxk = 1e9 + 5;
priority_queue<ll> q;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		ll tmp; cin >> tmp;
		if (tmp % 2 != 0) sum += tmp;
		else q.push(tmp);
	}
	
	while (k > 0) {
		if (!q.size()) break;
		ll u = q.top();
		q.pop();
		u /= 2;
		if (u % 2 != 0) sum += u;
		else q.push(u);
		k--; 
	}
	
	while (q.size()) {
		sum += q.top();
		q.pop();
	}
	
	cout << sum << endl;
	return 0;
}
