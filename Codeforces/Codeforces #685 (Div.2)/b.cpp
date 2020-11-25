#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		for (int i = 0; i < q; i++) {
			int l, r;
			cin >> l >> r;
			bool flag = false;
			for (int j = 0; j <= l-2; j++) {
				if (s[j] == s[l-1]) {
					flag = true;
					break;
				}
			}
			for (int j = r; j <= n-1; j++) {
				if (s[j] == s[r-1]) {
					flag = true;
					break;
				}
			}
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
