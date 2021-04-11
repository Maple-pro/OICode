#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int maxt = 1e5 + 5;
int island[maxn][maxn];
int n, m, t;
int par[maxn * maxn]; // ²¢²é¼¯
int height[maxt];
int ans[maxt];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct node {
	int x, y;
	int h;
};

node a[maxn * maxn];

bool comp(node a1, node a2)
{
	return a1.h < a2.h;
}

int find(int x)
{
	if (par[x] == x) return x;
	else return find(par[x]);
}

bool merge(int x, int y)
{
	int par_x = find(x);
	int par_y = find(y);
	if (par_x > par_y) {
		par[par_y] = par_x;
		return true;
	}
	else if (par_x < par_y) {
		par[par_x] = par_y;
		return true;
	}
	else return false;
}

int main()
{
//	freopen("./data/b/1.in", "r", stdin); 
	
	int Z; scanf("%d", &Z);
	while (Z--) {
		scanf("%d%d", &n, &m);
		memset(island, 0, sizeof(island));
		memset(height, 0, sizeof(height));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &island[i][j]);
				int s = i * m + j;
				a[s].x = i;
				a[s].y = j;
				a[s].h = island[i][j];
			}
		}
		scanf("%d", &t);
		for (int i = 0; i < t; i++) scanf("%d", &height[i]);
		
		memset(par, -1, sizeof(par));
		sort(a, a +  n * m, comp);
		
		int k = n * m - 1;
		int res = 0;
		for (int i = t - 1; i >= 0; i--) {
			if (a[k].h > height[i]) {
				while (k >= 0 && a[k].h > height[i]) {
					if (par[a[k].x * m + a[k].y] == -1) {
						par[a[k].x * m + a[k].y] = a[k].x * m + a[k].y;
						res++;
					}
					for (int j = 0; j < 4; j++) {
						int newx = a[k].x + dx[j];
						int newy = a[k].y + dy[j];
						if (newx >= 0 && newx < n && newy >= 0 && newy < m && island[newx][newy] > height[i] && par[newx * m + newy] != -1) {
							if (merge(newx * m + newy, a[k].x * m + a[k].y)) res--;
						} 
					}
					k--;
				}
				if (k < 0) {
					while (i >= 0) {
						ans[i] = res;
						i--;
					}
					break;
				}
			}
			ans[i] = res;
		}
		
		// print ans
		for (int i = 0; i < t; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}
