#include <iostream>
#include <queue>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
};

const int maxn = 35;
int in_order[maxn];
int post_order[maxn];
int n;

Node* build(int in_l, int in_r, int post_l, int post_r)
{
	if (in_l > in_r || post_l > post_r) return NULL;
	
	Node* root = new Node;
	root->data = post_order[post_r];
	int k;
	for (k = in_l; k <= in_r; k++) {
		if (in_order[k] == root->data) break;
	}
	int left_len = k - in_l;
	int right_len = in_r - k;
	root->left = build(in_l, k - 1, post_l, post_l + left_len - 1);
	root->right = build(k + 1, in_r, post_l + left_len, post_r - 1);
	
	return root;
}

void bfs(Node* root)
{
	int num = 0;
	queue<Node*> que;
	que.push(root);
	while (!que.empty()) {
		Node* cur = que.front();
		que.pop();
		printf("%d", cur->data);
		num++;
		if (num != n) printf(" ");
		if (cur->left != NULL) que.push(cur->left);
		if (cur->right != NULL) que.push(cur->right);
	}
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> post_order[i];
	for (int i = 0; i < n; i++) cin >> in_order[i];
	Node* tree = build(0, n - 1, 0, n - 1);
	bfs(tree);
	
	return 0;
}
