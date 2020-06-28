#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
ll m[maxn];

void change(int left, int right)
{
	int index = left;
	ll left_sum = 0;
	ll right_sum = 0;
	for (int i=left; i<=right; i++)
	{
		if (m[i] < m[index])
			index = i;
	}
	for (int i=left; i<index; i++)
		left_sum += m[i];
	left_sum -= m[index] * (index - left);

	for (int i=index+1; i<=right; i++)
		right_sum += m[i];
	right_sum -= m[index] * (right - index);

	if(left_sum < right_sum)
	{
		for (int i=left; i<index; i++)
			if(m[i] > m[index]) m[i] = m[index];
		if(left != index-1 && index != left && index+1 != right && index != right)
			change(index+1, right);
	}
	else
	{
		for (int i=index+1; i<=right; i++)
			if(m[i] > m[index]) m[i] = m[index];
		if(left != index-1 && index != left && index+1 != right && index != right)
			change(left, index-1);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> m[i];

	change(1, n);

	for (int i=1; i<=n; i++)
		cout << m[i] << " ";
	cout << endl;
	return 0;
}