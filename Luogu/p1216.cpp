// ¶¯Ì¬¹æ»® 
#include <bits/stdc++.h>
using namespace std;

const int maxr = 1005;
int a[maxr][maxr];
int s[maxr][maxr];

int main()
{
	int r; cin >> r;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> a[i][j]; 
		}
	}
	
	s[0][0] = a[0][0];
	for (int i = 1; i < r; i++)
	{
		s[i][0] = s[i - 1][0] + a[i][0];
		s[i][i] = s[i - 1][i - 1] + a[i][i];
		for (int j = 1; j < i; j++)
		{
			s[i][j] = max(s[i - 1][j - 1], s[i - 1][j]) + a[i][j];
		}
	}
	
	
	int ans = 0;
	for (int i = 0; i < r + 1; i++)
	{
		ans = max(ans, s[r -1][i]);
	}
	cout << ans << endl;
	
	
	return 0;
}
