// Ì°ÐÄ 
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxr = 1005;
const int maxn = 1005;
int s[maxn];

int main()
{
	while (true)
	{
		int r, n;
		cin >> r >> n;
		if (r == -1 && n == -1) break;
		memset(s, -1, sizeof(s));
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}
		sort(s, s + n);
		int i = 0;
		int res = 0;
		while (i < n)
		{
			int pre = s[i];
			while (i < n && s[i] - pre <= r) i++;
			int flag = s[i-1];
			while (i < n && s[i] - flag <= r) i++;
			res++;
		}
		cout << res << endl;
	}
	return 0;
 } 
