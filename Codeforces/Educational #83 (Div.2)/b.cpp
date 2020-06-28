#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int a[maxn];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i=0; i<n; i++)
		{
			cin >> a[i];
		}
		sort(a, a+n);
		for (int i=n-1; i>=0; i--)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}