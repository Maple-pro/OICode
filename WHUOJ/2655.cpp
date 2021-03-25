#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
int matrix[maxn][maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			matrix[i][j] += tmp;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j];
			if (j != m-1) cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
