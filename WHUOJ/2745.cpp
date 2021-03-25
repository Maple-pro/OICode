#include <bits/stdc++.h>
using namespace std;

const int maxn = 8;
int digit[maxn];

void getDigit(int num)
{
	memset(digit, -1, sizeof(digit));
	for (int i = 0; ; i++)
	{
		if (num == 0) break;
		int tmp = num % 10;
		digit[i] = tmp;
		num = num / 10;
	}
}

int main()
{
	int x, n;
	cin >> x >> n;
	for (int i = 1; i <= n; i++) {
		getDigit(x);
		x = 0;
		for (int j = 0; ; j++) {
			if (digit[j] == -1) break;
			x += digit[j] * digit[j];
		}
	}
	cout << x << endl;
	return 0;
}
