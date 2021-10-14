#include <iostream>
#include <map>
#include <string.h>
using namespace std;

const int maxn = 2005;

int N, K;
map<string, int> string2int;
map<int, string> int2string;
int personNum = 0;
int graph[maxn][maxn]; 
int weight[maxn];
int vis[maxn];
map<string, int> res;

int change(string name)
{
	if (string2int.find(name) == string2int.end()) {
		string2int[name] = personNum;
		int2string[personNum] = name;
		personNum++;
		return personNum - 1;
	}
	else {
		return string2int[name];
	}
}

void dfs(int now, int &num, int &head, int &total_num)
{
	num++;
	vis[now] = 1;
	if (weight[now] > weight[head]) head = now;
	for (int i = 0; i < personNum; i++) {
		if (graph[now][i]) {
			total_num += graph[now][i];
			graph[now][i] = graph[i][now] = 0;
			if (!vis[i]) dfs(i, num, head, total_num);
		}
	}
}

void dfsTravel()
{
	for (int i = 0; i < personNum; i++) {
		if (!vis[i]) {
			int num = 0;
			int head = i;
			int total_num = 0;

			dfs(i, num, head, total_num);

			if (num > 2 && total_num > K) {
				res[int2string[head]] = num;
			}
		}
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	memset(graph, 0, sizeof(graph));
	memset(weight, 0, sizeof(weight));
	scanf("%d%d", &N, &K);
	int w;
	string name1, name2;
	for (int i = 0; i < N; i++) {
		cin >> name1 >> name2 >> w;
		int id1 = change(name1);
		int id2 = change(name2);
		weight[id1] += w;
		weight[id2] += w;
		graph[id1][id2] += w;
		graph[id2][id1] += w;
	}

	memset(vis, 0, sizeof(vis));
	dfsTravel();

	cout << res.size() << endl;
	map<string, int>::iterator ite;
	for (ite = res.begin(); ite != res.end(); ite++) {
		cout << ite->first << " " << ite->second << "\n";
	}

	return 0;
}
