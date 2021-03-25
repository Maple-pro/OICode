#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
int nums[maxn];

int main()
{
	int n, q;
	int caseNum = 1;
	while ((scanf("%d%d", &n, &q) == 2) && n)
	{
		printf("CASE# %d:\n", caseNum);
		caseNum++;
		for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
		sort(nums, nums+n);
		for (int i = 0; i < q; i++) {
			int x;
			scanf("%d", &x);
			int res = lower_bound(nums, nums+n, x) - nums;
			if (nums[res] == x) printf("%d found at %d\n", x, res+1);
			else printf("%d not found\n", x);
		}
	} 
	
	return 0;
}
