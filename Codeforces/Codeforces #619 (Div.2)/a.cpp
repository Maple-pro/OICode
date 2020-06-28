#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
char a[maxn];
char b[maxn];
char c[maxn];

int main()
{
	int t; cin >> t;
	while (t--)
	{
		scanf ("%s", a);
		scanf ("%s", b);
		scanf ("%s", c);
		int length = strlen(a);
		int i;
		for (i=0; i<length; i++)
		{
			if ((a[i] != c[i]) && (b[i] != c[i])) break;
		}
		if (i < length) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}