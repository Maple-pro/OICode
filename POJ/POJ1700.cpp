// Ì°ĞÄ 
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int t[maxn];
int n;
int sum;

int getres(int a, int b, int c, int d)
{
	int sum1 = 2 * a + c + d;
	int sum2 = 2 * b + a + d;
	return min(sum1, sum2);
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; i++) scanf("%d", &t[i]);
		
		sum = 0;
		while (n > 3) {
			int a = t[0];
			int b = t[1];
			int c = t[n - 2];
			int d = t[n - 1];
			sum += getres(a, b, c, d);
			n -= 2;
		}
		if (n == 1) sum += t[0];
		if (n == 2) sum += max(t[0], t[1]);
		if (n == 3) sum += t[0] + t[1] + t[2];
		
		printf("%d\n", sum);
	}
	
	return 0;
}
