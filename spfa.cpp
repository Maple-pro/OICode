struct Node {
	int v; // 邻接边的目标顶点 
	int dis; // 邻接边的边权
	Node(int _v, int _dis): v(_v), dis(_dis) {} 
};

const int INF = 0x3f3f3f3f;
vector<Node> Adj[MAXV]; // 邻接表 
int n, d[MAXV], num[MAXV]; // num数组记录顶点的入队次数
bool inq[MAXV]; // 顶点是否在队列中 

bool SPFA(int s) {
	memset(inq, false, sizeof(inq));
	memset(num, 0, sizeof(num));
	memset(d, 0x3f, sizeof(d));
	
	queue<int> Q;
	Q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i].v;
			int dis = Adj[u][i].dis;
			// 松弛操作
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n) return false; // 有可达负环 
				}
			} 
		} 
	}
	
	return true; // 无可达负环 
}
