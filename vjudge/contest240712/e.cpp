// WA 
#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
string files[maxn];
const int maxcol = 60;

int main() {
	int n;
	while (cin >> n) {
		int maxlen = 0;
		for (int i = 0; i < n; i++) {
			cin >> files[i];
			int len = files[i].size();
			maxlen = max(maxlen, len);
		}
		int col = (maxcol + 2) / (maxlen + 2);
		int row = n / col;
		if (n % col != 0) row++;
//		cout << col << row << endl;
		sort(files, files + n);
		for (int i = 0; i < 60; i++) {
			cout << '-';
		}
		cout << endl;
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				
				int len = files[i - 1 + row * (j - 1)].size();
				if (j != col) {
					cout << files[i - 1 + row * (j - 1)];
					for (int i = 0; i < maxlen + 2 - len; i++) cout << " ";
				}
				else {
					cout << files[i - 1 + row * (j - 1)];
					for (int i = 0; i < maxlen - len; i++) cout << " ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}
