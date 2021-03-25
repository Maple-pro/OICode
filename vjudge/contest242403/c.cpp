#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll k;
	while (cin >> k) {
		ll x, y;
		vector<pair<int, int>> ans;
		for (y = k + 1; y <= 2 * k; y++) {
			if ((k * y) % (y - k) == 0) {
				x = (k * y) / (y - k);
				ans.push_back({x, y});
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("1/%lld = 1/%lld + 1/%lld\n", k, ans[i].first, ans[i].second);
		}
	}
	
	return 0;
}
