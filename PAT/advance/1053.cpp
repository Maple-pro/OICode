#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 105;
struct Node {
	int data;
	vector<int> childs;
};

Node nodes[maxn];
int N, M, S;
int path[maxn];

bool comp(int a1, int a2)
{
	return nodes[a1].data > nodes[a2].data;
}

void dfs(int index, int sum, int pathNum)
{	
	if (sum > S) return;
	if (sum == S) {
		if (nodes[index].childs.size() != 0) return;
		for (int i = 0; i < pathNum; i++) {
			printf("%d", nodes[path[i]].data);
			if (i < pathNum - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < nodes[index].childs.size(); i++) {
		int child = nodes[index].childs[i];
		path[pathNum] = child;
		dfs(child, sum + nodes[child].data, pathNum + 1);
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		nodes[i].data = tmp;
	}
	int id, k;
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			int child;
			scanf("%d", &child);
			nodes[id].childs.push_back(child);
		}
		sort(nodes[id].childs.begin(), nodes[id].childs.end(), comp);
	}
	path[0] = 0;
	dfs(0, nodes[0].data, 1);
	
	return 0;
}
