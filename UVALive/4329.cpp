// Ê÷×´Êý×é 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 5;
const int maxa = 1e5 + 5;
int a[maxn];
int left_bit[maxa]; // left_bit
int right_bit[maxa]; // right_bit
int c[maxn]; // left
int d[maxn]; // right
int n;

int lowbit(int x)
{
	return x & -x;
}

int sum1(int x)
{
	int ret = 0;
	while (x >= 1) {
		ret += left_bit[x];
		x -= lowbit(x);
	}
	return ret;
}

int sum2(int x)
{
	int ret = 0;
	while (x >= 1) {
		ret += right_bit[x];
		x -= lowbit(x);
	}
	return ret;
}

void add1(int x)
{
	while (x <= maxa) {
		left_bit[x]++;
//		printf("%d %d\n", x, left_bit[x]);
		x += lowbit(x);
	}
}

void add2(int x)
{
	while (x <= maxa) {
		right_bit[x]++;
		x += lowbit(x);
	}
}

int main()
{
	int t; cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(left_bit, 0, sizeof(left_bit));
		memset(right_bit, 0, sizeof(right_bit));
		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));
		long long res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			c[i] = sum1(a[i] - 1);
//			printf("a[i] is: %d\n", a[i]);
			add1(a[i]);
		}
		for (int i = n; i >= 1; i--) {
			d[i] = sum2(a[i] - 1);
			add2(a[i]);
		}
		for (int i = 2; i <= n-1; i++) {
			res += c[i] * (n - i - d[i]) + d[i] * (i - 1 - c[i]);
		}
//		for (int i = 1; i <= n; i++) {
//			printf("%d %d\n", c[i], d[i]);
//		}
		cout << res << endl;
	}
}
