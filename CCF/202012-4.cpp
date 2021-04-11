#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxk = 15;
int N, M, K;
int need[maxn][maxk];

int main()
{
	freopen("data.in", "r", stdin);
	
	scanf("%d%d%d", &N, &M, &K);
	memset(need, 0, sizeof(need));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &need[i][j]);
		}
	}
}
