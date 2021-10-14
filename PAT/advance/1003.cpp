#include <iostream>
#include <string.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 505;
int roads[maxn][maxn];
int nums[maxn];
int N, M;
int c1, c2;
int path[maxn];
int weight[maxn];
int vis[maxn] = {0};
int path_num[maxn];

void djs()
{
	for (int i = 0; i < N; i++) {
		int start = -1;
		int start_len = INF;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && path[j] < start_len) {
				start = j;
				start_len = path[j];
			}
		}
		if (start == -1) return;
		vis[start] = 1;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && path[start] + roads[start][j] < path[j]) {
				path[j] = path[start] + roads[start][j];
				weight[j] = weight[start] + nums[j];
				path_num[j] = path_num[start];
			}
			else if (path[start] + roads[start][j] == path[j]) {
				path_num[j] += path_num[start];
				if (weight[start] + nums[j] > weight[j]) {
					weight[j] = weight[start] + nums[j];
				}
			}
		}
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	memset(roads, 0x3f, sizeof(roads));
	memset(path, 0x3f, sizeof(path));
	memset(weight, 0, sizeof(weight));
	memset(path_num, 0, sizeof(path_num));
	scanf("%d%d%d%d", &N, &M, &c1, &c2);
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	for (int i = 0; i < M; i++) {
		int from, to, len;
		scanf("%d%d%d", &from, &to, &len);
		roads[from][to] = len;
		roads[to][from] = len;
	}
	path[c1] = 0;
	weight[c1] = nums[c1];
	path_num[c1] = 1;
	djs();
	
	printf("%d %d\n", path_num[c2], weight[c2]);
	
	return 0;
}
