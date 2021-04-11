#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;

struct Node {
	int data;
	Node* left;
	Node* right;
};
vector<int> origin;
int N;
Node* root = NULL;
vector<int> pre, pre_mirror, post, post_mirror; 

void insert(Node*& now, int data)
{
	if (now == NULL) {
		now = new Node;
		now->data = data;
		now->left = NULL;
		now->right = NULL;
		return;
	}
	if (data < now->data) insert(now->left, data);
	else insert(now->right, data);
}

void pre_order(Node* now)
{
	if (now == NULL) return;
	pre.push_back(now->data);
	pre_order(now->left);
	pre_order(now->right);
}

void pre_order_mirror(Node* now)
{
	if (now == NULL) return;
	pre_mirror.push_back(now->data);
	pre_order_mirror(now->right);
	pre_order_mirror(now->left);
}

void post_order(Node* now)
{
	if (now == NULL) return;
	post_order(now->left);
	post_order(now->right);
	post.push_back(now->data);
}

void post_order_mirror(Node* now)
{
	if (now == NULL) return;
	post_order_mirror(now->right);
	post_order_mirror(now->left);
	post_mirror.push_back(now->data);
}

int main()
{
//	freopen("data.in", "r", stdin);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int data;
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	
	pre_order(root);
	pre_order_mirror(root);
	post_order(root);
	post_order_mirror(root);
	
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size() - 1) printf(" ");
		}
	}
	else if (origin == pre_mirror) {
		printf("YES\n");
		for (int i = 0; i < post_mirror.size(); i++) {
			printf("%d", post_mirror[i]);
			if (i < post_mirror.size() - 1) printf(" ");
		} 
	}
	else {
		printf("NO\n");
	}
	
	return 0;
}
