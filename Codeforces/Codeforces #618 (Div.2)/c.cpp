#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5; //the max size of the array
const int maxpos = 35; //the max position of the number
ll a[maxn];
int num[maxpos];

int main()
{
	memset(num, 0, sizeof(num));
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		scanf("%I64d", &a[i]);
	}
	for (int i=1; i<=n; i++){
		for (int j=0; j<=31; j++){
			if (((a[i]>>j) & 1) == 1) num[j]++;
		}
	}

	int now = 35;
	while (now >= 0)
	{
		if (num[now] == 1) break;
		now--;
	}
	int result;
	for (result=1; result<=n; result++)
	{
		if (((a[result]>>now) & 1) == 1) break;
	}

	if (now != -1) {
		printf("%I64d ", a[result]);
	}
	for (int i=1; i<=n; i++){
		if (i != result) {
			printf("%I64d ", a[i]);
		}
	}
	printf("\n");

	return 0;
}