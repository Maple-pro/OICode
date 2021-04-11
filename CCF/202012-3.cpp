#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e6 + 5;

typedef long long ll;
struct Node {
	map<string, int> child;
	int kind; // ���ͣ�0Ϊ�ļ���1ΪĿ¼ 
	ll max_ld, max_lr;
	ll ld, lr;
	ll filesize;
	int fa;
};

int n;
Node nodes[maxn];
vector<pair<int, string>> reback; // �����·����id��Ӧ���ڵ㣬string��Ӧ��ӵĽڵ� 
int index = 0; // ��ǰ�Ľڵ��� 

// �ع�֮ǰ�Ĳ�����ɾ���������ļ��� 
void Reback()
{
	for (int i = 0; i < reback.size(); i++) {
		int f_id = reback[i].first;
		string son_name = reback[i].second;
		nodes[f_id].child.erase(son_name);
	}
}

// �����ļ� 
bool doC(string path, ll size)
{
	int id = 0; // ��ǰ�������Ľڵ� 
	int origin_index = index; // rollback֮ǰ�ظ�index 
	
	int last = path.rfind("/");
	reback.clear();
	int p = 1;
	// ·����鲢����·�� 
	while (p < last) {
		string t = "";
		for (; p < last && path[p] != '/'; p++) {
			t.push_back(path[p]);
		}
		p++;
		
		// ·�������� 
		if (nodes[id].child.find(t) == nodes[id].child.end()) {
			// ����·�� 
			index++; 
			nodes[id].child[t] = index;
			nodes[index].fa = id;
			nodes[index].kind = 1;
			nodes[index].max_ld = LLONG_MAX / 3;
			nodes[index].max_lr = LLONG_MAX / 3;
			nodes[index].ld = 0;
			nodes[index].lr = 0;
			reback.push_back(make_pair(id, t));
			id = index;
		}
		// ·������ 
		else {
			int sonid = nodes[id].child[t];
			if (nodes[sonid].kind == 0) {
				index = origin_index;
				Reback();
				return false;
			}
			id = sonid;
		}
	}
	
	// �ļ���鲢�����ļ�
	string filename = path.substr(last + 1);
	// �Ѿ������ļ��� 
	if (nodes[id].child.find(filename) != nodes[id].child.end()) {
		int sonid = nodes[id].child[filename];
		// �Ҹ��ļ�ΪĿ¼�ļ��� ִ��ʧ�� 
		if (nodes[sonid].kind == 1) {
			index = origin_index;
			Reback();
			return false; 
		}
	}
	ll py; // �����ӵ���� 
	if (nodes[id].child.find(filename) == nodes[id].child.end()) py = size;
	else py = size - nodes[nodes[id].child[filename]].filesize;
	
	// ���Ŀ¼���
	if (nodes[id].ld + py > nodes[id].max_ld) {
		index = origin_index;
		Reback();
		return false;
	}
	
	// ��������
	int tmp_id = id;
	while (tmp_id != -1) {
		if (nodes[tmp_id].lr + py > nodes[tmp_id].max_lr) {
			index = origin_index;
			Reback();
			return false;
		}
		tmp_id = nodes[tmp_id].fa;
	}
	
	// ������������������ļ�
	if (nodes[id].child.find(filename) == nodes[id].child.end()) {
		index++;
		nodes[id].child[filename] = index;
		nodes[index].fa = id;
		nodes[index].kind = 0;
		nodes[index].filesize = size;
	}
	// ��������������滻ԭ���ļ� 
	else {
		int sonid = nodes[id].child[filename];
		nodes[sonid].filesize = size;
	}
	
	// ����Ŀ¼��ǰռ�ÿռ� 
	nodes[id].ld += py;
	int tmp_id2 = id;
	while (tmp_id2 != -1) {
		nodes[tmp_id2].lr += py;
		tmp_id2 = nodes[tmp_id2].fa;
	}
	
	return true;
}

// �Ƴ��ļ� 
bool doR(string path)
{
	int id = 0;
	
	int last = path.rfind("/");
	
	int p = 1;
	// ·�����
	while (p < last) {
		string t = "";
		for (; p < last && path[p] != '/'; p++) t += path[p];
		p++;
		
		if (nodes[id].child.find(t) == nodes[id].child.end()) return true;
		else {
			int sonid = nodes[id].child[t];
			if (nodes[sonid].kind == 0) return true;
			id = sonid;
		}
	}
	
	// �ļ�ɾ��
	string filename = path.substr(last + 1);
	if (nodes[id].child.find(filename) == nodes[id].child.end()) return true;
	else {
		int sonid = nodes[id].child[filename];
		// ��ͨ�ļ� 
		if (nodes[sonid].kind == 0) {
			nodes[id].child.erase(filename);
			nodes[id].ld -= nodes[sonid].filesize;
			int tmp_id = id;
			while (tmp_id != -1) {
				nodes[tmp_id].lr -= nodes[sonid].filesize;
				tmp_id = nodes[tmp_id].fa;
			}
		}
		// Ŀ¼�ļ�
		else {
			nodes[id].child.erase(filename);
			int tmp_id = id;
			while (tmp_id != -1) {
				nodes[tmp_id].lr -= nodes[sonid].lr;
				tmp_id = nodes[tmp_id].fa;
			}
		} 
	}
	
	return true;
}

// ������� 
bool doQ(string path, ll ld, ll lr)
{
	if (ld == 0) ld = LLONG_MAX / 3;
	if (lr == 0) lr = LLONG_MAX / 3;
	
	int id = 0;
	
	int last = path.rfind("/");
	int p = 1;
	while (p < last) {
		string t = "";
		for (; p < last && path[p] != '/'; p++) t += path[p];
		p++;
		
		if (nodes[id].child.find(t) == nodes[id].child.end()) return false;
		else {
			int sonid = nodes[id].child[t];
			if (nodes[sonid].kind == 0) return false;
			id = sonid;
		}
	}
	
	string filename = path.substr(last + 1);
	int filenode;
	if (filename == "") filenode = 0;
	else {
		if (nodes[id].child.find(filename) == nodes[id].child.end()) return false;
		else filenode = nodes[id].child[filename];
	}
	if (nodes[filenode].kind == 0) return false;
	else { // �����Ŀ¼ 
		if (ld < nodes[filenode].ld || lr < nodes[filenode].lr) return false;
		else {
			nodes[filenode].max_ld = ld;
			nodes[filenode].max_lr = lr;
			return true;
		}
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	// �������ڵ� 
	nodes[0].fa = -1;
	nodes[0].kind = 1;
	nodes[0].max_ld = LLONG_MAX / 3;
	nodes[0].max_lr = LLONG_MAX / 3;
	nodes[0].ld = 0;
	nodes[0].lr = 0;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		if (op == "C") {
			string path;
			ll size;
			cin >> path >> size;
			bool res = doC(path, size);
			if (res) printf("Y\n");
			else printf("N\n");
		}
		else if (op == "R") {
			string path;
			cin >> path;
			bool res = doR(path);
			if (res) printf("Y\n");
			else printf("N\n");
		}
		else if (op == "Q") {
			string path;
			ll ld, lr;
			cin >> path >> ld >> lr;
			bool res = doQ(path, ld, lr);
			if (res) printf("Y\n");
			else printf("N\n");
		}
	}
	
	return 0;
}
