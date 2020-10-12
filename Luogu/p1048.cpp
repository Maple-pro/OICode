# include <bits/stdc++.h>
using namespace std;

const int maxm = 105;
const int maxt = 1005;
int T, M;
int value[maxm][maxt];
int t[maxm];
int v[maxm];

int main()
{
	cin >> T >> M;
	memset(value, 0, sizeof(value));
	memset(t, 0, sizeof(t));
	memset(v, 0, sizeof(v));
	for (int i = 0; i < M; i++)
	{
		cin >> t[i] >> v[i];
	}
	
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j <= T; j++)
		{
			if (j < t[i-1]) value[i][j] = value[i-1][j];
			else value[i][j] = max(value[i-1][j], value[i-1][j-t[i-1]] + v[i-1]);
		}
	}
	cout << value[M][T] << endl;
	return 0;
}
