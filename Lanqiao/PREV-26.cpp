#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
int matrix[maxn][maxn];
int sub[maxn];
int n, m;

int getmax()
{
	int res = sub[0];
	int start = sub[0];
	for (int i = 1; i < m; i++) {
		if (start + sub[i] > sub[i]) {
			start = start + sub[i];
		}
		else {
			start = sub[i];
		}
		if (start > res) {
			res = start;
		}
	}
	return res;
}

int main()
{
	int ans = -99999999;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		memset(sub, 0, sizeof(sub));
		for (int j = i; j < n; j++) {
			for (int k = 0; k < m; k++) {
				sub[k] += matrix[j][k];
			}
			int tmp = getmax();
			if (ans < tmp) {
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
	return 0;
 } 
