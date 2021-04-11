// unfinished
// uva-122
#include <bits/stdc++.h>
using namespace std;

struct Node {
	string value;
	bool has_value;
	Node *left, *right;
	Node(): has_value(false), left(nullptr), right(nullptr) {}
};

Node *root;

string s;
string v;
bool failed;

void addnode(string p, string v)
{
	Node *now = root;
	int len = p.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == 'L') {
			if (now->left == nullptr) now->left = new Node();
			now = now->left;
		}
		else if (s[i] == 'R') {
			if (now->right == nullptr) now->right = new Node();
			now = now->right;
		}
	}
	if (now->has_value) failed = true;
	now->value = v;
	now->has_value = true;
}

bool check(Node *now)
{
	if (!now->has_value) return false;
	if (now->left != nullptr && !check(now->left)) return false;
	if (now->right != nullptr && !check(now->right)) return false;
	return true;
}

void bfs()
{
	
}

int main()
{
	while (true) {
		bool complete = false;
		failed = false;
		root = new Node();
		while (true) {
			if (cin >> s) {
				complete = true;
				break;
			}
			if (s == "()") break;
			string v = s.substr(1, s.find(",") - 1);
			string p = s.substr(s.find(",") + 1, s.find(")") - 3);
			addnode(p, v);
		}
		if (complete) break;
		if (!failed && check(root)) {
			bfs();
			printf("it is compelte\n");
		}
		else {
			printf("not complete\n");
		}
	}
	
	return 0;
}
