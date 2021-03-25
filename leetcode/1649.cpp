// Ê÷×´Êý×é 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int tree[maxn];

int lowbit(int x) {
    return x & -x;
}

int sum(int x) {
    int ret = 0;
    while (x >= 0) {
//    	printf("%d\n", x);
        ret += tree[x];
        x -= lowbit(x);
        if (x == 0) break;
    }
    return ret;
}

void add(int x) {
    while (x < maxn) {
        tree[x]++;
        x += lowbit(x);
    }
}

int createSortedArray(vector<int>& instructions) {
    int m = 0;
    int n = instructions.size();
    int ans = 0;
    long long mod = 1e9 + 7;
    
    for (int i = 0; i < n; i++) {
        int now = instructions[i];
        m = max(now, m);
        add(now);
        int tmp1 = sum(m) - sum(now);
        int tmp2 = sum(now - 1);
        ans += min(tmp1, tmp2);
        ans %= mod;
    }
    
    return ans;
}

int main()
{
	vector<int> instru = {1,2,3,6,5,4};
	int ans = createSortedArray(instru);
	cout << ans << endl;
	return 0;
}
