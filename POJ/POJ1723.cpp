#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10005;
int x[maxn];
int y[maxn];
int newx[maxn];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) newx[i] = x[i] - i + 1;
	
	sort(newx + 1, newx + n + 1);
	sort(y + 1, y + n + 1);
	
	int x0 = newx[n / 2 + 1];
	int y0 = y[n / 2 + 1];
	
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += abs(y[i] - y0);
		res += abs(newx[i] - x0);
	}
	cout << res << endl;
	
	return 0;
}
