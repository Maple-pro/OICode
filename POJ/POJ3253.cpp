// Ì°ÐÄ 
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;
const int maxn = 20005;
int l[maxn];

int main()
{
	int n;
	cin >> n;
	memset(l, 0, sizeof(l));
	
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	
	ll res = 0;
	while (n > 1) {
		int m1 = 0;
		int m2 = 1;
		if (l[m1] > l[m2]) {
			int tmp = m2;
			m2 = m1; m1 = tmp;
		}
		for (int i = 2; i < n; i++) {
			if (l[i] < l[m1]) {
				m2 = m1; m1 = i;
			}
			else if (l[i] < l[m2]) m2 = i;
		}
		int t = l[m1] + l[m2];
		if (m1 == n-1) {
			int tmp = m2;
			m2 = m1; m1 = tmp;
		}
		l[m1] = t;
		l[m2] = l[n-1];
		res += t;
		n--;
	}
	cout << res << endl;
	
	return 0;
}
