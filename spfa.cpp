struct Node {
	int v; // �ڽӱߵ�Ŀ�궥�� 
	int dis; // �ڽӱߵı�Ȩ
	Node(int _v, int _dis): v(_v), dis(_dis) {} 
};

const int INF = 0x3f3f3f3f;
vector<Node> Adj[MAXV]; // �ڽӱ� 
int n, d[MAXV], num[MAXV]; // num�����¼�������Ӵ���
bool inq[MAXV]; // �����Ƿ��ڶ����� 

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
			// �ɳڲ���
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {
					Q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n) return false; // �пɴ︺�� 
				}
			} 
		} 
	}
	
	return true; // �޿ɴ︺�� 
}
