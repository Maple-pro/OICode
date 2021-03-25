#include <bits/stdc++.h>
using namespace std;

const int maxn = 8;
int maze[maxn][maxn];
int n;
int pos[maxn];
int pos1[maxn];
int ans = 0;

void search2(int cnt)
{
	if (cnt == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!maze[cnt][i]) continue;
		if (pos[cnt] == i) continue;
		bool flag = true;
		for (int j = 0; j < cnt; j++) {
			if (i == pos1[j] || abs(cnt - j) == abs(i - pos1[j])) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		else {
			pos1[cnt] = i;
			search2(cnt + 1);
		}
	}
}

void search(int cnt)
{
	if (cnt == n) {
		search2(0);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!maze[cnt][i]) continue;
		bool flag = true;
		for (int j = 0; j < cnt; j++) {
			if (i == pos[j] || abs(cnt - j) == abs(i - pos[j])) {
				flag = false;
				break;
			}
		} 
		if (!flag) continue;
		else {
			pos[cnt] = i;
			search(cnt + 1);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
	search(0);
	cout << ans << endl;
}
