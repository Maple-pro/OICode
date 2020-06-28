#include <bits/stdc++.h>
using namespace std;

const int maxn = 2*1e5 + 5;
int result[maxn];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(result, 0, sizeof(result));
		int n;
		string s;
		cin >> n >> s;

		int pre1 = 0;
		int max_num = n;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '>' || i == n-1)
			{
				for (int j=i; j>=pre1; j--)
				{
					result[j] = max_num;
					max_num--;
				}
				pre1 = i+1;
			}
		}
		for (int i=0; i<n; i++)
			cout << result[i] << " ";
		cout << '\n';

		int pre2 = 0;
		int min_num = 1;
		for (int i=0; i<n; i++)
		{
			if (s[i] == '<' || i == n-1)
			{
				for (int j=i; j>=pre2; j--)
				{
					result[j] = min_num;
					min_num++;
				}
				pre2 = i+1;
			}
		}
		for (int i=0; i<n; i++)
			cout << result[i] << " ";
		cout << '\n';
	}

	return 0;
}