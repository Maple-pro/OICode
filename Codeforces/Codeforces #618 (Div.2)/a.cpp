#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int data[maxn];

int main()
{
	int t;
	cin >> t;
	data[0] = 0;
	while(t--)
	{
		int n;
		int sum = 0;
		int zero_num = 0;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> data[i];
			sum += data[i];
			if (data[i] == 0)
			{
				zero_num ++;
			}
		}
		if (sum + zero_num == 0)
		{
			cout << zero_num + 1 << endl;
		}
		else
		{
			cout << zero_num <<endl;
		}
	}

	return 0;
}