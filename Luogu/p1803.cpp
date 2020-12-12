// Ì°ÐÄ 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
typedef struct {
	int a;
	int b;
} T;
T t[maxn];

bool comp(T t1, T t2)
{
	return t1.b < t2.b;
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i].a >> t[i].b;
	}
	sort(t, t+n, comp);
	int res = 0;
	int pre = 0;
	int i = 0;
	while (i < n)
	{
		if (t[i].a >= pre) {
			res++;
			pre = t[i].b;
		}
		i++;
	}
	printf("%d", res);
	return 0;
}
