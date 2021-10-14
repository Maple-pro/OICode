#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct Node {
	int num;
	int layer; 
};

const int maxn = 1e3 + 5;
const int maxm = 105;
int N, L;
vector<int> links[maxn];
int query[maxn];
int query_num;

Node newnode(int num, int layer)
{
	Node res;
	res.num = num;
	res.layer = layer;
	return res;
}

int getres(int start)
{
	queue<Node> que;
	que.push(newnode(start, 0));
	int num = 0;
	int vis[maxn] = {0};
	vis[start] = 1;
	while (!que.empty()) {
		Node now = que.front();
		que.pop();
		if (now.layer == L) continue;
		for (int i = 0; i < links[now.num].size(); i++) {
			int next = links[now.num][i];
			if (!vis[next]) {
				que.push(newnode(next, now.layer + 1));
				num++;
				vis[next] = 1;
			}
		}
	}
	return num;
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	memset(links, 0, sizeof(links));
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int fol;
			scanf("%d", &fol);
			links[fol].push_back(i);
		}
	}
	
	scanf("%d", &query_num);
	for (int i = 0; i < query_num; i++) scanf("%d", &query[i]);
	
	for (int i = 0; i < query_num; i++) {
		printf("%d\n", getres(query[i]));
	}
	
	return 0;
}
