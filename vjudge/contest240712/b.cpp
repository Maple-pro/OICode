#include <bits/stdc++.h>
using namespace std;

const int maxn = 30; 
int n;
vector<int> pile[maxn];

void find_block(int a, int &pa, int &ha)
{
	for (pa = 0; pa < n; pa++) {
		for (ha = 0; ha < pile[pa].size(); ha++) {
			if (pile[pa][ha] == a) return;
		}
	}
}

void clear_above(int p, int h)
{
	int len = pile[p].size();
	for (int i = h+1 ; i < pile[p].size(); i++) {
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h+1);
}

void move_above(int p, int h, int p2)
{
	for (int i = h; i < pile[p].size(); i++) {
		int b = pile[p][i];
		pile[p2].push_back(b);
	}
	pile[p].resize(h);
} 

void print_pile()
{
	for (int i = 0; i < n; i++) {
		printf("%d:", i);
		for (int j = 0; j < pile[i].size(); j++) {
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a, b;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++) pile[i].push_back(i);
	
	while (true) {
		cin >> s1;
		if (s1 == "quit") break;
		cin >> a;
		cin >> s2;
		cin >> b;
//		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
//		printf("%d %d %d %d\n", pa, pb, ha, hb);
		if (pa == pb) continue;
		if (s1 == "move" && s2 == "onto") {
			clear_above(pa, ha);
			clear_above(pb, hb);
			move_above(pa, ha, pb); 
		}
		else if (s1 == "move" && s2 == "over") {
			clear_above(pa, ha);
			move_above(pa, ha, pb);
		} 
		else if (s1 == "pile" && s2 == "onto") {
			clear_above(pb, hb);
			move_above(pa, ha, pb); 
		}
		else if (s1 == "pile" && s2 == "over") {
			move_above(pa, ha, pb);
		}
	}
	
	print_pile();
	
	return 0;
}
