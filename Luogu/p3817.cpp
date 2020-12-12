// Ì°ÐÄ 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
int a[maxn];

int main()
{
	int n; cin >> n;
	int x; cin >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll res = 0;
	for (int i = 1; i < n; i++) {
		if ((a[i-1] + a[i]) > x) {
			res += a[i-1] + a[i] - x;
			a[i] = x - a[i-1];
		}
	}
	cout << res << endl;
	return 0;
} 
