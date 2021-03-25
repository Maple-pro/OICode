#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn];

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; i++) {
		sort(a + i -1, a + n);
		a[i] = a[i-1] + a[i];
		ans += a[i];
	}
	
	cout << ans << endl;
	return 0;
}
