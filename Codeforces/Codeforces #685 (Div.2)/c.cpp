#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		bool res = true;
		
		int n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		int cnt1[26];
		int cnt2[26];
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for (int i = 0; i < n; i++) {
			cnt1[a[i] - 'a']++;
			cnt2[b[i] - 'a']++;
		}
		
		for (int i = 0; i < 26; i++) {
			if (cnt1[i] < cnt2[i]) {
				cnt2[i] = cnt2[i] - cnt1[i];
				cnt1[i] = 0;
			}
			else {
				cnt1[i] = cnt1[i] - cnt2[i];
				cnt2[i] = 0;
			}
		}
//		for (int i = 0; i < 8; i++) cout << cnt1[i] << " " << cnt2[i] << endl;
		
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < 26; i++) {
			sum1 += cnt1[i];
			sum2 += cnt2[i];
			if (sum1 < sum2) {
				res = false;
				break;
			}
			if (cnt1[i] % k != 0 || cnt2[i] % k != 0) {
				res = false;
				break;
			}
		}
		if (res) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
