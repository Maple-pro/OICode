#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int target[maxn];

int main()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		while (true) {
			bool flag = false;
			cin >> target[0];
			if (target[0] == 0) {
				cout << endl;
				break;
			}
			for (int i = 1; i < n; i++) cin >> target[i];
			
			stack<int> s;
			int a = 0;
			int b = 1;
			while (a < n) {
				int now = target[a];
				if (now == b) {
					b++;
					a++;
				}
				else if (!s.empty() && s.top() == now) {
					s.pop();
					a++;
				}
				else if (b <= n) {
					s.push(b);
					b++; 
				}
				else {
					flag = true;
					cout << "No" << endl;
					break;
				}
			}
			if (!flag) cout << "Yes" << endl;
		}
		
	}
	
	return 0;
}
