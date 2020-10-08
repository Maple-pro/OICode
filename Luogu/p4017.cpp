// 记忆化搜索，dfs 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5005;
const int maxm = 500005;
const int mod = 80112002;

vector<int> eat[maxn];
bool flag1[maxn]; // 标记吃的人
bool flag2[maxn]; // 标记被吃的人 
ll s[maxn];

int dfs(int x)
{
	if (!flag1[x])
	{
		s[x] = 1; return 1;
	} 
	if (s[x] != 0) return s[x];
	s[x] = 0;
	for (int i = 0; i < eat[x].size(); i++)
	{
		int next = eat[x][i];
		dfs(next);
		s[x] = (s[x] + s[next]) % mod;
	}
	return s[x];
}

int main()
{
	int n, m;
	cin >> n >> m;
	memset(flag1, false, sizeof(flag1));
	memset(flag2, false, sizeof(flag2));
	memset(s, 0, sizeof(s));
	for (int i = 0; i < m; i++)
	{
		int A, B;
		cin >> A >> B;
		eat[B-1].push_back(A-1);
		flag1[B-1] = true;
		flag2[A-1] = true;
	}
	
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (!flag2[i])
		{
			res += dfs(i);
			res %= mod;
		}
	}
	
	// for (int i = 0; i < n; i++) cout << s[i] << endl;
	
	cout << res;
	return 0;
}
