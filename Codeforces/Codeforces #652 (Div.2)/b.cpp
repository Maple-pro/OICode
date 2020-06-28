#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int flag1 = -1;
		int flag2 = -1;
		memset(s, 0, sizeof(s));
		cin >> s;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				flag1 = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '0')
			{
				flag2 = i;
				break;
			}
		}

		if (flag1 == -1 || flag2 == -1)
		{
			for (int i = 0; i < n; i++)
			{
				cout << s[i];
			}
			cout << endl;
		}
		else if (flag1 < flag2)
		{
			for (int i = 0; i < flag1; i++)
			{
				cout << s[i];
			}
			for (int i = flag2; i < n; i++)
			{
				cout << s[i];
			}
			cout << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}