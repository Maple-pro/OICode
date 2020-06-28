#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
string a[maxn];
string l[maxn];
string r[maxn];
string mid;
bool flag[maxn];
int left_num = 0;
int mid_num = 0;

int main()
{
	memset(flag, true, sizeof(flag));
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}

	for (int i=0; i<n; i++)
	{
		if (flag[i] == false) continue;
		string temp = a[i];
		reverse(temp.begin(), temp.end());
		if (temp == a[i])
		{
			mid = a[i];
			if(mid_num == 0) mid_num++;
		}
		else
		{
			for (int j=i+1; j<n; j++)
			{
				if (flag[j] != false && a[j] == temp)
				{
					l[left_num] = a[i];
					r[left_num] = a[j];
					left_num++;
					flag[j] = false;
					break;
				}
			}
		}
		flag[i] = false;
	}

	cout << left_num * 2 * m + mid_num * m << endl;
	for (int i=0; i<left_num; i++) {
		cout << l[i];
	}
	if (mid_num == 1) cout << mid;
	for (int k=0; k<left_num; k++) {
		cout << r[left_num - k - 1];
	}
	cout << endl;

	return 0;
}