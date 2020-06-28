#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s[maxn];
		cin >> s;
		int len = strlen(s);
		int n1 = 0;
		int n2 = 0;
		int minn = 0;
		for (int i = 0; i< len; i++)
		{
			if (s[i] == '1')
			{
				n1++;
			}
			else
			{
				n2++;
			}
		}
		if (n1 <= n2)
		{
			minn = n1;
		}
		else
		{
			minn = n2;
		}
		if (minn % 2 == 0)
		{
			cout << "NET" << endl;
		}
		else
		{
			cout << "DA" << endl;
		}
	}
	return 0;
	
}